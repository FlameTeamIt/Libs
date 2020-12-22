#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Common/OsTypes.hpp>
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
	if (!ReleaseSemaphore(context.object, 1, &context.value))
	{
		status = GetLastError();
	}
}

void Semaphore::wait() noexcept
{
	if (WaitForSingleObject(context.object, INFINITE))
	{
		status = GetLastError();
	}
}

os::SemaphoreValue Semaphore::getValue() const noexcept
{
	return context.value;
}

os::Status Semaphore::getStatus() const noexcept
{
	return status;
}


}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
