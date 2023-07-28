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

	constexpr Types::ssize_t size() const noexcept
	{
		return SIZE_IN_BYTES;
	}

private:
	using CallbackDestroy = void(*)(void *);

	template<typename T>
	constexpr void staticCheck() const noexcept
	{
		static_assert(
				sizeof(data) >= sizeof(T)
				, "Object is too big. Needs to change size of object"
		);
	}

	template<typename T>
	static CallbackDestroy getCallbackDestroy() noexcept;

private:
	CallbackDestroy callbackDestroy = nullptr;
	Types::size_t data[
			(SIZE_IN_BYTES % sizeof(Types::size_t))
					? (SIZE_IN_BYTES / sizeof(Types::size_t)) + 1
					: (SIZE_IN_BYTES / sizeof(Types::size_t))
	];
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

	callbackDestroy(&data);
}

template<Types::size_t SIZE_IN_BYTES>
Object<SIZE_IN_BYTES> &Object<SIZE_IN_BYTES>::operator=(Me &&object) noexcept
{
	if (callbackDestroy)
		callbackDestroy(&data);

	flame_ide::copy(data, object.data);
	callbackDestroy = object.callbackDestroy;

	object.callbackDestroy = nullptr;

	return *this;
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
Object<SIZE_IN_BYTES> &Object<SIZE_IN_BYTES>::operator=(T &&value) noexcept
{
	staticCheck<T>();

	if (callbackDestroy)
		callbackDestroy(&data);

	flame_ide::placementNew<T>(reinterpret_cast<T *>(&data), flame_ide::move(value));
	callbackDestroy = getCallbackDestroy<T>();

	return *this;
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
Object<SIZE_IN_BYTES> &Object<SIZE_IN_BYTES>::operator=(const T &value) noexcept
{
	staticCheck<T>();

	if (callbackDestroy)
		callbackDestroy(&data);

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
	return *reinterpret_cast<T *>(&data);
}

template<Types::size_t SIZE_IN_BYTES>
template<typename T>
const T &Object<SIZE_IN_BYTES>::get() const noexcept
{
	staticCheck<T>();
	return *reinterpret_cast<const T *>(&data);
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
