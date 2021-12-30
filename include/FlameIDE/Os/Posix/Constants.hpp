#ifndef FLAMEIDE_OS_POSIX_CONSTANTS_HPP
#define FLAMEIDE_OS_POSIX_CONSTANTS_HPP

#include <FlameIDE/Os/Posix/Types.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

namespace flame_ide
{namespace os
{namespace posix
{

constexpr OsFileDescriptor OS_INVALID_DESCRIPTOR = -1;

constexpr OsStatus OS_STATUS_SUCCESS = 0;

constexpr OsAddressContext OS_IPV4_ADDRESS_INITIALIZER = {
		::sockaddr_in{ AF_INET, 0, {}, {} }, ::sockaddr_in6{}, true
};

constexpr OsAddressContext OS_IPV6_ADDRESS_INITIALIZER = {
		::sockaddr_in{}, ::sockaddr_in6{ AF_INET6, {}, {}, {}, {} }, false
};

constexpr OsAddressContext OS_IPV4_ADDRESS_LOOPBACK = {
	::sockaddr_in{ AF_INET, 0, {INADDR_LOOPBACK}, {} }, {}, true
};

constexpr OsAddressContext OS_IPV6_ADDRESS_LOOPBACK = {
	::sockaddr_in{}, ::sockaddr_in6{ AF_INET6, 0, {}, IN6ADDR_LOOPBACK_INIT, {} }, false
};

constexpr OsSocketContext OS_SOCKET_IPV4_INITIALIZER = OsSocketContext {
		OS_INVALID_DESCRIPTOR, OS_IPV4_ADDRESS_INITIALIZER
};

constexpr OsSocketContext OS_SOCKET_IPV6_INITIALIZER = OsSocketContext {
		OS_INVALID_DESCRIPTOR, OS_IPV6_ADDRESS_INITIALIZER
};

constexpr OsThreadContext OS_THREAD_CONTEXT_INITIALIZER = OsThreadContext{};

constexpr OsMutexContext OS_MUTEX_CONTEXT_INITIALIZER = {
	PTHREAD_MUTEX_INITIALIZER, {}
};

constexpr OsSemaphoreContext OS_SEMAPHORE_CONTEXT_INITIALIZER = OsSemaphoreContext{};

constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_DEFAULT = 1u;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_INVALID =
		NumberLimitTrait<OsSemaphoreValue>::MAX_VALUE;

constexpr char OS_PLATFORM_PREFIX[] = "/tmp/";

constexpr OsLibraryHandle OS_LIBRARY_HANDLE_INVALID = OsLibraryHandle{};

constexpr char OS_LIBRARY_PREFIX[] = "lib";
constexpr char OS_LIBRARY_SUFFIX_SHARED[] = ".so";

constexpr char OS_DIRECTORY_SLASH = '/';

}}}

#ifndef FLAMEIDE_OS_NAMESPACE
#	define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::posix
#endif // FLAMEIDE_OS_NAMESPACE

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_OS_POSIX_CONSTANTS_HPP
