#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <pthread.h>
#include <errno.h>

#include <FlameIDE/Threads/Semaphore.hpp>

// need static functions

namespace flame_ide
{namespace threads
{

static inline bool operator!=(const os::SemaphoreContext &contex1
		, const os::SemaphoreContext &contex2)
{
	return ::memcmp(&contex1, &contex2, sizeof (os::SemaphoreContext));
}

static inline bool operator==(const os::SemaphoreContext &contex1
		, const os::SemaphoreContext &contex2)
{
	return !(contex1 != contex2);
}

static inline os::SemaphoreContext semaphoreContexInit(os::SemaphoreValue value)
{
	os::SemaphoreContext ctx;
	if (::sem_init(&ctx, 0, value))
	{
		return os::SEMAPHORE_CONTEXT_INITIALIZER;
	}
	return ctx;
}

static inline os::Status semaphoreContexDestroy(os::SemaphoreContext &ctx)
{
	if (ctx != os::SEMAPHORE_CONTEXT_INITIALIZER && ::sem_destroy(&ctx))
	{
		return -errno;
	}
	return os::STATUS_SUCCESS;
}

}}

namespace flame_ide
{namespace threads
{

Semaphore::Semaphore() noexcept : Semaphore(os::SEMAPHORE_VALUE_DEFAULT)
{}

Semaphore::Semaphore(Semaphore &&sem) noexcept : context(sem.context)
{
	sem.context = os::SEMAPHORE_CONTEXT_INITIALIZER;
}

Semaphore::Semaphore(os::SemaphoreValue value) noexcept :
		context(semaphoreContexInit(value))
{
	if (context == os::SEMAPHORE_CONTEXT_INITIALIZER)
	{
		status = -errno;
	}
}

Semaphore::~Semaphore() noexcept
{
	semaphoreContexDestroy(context);
}

Semaphore &Semaphore::operator=(Semaphore &&semaphore) noexcept
{
	if (this != &semaphore)
	{
		if (!status)
		{
			status = semaphoreContexDestroy(context);
			if (status != os::STATUS_SUCCESS)
			{
				return *this;
			}

			context = semaphore.context;
			semaphore.context = os::SEMAPHORE_CONTEXT_INITIALIZER;
		}
	}
	return *this;
}

void Semaphore::post() noexcept
{
	if (!status && ::sem_post(&context))
	{
		status = -errno;
	}
}

void Semaphore::wait() noexcept
{
	if (!status && ::sem_wait(&context))
	{
		status = -errno;
	}
}

os::SemaphoreValue Semaphore::getValue() const noexcept
{
	int value = 0;
	if (!status && ::sem_getvalue(&context, &value))
	{
		return static_cast<os::SemaphoreValue>(value);
	}
	return os::SEMAPHORE_VALUE_INVALID;
}

os::Status Semaphore::getStatus() const noexcept
{
	return status;
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
