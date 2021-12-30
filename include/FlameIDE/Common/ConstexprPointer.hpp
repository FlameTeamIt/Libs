#ifndef FLAMEIDE_COMMON_CONSTEXPR_POINTER_HPP
#define FLAMEIDE_COMMON_CONSTEXPR_POINTER_HPP

#include <FlameIDE/Common/Traits/Fuctional.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{

template<typename T>
union ConstexprPointer
{
	constexpr ConstexprPointer() noexcept;
	constexpr ConstexprPointer(const ConstexprPointer<T> &pointer) noexcept;
	constexpr ConstexprPointer(ConstexprPointer<T> &&pointer) noexcept;
	constexpr ConstexprPointer(Types::diff_t value) noexcept;

	ConstexprPointer(T *object) noexcept;

	constexpr ConstexprPointer<T> &operator=(const ConstexprPointer<T> &pointer) noexcept;
	constexpr ConstexprPointer<T> &operator=(ConstexprPointer<T> &&pointer) noexcept;

	constexpr operator bool() const noexcept;

	constexpr operator Types::diff_t() const noexcept;

	operator T *() noexcept;

	operator const T *() const noexcept;

	typename DefaultTraits<T>::Pointer object;
	Types::diff_t value;

	static_assert(
			sizeof(Types::diff_t) == sizeof(object)
			, "flame_ide::ConstexprPointer<T>: Invalid pointer size"
	);
};

} // namespace flame_ide

namespace flame_ide
{

template<typename T>
constexpr ConstexprPointer<T>::ConstexprPointer() noexcept : value{}
{}

template<typename T> constexpr
ConstexprPointer<T>::ConstexprPointer(const ConstexprPointer<T> &pointer) noexcept :
		value{ pointer.value }
{}

template<typename T> constexpr
ConstexprPointer<T>::ConstexprPointer(ConstexprPointer<T> &&pointer) noexcept :
		value{ pointer.value }
{
	pointer.value = decltype(value){};
}

template<typename T> constexpr
ConstexprPointer<T>::ConstexprPointer(Types::diff_t value) noexcept :
	value{ value }
{}

template<typename T>
ConstexprPointer<T>::ConstexprPointer(T *object) noexcept :
	object{ object }
{}

template<typename T> constexpr
ConstexprPointer<T> &
ConstexprPointer<T>::operator=(ConstexprPointer<T> &&pointer) noexcept
{
	value = pointer.value;
	pointer.value = decltype(value){};
	return *this;
}

template<typename T> constexpr
ConstexprPointer<T> &
ConstexprPointer<T>::operator=(const ConstexprPointer<T> &pointer) noexcept
{
	value = pointer.value;
	return *this;
}

template<typename T>
constexpr ConstexprPointer<T>::operator bool() const noexcept
{
	return value != decltype(value){};
}

template<typename T>
constexpr ConstexprPointer<T>::operator Types::diff_t() const noexcept
{
	return value;
}

template<typename T>
ConstexprPointer<T>::operator T *() noexcept
{
	return object;
}

template<typename T>
ConstexprPointer<T>::operator const T *() const noexcept
{
	return object;
}

} // namespace flame_ide

#endif // FLAMEIDE_COMMON_CONSTEXPR_POINTER_HPP
