#ifndef TAGS_HPP
#define TAGS_HPP

#include <Common/PrimitiveTypes.hpp>

namespace flame_ide
{namespace bson
{

enum class Type: uchar_t
{
	FLOAT64 = 0x01,
	UTF8_STRING = 0x02,
	DOCUMENT = 0x03,
	ARRAY = 0x04,
	BINARY = 0x05,
	OBJECT_ID = 0x07,
	BOOL = 0x08,
	UTC_DATE = 0x09,
	NULL_VALUE = 0x0A,
	REGEXP = 0x0B,
	JS_CODE = 0x0D,
	JS_CODE_W = 0x0F,
	INT32 = 0x10,
	TIMESTAMP = 0x11,
	INT64 = 0x12,
	DEC128 = 0x13,
	MIN_KEY = 0xFF,
	MAX_KEY = 0x7F,
	ERROR = 0x00
};

enum class SubType: uchar_t
{
	GENERIC_BINARY = 0x00,
	FUNCTION = 0x01,
	BINARY_OLD = 0x02,
	UUID_OLD = 0x03,
	UUID = 0x04,
	MD5 = 0x05,
	USER_DEFINED = 0x80,
	ERROR = 0xFF
};

inline Type CheckType(uchar_t byte)
{
	switch (static_cast<Type>(byte))
	{
		case Type::FLOAT64:
		case Type::UTF8_STRING:
		case Type::DOCUMENT:
		case Type::ARRAY:
		case Type::BINARY:
		case Type::OBJECT_ID:
		case Type::BOOL:
		case Type::UTC_DATE:
		case Type::NULL_VALUE:
		case Type::REGEXP:
		case Type::JS_CODE:
		case Type::JS_CODE_W:
		case Type::INT32:
		case Type::TIMESTAMP:
		case Type::INT64:
		case Type::DEC128:
		case Type::MIN_KEY:
		case Type::MAX_KEY:
			return static_cast<Type>(byte);

		default:
			return Type::ERROR;
	}
}

}}

#endif // TAGS_HPP
