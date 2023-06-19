#include <FlameIDE/../../src/Os/Threads/MutexFunctions.hpp>

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
{namespace mutex
{

os::Status init(os::MutexContext &context) noexcept
{
	os::Status status = {};

	RETURN_RESULT(::pthread_mutexattr_init(&context.attributes), status);
	if (status < 0)
	{
		context = os::MUTEX_CONTEXT_INITIALIZER;
		return status;
	}

	RETURN_RESULT(::pthread_mutex_init(&context.object, &context.attributes), status);
	if (status < 0)
	{
		os::Status attrDestroyStatus = {};
		RETURN_RESULT(
				::pthread_mutexattr_destroy(&context.attributes)
				, attrDestroyStatus
		);
		context = os::MUTEX_CONTEXT_INITIALIZER;
	}
	return status;
}

os::Status destroy(os::MutexContext &context) noexcept
{
	os::Status status = {};
	if (!flame_ide::isEqual(context.object, os::MUTEX_CONTEXT_INITIALIZER.object))
	{
		RETURN_RESULT(::pthread_mutex_destroy(&context.object), status);
	}
	if (!flame_ide::isEqual(context.attributes
			, os::MUTEX_CONTEXT_INITIALIZER.attributes))
	{
		RETURN_RESULT(::pthread_mutexattr_destroy(&context.attributes), status);
	}
	return status;
}

os::Status lock(os::MutexContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_mutex_lock(&context.object), status);
	return status;
}

TryLockStatus tryLock(os::MutexContext &context) noexcept
{
	return static_cast<TryLockStatus>(-::pthread_mutex_trylock(&context.object));
}

os::Status unlock(os::MutexContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_mutex_unlock(&context.object), status);
	return status;
}

}}}} // namespace flame_ide::os::threads::mutex
