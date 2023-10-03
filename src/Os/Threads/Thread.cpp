#include <FlameIDE/Os/Threads/Thread.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Threads/ThreadFunctions.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

ThreadBase::ThreadBase() noexcept :
		context{ os::THREAD_CONTEXT_INITIALIZER }
		, status{}
{}

ThreadBase::ThreadBase(ThreadBase &&thread) noexcept :
		status{ os::STATUS_SUCCESS }
{
	operator=(flame_ide::move(thread));
}

ThreadBase::~ThreadBase() noexcept
{
	if (flame_ide::isEqual(context, os::THREAD_CONTEXT_INITIALIZER))
	{
		return;
	}

	join();
	thread::destroy(context);
}

ThreadBase &ThreadBase::operator=(ThreadBase &&thread) noexcept
{
	if (!flame_ide::isEqual(context, os::THREAD_CONTEXT_INITIALIZER))
	{
		thread::destroy(context);
	}

	context = thread.context;
	status = thread.status;

	thread.context = os::THREAD_CONTEXT_INITIALIZER;
	thread.status = os::STATUS_SUCCESS;

	return *this;
}

void ThreadBase::run() noexcept
{
	if (flame_ide::isEqual(context, os::THREAD_CONTEXT_INITIALIZER))
	{
		status = thread::init(context);
	}
	if (status == os::STATUS_SUCCESS)
	{
		status = thread::create(context, (os::ThreadTaskTrait::Task)(task), this);
	}
}

void ThreadBase::join() noexcept
{
	os::ThreadTaskTrait::Return ret = {};
	status = thread::join(context, ret);
}

void ThreadBase::detach() noexcept
{
	status = thread::detach(context);
	if (status != os::STATUS_SUCCESS)
	{
		return;
	}

	status = thread::destroy(context);
	if (status != os::STATUS_SUCCESS)
	{
		return;
	}

	context = os::THREAD_CONTEXT_INITIALIZER;
}

bool ThreadBase::isWorking() const noexcept
{
	auto workingStatus = thread::isWorking(context);
	if (workingStatus > 0)
		return workingStatus;
	return false;
}

os::Status ThreadBase::getStatus() const noexcept
{
	return status;
}

os::ThreadTaskTrait::Return ThreadBase::task(ThreadBase *data) noexcept
{
	data->vRun();
	return {};
}

}}} // namespace flame_ide::os::threads
