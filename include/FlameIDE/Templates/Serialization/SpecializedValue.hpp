#ifndef FLAMEIDE_TEMPLATES_SERIALIZATION_SPECIALIZED_VALUE_HPP
#define FLAMEIDE_TEMPLATES_SERIALIZATION_SPECIALIZED_VALUE_HPP

#include <FlameIDE/Templates/ByteOrder.hpp>
#include <FlameIDE/Templates/Serialization/ValueInfo.hpp>

namespace flame_ide
{namespace templates
{

///
/// @brief The SpecializedValue class
/// @tparam ORDER
/// @tparam T
///
template<ByteOrder ORDER, typename T>
class SpecializedValue: public ValueInfo<T>
{
public:
	///
	/// @brief begin
	/// @return
	///
	typename ValueInfo<T>::Iterator begin();

	///
	/// @brief begin
	/// @return
	///
	typename ValueInfo<T>::ConstIterator begin() const;

	///
	/// @brief rbegin
	/// @return
	///
	typename ValueInfo<T>::ReverseIterator rbegin();

	///
	/// @brief rbegin
	/// @return
	///
	typename ValueInfo<T>::ConstReverseIterator rbegin() const;

	///
	/// @brief end
	/// @return
	///
	typename ValueInfo<T>::Iterator end();

	///
	/// @brief end
	/// @return
	///
	typename ValueInfo<T>::ConstIterator end() const;

	///
	/// @brief rend
	/// @return
	///
	typename ValueInfo<T>::ReverseIterator rend();

	///
	/// @brief rend
	/// @return
	///
	typename ValueInfo<T>::ConstReverseIterator rend() const;
}; // class SpecializedValue

///
/// @brief The SpecializedValue class
/// @tparam T
///
template<typename T>
struct SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>: public ValueInfo<T>
{
	using Me = SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>;
	using Parent = ValueInfo<T>;

	///
	/// @brief SpecializedValue
	/// @param initValue
	/// @param initSize
	/// @param initOffset
	///
	SpecializedValue(T initValue, Types::size_t initSize, Types::size_t initOffset);

	SpecializedValue(const Me &) = default;
	SpecializedValue(Me &&) = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	///
	/// @brief operator SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER_ORDER, T>
	///
	operator SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>() const
	{
		return SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>{
				ToNeedOrder<
					ByteOrder::LITTLE_ENDIAN_ORDER
					, ByteOrder::BIG_ENDIAN_ORDER
				>::convert(getValue)
				, getSize()
				, getOffset()
		};
	}

	///
	/// @brief begin
	/// @return
	///
	typename ValueInfo<T>::Iterator begin();

	///
	/// @brief begin
	/// @return
	///
	typename ValueInfo<T>::ConstIterator begin() const;

	///
	/// @brief rbegin
	/// @return
	///
	typename ValueInfo<T>::ReverseIterator rbegin();

	///
	/// @brief rbegin
	/// @return
	///
	typename ValueInfo<T>::ConstReverseIterator rbegin() const;

	///
	/// @brief end
	/// @return
	///
	typename ValueInfo<T>::Iterator end();

	///
	/// @brief end
	/// @return
	///
	typename ValueInfo<T>::ConstIterator end() const;

	///
	/// @brief rend
	/// @return
	///
	typename ValueInfo<T>::ReverseIterator rend();

	///
	/// @brief rend
	/// @return
	///
	typename ValueInfo<T>::ConstReverseIterator rend() const;

	using ValueInfo<T>::getSize;
	using ValueInfo<T>::getOffset;
	using ValueInfo<T>::getValue;
}; // struct SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER_ORDER, T>

///
/// @brief The SpecializedValue class
/// @tparam T
///
template<typename T>
struct SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>: public ValueInfo<T>
{
	using Me = SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>;
	using Parent = ValueInfo<T>;

	///
	/// @brief SpecializedValue
	/// @param initValue
	/// @param initSize
	/// @param initOffset
	///
	SpecializedValue(T initValue, Types::size_t initSize, Types::size_t initOffset);

	SpecializedValue(const Me &) = default;
	SpecializedValue(Me &&) = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	///
	/// @brief operator SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER_ORDER, T>
	///
	operator SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>() const;

	///
	/// @brief begin
	/// @return
	///
	typename ValueInfo<T>::Iterator begin();

	///
	/// @brief begin
	/// @return
	///
	typename ValueInfo<T>::ConstIterator begin() const;

	///
	/// @brief rbegin
	/// @return
	///
	typename ValueInfo<T>::ReverseIterator rbegin();

	///
	/// @brief rbegin
	/// @return
	///
	typename ValueInfo<T>::ConstReverseIterator rbegin() const;

	///
	/// @brief end
	/// @return
	///
	typename ValueInfo<T>::Iterator end();

	///
	/// @brief end
	/// @return
	///
	typename ValueInfo<T>::ConstIterator end() const;

	///
	/// @brief rend
	/// @return
	///
	typename ValueInfo<T>::ReverseIterator rend();

	///
	/// @brief rend
	/// @return
	///
	typename ValueInfo<T>::ConstReverseIterator rend() const;

	using ValueInfo<T>::getValue;
	using ValueInfo<T>::getSize;
	using ValueInfo<T>::getOffset;
}; // struct SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER_ORDER, T>

///
/// @brief makeSpecializedValue
/// @param value
/// @param size
/// @param offset
/// @return
///
template<ByteOrder ORDER, typename T>
SpecializedValue<ORDER, T> makeSpecializedValue(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecializedValueEmpty
/// @param size
/// @param offset
/// @return
///
template<ByteOrder ORDER, typename T>
SpecializedValue<ORDER, T> makeSpecializedValueEmpty(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecializedValueLe
/// @param value
/// @param size
/// @param offset
/// @return
///
template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> makeSpecializedValueLe(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecializedValueEmptyLe
/// @param size
/// @param offset
/// @return
///
template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> makeSpecializedValueEmptyLe(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecializedValueBe
/// @param value
/// @param size
/// @param offset
/// @return
///
template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> makeSpecializedValueBe(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecializedValueEmptyBe
/// @param size
/// @param offset
/// @return
///
template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> makeSpecializedValueEmptyBe(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecifiedValueHost
/// @param value
/// @param size
/// @param offset
/// @return
///
template<typename T>
SpecializedValue<ByteOrder::HOST, T> makeSpecifiedValueHost(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// @brief makeSpecifiedValueEmptyHost
/// @param size
/// @param offset
/// @return
///
template<typename T>
SpecializedValue<ByteOrder::HOST, T> makeSpecifiedValueEmptyHost(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

}}


namespace flame_ide
{namespace templates
{

template<typename T>
using SpecializedValueLe = SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>;

template<typename T>
using SpecializedValueBe = SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>;

// ByteOrder::BIG_ENDIAN_ORDER_ORDER

template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::SpecializedValue(
		T initValue, Types::size_t initSize, Types::size_t initOffset)
	: Parent(initValue, initSize, initOffset)
{}

template<typename T>
typename ValueInfo<T>::Iterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::begin()
{
	return makeByteRange(getValue()).begin() + getOffset();
}

template<typename T>
typename ValueInfo<T>::ConstIterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::begin() const
{
	return makeConstByteRange(getValue()).begin() + getOffset();
}

template<typename T>
typename ValueInfo<T>::ReverseIterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::rbegin()
{
	return end() - 1;
}

template<typename T>
typename ValueInfo<T>::ConstReverseIterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::rbegin() const
{
	return end() - 1;
}

template<typename T>
typename ValueInfo<T>::Iterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::end()
{
	return begin() + getSize();
}

template<typename T>
typename ValueInfo<T>::ConstIterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::end() const
{
	return begin() + getSize();
}

template<typename T>
typename ValueInfo<T>::ReverseIterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::rend()
{
	return begin() - 1;
}
template<typename T>
typename ValueInfo<T>::ConstReverseIterator
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::rend() const
{
	return begin() - 1;
}

// ByteOrder::LITTLE_ENDIAN_ORDER_ORDER

template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::SpecializedValue(
		T initValue, Types::size_t initSize, Types::size_t initOffset)
		: Parent(initValue, initSize, initOffset)
{}

template<typename T>
typename ValueInfo<T>::Iterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::begin()
{
	return  makeByteRange(getValue()).begin()
			+ sizeof(getValue()) - getSize() - getOffset();
}

template<typename T>
typename ValueInfo<T>::ConstIterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::begin() const
{
	return makeConstByteRange(getValue()).begin()
			+ sizeof(getValue()) - getSize() - getOffset();
}

template<typename T>
typename ValueInfo<T>::ReverseIterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::rbegin()
{
	return end() - 1;
}

template<typename T>
typename ValueInfo<T>::ConstReverseIterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::rbegin() const
{
	return end() - 1;
}

template<typename T>
typename ValueInfo<T>::Iterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::end()
{
	return begin() + getSize();
}

template<typename T>
typename ValueInfo<T>::ConstIterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::end() const
{
	return begin() + getSize();
}

template<typename T>
typename ValueInfo<T>::ReverseIterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::rend()
{
	return begin() - 1;
}

template<typename T>
typename ValueInfo<T>::ConstReverseIterator
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::rend() const
{
	return begin() - 1;
}

template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>::
operator SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>() const
{
	return SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>{
		ToNeedOrder<
			ByteOrder::BIG_ENDIAN_ORDER
			, ByteOrder::LITTLE_ENDIAN_ORDER
		>::convert(getValue)
		, getSize()
		, getOffset()
	};
}

// functions

template<ByteOrder ORDER, typename T>
SpecializedValue<ORDER, T> makeSpecializedValue(
		T value
		, Types::size_t size
		, Types::size_t offset)
{
	return SpecializedValue<ORDER, T>{
		ToNeedOrder<ByteOrder::HOST, ORDER>()(value)
		, size, offset
	};
}

template<ByteOrder ORDER, typename T>
SpecializedValue<ORDER, T> makeSpecializedValueEmpty(
		Types::size_t size
		, Types::size_t offset)
{
	return SpecializedValue<ORDER, T>{
		T{}, size, offset
	};
}


template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> makeSpecializedValueLe(T value
		, Types::size_t size, Types::size_t offset)
{
	return makeSpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>(
			value, size, offset
	);
}

template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> makeSpecializedValueEmptyLe(
		Types::size_t size, Types::size_t offset)
{
	return makeSpecializedValueEmpty<ByteOrder::LITTLE_ENDIAN_ORDER, T>(size, offset);
}

template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> makeSpecializedValueBe(T value
		, Types::size_t size, Types::size_t offset)
{
	return makeSpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>(
			value, size, offset
	);
}

template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> makeSpecializedValueEmptyBe(
		Types::size_t size, Types::size_t offset)
{
	return makeSpecializedValueEmpty<ByteOrder::BIG_ENDIAN_ORDER, T>(size, offset);
}

template<typename T>
SpecializedValue<ByteOrder::HOST, T> makeSpecifiedValueEmptyHost(
		Types::size_t size, Types::size_t offset)
{
	return SpecializedValue<ByteOrder::HOST, T>{ T{}, size, offset };
}

}}

#endif // FLAMEIDE_TEMPLATES_SERIALIZATION_SPECIALIZED_VALUE_HPP
