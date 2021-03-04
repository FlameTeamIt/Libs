#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Threads/Semaphore.hpp>

namespace flame_ide
{namespace threads
{

static inline os::SemaphoreContext createContext(os::SemaphoreValue value) noexcept
{
	return os::SemaphoreContext {
		CreateSemaphoreA(nullptr, value, value, nullptr)
		, value
	};
}

static inline bool operator==(const os::SemaphoreContext &context1
		, const os::SemaphoreContext &context2)
{
	return context1.object.value == context2.object.value
			&& context1.value == context2.value;
}

static inline bool operator!=(const os::SemaphoreContext &context1
		, const os::SemaphoreContext &context2)
{
	return !(context1 == context2);
}

Semaphore::Semaphore() noexcept : Semaphore(os::SEMAPHORE_VALUE_DEFAULT)
{}

Semaphore::Semaphore(Semaphore &&semaphore) noexcept : context(semaphore.context)
{
	semaphore.context = os::SEMAPHORE_CONTEXT_INITIALIZER;
}

Semaphore::Semaphore(os::SemaphoreValue initValue) noexcept :
		context(createContext(initValue))
		, status(os::STATUS_SUCCESS)
{
	if (context == os::SEMAPHORE_CONTEXT_INITIALIZER)
	{
		status = GetLastError();
	}
}

Semaphore::~Semaphore() noexcept
{
	if (context != os::SEMAPHORE_CONTEXT_INITIALIZER)
	{
		CloseHandle(context.object);
	}
}

Semaphore &Semaphore::operator=(Semaphore &&semaphore) noexcept
{
	if (context != os::SEMAPHORE_CONTEXT_INITIALIZER)
	{
		if (!CloseHandle(context.object))
		{
			status = GetLastError();
		}
	}

	context = semaphore.context;
	semaphore.context = os::SEMAPHORE_CONTEXT_INITIALIZER;

	return *this;
}

void Semaphore::post() noexcept
{
	if (!ReleaseSemaphore(context.object, 1, nullptr))
	{
		status = GetLastError();
	}
	context.value = InterlockedIncrement(&context.value);
}

void Semaphore::wait() noexcept
{
	os::Status statusLocal = WaitForSingleObject(context.object, 0);
	switch(statusLocal)
	{
		case WAIT_OBJECT_0:
		{
			context.value = InterlockedDecrement(&context.value);
			break;
		}

		case WAIT_TIMEOUT:
		default:
		{
			status = GetLastError();
			break;
		}
	}
}

os::SemaphoreValue Semaphore::getValue() const noexcept
{
	return InterlockedAdd(&context.value, 0);
}

os::Status Semaphore::getStatus() const noexcept
{
	return status;
}


}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
