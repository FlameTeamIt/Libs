#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <pthread.h>
#include <errno.h>

#include <FlameIDE/Threads/Thread.hpp>

namespace flame_ide
{namespace threads
{

static inline os::Status attributesDestroy(pthread_attr_t &attrs)
{
	if (pthread_attr_destroy(&attrs))
	{
		return -errno;
	}
	return 0;
}

Thread::Thread() noexcept :
		context{ os::THREAD_CONTEXT_INITIALIZER }
		, status{ os::STATUS_SUCCESS }
{
	if (pthread_attr_init(&context.attributes) != os::STATUS_SUCCESS)
	{
		status = -errno;
	}
}

Thread::Thread(Thread &&thread) noexcept :
		context{ thread.context }
{
	thread.context = os::THREAD_CONTEXT_INITIALIZER;
}

Thread::~Thread() noexcept
{
	auto initializer = os::THREAD_CONTEXT_INITIALIZER;
	if (!memcmp(&context, &initializer, sizeof(os::ThreadContext)))
	{
		join();
		attributesDestroy(context.attributes);
	}
}

Thread &Thread::operator=(Thread &&thread) noexcept
{
	auto initializer = os::THREAD_CONTEXT_INITIALIZER;
	if (status == os::STATUS_SUCCESS
			&& memcmp(&context, &initializer, sizeof(os::ThreadContext)))
	{
		// FIXME: спорное решение
		detach();
		if (status)
		{
			return *this;
		}
		status = attributesDestroy(context.attributes);
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
	if (pthread_create(&context.object, &context.attributes, task, this))
	{
		status = -errno;
	}
}

void Thread::join() noexcept
{
	if (pthread_join(context.object, nullptr))
	{
		status = -errno;
	}
}

void Thread::detach() noexcept
{
	if (pthread_detach(context.object))
	{
		status = -errno;
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
	return os::ThreadTaskTrait::ReturnType{};
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
