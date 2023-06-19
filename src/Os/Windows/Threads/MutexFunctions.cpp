#include <FlameIDE/../../src/Os/Threads/MutexFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#define GET_LAST_ERROR \
		-static_cast<flame_ide::os::Status>(::GetLastError())

namespace flame_ide
{namespace os
{namespace threads
{namespace mutex
{

os::Status init(os::MutexContext &context) noexcept
{
	constexpr ::LONG MUTEX_INITIAL_VALUE = 1;
	os::Status status = os::STATUS_SUCCESS;
	context.object = ::CreateSemaphoreA(
			nullptr
			, MUTEX_INITIAL_VALUE
			, MUTEX_INITIAL_VALUE
			, nullptr
	);
	if (!context.object)
	{
		status = GET_LAST_ERROR;
	}
	return status;
}

os::Status destroy(os::MutexContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	if (!::CloseHandle(context.object))
	{
		status = GET_LAST_ERROR;
	}
	return status;
}

os::Status lock(os::MutexContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	auto value = ::WaitForSingleObject(context.object, windows::OS_INFINITE_WAIT);
	if (value != WAIT_OBJECT_0)
	{
		status = GET_LAST_ERROR;
	}
	return status;
}

TryLockStatus tryLock(os::MutexContext &context) noexcept
{
	TryLockStatus tryLockStatus = TryLockStatus::TRY_LOCK_OK;
	auto value = ::WaitForSingleObject(context.object, windows::OS_NO_WAIT);
	switch (value)
	{
		case WAIT_OBJECT_0:
			break;
		case WAIT_TIMEOUT:
			tryLockStatus = TryLockStatus::TRY_LOCK_BUSY;
			break;
		default:
			tryLockStatus = static_cast<TryLockStatus>(GET_LAST_ERROR);
			break;
	}
	return tryLockStatus;
}

os::Status unlock(os::MutexContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	if (!::ReleaseSemaphore(context.object, 1, nullptr))
	{
		status = GET_LAST_ERROR;
	}
	return status;
}

}}}} // namespace flame_ide::os::threads::mutex
