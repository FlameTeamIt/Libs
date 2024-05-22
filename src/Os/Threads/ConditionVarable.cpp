#include <FlameIDE/Os/Threads/ConditionVariable.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

ConditionVariable::~ConditionVariable() noexcept
{
	notify();
}

void ConditionVariable::wait() noexcept
{
	++counter;

	if (!counter.current())
		return;

	locker.lock();
	locker.unlock();

	--counter;
}

bool ConditionVariable::tryWait() noexcept
{
	bool lockStatus = locker.tryLock();
	if (lockStatus)
		locker.unlock();
	return lockStatus;
}

void ConditionVariable::unwait() noexcept
{
	--counter;
}

bool ConditionVariable::isWait() const noexcept
{
	return counter.current();
}

void ConditionVariable::notify() noexcept
{
	volatile auto counterValue = counter.current();
	if (!counterValue)
		return;

	locker.unlock();
	do {} while (counter.current() != (counterValue - 1));
	do {} while (!locker.tryLock());
}

}}} // namespace flame_ide::os::threads
