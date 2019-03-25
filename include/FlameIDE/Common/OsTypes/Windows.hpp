#ifndef FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP
#define FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP

#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <winsock2.h>
#include <windows.h>

namespace flame_ide
{namespace os
{namespace windows
{

using OsFileDescriptor = HANDLE;
constexpr OsFileDescriptor OS_INVALID_DESCRIPTOR = HANDLE{};

using OsStatus = DWORD;
constexpr OsStatus OS_SUCCESS_STATUS = 0;

struct OsSocket
{
	::SOCKADDR_IN sockaddr;
	SOCKET sock;
};
constexpr OsSocket OS_SOCKET_INITIALIZER = OsSocket {
		::SOCKADDR_IN{}, SOCKET{}
};

struct OsAsyncIoContext{};
constexpr OsAsyncIoContext OS_ASYNC_CONTEXT_INITIALIZER = OsAsyncIoContext{};

struct OsThreadContext{};
constexpr OsThreadContext OS_THREAD_CONTEXT_INITIALIZER = OsThreadContext{};

struct OsMutexContext{};
constexpr OsMutexContext OS_MUTEX_CONTEXT_INITIALIZER = {};

struct OsSemaphoreContext{};
constexpr OsSemaphoreContext OS_SEMAPHORE_CONTEXT_INITIALIZER = OsSemaphoreContext{};
using OsSemaphoreValue = LONG;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_DEFAULT = 1;

}}}

#define FLAMEIDE_OS_NAMESPACE flame_ide::os::windows

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP
