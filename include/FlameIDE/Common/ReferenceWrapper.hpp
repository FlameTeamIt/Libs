#ifndef FLAMEIDE_COMMON_REFERENCE_WRAPPER_HPP
#define FLAMEIDE_COMMON_REFERENCE_WRAPPER_HPP

#include <FlameIDE/Common/Traits/ContainerTraits.hpp>

namespace flame_ide
{

///
/// @brief The ReferenceWrapper class
///
template<typename T, typename Traits = ContainerTraits<T>>
class ReferenceWrapper
{
public:
	using Pointer = typename Traits::Pointer;
	using Reference = typename Traits::Reference;

	///
	/// @brief ReferenceWrapper
	/// @param initValue
	///
	ReferenceWrapper(Pointer initValue) noexcept;

	///
	/// @brief ReferenceWrapper
	/// @param initValue
	///
	ReferenceWrapper(Reference initValue) noexcept;

	///
	/// @brief get
	/// @return
	///
	Reference get() const noexcept;

	///
	/// @brief operator bool
	///
	operator bool() const noexcept;

private:
	mutable Pointer value; ///<
};

///
/// @brief the ConstReferenceWrapper alias
///
template<typename T>
using ConstReferenceWrapper = ReferenceWrapper<const T, ConstTraits<T>>;

template<typename T>
ReferenceWrapper<T> makeReferenceWrapper(T &value) noexcept;

template<typename T>
ConstReferenceWrapper<T> makeConstReferenceWrapper(T &value) noexcept;

template<typename T>
T &getReference(T &value) noexcept;

template<typename T>
const T &getConstReference(const T &value);

} // namespace flame_ide

namespace flame_ide
{

// ReferenceWrapper

template<typename T, typename Traits>
ReferenceWrapper<T, Traits>::ReferenceWrapper(Pointer initValue) noexcept :
		value(initValue)
{}

template<typename T, typename Traits>
ReferenceWrapper<T, Traits>::ReferenceWrapper(Reference initValue) noexcept :
		value(&initValue)
{}

template<typename T, typename Traits>
typename ReferenceWrapper<T, Traits>::Reference
ReferenceWrapper<T, Traits>::get() const noexcept
{
	return *value;
}

template<typename T, typename Traits>
ReferenceWrapper<T, Traits>::operator bool() const noexcept
{
	return value != nullptr;
}

// functions

template<typename T>
ReferenceWrapper<T> makeReferenceWrapper(T &value) noexcept
{
	return ReferenceWrapper<T>{ value };
}

template<typename T>
ConstReferenceWrapper<T> makeConstReferenceWrapper(T &value) noexcept
{
	return ConstReferenceWrapper<T>{ value };
}

template<typename T>
T &getReference(T &value) noexcept
{
	return makeReferenceWrapper(value).get();
}

template<typename T>
const T &getConstReference(const T &value)
{
	return makeConstReferenceWrapper(value).get();
}

} // namespace flame_ide

#endif // FLAMEIDE_COMMON_REFERENCE_WRAPPER_HPP
