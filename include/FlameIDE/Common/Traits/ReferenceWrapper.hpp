#ifndef FLAMEIDE_COMMON_REFERENCE_WRAPPER_HPP
#define FLAMEIDE_COMMON_REFERENCE_WRAPPER_HPP

namespace flame_ide
{

///
/// @brief The ReferenceWrapper class
///
template<typename T>
class ReferenceWrapper
{
public:
	inline ReferenceWrapper(T &initValue) noexcept : value(&initValue)
	{}

	T &get() const
	{
		return *value;
	}

private:
	mutable T *value;
};

///
/// @brief The ReferenceWrapper<const T> class
///
template<typename T>
class ReferenceWrapper<const T>
{
public:
	inline ReferenceWrapper(const T &initValue) noexcept : value(&initValue)
	{}

	const T &get() const
	{
		return *value;
	}

private:
	mutable const T *value;
};

///
/// @brief the ConstReferenceWrapper alias
///
template<typename T>
using ConstReferenceWrapper = ReferenceWrapper<const T>;

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
inline T &getReference(T &value) noexcept
{
	return value;
}

template<typename T>
const T &getConstReference(const T &value)
{
	return value;
}

} // namespace flame_ide

#endif // FLAMEIDE_COMMON_REFERENCE_WRAPPER_HPP
