#ifndef FLAMEIDE_UBJSON_TYPES_HPP
#define FLAMEIDE_UBJSON_TYPES_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>

namespace flame_ide
{namespace ubjson
{

enum class Type : uichar_t
{
	NULLVAL = 'Z'
	, NOOP = 'N'
	, TRUE = 'T'
	, FALSE = 'F'
	, INT8 = 'i'
	, UINT8 = 'U'
	, INT16 = 'I'
	, INT32 = 'l'
	, INT64 = 'L'
	, FLOAT32 = 'd'
	, FLOAT64 = 'D'
	, HUGE_NUM = 'H'
	, CHAR = 'C'
	, STRING = 'S'
	, ARRAY_OPEN = '['
	, ARRAY_CLOSE = ']'
	, OBJECT_OPEN = '{'
	, OBJECT_CLOSE = '}'
	, ERROR = 0xFF
};

enum EnumeratedType : uichar_t
{
	NULLVAL
	, NOOP
	, TRUE
	, FALSE
	, INT8
	, UINT8
	, INT16
	, INT32
	, INT64
	, FLOAT32
	, FLOAT64
	, HUGE_NUM
	, CHAR
	, STRING
	, ARRAY
	, OBJECT
	, ERROR = 0xFF
	, ENUMERATED_TYPE_COUNT = OBJECT + 2
};

}}

#endif // FLAMEIDE_UBJSON_TYPES_HPP
