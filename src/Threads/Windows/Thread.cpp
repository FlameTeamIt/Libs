#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Threads/Thread.hpp>

namespace flame_ide
{namespace threads
{

Thread::Thread() noexcept :
		context{ os::THREAD_CONTEXT_INITIALIZER }
		, status{ os::STATUS_SUCCESS }
{}

Thread::Thread(Thread &&thread) noexcept :
	context{ thread.context }
	, status{ os::STATUS_SUCCESS }
{
	thread.context = os::THREAD_CONTEXT_INITIALIZER;
}

Thread::~Thread() noexcept
{
	auto initializer = os::THREAD_CONTEXT_INITIALIZER;
	if (context != os::THREAD_CONTEXT_INITIALIZER)
	{
		join();
		CloseHandle(context);
	}
}

Thread &Thread::operator=(Thread &&thread) noexcept
{
	if (status == os::STATUS_SUCCESS &&
			context != os::THREAD_CONTEXT_INITIALIZER)
	{
		detach();
		if (status)
		{
			return *this;
		}
	}

	context = thread.context;
	thread.context = os::THREAD_CONTEXT_INITIALIZER;

	return *this;
}

void Thread::run() noexcept
{
	context = CreateThread(nullptr, 0, task, this, 0, nullptr);
	if (context == os::THREAD_CONTEXT_INITIALIZER)
	{
		status = GetLastError();
	}
}

void Thread::join() noexcept
{
	if (WaitForSingleObject(context, INFINITE))
	{
		status = GetLastError();
	}
}

void Thread::detach() noexcept
{
	if (!CloseHandle(context))
	{
		status = GetLastError();
	}
}

os::Status Thread::getStatus() const noexcept
{
	return status;
}

// private

os::ThreadTaskTrait::ReturnType
Thread::task(os::ThreadTaskTrait::ArgumentType data) noexcept
{
	reinterpret_cast<Thread *>(data)->vRun();
	ExitThread(0);
}


}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
