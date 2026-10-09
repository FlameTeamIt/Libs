#include <FlameIDE/../../src/Handler/Network/WorkerBase.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

WorkerBase::Notifier WorkerBase::notifier() noexcept
{
	return WorkerBase::Notifier{ condvar };
}

os::Status WorkerBase::start() noexcept
{
	run();
	return getStatus();

}

os::Status WorkerBase::stop() noexcept
{
	{
		os::threads::Locker locker{ stopSpin };
		stopFlag = true;
	}

	if (condvar.isWait())
		condvar.notify();

	// join();
	return getStatus();
}

void WorkerBase::vRun() noexcept
{
	while (!needStop())
	{
		condvar.wait();

		if (needStop())
			break;

		processing();
	}
}

bool WorkerBase::needStop() noexcept
{
	os::threads::Locker locker{ stopSpin };
	return stopFlag;
}

//

WorkerBase::Notifier::Notifier(os::threads::ConditionVariable &condvarInit) noexcept
		: condvar{ &condvarInit }
{}

void WorkerBase::Notifier::operator()() noexcept
{
	condvar->notify();
}

}}} // namespace flame_ide::handler::network
