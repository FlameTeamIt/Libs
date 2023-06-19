#include <FlameIDE/../../src/Os/Threads/SemaphoreFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#define RETURN_RESULT(condition, result) \
{ \
	result = condition; \
	if (result != os::STATUS_SUCCESS) \
	{ \
		result = -errno; \
	} \
}

namespace flame_ide
{namespace os
{namespace threads
{namespace semaphore
{

os::Status init(os::SemaphoreContext &context, os::SemaphoreValue value) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::sem_init(&context.object, 0, value), status);
	return status;
}

os::Status destroy(os::SemaphoreContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::sem_destroy(&context.object), status);
	return status;
}

os::Status post(os::SemaphoreContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::sem_post(&context.object), status);
	return status;
}

os::Status wait(os::SemaphoreContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::sem_wait(&context.object), status);
	return status;
}

TryLockStatus tryWait(os::SemaphoreContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::sem_trywait(&context.object), status);
	switch (status)
	{
		case -EAGAIN:
			return TryLockStatus::TRY_LOCK_BUSY;
		case -EDEADLK:
			return TryLockStatus::TRY_LOCK_DEAD_LOCK;
		case -EINTR:
			return TryLockStatus::TRY_LOCK_INTERRUPT;
		case -EINVAL:
			return TryLockStatus::TRY_LOCK_INVLID_VALUE;
		default:
			return TryLockStatus::TRY_LOCK_OK;
	}
}

os::SemaphoreValue value(os::SemaphoreContext &context) noexcept
{
	os::Status status = {};
	os::SemaphoreValue value = {};
	RETURN_RESULT(::sem_getvalue(&context.object, &value), status);
	if (status < 0)
	{
		return status;
	}
	return value;
}

}}}} // namespace flame_ide::os::threads::semaphore
