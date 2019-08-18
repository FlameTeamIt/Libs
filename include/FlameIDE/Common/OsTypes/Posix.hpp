#ifndef FLAMEIDE_COMMON_OSTYPES_POSIX_HPP
#define FLAMEIDE_COMMON_OSTYPES_POSIX_HPP

#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <sys/socket.h>
#include <sys/un.h>
#include <aio.h>
#include <pthread.h>
#include <semaphore.h>

#include <FlameIDE/Common/Traits/Numbers.hpp>

namespace flame_ide
{namespace os
{namespace posix
{

using OsFileDescriptor = int;
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

struct OsAsyncIoContext : public ::aiocb
{
	constexpr OsAsyncIoContext() : ::aiocb{}
	{
		aio_nbytes = 0;
		aio_fildes = OS_INVALID_DESCRIPTOR;
		aio_offset = 0;
		aio_buf = nullptr;
	}
};
constexpr OsAsyncIoContext OS_ASYNC_CONTEXT_INITIALIZER = OsAsyncIoContext{};

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
		NumberLimit<OsSemaphoreValue>::MAX_VALUE;

constexpr char OS_PLATFORM_PREFIX[] = "/tmp/";

}}}

#define FLAMEIDE_OS_NAMESPACE flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_COMMON_OSTYPES_POSIX_HPP
