#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Threads/SpinFunctions.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

Spin::Spin() noexcept
{
	status = spin::init(context);
}

Spin::Spin(Spin &&spinlock) noexcept
{
	operator=(flame_ide::move(spinlock));
}

Spin::~Spin() noexcept
{
	if (flame_ide::isEqual(context, SPINLOCK_CONTEXT_INITIALIZER))
	{
		return;
	}
	status = spin::destroy(context);
}

Spin &Spin::operator=(Spin &&spinlock) noexcept
{
	if (!flame_ide::isEqual(context, os::SPINLOCK_CONTEXT_INITIALIZER))
	{
		spin::destroy(context);
	}

	context = spinlock.context;
	status = spinlock.status;

	spinlock.context = os::SPINLOCK_CONTEXT_INITIALIZER;
	spinlock.status = os::STATUS_SUCCESS;

	return *this;
}

Spin::operator bool() const noexcept
{
	return status == os::STATUS_SUCCESS;
}

void Spin::lock() noexcept
{
	status = spin::lock(context);
}

void Spin::unlock() noexcept
{
	status = spin::unlock(context);
}

bool Spin::tryLock() noexcept
{
	auto tryLockStatus = spin::tryLock(context);
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

os::SpinContext &Spin::native() noexcept
{
	return context;
}

os::Status Spin::getStatus() const noexcept
{
	return status;
}

}}} // namespace flame_ide::os::threads
