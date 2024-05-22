#ifndef FLAMEIDE_UBJSON_TRAITS_HPP
#define FLAMEIDE_UBJSON_TRAITS_HPP

#include <FlameIDE/Common/Traits.hpp>

#include <FlameIDE/Templates/Variant.hpp>

#include <FlameIDE/Ubjson/Types.hpp>

namespace flame_ide
{namespace ubjson
{

struct NullValue;
struct Noop;
struct True;
struct False;

class HugeNumber;

class String;
class Array;
class Object;

class Value;

template<EnumeratedValueType UBJSON_TYPE>
struct ValueTraits
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::ERROR;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = void;
};

template<>
struct ValueTraits<EnumeratedValueType::NULLVAL>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::NULLVAL;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = NullValue;
};

template<>
struct ValueTraits<EnumeratedValueType::NOOP>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::NOOP;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = Noop;
};

template<>
struct ValueTraits<EnumeratedValueType::TRUE>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::TRUE;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = True;
};

template<>
struct ValueTraits<EnumeratedValueType::FALSE>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::FALSE;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = False;
};

template<>
struct ValueTraits<EnumeratedValueType::INT8>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::INT8;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = ichar_t;
};

template<>
struct ValueTraits<EnumeratedValueType::UINT8>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::UINT8;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::uichar_t;
};

template<>
struct ValueTraits<EnumeratedValueType::INT16>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::INT16;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::short_t;
};

template<>
struct ValueTraits<EnumeratedValueType::INT32>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::INT32;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::int_t;
};

template<>
struct ValueTraits<EnumeratedValueType::INT64>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::INT64;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::long_t;
};

template<>
struct ValueTraits<EnumeratedValueType::FLOAT32>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::FLOAT32;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::float_t;
};

template<>
struct ValueTraits<EnumeratedValueType::FLOAT64>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::FLOAT64;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::double_t;
};

template<>
struct ValueTraits<EnumeratedValueType::CHAR>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::CHAR;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::char_t;
};

template<>
struct ValueTraits<EnumeratedValueType::HUGE_NUM>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::HUGE_NUM;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = HugeNumber;
};

template<>
struct ValueTraits<EnumeratedValueType::STRING>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::STRING;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = String;
};

template<>
struct ValueTraits<EnumeratedValueType::ARRAY>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::ARRAY_OPEN;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::ARRAY_CLOSE;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = Array;
};

template<>
struct ValueTraits<EnumeratedValueType::OBJECT>
{
	static constexpr auto VALUE_TYPE = ubjson::ValueType::OBJECT_OPEN;
	static constexpr auto VALUE_TYPE_CLOSE = ubjson::ValueType::OBJECT_CLOSE;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = Object;
};

}}

#endif // FLAMEIDE_UBJSON_TRAITS_HPP
