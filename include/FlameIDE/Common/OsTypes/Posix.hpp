#ifndef FLAMEIDE_COMMON_OSTYPES_POSIX_HPP
#define FLAMEIDE_COMMON_OSTYPES_POSIX_HPP

#include <FlameIDE/Common/Macroses.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

namespace flame_ide
{namespace os
{namespace posix
{

using OsFileDescriptor = int;

}}}

#define FLAMEIDE_OS_NAMESPACE flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_COMMON_OSTYPES_POSIX_HPP