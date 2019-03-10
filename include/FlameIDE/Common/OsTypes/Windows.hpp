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

}}}

#define FLAMEIDE_OS_NAMESPACE flame_ide::os::windows

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // FLAMEIDE_COMMON_OSTYPES_WINDOWS_HPP
