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

using OsStatus = int;

struct OsSocketReceive;
struct OsSocket
{
	::sockaddr_un address;
	OsFileDescriptor descriptor;

	OsSocket &operator=(const OsSocketReceive &socketReceive) noexcept;
};

struct OsSocketReceive
{
	::sockaddr_un address;
	const OsFileDescriptor *descriptor;

	OsSocketReceive &operator=(const OsSocket &socket) noexcept;
};

struct OsThreadContext
{
	pthread_t object;
	pthread_attr_t attributes;
};
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

using OsSemaphoreContext = ::sem_t;
using OsSemaphoreValue = unsigned int;

struct OsLibraryHandle
{
	using Handle = decltype(dlopen(nullptr, 0));
	using Symbol = decltype(dlsym(Handle{}, nullptr));
	static constexpr auto OPEN_FLAG = RTLD_LAZY;

	Handle address = Handle{};
};

}}} // namespace flame_ide::os::posix

#define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_OS_POSIX_TYPES_HPP
