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

template<EnumeratedType UBJSON_TYPE>
struct ValueTraits
{
	static constexpr Type VALUE_TYPE = Type::ERROR;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = decltype(nullptr);
};

template<>
struct ValueTraits<EnumeratedType::NULLVAL>
{
	static constexpr Type VALUE_TYPE = Type::NULLVAL;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = NullValue;
};

template<>
struct ValueTraits<EnumeratedType::NOOP>
{
	static constexpr Type VALUE_TYPE = Type::NOOP;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::FalseType::VALUE;
	using ValueType = Noop;
};

template<>
struct ValueTraits<EnumeratedType::TRUE>
{
	static constexpr Type VALUE_TYPE = Type::TRUE;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = True;
};

template<>
struct ValueTraits<EnumeratedType::FALSE>
{
	static constexpr Type VALUE_TYPE = Type::FALSE;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = False;
};

template<>
struct ValueTraits<EnumeratedType::INT8>
{
	static constexpr Type VALUE_TYPE = Type::INT8;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = ichar_t;
};

template<>
struct ValueTraits<EnumeratedType::UINT8>
{
	static constexpr Type VALUE_TYPE = Type::UINT8;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = uichar_t;
};

template<>
struct ValueTraits<EnumeratedType::INT16>
{
	static constexpr Type VALUE_TYPE = Type::INT16;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = short_t;
};

template<>
struct ValueTraits<EnumeratedType::INT32>
{
	static constexpr Type VALUE_TYPE = Type::INT32;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = int_t;
};

template<>
struct ValueTraits<EnumeratedType::INT64>
{
	static constexpr Type VALUE_TYPE = Type::INT64;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::FLOAT32>
{
	static constexpr Type VALUE_TYPE = Type::FLOAT32;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = float_t;
};

template<>
struct ValueTraits<EnumeratedType::FLOAT64>
{
	static constexpr Type VALUE_TYPE = Type::FLOAT64;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = double_t;
};

template<>
struct ValueTraits<EnumeratedType::CHAR>
{
	static constexpr Type VALUE_TYPE = Type::CHAR;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = char_t;
};

template<>
struct ValueTraits<EnumeratedType::HUGE_NUM>
{
	static constexpr Type VALUE_TYPE = Type::HUGE_NUM;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = HugeNumber;
};

template<>
struct ValueTraits<EnumeratedType::STRING>
{
	static constexpr Type VALUE_TYPE = Type::STRING;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = flame_ide::TrueType::VALUE;
	using ValueType = String;
};

template<>
struct ValueTraits<EnumeratedType::ARRAY>
{
	static constexpr Type VALUE_TYPE = Type::ARRAY_OPEN;
	static constexpr Type VALUE_TYPE_CLOSE = Type::ARRAY_CLOSE;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = Array;
};

template<>
struct ValueTraits<EnumeratedType::OBJECT>
{
	static constexpr Type VALUE_TYPE = Type::OBJECT_OPEN;
	static constexpr Type VALUE_TYPE_CLOSE = Type::OBJECT_CLOSE;
	static constexpr bool DATA_PAYLOAD = TrueType::VALUE;
	using ValueType = Object;
};

}}

#endif // FLAMEIDE_UBJSON_TRAITS_HPP
