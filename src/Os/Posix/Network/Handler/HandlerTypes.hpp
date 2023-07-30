#ifndef POSIX_HANDLERTYPES_HPP
#define POSIX_HANDLERTYPES_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/Posix/Network/Handler/Registration.hpp>
#include <FlameIDE/../../src/Os/Posix/Network/Handler/Worker.hpp>

#define FLAMEIDE_HANDLERTYPES_NAMESPACE ::flame_ide::os::network::posix
#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // POSIX_HANDLERTYPES_HPP
