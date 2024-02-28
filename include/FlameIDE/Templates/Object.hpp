#ifndef FLAMEIDE_TEMPLATES_OBJECT_HPP
#define FLAMEIDE_TEMPLATES_OBJECT_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace templates
{

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
class Object;

template<typename T>
class ConcreteObject;

}} // flame_ide::templates

namespace flame_ide
{namespace templates
{

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType = VoidTraits::Pointer>
class Object
{
public:
	using Me = Object<SIZE_IN_BYTES, AlignedAsType>;

public:
	Object() noexcept;
	Object(const Me &) noexcept = delete;
	Object(Me &&object) noexcept;

	template<typename T>
	Object(T &&value) noexcept;

	template<typename T>
	Object(const T &value) noexcept;

	~Object() noexcept;

	Me &operator=(const Me &) noexcept = delete;
	Me &operator=(Me &&object) noexcept;

	template<typename T>
	Me &operator=(T &&value) noexcept;

	template<typename T>
	Me &operator=(const T &value) noexcept;

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
		constexpr Types::size_t OBJECT_SIZE = sizeof(T);
		constexpr Types::size_t MY_SIZE = SIZE_IN_BYTES;
		static_assert(
				OBJECT_SIZE <= MY_SIZE
				, "Input object is too big. Needs to change size of Object's SIZE"
		);

		constexpr Types::size_t OBJECT_ALIGNMENT = alignof(T);
		constexpr Types::size_t MY_ALIGNMENT = alignof(AlignedAsType);
		static_assert(
				(MY_ALIGNMENT < OBJECT_ALIGNMENT)
						? OBJECT_SIZE + OBJECT_ALIGNMENT < MY_SIZE
						: true
				, "Check Object's SIZE parameter and sum of object size and it's"
				" alignment"
		);
	}

	void destroy() noexcept;

	template<typename T>
	static CallbackDestroy getCallbackDestroy() noexcept;

private:
	alignas(AlignedAsType) Types::uichar_t data[SIZE_IN_BYTES];
	CallbackDestroy callbackDestroy = nullptr;
};

}} // flame_ide::templates

namespace flame_ide
{namespace templates
{

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
Object<SIZE_IN_BYTES, AlignedAsType>::Object() noexcept
{}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
Object<SIZE_IN_BYTES, AlignedAsType>::Object(Me &&object) noexcept
{
	operator=(flame_ide::move(object));
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
Object<SIZE_IN_BYTES, AlignedAsType>::Object(T &&value) noexcept
{
	staticCheck<T>();
	operator=(flame_ide::move(value));
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
Object<SIZE_IN_BYTES, AlignedAsType>::Object(const T &value) noexcept
{
	staticCheck<T>();
	operator=(value);
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
Object<SIZE_IN_BYTES, AlignedAsType>::~Object() noexcept
{
	if (!callbackDestroy)
		return;
	callbackDestroy(data);
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
Object<SIZE_IN_BYTES, AlignedAsType> &
Object<SIZE_IN_BYTES, AlignedAsType>::operator=(Me &&object) noexcept
{
	destroy();

	flame_ide::copy(data, object.data);
	callbackDestroy = object.callbackDestroy;
	object.callbackDestroy = nullptr;

	return *this;
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
Object<SIZE_IN_BYTES, AlignedAsType> &
Object<SIZE_IN_BYTES, AlignedAsType>::operator=(T &&value) noexcept
{
	staticCheck<T>();
	destroy();

	flame_ide::placementNew(flame_ide::alignedPointer<T>(data), flame_ide::move(value));
	callbackDestroy = getCallbackDestroy<T>();

	return *this;
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
Object<SIZE_IN_BYTES, AlignedAsType> &
Object<SIZE_IN_BYTES, AlignedAsType>::operator=(const T &value) noexcept
{
	staticCheck<T>();
	destroy();

	flame_ide::placementNew(flame_ide::alignedPointer<T>(data), value);
	callbackDestroy = getCallbackDestroy<T>();

	return *this;
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
Object<SIZE_IN_BYTES, AlignedAsType>::operator bool() const noexcept
{
	return callbackDestroy;
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
T &Object<SIZE_IN_BYTES, AlignedAsType>::get() noexcept
{
	staticCheck<T>();
	return *flame_ide::alignedPointer<T>(data);
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
const T &Object<SIZE_IN_BYTES, AlignedAsType>::get() const noexcept
{
	staticCheck<T>();
	return *flame_ide::alignedPointer<T>(data);
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
flame_ide::AddMoveReferenceType<T> Object<SIZE_IN_BYTES, AlignedAsType>::move() noexcept
{
	callbackDestroy = nullptr;
	return flame_ide::move(get());
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
void Object<SIZE_IN_BYTES, AlignedAsType>::destroy() noexcept
{
	if (callbackDestroy)
	{
		callbackDestroy(data);
		callbackDestroy = nullptr;
	}
}

template<Types::size_t SIZE_IN_BYTES, typename AlignedAsType>
template<typename T>
typename Object<SIZE_IN_BYTES, AlignedAsType>::CallbackDestroy
Object<SIZE_IN_BYTES, AlignedAsType>::getCallbackDestroy() noexcept
{
	static auto destroy = [](void *value) -> void
	{
		alignedPointer<T>(value)->~T();
	};
	return destroy;
}


}} // flame_ide::templates

#endif // FLAMEIDE_TEMPLATES_OBJECT_HPP
