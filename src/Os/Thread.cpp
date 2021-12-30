#include <FlameIDE/Os/Thread.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/ThreadFunctions.hpp>

namespace flame_ide
{namespace os
{

Thread::Thread() noexcept
		: context{}
		, task{}
		, lastStatus{ STATUS_SUCCESS }
		, needJoin{ false }
{}

Thread::Thread(ThreadTask task, bool needJoin) noexcept
		: context{}
		, task{ task }
		, lastStatus{ STATUS_SUCCESS }
		, needJoin{ needJoin }
{}

Thread::Thread(Thread &&thread) noexcept
{
	operator=(move(thread));
}

Thread::~Thread() noexcept
{
	if (needJoin)
	{
		join();
	}
}

Thread &Thread::operator=(Thread &&thread) noexcept
{
	context = thread.context;
	task = thread.task;
	lastStatus = thread.lastStatus;
	needJoin = thread.needJoin;

	thread.context = ThreadContext{};
	thread.task = ThreadTask{};
	thread.needJoin = false;

	return *this;
}


void Thread::run() noexcept
{
	lastStatus = createThread(context, task.taskValue, task.argumentValue);
}

void Thread::join() noexcept
{
	lastStatus = joinThread(context);
}

void Thread::detach() noexcept
{
	needJoin = false;
}

bool Thread::setTask(ThreadTask task, bool needJoin) noexcept
{
	if (task)
	{
		return false;
	}

	this->task = task;
	this->needJoin = needJoin;
	return true;
}

Status Thread::status() const noexcept
{
	return lastStatus;
}

ThreadContext &Thread::native() noexcept
{
	return context;
}

const ThreadContext &Thread::native() const noexcept
{
	return context;
}

}} // namespace flame_ide::os
