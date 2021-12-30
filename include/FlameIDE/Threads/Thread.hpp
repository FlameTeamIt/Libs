#ifndef FLAMEIDE_THREADS_THREAD_HPP
#define FLAMEIDE_THREADS_THREAD_HPP

#include <FlameIDE/Os/Thread.hpp>

namespace flame_ide
{namespace threads
{

class Thread
{
public:
	Thread() noexcept;
	Thread(const Thread &) = delete;
	Thread(Thread &&thread) noexcept;
	virtual ~Thread() noexcept;

	Thread &operator=(const Thread &) = delete;
	Thread &operator=(Thread &&) noexcept;

	///
	/// @brief run
	///
	void run() noexcept;

	///
	/// @brief join
	///
	void join() noexcept;

	///
	/// @brief detach
	///
	void detach() noexcept;

	///
	/// @brief getStatus
	/// @return
	///
	os::Status getStatus() const noexcept;

protected:
	///
	/// @brief vRun
	///
	virtual void vRun() = 0;

	os::Thread object; ///<

private:
	///
	/// @brief task
	/// @param data
	/// @return
	///
	static os::ThreadTaskTrait::ReturnType
	task(Thread *thread) noexcept;

	os::Status status; ///<
};

}} // namespace flame_ide::threads

#endif // FLAMEIDE_THREADS_THREAD_HPP
