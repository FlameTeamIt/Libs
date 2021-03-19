#ifndef FLAMEIDE_OS_POSIX_TYPES_HPP
#define FLAMEIDE_OS_POSIX_TYPES_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <sys/socket.h>
#include <sys/un.h>
#include <pthread.h>
#include <semaphore.h>
#include <dlfcn.h>

namespace flame_ide
{namespace os
{namespace posix
{

class OsFileDescriptor
{
public:
	using DefaultFd = int;

	constexpr OsFileDescriptor() : OsFileDescriptor(DefaultFd{-1})
	{}

	constexpr OsFileDescriptor(DefaultFd fd) : defaultFd(fd)
	{}

	constexpr operator int() noexcept
	{
		return defaultFd;
	}

	constexpr operator const int() const noexcept
	{
		return defaultFd;
	}

	constexpr bool operator==(OsFileDescriptor fd) const noexcept
	{
		return defaultFd == fd.defaultFd;
	}

	constexpr bool operator!=(OsFileDescriptor fd) const noexcept
	{
		return !(operator==(fd));
	}

private:
	DefaultFd defaultFd;
};
constexpr OsFileDescriptor OS_INVALID_DESCRIPTOR = -1;

using OsStatus = int;
constexpr OsStatus OS_STATUS_SUCCESS = 0;

struct OsSocket
{
	::sockaddr_un sockaddr;
	OsFileDescriptor fd;
};
constexpr OsSocket OS_SOCKET_INITIALIZER = OsSocket {
		{}, OS_INVALID_DESCRIPTOR
};

struct OsThreadContext
{
	pthread_t object;
	pthread_attr_t attributes;
};
constexpr OsThreadContext OS_THREAD_CONTEXT_INITIALIZER = OsThreadContext{};
struct OsThreadTaskTrait : NonCreational
{
	using ReturnType = void *;
	using ArgumentType = void *;
	using TaskType = ReturnType(*)(ArgumentType);
};

struct OsMutexContext
{
	pthread_mutex_t object;
	pthread_mutexattr_t attributes;
};
constexpr OsMutexContext OS_MUTEX_CONTEXT_INITIALIZER = {
	PTHREAD_MUTEX_INITIALIZER, {}
};

using OsSemaphoreContext = ::sem_t;
constexpr OsSemaphoreContext OS_SEMAPHORE_CONTEXT_INITIALIZER = OsSemaphoreContext{};
using OsSemaphoreValue = unsigned int;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_DEFAULT = 1u;
constexpr OsSemaphoreValue OS_SEMAPHORE_VALUE_INVALID =
		NumberLimitTrait<OsSemaphoreValue>::MAX_VALUE;

constexpr char OS_PLATFORM_PREFIX[] = "/tmp/";

struct OsLibraryHandle
{
	using Handle = decltype(dlopen(nullptr, 0));
	using Symbol = decltype(dlsym(Handle{}, nullptr));
	static constexpr auto OPEN_FLAG = RTLD_LAZY;

	Handle address = Handle{};
};
constexpr OsLibraryHandle OS_LIBRARY_HANDLE_INVALID = OsLibraryHandle{};

constexpr char OS_LIBRARY_PREFIX[] = "lib";
constexpr char OS_LIBRARY_SUFFIX_SHARED[] = ".so";

constexpr char OS_DIRECTORY_SLASH = '/';

}}} // flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_OS_POSIX_TYPES_HPP
