#ifndef FLAMEIDE_OS_CONSTANTS_HPP
#define FLAMEIDE_OS_CONSTANTS_HPP

#include <FlameIDE/Os/Posix/Constants.hpp>
#include <FlameIDE/Os/Windows/Constants.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
#	define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::posix
#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
#	define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::windows
#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

namespace flame_ide
{namespace os
{



}}

#undef FLAMEIDE_OS_NAMESPACE

#endif // FLAMEIDE_OS_CONSTANTS_HPP
