#ifndef FLAMEIDE_TEMPLATES_SERIALIZATION_DESERIALIZER_HPP
#define FLAMEIDE_TEMPLATES_SERIALIZATION_DESERIALIZER_HPP

#include <FlameIDE/Templates/View.hpp>
#include <FlameIDE/Templates/Serialization/SpecializedValue.hpp>

namespace flame_ide
{namespace templates
{

///
/// @brief The Deserializer class
/// @tparam ORDER
/// @tparam IS_VOLATILE
///
template<ByteOrder ORDER, bool IS_VOLATILE>
class Deserializer
{
public:
	using ConstInputDataBlock = typename SerializationTraits<IS_VOLATILE>::ConstInputDataBlock;
	using ConstInternalDataBlock = typename SerializationTraits<IS_VOLATILE>::ConstInternalDataBlock;

	///
	/// @brief Deserializer
	/// @param initData
	/// @param initOffset
	///
	Deserializer(ConstInputDataBlock initData = nullptr, Types::size_t initOffset = 0);

	///
	/// @brief operator ()
	/// @param value
	/// @return
	///
	template<typename T>
	Types::size_t operator()(T &value);

	///
	/// @brief operator ()
	/// @param value
	/// @return
	///
	template<typename T>
	Types::size_t operator()(SpecializedValue<ORDER, T> &value);

	///
	/// @brief operator ()
	/// @param value
	/// @return
	///
	template<ByteOrder OTHER_ORDER, typename T>
	Types::size_t operator()(SpecializedValue<OTHER_ORDER, T> &value);

	///
	/// @brief toOrder
	/// @param value
	/// @return
	///
	template<typename T>
	static T toOrder(T value);

private:

	///
	/// @brief makeByteRange
	/// @param value
	/// @return
	///
	template<typename T>
	static Range<Types::uichar_t *> makeByteRange(T &value);

	///
	/// @brief castToByteArray
	/// @param value
	/// @return
	///
	template<typename T>
	static Types::uichar_t *castToByteArray(T &value);

	ConstInternalDataBlock data;
	Types::size_t offset;
};

}}

namespace flame_ide
{namespace templates
{

using DeserializerLe = Deserializer<ByteOrder::LITTLE_ENDIAN_ORDER, false>;
using DeserializerBe = Deserializer<ByteOrder::BIG_ENDIAN_ORDER, false>;

template<ByteOrder ORDER, bool IS_VOLATILE>
Deserializer<ORDER, IS_VOLATILE>::Deserializer(ConstInputDataBlock initData, Types::size_t initOffset)
	: data(static_cast<ConstInternalDataBlock>(initData))
	, offset(initOffset)
{}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Types::size_t Deserializer<ORDER, IS_VOLATILE>::operator()(T &value)
{
	T DeserializeValue;
	auto range = makeByteRange(DeserializeValue);
	auto bufferRange = makeRange(data + offset, data + offset + sizeof(value));
	auto newOffset = copy(bufferRange, range.begin());
	offset += newOffset;
	value = toOrder(DeserializeValue);
	return newOffset;
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<ByteOrder OTHER_ORDER, typename T>
Types::size_t Deserializer<ORDER, IS_VOLATILE>::operator()(SpecializedValue<OTHER_ORDER, T> &value)
{
	auto range = makeRange(value.rbegin(), value.rend());
	auto bufferRange = makeRange(data + offset, data + offset + value.getSize());

	auto newOffset = copy(bufferRange, range.begin());
	offset += newOffset;

	return newOffset;
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Types::size_t Deserializer<ORDER, IS_VOLATILE>::operator()(SpecializedValue<ORDER, T> &value)
{
	auto range = makeRange(value.begin(), value.end());
	auto bufferRange = makeRange(data + offset, data + offset + value.getSize());

	auto newOffset = copy(bufferRange, range.begin());
	offset += newOffset;

	return newOffset;
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
T Deserializer<ORDER, IS_VOLATILE>::toOrder(T value)
{
	return ToNeedOrder<ORDER, ByteOrder::HOST_ORDER>()(value);
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Range<Types::uichar_t *> Deserializer<ORDER, IS_VOLATILE>::makeByteRange(T &value)
{
	auto begin = castToByteArray(value);
	auto end = begin + sizeof(value);
	return makeRange(begin, end);
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Types::uichar_t *Deserializer<ORDER, IS_VOLATILE>::castToByteArray(T &value)
{
	void *pointer = &value;
	return static_cast<uint8_t*>(pointer);
}

}}

#endif // FLAMEIDE_TEMPLATES_SERIALIZATION_DESERIALIZER_HPP
