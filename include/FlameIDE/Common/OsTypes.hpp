#ifndef FLAMEIDE_COMMON_OSTYPES_HPP
#define FLAMEIDE_COMMON_OSTYPES_HPP

#include <FlameIDE/Common/OsTypes/Posix.hpp>
#include <FlameIDE/Common/OsTypes/Windows.hpp>

namespace flame_ide
{namespace os
{

using FileDescriptor = FLAMEIDE_OS_NAMESPACE::OsFileDescriptor;
constexpr FileDescriptor INVALID_DESCRIPTOR =
		FLAMEIDE_OS_NAMESPACE::OS_INVALID_DESCRIPTOR;

using Status = FLAMEIDE_OS_NAMESPACE::OsStatus;
constexpr Status SUCCESS_STATUS =
		FLAMEIDE_OS_NAMESPACE::OS_SUCCESS_STATUS;

using Socket = FLAMEIDE_OS_NAMESPACE::OsSocket;
constexpr Socket SOCKET_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_SOCKET_INITIALIZER;

using AsyncIo = FLAMEIDE_OS_NAMESPACE::OsAsyncIoContext;
constexpr AsyncIo ASYNC_CONTEXT_INITIALIZER =
		FLAMEIDE_OS_NAMESPACE::OS_ASYNC_CONTEXT_INITIALIZER;

}}

#endif // FLAMEIDE_COMMON_OSTYPES_HPP
