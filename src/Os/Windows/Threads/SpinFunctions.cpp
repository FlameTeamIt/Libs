#include <FlameIDE/../../src/Os/Threads/SpinFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace spin
{

os::Status init(os::SpinContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	context = os::SpinContext{ os::windows::OS_SPINLOCK_VALUE_UNLOCKED };
	return status;
}

os::Status destroy(os::SpinContext &context) noexcept
{
	context = os::SPINLOCK_CONTEXT_INITIALIZER;
	return os::STATUS_SUCCESS;
}

os::Status lock(os::SpinContext &context) noexcept
{
	while (tryLock(context) != TryLockStatus::TRY_LOCK_BUSY);
	return os::STATUS_SUCCESS;
}

TryLockStatus tryLock(os::SpinContext &context) noexcept
{
	auto status = TryLockStatus::TRY_LOCK_OK;
	volatile windows::OsSpinlockValue *value = &context.value;
	if (::InterlockedAnd(value, windows::OS_SPINLOCK_VALUE_LOCKED)
			== windows::OS_SPINLOCK_VALUE_LOCKED)
	{
		status = TryLockStatus::TRY_LOCK_BUSY;
	}
	else
	{
		::InterlockedExchange(value, windows::OS_SPINLOCK_VALUE_LOCKED);
	}
	return status;
}

os::Status unlock(os::SpinContext &context) noexcept
{
	volatile windows::OsSpinlockValue *value = &context.value;
	::InterlockedExchange(value, windows::OS_SPINLOCK_VALUE_UNLOCKED);
	return os::STATUS_SUCCESS;
}

}}}} // namespace flame_ide::os::threads::spin
