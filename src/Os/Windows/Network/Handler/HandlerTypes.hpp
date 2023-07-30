#ifndef WINDOWS_HANDLERTYPES_HPP
#define WINDOWS_HANDLERTYPES_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Os/Windows/Network/Handler/Registration.hpp>
#include <FlameIDE/../../src/Os/Windows/Network/Handler/Worker.hpp>

#define FLAMEIDE_HANDLERTYPES_NAMESPACE ::flame_ide::os::network::windows
#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // WINDOWS_HANDLERTYPES_HPP
