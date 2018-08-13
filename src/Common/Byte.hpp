#ifndef COMMON_BYTE_HPP
#define COMMON_BYTE_HPP

#include <Common/PrimitiveTypes.hpp>
#include <Templates/Traits.hpp>

namespace flame_ide
{

enum class byte_t : uichar_t
{
};

template<typename IntegerType>
constexpr byte_t operator<<(byte_t byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t &operator<<=(byte_t &byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t operator>>(byte_t byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t &operator>>=(byte_t &byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t operator|(byte_t byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t &operator|=(byte_t &byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t operator&(byte_t byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t &operator&=(byte_t &byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t operator^(byte_t byteValue, IntegerType shiftValue);

template<typename IntegerType>
constexpr byte_t &operator^=(byte_t &byteValue, IntegerType shiftValue);

}

namespace flame_ide
{

template<typename IntegerType>
constexpr byte_t operator<<(byte_t byteValue, IntegerType shiftValue)
{
	using uchar_t = uichar_t;
	static_assert(templates::IsIntegralType<IntegerType>::VALUE, "Type is not integral.");
	return static_cast<byte_t>(
			static_cast<uchar_t>(byteValue) << shiftValue
	);
}

template<typename IntegerType>
constexpr byte_t &operator<<=(byte_t &byteValue, IntegerType shiftValue)
{
	return byteValue = byteValue << shiftValue;
}

template<typename IntegerType>
constexpr byte_t operator>>(byte_t byteValue, IntegerType shiftValue)
{
	using uchar_t = templates::Types::uichar_t;
	static_assert (templates::IsIntegralType<IntegerType>::VALUE, "Type is not integral.");
	return static_cast<byte_t>(
			static_cast<uchar_t>(byteValue) >> shiftValue
	);
}

template<typename IntegerType>
constexpr byte_t &operator>>=(byte_t &byteValue, IntegerType shiftValue)
{
	return byteValue = byteValue >> shiftValue;
}

template<typename IntegerType>
constexpr byte_t operator|(byte_t byteValue, IntegerType shiftValue)
{
	using uchar_t = templates::Types::uichar_t;
	static_assert(templates::IsIntegralType<IntegerType>::VALUE, "Type is not integral.");
	return static_cast<byte_t>(
			static_cast<uchar_t>(byteValue) | shiftValue
	);
}

template<typename IntegerType>
constexpr byte_t &operator|=(byte_t &byteValue, IntegerType shiftValue)
{
	return byteValue = byteValue | shiftValue;
}

template<typename IntegerType>
constexpr byte_t operator&(byte_t byteValue, IntegerType shiftValue)
{
	using uchar_t = templates::Types::uichar_t;
	static_assert(templates::IsIntegralType<IntegerType>::VALUE, "Type is not integral.");
	return static_cast<byte_t>(
			static_cast<uchar_t>(byteValue) & shiftValue
	);
}

template<typename IntegerType>
constexpr byte_t &operator&=(byte_t &byteValue, IntegerType shiftValue)
{
	return byteValue = byteValue & shiftValue;
}

template<typename IntegerType>
constexpr byte_t operator^(byte_t byteValue, IntegerType shiftValue)
{
	using uchar_t = templates::Types::uichar_t;
	static_assert(templates::IsIntegralType<IntegerType>::VALUE, "Type is not integral.");
	return static_cast<byte_t>(
			static_cast<uchar_t>(byteValue) ^ shiftValue
	);
}

template<typename IntegerType>
constexpr byte_t &operator^=(byte_t &byteValue, IntegerType shiftValue)
{
	return byteValue = byteValue ^ shiftValue;
}

constexpr byte_t operator~(byte_t byteValue)
{
	using uchar_t = templates::Types::uichar_t;
	return byte_t(~static_cast<uchar_t>(byteValue));
}

template<typename IntegerType>
constexpr IntegerType toInteger(byte_t byteValue)
{
	static_assert(templates::IsIntegralType<IntegerType>::VALUE, "Type is not integral.");
	return static_cast<IntegerType>(byteValue);
}

}

#endif // COMMON_BYTE_HPP
