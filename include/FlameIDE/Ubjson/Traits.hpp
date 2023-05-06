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
	static constexpr ValueType VALUE_TYPE = ValueType::ERROR;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = decltype(nullptr);
};

template<>
struct ValueTraits<EnumeratedValueType::NULLVAL>
{
	static constexpr ValueType VALUE_TYPE = ValueType::NULLVAL;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = NullValue;
};

template<>
struct ValueTraits<EnumeratedValueType::NOOP>
{
	static constexpr ValueType VALUE_TYPE = ValueType::NOOP;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = Noop;
};

template<>
struct ValueTraits<EnumeratedValueType::TRUE>
{
	static constexpr ValueType VALUE_TYPE = ValueType::TRUE;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = True;
};

template<>
struct ValueTraits<EnumeratedValueType::FALSE>
{
	static constexpr ValueType VALUE_TYPE = ValueType::FALSE;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = False;
};

template<>
struct ValueTraits<EnumeratedValueType::INT8>
{
	static constexpr ValueType VALUE_TYPE = ValueType::INT8;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = ichar_t;
};

template<>
struct ValueTraits<EnumeratedValueType::UINT8>
{
	static constexpr ValueType VALUE_TYPE = ValueType::UINT8;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::uichar_t;
};

template<>
struct ValueTraits<EnumeratedValueType::INT16>
{
	static constexpr ValueType VALUE_TYPE = ValueType::INT16;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::short_t;
};

template<>
struct ValueTraits<EnumeratedValueType::INT32>
{
	static constexpr ValueType VALUE_TYPE = ValueType::INT32;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::int_t;
};

template<>
struct ValueTraits<EnumeratedValueType::INT64>
{
	static constexpr ValueType VALUE_TYPE = ValueType::INT64;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::long_t;
};

template<>
struct ValueTraits<EnumeratedValueType::FLOAT32>
{
	static constexpr ValueType VALUE_TYPE = ValueType::FLOAT32;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::float_t;
};

template<>
struct ValueTraits<EnumeratedValueType::FLOAT64>
{
	static constexpr ValueType VALUE_TYPE = ValueType::FLOAT64;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::double_t;
};

template<>
struct ValueTraits<EnumeratedValueType::CHAR>
{
	static constexpr ValueType VALUE_TYPE = ValueType::CHAR;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = Types::char_t;
};

template<>
struct ValueTraits<EnumeratedValueType::HUGE_NUM>
{
	static constexpr ValueType VALUE_TYPE = ValueType::HUGE_NUM;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = HugeNumber;
};

template<>
struct ValueTraits<EnumeratedValueType::STRING>
{
	static constexpr ValueType VALUE_TYPE = ValueType::STRING;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = String;
};

template<>
struct ValueTraits<EnumeratedValueType::ARRAY>
{
	static constexpr ValueType VALUE_TYPE = ValueType::ARRAY_OPEN;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::ARRAY_CLOSE;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = Array;
};

template<>
struct ValueTraits<EnumeratedValueType::OBJECT>
{
	static constexpr ValueType VALUE_TYPE = ValueType::OBJECT_OPEN;
	static constexpr ValueType VALUE_TYPE_CLOSE = ValueType::OBJECT_CLOSE;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = Object;
};

}}

#endif // FLAMEIDE_UBJSON_TRAITS_HPP
