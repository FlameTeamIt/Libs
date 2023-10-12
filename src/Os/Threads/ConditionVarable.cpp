#include <FlameIDE/Os/Threads/ConditionVariable.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

ConditionVariable::~ConditionVariable()
{
	notify();
}

void ConditionVariable::wait()
{
	locker.lock();
}

void ConditionVariable::notify()
{
	locker.unlock();
}

}}} // namespace flame_ide::os::threads
