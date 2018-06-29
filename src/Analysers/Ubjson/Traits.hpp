#ifndef ANALYSERS_UBJSON_TRAITS_HPP
#define ANALYSERS_UBJSON_TRAITS_HPP

#include <Templates/Traits.hpp>
#include <Templates/Variant.hpp>

#include <Analysers/Ubjson/Types.hpp>

namespace flame_ide
{namespace ubjson
{

struct NullValue
{};

struct Noop
{};

struct True
{
	constexpr operator bool()
	{
		return true;
	}
};

struct False
{
	constexpr operator bool()
	{
		return false;
	}
};

template<EnumeratedType BJSON_TYPE>
struct ValueTraits
{
	static constexpr Type VALUE_TYPE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = templates::FalseType::VALUE;
	using ValueType = decltype(nullptr);
};

template<>
struct ValueTraits<EnumeratedType::NULLVAL>
{
	static constexpr Type VALUE_TYPE = Type::NULLVAL;
	static constexpr bool DATA_PAYLOAD = templates::FalseType::VALUE;
	using ValueType = NullValue;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::NOOP>
{
	static constexpr Type VALUE_TYPE = Type::NOOP;
	static constexpr bool DATA_PAYLOAD = templates::FalseType::VALUE;
	using ValueType = Noop;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::TRUE>
{
	static constexpr Type VALUE_TYPE = Type::TRUE;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = True;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::FALSE>
{
	static constexpr Type VALUE_TYPE = Type::FALSE;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = False;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::INT8>
{
	static constexpr Type VALUE_TYPE = Type::INT8;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = ichar_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::UINT8>
{
	static constexpr Type VALUE_TYPE = Type::UINT8;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = uichar_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::INT16>
{
	static constexpr Type VALUE_TYPE = Type::INT16;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = short_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::INT32>
{
	static constexpr Type VALUE_TYPE = Type::INT32;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = int_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::INT64>
{
	static constexpr Type VALUE_TYPE = Type::INT64;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::FLOAT32>
{
	static constexpr Type VALUE_TYPE = Type::FLOAT32;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = float_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::FLOAT64>
{
	static constexpr Type VALUE_TYPE = Type::FLOAT64;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = double_t;
	ValueType value;
};

template<>
struct ValueTraits<EnumeratedType::CHAR>
{
	static constexpr Type VALUE_TYPE = Type::CHAR;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = char_t;
	ValueType value;
};

}}

#endif // ANALYSERS_UBJSON_TRAITS_HPP
