#ifndef FLAMEIDE_OS_THREADS_SPIN_HPP
#define FLAMEIDE_OS_THREADS_SPIN_HPP

#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

class Spin
{
public:
	Spin() noexcept;

	Spin(const Spin &) noexcept = delete;
	Spin(Spin &&spinlock) noexcept;

	~Spin() noexcept;

	Spin &operator=(const Spin &) noexcept = delete;
	Spin &operator=(Spin &&spinlock) noexcept;

	operator bool() const noexcept;

	void lock() noexcept;
	void unlock() noexcept;

	bool tryLock() noexcept;

	os::SpinContext &native() noexcept;
	
	os::Status getStatus() const noexcept;

private:
	os::Status status;
	os::SpinContext context;
};

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_SPIN_HPP
