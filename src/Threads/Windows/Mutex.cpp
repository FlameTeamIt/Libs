#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Threads/Mutex.hpp>

namespace flame_ide
{namespace threads
{

static inline os::MutexContext getContext() noexcept
{
	return CreateMutexA(nullptr, false, nullptr);
}

Mutex::Mutex() noexcept :
		context(getContext())
		, status{ os::STATUS_SUCCESS }
{}

Mutex::Mutex(Mutex &&mutex) noexcept :
		context(mutex.context)
		, status{ mutex.status }
{
	mutex.context = os::MUTEX_CONTEXT_INITIALIZER;
}

Mutex::~Mutex() noexcept
{
	if (context != os::MUTEX_CONTEXT_INITIALIZER)
	{
		CloseHandle(context);
	}
}

Mutex &Mutex::operator=(Mutex &&mutex) noexcept
{
	if (context != os::MUTEX_CONTEXT_INITIALIZER)
	{
		if (!CloseHandle(context))
		{
			status = GetLastError();
			return *this;
		}
	}

	context = mutex.context;
	mutex.context = os::MUTEX_CONTEXT_INITIALIZER;

	return *this;
}

void Mutex::lock() noexcept
{
	if (!WaitForSingleObject(context, INFINITE))
	{
		status = GetLastError();
	}
}

void Mutex::unlock() noexcept
{
	if (ReleaseMutex(context))
	{
		status = GetLastError();
	}
}

Mutex::State Mutex::getState() const noexcept
{
	os::Status statusLocal = WaitForSingleObject(context, 0);
	switch(statusLocal)
	{
		case WAIT_OBJECT_0:
			if (!ReleaseMutex(context))
			{
				status = GetLastError();
				return State::INVALID;
			}
			return State::UNLOCKED;

		case WAIT_ABANDONED:
		case WAIT_TIMEOUT:
			return State::LOCKED;

		default:
			status = GetLastError();
			return State::INVALID;
	}
}

os::Status Mutex::getStatus() const noexcept
{
	return status;
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
