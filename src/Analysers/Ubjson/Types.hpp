#ifndef UBJSON_TAGS_HPP
#define UBJSON_TAGS_HPP

#include <Common/PrimitiveTypes.hpp>
#include <Templates/Array.hpp>
#include <Templates/Variant.hpp>

namespace flame_ide
{namespace ubjson
{

enum class Type : uchar_t
{
	NULLVAL = 'Z',
	NOOP = 'N',
	TRUE = 'T',
	FALSE = 'F',
	INT8 = 'i',
	UINT8 = 'U',
	INT16 = 'I',
	INT32 = 'l',
	INT64 = 'L',
	FLOAT32 = 'd',
	FLOAT64 = 'D',
	HIGH = 'H',
	CHAR = 'C',
	STRING = 'S',
	ARRAY_OPEN = '[',
	ARRAY_CLOSE = ']',
	OBJECT_OPEN = '{',
	OBJECT_CLOSE = '}',
	ERROR = 0x7F
};

enum EnumeratedType : uchar_t
{
	NULLVAL,
	NOOP,
	TRUE,
	FALSE,
	INT8,
	UINT8,
	INT16,
	INT32,
	INT64,
	FLOAT32,
	FLOAT64,
	HIGH,
	CHAR,
	STRING,
	ARRAY,
	OBJECT
};

class String;
class Array;
class Object;

template<EnumeratedType BJSON_TYPE>
struct ValueTraits
{
	static constexpr Type VALUE_TYPE = Type::ERROR;
	static constexpr bool DATA_PAYLOAD = templates::FalseType::VALUE;
	using ValueType = void;
};

template<>
struct ValueTraits<EnumeratedType::NULLVAL>
{
	static constexpr Type VALUE_TYPE = Type::NULLVAL;
	static constexpr bool DATA_PAYLOAD = templates::FalseType::VALUE;
	using ValueType = void;
};

template<>
struct ValueTraits<EnumeratedType::NOOP>
{
	static constexpr Type VALUE_TYPE = Type::NOOP;
	static constexpr bool DATA_PAYLOAD = templates::FalseType::VALUE;
	using ValueType = void;
};

template<>
struct ValueTraits<EnumeratedType::TRUE>
{
	static constexpr Type VALUE_TYPE = Type::TRUE;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = void;
};

template<>
struct ValueTraits<EnumeratedType::FALSE>
{
	static constexpr Type VALUE_TYPE = Type::FALSE;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = void;
};

template<>
struct ValueTraits<EnumeratedType::INT8>
{
	static constexpr Type VALUE_TYPE = Type::INT8;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = ichar_t;
};

template<>
struct ValueTraits<EnumeratedType::UINT8>
{
	static constexpr Type VALUE_TYPE = Type::UINT8;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = uichar_t;
};

template<>
struct ValueTraits<EnumeratedType::INT16>
{
	static constexpr Type VALUE_TYPE = Type::INT16;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = short_t;
};

template<>
struct ValueTraits<EnumeratedType::INT32>
{
	static constexpr Type VALUE_TYPE = Type::INT32;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = int_t;
};

template<>
struct ValueTraits<EnumeratedType::INT64>
{
	static constexpr Type VALUE_TYPE = Type::INT64;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::FLOAT32>
{
	static constexpr Type VALUE_TYPE = Type::FLOAT32;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::FLOAT64>
{
	static constexpr Type VALUE_TYPE = Type::FLOAT64;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::HIGH>
{
	static constexpr Type VALUE_TYPE = Type::HIGH;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::CHAR>
{
	static constexpr Type VALUE_TYPE = Type::CHAR;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::STRING>
{
	static constexpr Type VALUE_TYPE = Type::STRING;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = long_t;
};

template<>
struct ValueTraits<EnumeratedType::ARRAY>
{
	static constexpr Type VALUE_TYPE = Type::ARRAY_OPEN;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = Array;
};

template<>
struct ValueTraits<EnumeratedType::OBJECT>
{
	static constexpr Type VALUE_TYPE = Type::OBJECT_OPEN;
	static constexpr bool DATA_PAYLOAD = templates::TrueType::VALUE;
	using ValueType = Object;
};

using ValueVariant = templates::Variant<
	ValueTraits<EnumeratedType::NULLVAL>
	, ValueTraits<EnumeratedType::NOOP>
	, ValueTraits<EnumeratedType::TRUE>
	, ValueTraits<EnumeratedType::FALSE>
	, ValueTraits<EnumeratedType::INT8>
	, ValueTraits<EnumeratedType::UINT8>
	, ValueTraits<EnumeratedType::INT16>
	, ValueTraits<EnumeratedType::INT32>
	, ValueTraits<EnumeratedType::INT64>
	, ValueTraits<EnumeratedType::FLOAT32>
	, ValueTraits<EnumeratedType::FLOAT64>
	, ValueTraits<EnumeratedType::HIGH>
	, ValueTraits<EnumeratedType::CHAR>
	, ValueTraits<EnumeratedType::STRING>
	, ValueTraits<EnumeratedType::ARRAY>
	, ValueTraits<EnumeratedType::OBJECT>
>;

}}

#endif // UBJSON_TAGS_HPP
