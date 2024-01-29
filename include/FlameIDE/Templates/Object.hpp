#ifndef FLAMEIDE_TEMPLATES_OBJECT_HPP
#define FLAMEIDE_TEMPLATES_OBJECT_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace templates
{

template<Types::size_t SIZE_IN_BYTES>
class Object;

template<typename T>
class ConcreteObject;

}} // flame_ide::templates

namespace flame_ide
{namespace templates
{

template<Types::size_t SIZE_IN_BYTES>
class Object
{
public:
	using Me = Object<SIZE_IN_BYTES>;

public:
	Object() noexcept;
	Object(const Me &) noexcept = delete;
	Object(Me &&object) noexcept;

	template<typename T>
	Object(T &&value) noexcept;

	template<typename T>
	Object(const T &value) noexcept;

	~Object() noexcept;

	Object &operator=(const Me &) noexcept = delete;
	Object &operator=(Me &&object) noexcept;

	template<typename T>
	Object &operator=(T &&value) noexcept;

	template<typename T>
	Object &operator=(const T &value) noexcept;

	operator bool() const noexcept;

	template<typename T>
	T &get() noexcept;

	template<typename T>
	const T &get() const noexcept;

	template<typename T>
	AddMoveReferenceType<T> move() noexcept;

	constexpr Types::size_t size() const noexcept
	{
		return SIZE_IN_BYTES;
	}

private:
	using CallbackDestroy = void(*)(void *);

	template<typename T>
	constexpr void staticCheck() const noexcept
	{
		static_assert(
				(sizeof(T) <= sizeof(data)) && (alignof(T) <= sizeof(data) - sizeof(T))
				, "Object is too big. Needs to change size of object"
		);
	}

	void destroy() noexcept;

	template<typename T>
	static CallbackDestroy getCallbackDestroy() noexcept;

private:
	Types::uichar_t data[SIZE_IN_BYTES + sizeof(size_t)];
	VoidTraits::Pointer pointer = nullptr;
	CallbackDestroy callbackDestroy = nullptr;
	Types::ssize_t align = -1;
};

}} // flame_ide::templates

namespace flame_ide
{namespace templates
{

template<Types::size_t SIZE_IN_BYTES>
Object<SIZE_IN_BYTES>::Object() noexcept
{}

template<Types::size_t SIZE_IN_BYTES>
Object<SIZE_IN_BYTES>::Object(Me &&object) noexcept
{
	operator=(flame_ide::move(object));
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
Object<SIZE_IN_BYTES>::Object(T &&value) noexcept
{
	staticCheck<T>();
	operator=(flame_ide::move(value));
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
Object<SIZE_IN_BYTES>::Object(const T &value) noexcept
{
	staticCheck<T>();
	operator=(value);
}

template<Types::size_t SIZE_IN_BYTES>
Object<SIZE_IN_BYTES>::~Object() noexcept
{
	if (!callbackDestroy)
		return;
	callbackDestroy(pointer);
}

template<Types::size_t SIZE_IN_BYTES>
Object<SIZE_IN_BYTES> &Object<SIZE_IN_BYTES>::operator=(Me &&object) noexcept
{
	destroy();

	auto *dataPointer = data;
	const auto remainder = reinterpret_cast<Types::ptrint_t>(dataPointer) % object.align;
	const Types::ssize_t shift = (remainder) ? 0 : object.align - remainder;
	pointer = static_cast<decltype(pointer)>(data + shift);

	flame_ide::copy(pointer, object.pointer
			, flame_ide::min(
					SIZE_IN_BYTES - (
							reinterpret_cast<decltype(dataPointer)>(pointer)
									- dataPointer
					)
					, SIZE_IN_BYTES - (
							reinterpret_cast<decltype(dataPointer)>(object.pointer)
									- &object.data[0]
					)
			)
	);
	callbackDestroy = object.callbackDestroy;

	object.callbackDestroy = nullptr;
	object.pointer = nullptr;

	return *this;
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
Object<SIZE_IN_BYTES> &Object<SIZE_IN_BYTES>::operator=(T &&value) noexcept
{
	staticCheck<T>();
	destroy();

	pointer = flame_ide::placementNew<T>(
			reinterpret_cast<T *>(&data), flame_ide::move(value)
	);
	callbackDestroy = getCallbackDestroy<T>();
	align = alignof(T);

	return *this;
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
Object<SIZE_IN_BYTES> &Object<SIZE_IN_BYTES>::operator=(const T &value) noexcept
{
	staticCheck<T>();

	if (callbackDestroy)
		callbackDestroy(pointer);

	flame_ide::placementNew<T>(reinterpret_cast<T *>(&data), value);
	callbackDestroy = getCallbackDestroy<T>();

	return *this;
}

template<Types::size_t SIZE_IN_BYTES>
Object<SIZE_IN_BYTES>::operator bool() const noexcept
{
	return callbackDestroy;
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
T &Object<SIZE_IN_BYTES>::get() noexcept
{
	staticCheck<T>();
	return *reinterpret_cast<T *>(pointer);
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
const T &Object<SIZE_IN_BYTES>::get() const noexcept
{
	staticCheck<T>();
	return *reinterpret_cast<const T *>(pointer);
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
flame_ide::AddMoveReferenceType<T> Object<SIZE_IN_BYTES>::move() noexcept
{
	callbackDestroy = nullptr;
	return flame_ide::move(get());
}

template<Types::size_t SIZE_IN_BYTES>
void Object<SIZE_IN_BYTES>::destroy() noexcept
{
	if (callbackDestroy)
	{
		callbackDestroy(pointer);
		callbackDestroy = nullptr;
	}
	pointer = nullptr;
	align = -1;
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
typename Object<SIZE_IN_BYTES>::CallbackDestroy
Object<SIZE_IN_BYTES>::getCallbackDestroy() noexcept
{
	static auto destroy = [](void *value) -> void
	{
		reinterpret_cast<T *>(value)->~T();
	};
	return destroy;
}


}} // flame_ide::templates

#endif // FLAMEIDE_TEMPLATES_OBJECT_HPP
