#include <FlameIDE/Os/Threads/Semaphore.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Threads/SemaphoreFunctions.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

Semaphore::Semaphore() noexcept : Semaphore(os::SEMAPHORE_VALUE_DEFAULT)
{}

Semaphore::Semaphore(Semaphore &&semaphore) noexcept :
		context{ os::SEMAPHORE_CONTEXT_INITIALIZER }
{
	operator=(flame_ide::move(semaphore));
}

Semaphore::Semaphore(os::SemaphoreValue initValue) noexcept
{
	status = semaphore::init(context, initValue);
}

Semaphore::~Semaphore() noexcept
{
	if (os::SEMAPHORE_CONTEXT_INITIALIZER == context)
	{
		return;
	}
	status = semaphore::destroy(context);
}

Semaphore &Semaphore::operator=(Semaphore &&semaphore) noexcept
{
	if (os::SEMAPHORE_CONTEXT_INITIALIZER == context)
	{
		semaphore::destroy(context);
	}

	context = semaphore.context;
	status = semaphore.status;

	semaphore.context = os::SEMAPHORE_CONTEXT_INITIALIZER;
	semaphore.status = os::STATUS_SUCCESS;

	return *this;
}

Semaphore::operator bool() const noexcept
{
	return (status == os::STATUS_SUCCESS);
}

void Semaphore::post() noexcept
{
	status = semaphore::post(context);
}

void Semaphore::wait() noexcept
{
	status = semaphore::wait(context);
}

bool Semaphore::tryWait() noexcept
{
	auto tryLockStatus = semaphore::tryWait(context);
	switch (tryLockStatus)
	{
		case TryLockStatus::TRY_LOCK_OK:
			return true;

		case TryLockStatus::TRY_LOCK_BUSY:
			return false;

		default:
			status = static_cast<os::Status>(tryLockStatus);
			return false;
	}
}

os::SemaphoreContext &Semaphore::native() noexcept
{
	return context;
}

os::SemaphoreValue Semaphore::getValue() const noexcept
{
	return semaphore::value(context);
}

os::Status Semaphore::getStatus() const noexcept
{
	return status;
}

}}} // namespace flame_ide::os::threads
