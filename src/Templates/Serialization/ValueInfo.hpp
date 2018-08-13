#ifndef TEMPLATES_SERIALIZATION_VALUE_INFO_HPP
#define TEMPLATES_SERIALIZATION_VALUE_INFO_HPP

#include <Common/Traits.hpp>
#include <Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

///
/// @brief The ValueInfo class
/// @tparam T
///
template<typename T>
class ValueInfo
{
public:
	using Iterator = Types::uichar_t*;
	using ConstIterator = const Types::uichar_t*;
	using ReverseIterator = templates::ReverseIterator<Iterator>;
	using ConstReverseIterator = templates::ConstReverseIterator<ConstIterator>;

	///
	/// @brief ValueInfo
	/// @param initValue
	/// @param initSize
	/// @param initOffset
	///
	ValueInfo(T initValue, Types::size_t initSize, Types::size_t initOffset);

	ValueInfo(const ValueInfo<T> &) = default;
	ValueInfo(ValueInfo<T> &&) = default;
	ValueInfo<T> &operator=(const ValueInfo<T> &) = default;
	ValueInfo<T> &operator=(ValueInfo<T> &&) = default;

	///
	/// @brief getValue
	/// @return
	///
	T &getValue();

	///
	/// @brief getValue
	/// @return
	///
	const T &getValue() const;

	///
	/// @brief getSize
	/// @return
	///
	Types::size_t &getSize();

	///
	/// @brief getSize
	/// @return
	///
	const Types::size_t &getSize() const;

	///
	/// @brief getOffset
	/// @return
	///
	Types::size_t &getOffset();

	///
	/// @brief getOffset
	/// @return
	///
	const Types::size_t &getOffset() const;

private:
	Types::size_t size; ///<
	Types::size_t offset; ///<
	T value; ///<
}; // class ValueInfo

}}

namespace flame_ide
{namespace templates
{

template<typename T>
ValueInfo<T>::ValueInfo(
		T initValue, Types::size_t initSize, Types::size_t initOffset)
		: size(initSize) , offset(initOffset) , value(initValue)
{}

template<typename T>
T &ValueInfo<T>::getValue()
{
	return value;
}

template<typename T>
const T &ValueInfo<T>::getValue() const
{
	return value;
}

template<typename T>
Types::size_t &ValueInfo<T>::getSize()
{
	return size;
}

template<typename T>
const Types::size_t &ValueInfo<T>::getSize() const
{
	return size;
}

template<typename T>
Types::size_t &ValueInfo<T>::getOffset()
{
	return offset;
}

template<typename T>
const Types::size_t &ValueInfo<T>::getOffset() const
{
	return offset;
}

}}

#endif // TEMPLATES_SERIALIZATION_VALUE_INFO_HPP
