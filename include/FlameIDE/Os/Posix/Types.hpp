#ifndef FLAMEIDE_OS_POSIX_TYPES_HPP
#define FLAMEIDE_OS_POSIX_TYPES_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Utils.hpp>

#include <arpa/inet.h>
#include <sys/socket.h>

#include <errno.h>
#include <dlfcn.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

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

	constexpr operator int() const noexcept
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

using OsSocketAddressIn = ::sockaddr_in;
using OsSocketDescriptor = decltype(::socket({}, {}, {}));

struct OsSocketReceive;
struct OsSocket
{
	constexpr OsSocket() noexcept = default;
	OsSocket(const OsSocket &) noexcept = default;

	constexpr OsSocket(
			const OsSocketAddressIn address, const OsSocketDescriptor descriptor
	) noexcept : address{ address }, descriptor{ descriptor }
	{}
	constexpr OsSocket(
			const OsSocketDescriptor descriptor, const OsSocketAddressIn address
	) noexcept : OsSocket(address, descriptor)
	{}
	explicit constexpr
	OsSocket(const OsSocketDescriptor descriptor) noexcept : OsSocket(descriptor, {})
	{}

	OsSocket(const OsSocketReceive &) noexcept;

	OsSocket &operator=(const OsSocket &) noexcept = default;
	OsSocket &operator=(const OsSocketReceive &socketReceive) noexcept;

	OsSocketAddressIn address = {};
	OsSocketDescriptor descriptor = -1;
};

struct OsSocketReceive
{
	constexpr OsSocketReceive() noexcept = default;
	OsSocketReceive(const OsSocketReceive &) noexcept = default;
	OsSocketReceive(const OsSocket &) noexcept;

	OsSocketReceive &operator=(const OsSocketReceive &) noexcept = default;
	OsSocketReceive &operator=(const OsSocket &socket) noexcept;

	OsSocketAddressIn address = {};
	const OsSocketDescriptor *descriptor = nullptr;
};

struct OsThreadContext
{
	pthread_t object;
	pthread_attr_t attributes;
};
struct OsThreadTaskTrait: public NonCreational
{
	using Return = void *;
	using Argument = void *;
	using Task = Return(*)(Argument);
};

struct OsMutexContext
{
	pthread_mutex_t object;
	pthread_mutexattr_t attributes;
};

using OsSemaphoreObject = ::sem_t;
struct OsSemaphoreContext
{
	OsSemaphoreObject object;

	bool operator==(const OsSemaphoreContext &context) const noexcept
	{
		return isEqual(object, context.object);
	}
};

using OsSemaphoreValue = int;

using OsSpinlockContext = ::pthread_spinlock_t;

struct OsLibraryHandle
{
	using Handle = decltype(dlopen(nullptr, 0));
	using Symbol = decltype(dlsym((void *)(0x0), (const char *)(0x10)));
	static constexpr auto OPEN_FLAG = RTLD_LAZY;

	Handle address = Handle{};
};

enum Signal : decltype(SIGRTMIN)
{
	EMPTY = 0
	, INT = SIGINT
	, ILL = SIGILL
	, ABRT = SIGABRT
	, FPE = SIGFPE
	, SEGV = SIGSEGV
	, TERM = SIGTERM
	, HUP = SIGHUP
	, QUIT = SIGQUIT
	, TRAP = SIGTRAP
	, KILL = SIGKILL
	, PIPE = SIGPIPE
	, ALRM = SIGALRM

	, IO = SIGIO
	, IOT = SIGIOT
	, CLD = SIGCHLD

	, STKFLT = SIGSTKFLT
	, PWR = SIGPWR

	, BUS = SIGBUS
	, SYS = SIGSYS

	, URG = SIGURG
	, STOP = SIGSTOP
	, TSTP = SIGTSTP
	, CONT = SIGCONT
	, CHLD = SIGCHLD
	, TTIN = SIGTTIN
	, TTOU = SIGTTOU
	, POLL = SIGPOLL
	, XFSZ = SIGXFSZ
	, XCPU = SIGXCPU
	, VTALRM = SIGVTALRM
	, PROF = SIGPROF
	, USR1 = SIGUSR1
	, USR2 = SIGUSR2
};

}}} // namespace flame_ide::os::posix

#define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_OS_POSIX_TYPES_HPP
