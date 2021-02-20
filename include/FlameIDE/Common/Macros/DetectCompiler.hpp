#ifndef FLAMEIDE_COMMON_MACROS_DETECTCOMPILER_HPP
#define FLAMEIDE_COMMON_MACROS_DETECTCOMPILER_HPP

#define FLAMEIDE_COMPILER_INVALID 0
#define FLAMEIDE_COMPILER_GCC     1
#define FLAMEIDE_COMPILER_CLANG   2
#define FLAMEIDE_COMPILER_MSVC    3

#define FLAMEIDE_COMPILER FLAMEIDE_COMPILER_INVALID

#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
#	undef FLAMEIDE_COMPILER
#	define FLAMEIDE_COMPILER FLAMEIDE_COMPILER_GCC
#elif defined(__clang__)
#	undef FLAMEIDE_COMPILER
#	define FLAMEIDE_COMPILER FLAMEIDE_COMPILER_CLANG
#elif defined(_MSC_VER)
#	undef FLAMEIDE_COMPILER
#	define FLAMEIDE_COMPILER FLAMEIDE_COMPILER_MSVC
#endif

#if FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_INVALID
#	error "Not supported compiler"
#endif

#endif // FLAMEIDE_COMMON_MACROS_DETECTCOMPILER_HPP
