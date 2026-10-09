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
	while (tryLock(context) == TryLockStatus::TRY_LOCK_BUSY)
	{
		::YieldProcessor();
	}
	return os::STATUS_SUCCESS;
}

TryLockStatus tryLock(os::SpinContext &context) noexcept
{
	auto status = TryLockStatus::TRY_LOCK_OK;
	volatile windows::OsSpinlockValue *value = &context.value;

	windows::OsSpinlockValue result = ::InterlockedCompareExchange(
			value
			, windows::OS_SPINLOCK_VALUE_LOCKED
			, windows::OS_SPINLOCK_VALUE_UNLOCKED
	);
	if(result == windows::OS_SPINLOCK_VALUE_LOCKED)
	{
		status = TryLockStatus::TRY_LOCK_BUSY;
	}
	return status;
}

os::Status unlock(os::SpinContext &context) noexcept
{
	volatile windows::OsSpinlockValue *value = &context.value;
	windows::OsSpinlockValue result = {};
	do
	{
		result = ::InterlockedCompareExchange(
				value
				, windows::OS_SPINLOCK_VALUE_UNLOCKED
				, windows::OS_SPINLOCK_VALUE_LOCKED
		);
	}
	while (result != windows::OS_SPINLOCK_VALUE_LOCKED);

	return os::STATUS_SUCCESS;
}

}}}} // namespace flame_ide::os::threads::spin
