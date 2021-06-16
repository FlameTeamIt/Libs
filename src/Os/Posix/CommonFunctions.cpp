#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/CommonFunctions.hpp>

#include <unistd.h>

namespace flame_ide
{namespace os
{

Types::ssize_t read(FileDescriptor fd, byte_t *data, Types::size_t size)
{
	return ::read(fd, data, size);
}

Types::ssize_t write(FileDescriptor fd, const byte_t *data, Types::size_t size)
{
	return ::write(fd, data, size);
}

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
