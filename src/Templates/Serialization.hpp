#ifndef TEMPLATE_SERIALIZATION_HPP
#define TEMPLATE_SERIALIZATION_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>
#include <Templates/ByteOrder.hpp>
#include <Templates/View.hpp>

#include <Templates/Iterator.hpp>

namespace flame_ide
{namespace templates
{

// TODO: вынести реалиацию за пределы классов.


///
/// @brief The ValueInfo class
/// @tparam T
///
template<typename T>
class ValueInfo
{
public:
	using Iterator = Types::uchar_t*;
	using ConstIterator = const Types::uchar_t*;
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
struct SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> : public ValueInfo<T>
{
	using Me = SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>;
	using Parent = ValueInfo<T>;

	///
	/// \brief SpecializedValue
	/// \param initValue
	/// \param initSize
	/// \param initOffset
	///
	SpecializedValue(T initValue, Types::size_t initSize, Types::size_t initOffset);

	SpecializedValue(const Me &) = default;
	SpecializedValue(Me &&) = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	///
	/// \brief operator SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>
	///
	operator SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>() const;

	///
	/// \brief begin
	/// \return
	///
	typename ValueInfo<T>::Iterator begin();

	///
	/// \brief begin
	/// \return
	///
	typename ValueInfo<T>::ConstIterator begin() const;

	///
	/// \brief rbegin
	/// \return
	///
	typename ValueInfo<T>::ReverseIterator rbegin();

	///
	/// \brief rbegin
	/// \return
	///
	typename ValueInfo<T>::ConstReverseIterator rbegin() const;

	///
	/// \brief end
	/// \return
	///
	typename ValueInfo<T>::Iterator end();

	///
	/// \brief end
	/// \return
	///
	typename ValueInfo<T>::ConstIterator end() const;

	///
	/// \brief rend
	/// \return
	///
	typename ValueInfo<T>::ReverseIterator rend();

	///
	/// \brief rend
	/// \return
	///
	typename ValueInfo<T>::ConstReverseIterator rend() const;

	using ValueInfo<T>::getSize;
	using ValueInfo<T>::getOffset;
	using ValueInfo<T>::getValue;
}; // struct SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>

///
/// @brief The SpecializedValue class
/// @tparam T
///
template<typename T>
struct SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> : public ValueInfo<T>
{
	using Me = SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>;
	using Parent = ValueInfo<T>;

	///
	/// \brief SpecializedValue
	/// \param initValue
	/// \param initSize
	/// \param initOffset
	///
	SpecializedValue(T initValue, Types::size_t initSize, Types::size_t initOffset);

	SpecializedValue(const Me &) = default;
	SpecializedValue(Me &&) = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	///
	/// \brief operator SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>
	///
	operator SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>() const;

	///
	/// \brief begin
	/// \return
	///
	typename ValueInfo<T>::Iterator begin();

	///
	/// \brief begin
	/// \return
	///
	typename ValueInfo<T>::ConstIterator begin() const;

	///
	/// \brief rbegin
	/// \return
	///
	typename ValueInfo<T>::ReverseIterator rbegin();

	///
	/// \brief rbegin
	/// \return
	///
	typename ValueInfo<T>::ConstReverseIterator rbegin() const;

	///
	/// \brief end
	/// \return
	///
	typename ValueInfo<T>::Iterator end();

	///
	/// \brief end
	/// \return
	///
	typename ValueInfo<T>::ConstIterator end() const;

	///
	/// \brief rend
	/// \return
	///
	typename ValueInfo<T>::ReverseIterator rend();

	///
	/// \brief rend
	/// \return
	///
	typename ValueInfo<T>::ConstReverseIterator rend() const;

	using ValueInfo<T>::getValue;
	using ValueInfo<T>::getSize;
	using ValueInfo<T>::getOffset;
}; // struct SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>

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
/// \brief makeSpecializedValueEmpty
/// \param size
/// \param offset
/// \return
///
template<ByteOrder ORDER, typename T>
SpecializedValue<ORDER, T> makeSpecializedValueEmpty(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief makeSpecializedValueLe
/// \param value
/// \param size
/// \param offset
/// \return
///
template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> makeSpecializedValueLe(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief makeSpecializedValueEmptyLe
/// \param size
/// \param offset
/// \return
///
template<typename T>
SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T> makeSpecializedValueEmptyLe(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief makeSpecializedValueBe
/// \param value
/// \param size
/// \param offset
/// \return
///
template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> makeSpecializedValueBe(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief makeSpecializedValueEmptyBe
/// \param size
/// \param offset
/// \return
///
template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T> makeSpecializedValueEmptyBe(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief makeSpecifiedValueHost
/// \param value
/// \param size
/// \param offset
/// \return
///
template<typename T>
SpecializedValue<ByteOrder::HOST_ORDER, T> makeSpecifiedValueHost(
		T value
		, Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief makeSpecifiedValueEmptyHost
/// \param size
/// \param offset
/// \return
///
template<typename T>
SpecializedValue<ByteOrder::HOST_ORDER, T> makeSpecifiedValueEmptyHost(
		Types::size_t size = sizeof(T)
		, Types::size_t offset = 0);

///
/// \brief The Serializer class
///
template<ByteOrder ORDER>
class Serializer
{
public:

	///
	/// \brief Serializer
	/// \param initData
	/// \param initOffset
	///
	Serializer(void* initData = nullptr, Types::size_t initOffset = 0);

	///
	/// \brief operator ()
	/// \param value
	/// \return
	///
	template<typename T>
	Types::size_t operator()(T value);

	///
	/// \brief operator ()
	/// \param value
	/// \return
	///
	template<ByteOrder OTHER_ORDER, typename T>
	Types::size_t operator()(const SpecializedValue<OTHER_ORDER, T> &value);

	///
	/// \brief operator ()
	/// \param value
	/// \return
	///
	template<typename T>
	Types::size_t operator()(const SpecializedValue<ORDER, T> &value);

	template<typename T>
	static T toOrder(T value);

private:

	///
	/// \brief makeByteRange
	/// \param value
	/// \return
	///
	template<typename T>
	static Range<const Types::uchar_t *> makeByteRange(const T &value);

	///
	/// \brief castToByteArray
	/// \param value
	/// \return
	///
	template<typename T>
	static const Types::uchar_t *castToByteArray(const T &value);

	Types::uchar_t* data;
	Types::size_t offset;
};

template<ByteOrder ORDER>
class Deserializer
{
public:

	///
	/// \brief Deserializer
	/// \param initData
	/// \param initOffset
	///
	Deserializer(const void *initData = nullptr, Types::size_t initOffset = 0);

	///
	/// \brief operator ()
	/// \param value
	/// \return
	///
	template<typename T>
	Types::size_t operator()(T &value);

	///
	/// \brief operator ()
	/// \param value
	/// \return
	///
	template<typename T>
	Types::size_t operator()(SpecializedValue<ORDER, T> &value);

	///
	/// \brief operator ()
	/// \param value
	/// \return
	///
	template<ByteOrder OTHER_ORDER, typename T>
	Types::size_t operator()(SpecializedValue<OTHER_ORDER, T> &value);

	///
	/// \brief toOrder
	/// \param value
	/// \return
	///
	template<typename T>
	static T toOrder(T value);

private:

	///
	/// \brief makeByteRange
	/// \param value
	/// \return
	///
	template<typename T>
	static Range<Types::uchar_t *> makeByteRange(T &value);

	///
	/// \brief castToByteArray
	/// \param value
	/// \return
	///
	template<typename T>
	static Types::uchar_t *castToByteArray(T &value);

	const Types::uchar_t* data;
	Types::size_t offset;
};

}}

namespace flame_ide
{namespace templates
{

using SerializerLe = Serializer<ByteOrder::LITTLE_ENDIAN_ORDER>;
using SerializerBe = Serializer<ByteOrder::BIG_ENDIAN_ORDER>;

using DeserializerLe = Deserializer<ByteOrder::LITTLE_ENDIAN_ORDER>;
using DeserializerBe = Deserializer<ByteOrder::BIG_ENDIAN_ORDER>;

template<typename T>
using SpecializedValueLe = SpecializedValue<ByteOrder::LITTLE_ENDIAN_ORDER, T>;

template<typename T>
using SpecializedValueBe = SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>;

// ValueInfo

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

// SpecializedValue

// ByteOrder::BIG_ENDIAN_ORDER

template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::SpecializedValue(
		T initValue, Types::size_t initSize, Types::size_t initOffset)
	: Parent(initValue, initSize, initOffset)
{}

template<typename T>
SpecializedValue<ByteOrder::BIG_ENDIAN_ORDER, T>::
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

// ByteOrder::LITTLE_ENDIAN_ORDER

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
		ToNeedOrder<ByteOrder::HOST_ORDER, ORDER>()(value)
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
SpecializedValue<ByteOrder::HOST_ORDER, T> makeSpecifiedValueEmptyHost(
		Types::size_t size, Types::size_t offset)
{
	return SpecializedValue<ByteOrder::HOST_ORDER, T>{ T{}, size, offset };
}

// Serializer

template<ByteOrder ORDER>
Serializer<ORDER>::Serializer(void* initData, Types::size_t initOffset)
		: data(static_cast<Types::uchar_t *>(initData))
		, offset(initOffset)
{}

template<ByteOrder ORDER>
template<typename T>
Types::size_t Serializer<ORDER>::operator()(T value)
{
	auto serializeValue = toOrder(value);
	auto range = makeByteRange(serializeValue);
	auto newOffset = copy(range, data + offset);
	offset += newOffset;
	return newOffset;
}

template<ByteOrder ORDER>
template<ByteOrder OTHER_ORDER, typename T>
Types::size_t Serializer<ORDER>::operator()(const SpecializedValue<OTHER_ORDER, T> &value)
{
	SpecializedValue<ORDER, T> serializeValue{
		toOrder(value.getValue()), value.getSize(), value.getOffset()
	};
	auto newOffset = copy(serializeValue, data + offset);
	offset += newOffset;
	return newOffset;
}

template<ByteOrder ORDER>
template<typename T>
Types::size_t Serializer<ORDER>::operator()(const SpecializedValue<ORDER, T> &value)
{
	auto newOffset = copy(value, data + offset);
	offset += newOffset;
	return newOffset;
}

template<ByteOrder ORDER>
template<typename T>
T Serializer<ORDER>::toOrder(T value)
{
	return ToNeedOrder<ByteOrder::HOST_ORDER, ORDER>()(value);
}

template<ByteOrder ORDER>
template<typename T>
Range<const Types::uchar_t *> Serializer<ORDER>::makeByteRange(const T &value)
{
	auto begin = castToByteArray(value);
	auto end = begin + sizeof(value);
	return makeRange(begin, end);
}

template<ByteOrder ORDER>
template<typename T>
const Types::uchar_t *Serializer<ORDER>::castToByteArray(const T &value)
{
	const void *pointer = &value;
	return static_cast<const uint8_t*>(pointer);
}

// Deserializer

template<ByteOrder ORDER>
Deserializer<ORDER>::Deserializer(const void *initData, Types::size_t initOffset)
	: data(static_cast<const Types::uchar_t*>(initData))
	, offset(initOffset)
{}

template<ByteOrder ORDER>
template<typename T>
Types::size_t Deserializer<ORDER>::operator()(T &value)
{
	T deserializeValue;
	auto range = makeByteRange(deserializeValue);
	auto bufferRange = makeRange(data + offset, data + offset + sizeof(value));
	auto newOffset = copy(bufferRange, range.begin());
	offset += newOffset;
	value = toOrder(deserializeValue);
	return newOffset;
}

template<ByteOrder ORDER>
template<ByteOrder OTHER_ORDER, typename T>
Types::size_t Deserializer<ORDER>::operator()(SpecializedValue<OTHER_ORDER, T> &value)
{
	SpecializedValue<ORDER, T> deserializedValue { T(), value.getSize(), value.getOffset() };
	auto range = makeRange(deserializedValue.begin(), deserializedValue.end());
	auto bufferRange = makeRange(data + offset, data + offset + value.getSize());

	auto newOffset = copy(bufferRange, range.begin());
	offset += newOffset;
	value = SpecializedValue<OTHER_ORDER, T> {
		toOrder(deserializedValue.getValue()) , deserializedValue.getSize()
		, deserializedValue.getOffset()
	};

	return newOffset;
}

template<ByteOrder ORDER>
template<typename T>
Types::size_t Deserializer<ORDER>::operator()(SpecializedValue<ORDER, T> &value)
{
	SpecializedValue<ORDER, T> deserializedValue { T(), value.getSize(), value.getOffset() };
	auto range = makeRange(deserializedValue.begin(), deserializedValue.end());
	auto bufferRange = makeRange(data + offset, data + offset + value.getSize());

	auto newOffset = copy(bufferRange, range.begin());
	offset += newOffset;
	value = SpecializedValue<ORDER, T> {
			deserializedValue.getValue() , deserializedValue.getSize()
			, deserializedValue.getOffset()
	};

	return newOffset;
}

template<ByteOrder ORDER>
template<typename T>
T Deserializer<ORDER>::toOrder(T value)
{
	return ToNeedOrder<ORDER, ByteOrder::HOST_ORDER>()(value);
}

template<ByteOrder ORDER>
template<typename T>
Range<Types::uchar_t *> Deserializer<ORDER>::makeByteRange(T &value)
{
	auto begin = castToByteArray(value);
	auto end = begin + sizeof(value);
	return makeRange(begin, end);
}

template<ByteOrder ORDER>
template<typename T>
Types::uchar_t *Deserializer<ORDER>::castToByteArray(T &value)
{
	void *pointer = &value;
	return static_cast<uint8_t*>(pointer);
}

}}

#endif // TEMPLATE_SERIALIZATION_HPP
