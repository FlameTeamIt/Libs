#ifndef FLAMEIDE_OS_THREADS_SEMAPHORE_HPP
#define FLAMEIDE_OS_THREADS_SEMAPHORE_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

class Semaphore
{
public:
	Semaphore() noexcept;

	Semaphore(const Semaphore &) = delete;
	Semaphore(Semaphore &&semaphore) noexcept;

	Semaphore(os::SemaphoreValue initValue) noexcept;

	~Semaphore() noexcept;

	Semaphore &operator=(const Semaphore &) = delete;
	Semaphore &operator=(Semaphore &&semaphore) noexcept;

	operator bool() const noexcept;

	void post() noexcept;

	void wait() noexcept;

	bool tryWait() noexcept;

	os::SemaphoreContext &native() noexcept;

	os::SemaphoreValue getValue() const noexcept;

	os::Status getStatus() const noexcept;

private:
	mutable os::SemaphoreContext context; ///<
	mutable os::Status status; ///<
};

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_SEMAPHORE_HPP
