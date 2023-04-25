#ifndef FLAMEIDE_COMMON_MACROS_DETECTOS_HPP
#define FLAMEIDE_COMMON_MACROS_DETECTOS_HPP

#define FLAMEIDE_OS_NULL                         0
#define FLAMEIDE_OS_LINUX                        1 << 0
#define FLAMEIDE_OS_FREEBSD                      1 << 1
#define FLAMEIDE_OS_MACOS                        1 << 2
#define FLAMEIDE_OS_WINDOWS                      1 << 3

// detect OS

#define FLAMEIDE_OS_CURRENT                      FLAMEIDE_OS_NULL

#if defined(__linux__)
#	undef FLAMEIDE_OS_CURRENT
#	define FLAMEIDE_OS_CURRENT                   FLAMEIDE_OS_LINUX
#endif // defined(__linux__)

#if defined(__FreeBSD__)
#	undef FLAMEIDE_OS_CURRENT
#	define FLAMEIDE_OS_CURRENT                   FLAMEIDE_OS_FREEBSD
#endif // defined(__FreeBSD__)

#if defined(__APPLE__) || defined(__MACH__)
#	undef FLAMEIDE_OS_CURRENT
#	define FLAMEIDE_OS_CURRENT                   FLAMEIDE_OS_MACOS
#endif // defined(__APPLE__) || defined(__MACH__)

#if defined(_WIN32)
#	undef FLAMEIDE_OS_CURRENT
#	define FLAMEIDE_OS_CURRENT                   FLAMEIDE_OS_WINDOWS
#endif // defined(_WIN32)

#define FLAMEIDE_OS_POSIX \
	(FLAMEIDE_OS_CURRENT > FLAMEIDE_OS_NULL) \
	&& (FLAMEIDE_OS_CURRENT < FLAMEIDE_OS_WINDOWS)

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_NULL
#	error "Unsupported OS."
#endif

#endif // FLAMEIDE_COMMON_MACROS_DETECTOS_HPP
