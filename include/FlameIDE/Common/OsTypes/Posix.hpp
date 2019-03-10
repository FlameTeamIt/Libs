#ifndef FLAMEIDE_COMMON_OSTYPES_POSIX_HPP
#define FLAMEIDE_COMMON_OSTYPES_POSIX_HPP

#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <sys/socket.h>
#include <sys/un.h>
#include <aio.h>

namespace flame_ide
{namespace os
{namespace posix
{

using OsFileDescriptor = int;
constexpr OsFileDescriptor OS_INVALID_DESCRIPTOR = -1;

using OsStatus = int;
constexpr OsStatus OS_SUCCESS_STATUS = 0;

struct OsSocket
{
	::sockaddr_un sockaddr;
	OsFileDescriptor fd;
};
constexpr OsSocket OS_SOCKET_INITIALIZER = OsSocket {
		{}, OS_INVALID_DESCRIPTOR
};

using OsAsyncIoContext = ::aiocb;
constexpr OsAsyncIoContext OS_ASYNC_CONTEXT_INITIALIZER = OsAsyncIoContext{};

}}}

#define FLAMEIDE_OS_NAMESPACE flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_COMMON_OSTYPES_POSIX_HPP
