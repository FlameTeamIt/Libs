#ifndef BASETYPES_H
#define BASETYPES_H

#include <stddef.h>
#include <stdint.h>

namespace flame_ide
{

typedef ptrdiff_t diff_t;
typedef diff_t ssize_t;

typedef ::size_t size_t;

typedef char char_t;

typedef uint8_t uichar_t;
typedef int8_t ichar_t;

typedef uint16_t ushort_t;
typedef int16_t short_t;

typedef uint32_t uint_t;
typedef int32_t int_t;

typedef uint64_t ulong_t;
typedef int64_t long_t;

typedef uint64_t ullong_t;
typedef int64_t llong_t;

typedef float float_t;
typedef double double_t;
typedef long double ldouble_t;

}

#endif // BASETYPES_H
