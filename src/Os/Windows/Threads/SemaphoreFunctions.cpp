#include <FlameIDE/../../src/Os/Threads/SemaphoreFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#define GET_LAST_ERROR \
		-static_cast<flame_ide::os::Status>(::GetLastError())

namespace flame_ide
{namespace os
{namespace threads
{namespace semaphore
{
namespace // anonymous
{

void increment(os::SemaphoreValue &value)
{
	volatile SemaphoreValue *exchangeValue = &value;
	::InterlockedIncrement(exchangeValue);
}

void decrement(os::SemaphoreValue &value)
{
	volatile SemaphoreValue *exchangeValue = &value;
	::InterlockedDecrement(exchangeValue);
}

os::SemaphoreValue value(os::SemaphoreValue &value)
{
	volatile SemaphoreValue *exchangeValue = &value;
	::InterlockedCompareExchange(exchangeValue, value, true);
	return *exchangeValue;
}

} // namespace anonymous
}}}} // namespace flame_ide::os::threads::semaphore

namespace flame_ide
{namespace os
{namespace threads
{namespace semaphore
{

os::Status init(os::SemaphoreContext &context, os::SemaphoreValue value) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	context.value = value;
	context.object = ::CreateSemaphoreA(nullptr, value, value, nullptr);
	if (!context.object)
	{
		status = GET_LAST_ERROR;
	}
	return status;
}

os::Status destroy(os::SemaphoreContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	if (!::CloseHandle(context.object))
	{
		status = GET_LAST_ERROR;
	}
	else
	{
		context = os::SEMAPHORE_CONTEXT_INITIALIZER;
	}
	return status;
}

os::Status wait(os::SemaphoreContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	auto value = ::WaitForSingleObject(context.object, windows::OS_INFINITE_WAIT);
	if (value != WAIT_OBJECT_0)
	{
		status = GET_LAST_ERROR;
	}

	decrement(context.value);

	return status;
}

TryLockStatus tryWait(os::SemaphoreContext &context) noexcept
{
	TryLockStatus tryLockStatus = TryLockStatus::TRY_LOCK_OK;
	auto value = ::WaitForSingleObject(context.object, windows::OS_NO_WAIT);
	switch (value)
	{
		case WAIT_OBJECT_0:
			decrement(context.value);
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

os::Status post(os::SemaphoreContext &context) noexcept
{
	os::Status status = os::STATUS_SUCCESS;
	if (!::ReleaseSemaphore(context.object, 1, nullptr))
	{
		status = GET_LAST_ERROR;
	}
	else
	{
		increment(context.value);
	}
	return status;
}

os::SemaphoreValue value(os::SemaphoreContext &context) noexcept
{
	os::SemaphoreValue contextValue = value(context.value);
	return contextValue;
}

}}}} // namespace flame_ide::os::threads::semaphore
