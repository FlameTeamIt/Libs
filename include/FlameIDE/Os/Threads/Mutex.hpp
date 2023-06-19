#ifndef FLAMEIDE_OS_THREADS_MUTEX_HPP
#define FLAMEIDE_OS_THREADS_MUTEX_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

class Mutex
{
public:
	Mutex() noexcept;

	Mutex(const Mutex &) = delete;
	Mutex(Mutex &&mutex) noexcept;

	~Mutex() noexcept;

	Mutex &operator=(const Mutex &) = delete;
	Mutex &operator=(Mutex &&mutex) noexcept;

	operator bool() const noexcept;

	void lock() noexcept;
	void unlock() noexcept;

	bool tryLock() noexcept;

	os::MutexContext &native() noexcept;

	os::Status getSatus() const noexcept;

private:
	os::Status status;
	os::MutexContext context;
};

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_MUTEX_HPP
