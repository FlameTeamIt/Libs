#ifndef INTERNALWINAPIFUNCTIONS_HPP
#define INTERNALWINAPIFUNCTIONS_HPP

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

struct Descriptors
{
	os::FileDescriptor reader;
	os::FileDescriptor writer;
};

Descriptors makeNamedPipe(const char *pipeName, os::ActionType action) noexcept;

}}

#endif // INTERNALWINAPIFUNCTIONS_HPP
