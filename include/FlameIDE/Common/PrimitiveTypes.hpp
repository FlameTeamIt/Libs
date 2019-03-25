#ifndef FLAMEIDE_COMMON_PRIMITIVE_TYPES_HPP
#define FLAMEIDE_COMMON_PRIMITIVE_TYPES_HPP

#include <stddef.h>
#include <stdint.h>

namespace flame_ide
{

using diff_t     = ::ptrdiff_t;
using ssize_t    = diff_t;
using size_t     = ::size_t;
using char_t     =  char;
using uichar_t   = ::uint8_t;
using ichar_t    = ::int8_t;
using ushort_t   = ::uint16_t;
using short_t    = ::int16_t;
using uint_t     = ::uint32_t;
using int_t      = ::int32_t;
using ulong_t    = ::uint64_t;
using long_t     = ::int64_t;
using float_t    = float;
using double_t   = double;
using ldouble_t  = long double;

}

#endif // FLAMEIDE_COMMON_PRIMITIVE_TYPES_HPP
