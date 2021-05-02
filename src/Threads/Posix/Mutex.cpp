#include <FlameIDE/Threads/Mutex.hpp>
#include <FlameIDE/Common/Macros/DetectOs.hpp>
#include <FlameIDE/Os/Constants.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <pthread.h>
#include <errno.h>

// need static functions

namespace flame_ide
{namespace threads
{

static inline bool operator!=(const os::MutexContext &contex1
		, const os::MutexContext &contex2)
{
	return memcmp(&contex1, &contex2, sizeof(os::MutexContext));
}

static inline bool operator==(const os::MutexContext &contex1
		, const os::MutexContext &contex2)
{
	return !(contex1 != contex2);
}

static inline os::MutexContext mutexContextInit() noexcept
{
	os::MutexContext ctx;
	if (pthread_mutexattr_init(&ctx.attributes))
	{
		return os::MUTEX_CONTEXT_INITIALIZER;
	}
	if (pthread_mutex_init(&ctx.object, &ctx.attributes))
	{
		return os::MUTEX_CONTEXT_INITIALIZER;
	}
	return ctx;
}

static inline os::Status mutexContextDestroy(os::MutexContext &ctx) noexcept
{
	if (ctx == os::MUTEX_CONTEXT_INITIALIZER)
	{
		return os::STATUS_SUCCESS;
	}
	if (pthread_mutexattr_destroy(&ctx.attributes))
	{
		return -errno;
	}
	if (pthread_mutex_destroy(&ctx.object))
	{
		return -errno;
	}
	return os::STATUS_SUCCESS;
}

static inline Mutex::State mutexGetState(os::MutexContext &ctx) noexcept
{
	auto tryLockStatus = -pthread_mutex_trylock(&ctx.object);
	if (tryLockStatus)
	{
		switch (tryLockStatus)
		{
			case -EBUSY:
				return Mutex::State::LOCKED;
			case -EINVAL:
				return Mutex::State::INVALID;
		}
	}
	if (pthread_mutex_unlock(&ctx.object))
	{
		return Mutex::State::INVALID;
	}
	return Mutex::State::UNLOCKED;
}

}}

// Mutex

namespace flame_ide
{namespace threads
{

Mutex::Mutex() noexcept :
		context{ mutexContextInit() }
		, status{ os::STATUS_SUCCESS }
{
	if (context == os::MUTEX_CONTEXT_INITIALIZER)
	{
		status = -errno;
	}
}

Mutex::Mutex(Mutex &&mutex) noexcept : context(mutex.context)
{
	mutex.context = os::MUTEX_CONTEXT_INITIALIZER;
}

Mutex::~Mutex() noexcept
{
	mutexContextDestroy(context);
}

Mutex &Mutex::operator=(Mutex &&mutex) noexcept
{
	if (this != &mutex)
	{
		status = mutexContextDestroy(context);
		if (!status)
		{
			return *this;
		}

		context = mutex.context;
		mutex.context = os::MUTEX_CONTEXT_INITIALIZER;
	}
	return *this;
}

void Mutex::lock() noexcept
{
	if (!status)
	{
		if (pthread_mutex_lock(&context.object))
		{
			status = -errno;
		}
		else
		{
			status = os::STATUS_SUCCESS;
		}
	}
}

void Mutex::unlock() noexcept
{
	if (!status)
	{
		if (pthread_mutex_unlock(&context.object))
		{
			status = -errno;
		}
		else
		{
			status = os::STATUS_SUCCESS;
		}
	}
}

Mutex::State Mutex::getState() const noexcept
{
	auto state = mutexGetState(context);
	if (state == State::INVALID)
	{
		status = -errno;
	}
	else
	{
		status = os::STATUS_SUCCESS;
	}
	return state;
}

os::Status Mutex::getStatus() const noexcept
{
	return status;
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
