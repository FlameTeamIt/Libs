#ifndef INTERNALWINAPIFUNCTIONS_HPP
#define INTERNALWINAPIFUNCTIONS_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

os::FileDescriptor makeNamedPipe(const char *pipeName, os::ActionType action) noexcept;

}}

#endif // INTERNALWINAPIFUNCTIONS_HPP
