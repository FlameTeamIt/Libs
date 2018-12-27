#ifndef FLAMEIDE_TEMPLATES_SERIALIZATION_SERIALIZER_HPP
#define FLAMEIDE_TEMPLATES_SERIALIZATION_SERIALIZER_HPP

#include <FlameIDE/Templates/View.hpp>
#include <FlameIDE/Templates/Serialization/SpecializedValue.hpp>

namespace flame_ide
{namespace templates
{

///
/// @brief The Serializer class
/// @tparam ORDER
/// @tparam IS_VOLATILE
///
template<ByteOrder ORDER, bool IS_VOLATILE>
class Serializer
{
public:
	using InputDataBlock = typename SerializationTraits<IS_VOLATILE>::InputDataBlock;
	using InternalDataBlock = typename SerializationTraits<IS_VOLATILE>::InternalDataBlock;

	///
	/// @brief Serializer
	/// @param initData
	/// @param initOffset
	///
	Serializer(InputDataBlock initData = nullptr, Types::size_t initOffset = 0);

	///
	/// @brief operator ()
	/// @param value
	/// @return
	///
	template<typename T>
	Types::size_t operator()(T value);

	///
	/// @brief operator ()
	/// @param value
	/// @return
	///
	template<ByteOrder OTHER_ORDER, typename T>
	Types::size_t operator()(const SpecializedValue<OTHER_ORDER, T> &value);

	///
	/// @brief operator ()
	/// @param value
	/// @return
	///
	template<typename T>
	Types::size_t operator()(const SpecializedValue<ORDER, T> &value);

	template<typename T>
	static T toOrder(T value);

private:

	///
	/// @brief makeByteRange
	/// @param value
	/// @return
	///
	template<typename T>
	static Range<const Types::uichar_t *> makeByteRange(const T &value);

	///
	/// @brief castToByteArray
	/// @param value
	/// @return
	///
	template<typename T>
	static const Types::uichar_t *castToByteArray(const T &value);

	InternalDataBlock data;
	Types::size_t offset;
};

}}

namespace flame_ide
{namespace templates
{

using SerializerLe = Serializer<ByteOrder::LITTLE_ENDIAN_ORDER, false>;
using SerializerBe = Serializer<ByteOrder::BIG_ENDIAN_ORDER, false>;

template<ByteOrder ORDER, bool IS_VOLATILE>
Serializer<ORDER, IS_VOLATILE>::Serializer(InputDataBlock initData, Types::size_t initOffset)
		: data(static_cast<InternalDataBlock>(initData))
		, offset(initOffset)
{}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Types::size_t Serializer<ORDER, IS_VOLATILE>::operator()(T value)
{
	auto serializeValue = toOrder(value);
	auto range = makeByteRange(serializeValue);
	auto newOffset = copy(range, data + offset);
	offset += newOffset;
	return newOffset;
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<ByteOrder OTHER_ORDER, typename T>
Types::size_t Serializer<ORDER, IS_VOLATILE>::operator()(const SpecializedValue<OTHER_ORDER, T> &value)
{
	auto range = makeRange(value.rbegin(), value.rend());
	auto newOffset = copy(range, data + offset);
	offset += newOffset;
	return newOffset;
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Types::size_t Serializer<ORDER, IS_VOLATILE>::operator()(const SpecializedValue<ORDER, T> &value)
{
	auto newOffset = copy(value, data + offset);
	offset += newOffset;
	return newOffset;
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
T Serializer<ORDER, IS_VOLATILE>::toOrder(T value)
{
	return ToNeedOrder<ByteOrder::HOST_ORDER, ORDER>()(value);
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
Range<const Types::uichar_t *> Serializer<ORDER, IS_VOLATILE>::makeByteRange(const T &value)
{
	auto begin = castToByteArray(value);
	auto end = begin + sizeof(value);
	return makeRange(begin, end);
}

template<ByteOrder ORDER, bool IS_VOLATILE>
template<typename T>
const Types::uichar_t *Serializer<ORDER, IS_VOLATILE>::castToByteArray(const T &value)
{
	const void *pointer = &value;
	return static_cast<const uint8_t*>(pointer);
}

}}

#endif // FLAMEIDE_TEMPLATES_SERIALIZATION_SERIALIZER_HPP
