#include <FlameIDE/../../src/Os/Threads/SpinFunctions.hpp>

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
{namespace spin
{

os::Status init(os::SpinContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_spin_init(&context, 0), status);
	return status;
}

os::Status destroy(os::SpinContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_spin_destroy(&context), status);
	return status;
}

os::Status lock(os::SpinContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_spin_lock(&context), status);
	return status;
}

TryLockStatus tryLock(os::SpinContext &context) noexcept
{
	TryLockStatus status = static_cast<TryLockStatus>(-::pthread_spin_trylock(&context));
	return status;
}

os::Status unlock(os::SpinContext &context) noexcept
{
	os::Status status = {};
	RETURN_RESULT(::pthread_spin_unlock(&context), status);
	return status;
}

}}}} // namespace flame_ide::os::threads::spin
