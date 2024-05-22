#include <FlameIDE/Os/Threads/Mutex.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Threads/MutexFunctions.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

Mutex::Mutex() noexcept
{
	status = mutex::init(context);
}

Mutex::Mutex(Mutex &&mutex) noexcept
{
	operator=(flame_ide::move(mutex));
}

Mutex::~Mutex() noexcept
{
	if (flame_ide::isEqual(context, os::MUTEX_CONTEXT_INITIALIZER))
		return;

	status = mutex::destroy(context);
}

Mutex &Mutex::operator=(Mutex &&mutex) noexcept
{
	if (!flame_ide::isEqual(context, os::MUTEX_CONTEXT_INITIALIZER))
	{
		mutex::destroy(context);
	}

	context = mutex.context;
	status = mutex.status;

	mutex.context = os::MUTEX_CONTEXT_INITIALIZER;
	mutex.status = os::STATUS_SUCCESS;

	return *this;
}

Mutex::operator bool() const noexcept
{
	return status == os::STATUS_SUCCESS;
}

void Mutex::lock() noexcept
{
	status = mutex::lock(context);
}

void Mutex::unlock() noexcept
{
	status = mutex::unlock(context);
}

bool Mutex::tryLock() noexcept
{
	auto tryLockStatus = mutex::tryLock(context);
	if (tryLockStatus == TryLockStatus::TRY_LOCK_OK)
	{
		return true;
	}
	if (tryLockStatus != TryLockStatus::TRY_LOCK_BUSY)
	{
		status = static_cast<os::Status>(tryLockStatus);
	}
	return false;
}

os::MutexContext &Mutex::native() noexcept
{
	return context;
}

os::Status Mutex::getStatus() const noexcept
{
	return status;
}

}}} // namespace flame_ide::os::threads
