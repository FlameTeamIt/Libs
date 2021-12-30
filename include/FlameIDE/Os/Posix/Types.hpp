#ifndef FLAMEIDE_OS_POSIX_TYPES_HPP
#define FLAMEIDE_OS_POSIX_TYPES_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Common/ConstexprPointer.hpp>
#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Utils.hpp>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>
#include <dlfcn.h>

namespace _4f48bc46_795d_4c6a_9eee_094cb82913ef
{

struct PthreadAttributes
{
	inline PthreadAttributes() noexcept
	{
		::pthread_attr_init(&object);
	}

	inline PthreadAttributes(PthreadAttributes &&attributes) noexcept
	{
		operator=(flame_ide::move(attributes));
	}

	inline ~PthreadAttributes() noexcept
	{
		::pthread_attr_destroy(&object);
	}

	inline PthreadAttributes &operator=(PthreadAttributes &&attributes) noexcept
	{
		object = attributes.object;
		::pthread_attr_init(&attributes.object);
		return *this;
	}

	inline operator ::pthread_attr_t *()
	{
		return &object;
	}

	pthread_attr_t object;
};

} // namespace_4f48bc46_795d_4c6a_9eee_094cb82913ef

namespace flame_ide
{namespace os
{namespace posix
{

class OsFileDescriptor
{
public:
	using DefaultFd = int;

	constexpr OsFileDescriptor() noexcept = default;

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
	DefaultFd defaultFd = -1;
};

using OsStatus = int;

struct OsAddressContext
{
	::sockaddr_in ipv4;
	::sockaddr_in6 ipv6;
	bool isIpv4;
};

struct OsSocketContext
{
	OsFileDescriptor fd;
	OsAddressContext address;
};

struct OsThreadAttributes
{
	enum class DetachState
	{
		CREATE_DETACHED = PTHREAD_CREATE_DETACHED
		, CREATE_JOINABLE = PTHREAD_CREATE_JOINABLE
	};

	enum class Scope
	{
		SYSTEM = PTHREAD_SCOPE_SYSTEM
		, PROCESS = PTHREAD_SCOPE_PROCESS
	};

	enum SchedulingPriority
	{
		HIGH = 0
		, NORMAL = 5 // TODO: get dafault
		, LOW = ::flame_ide::NumberLimitTrait<int>::MAX_VALUE
	};

	enum class SchedulingPolicy
	{
		FIFO = SCHED_FIFO
		, ROUND_ROBIN = SCHED_RR
		, OTHER = SCHED_OTHER
	};

	enum class InheritedSchedulingPolicy
	{
		INHERIT_SCHED = PTHREAD_INHERIT_SCHED
		, EXPLICIT_SCHED = PTHREAD_EXPLICIT_SCHED
	};

	struct Stack
	{
		ConstexprPointer<void> pointer;
		Types::size_t size;
	};

	inline static auto getDefaultNativeAttributes()
	{
		return ::_4f48bc46_795d_4c6a_9eee_094cb82913ef::PthreadAttributes{};
	}

	inline auto getCustomNativeAttributes() const
	{
		::_4f48bc46_795d_4c6a_9eee_094cb82913ef::PthreadAttributes attribute;
		::pthread_attr_setdetachstate(attribute, static_cast<int>(detachState));
		if (guardSize != decltype(guardSize){})
		{
			::pthread_attr_setguardsize(attribute, guardSize);
		}
		::pthread_attr_setscope(attribute, static_cast<int>(scope));
		::pthread_attr_setschedparam(attribute, &param);
		::pthread_attr_setschedpolicy(attribute, static_cast<int>(policy));
		::pthread_attr_setinheritsched(attribute
				, static_cast<int>(inheritedSchedulingPolicy));

		if (stack.pointer)
		{
			::pthread_attr_setstack(attribute, stack.pointer.object, stack.size);
		}
		return attribute;
	}

	DetachState detachState = DetachState::CREATE_JOINABLE;
	Types::size_t guardSize = {};
	::sched_param param = {SchedulingPriority::NORMAL};
	SchedulingPolicy policy = SchedulingPolicy::OTHER;
	InheritedSchedulingPolicy inheritedSchedulingPolicy
			= InheritedSchedulingPolicy::INHERIT_SCHED;
	Scope scope = Scope::SYSTEM;
	Stack stack = {};
};
struct OsThreadContext
{
	pthread_t object;
	OsThreadAttributes attributes;
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
	using Symbol = decltype(dlsym(Handle{}, ""));
	static constexpr auto OPEN_FLAG = RTLD_LAZY;

	Handle address = Handle{};
};

}}} // namespace flame_ide::os::posix

#define FLAMEIDE_OS_NAMESPACE ::flame_ide::os::posix

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // FLAMEIDE_OS_POSIX_TYPES_HPP
