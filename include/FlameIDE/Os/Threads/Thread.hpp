#ifndef FLAMEIDE_OS_THREADS_THREAD_HPP
#define FLAMEIDE_OS_THREADS_THREAD_HPP

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{namespace threads
{

class ThreadBase
{
public:
	ThreadBase() noexcept;
	ThreadBase(const ThreadBase &) = delete;
	ThreadBase(ThreadBase &&thread) noexcept;
	virtual ~ThreadBase() noexcept;

	ThreadBase &operator=(const ThreadBase &) = delete;
	ThreadBase &operator=(ThreadBase &&thread) noexcept;

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

	///
	/// @brief native
	/// @return
	///
	os::ThreadContext &native() noexcept;

protected:
	///
	/// @brief vRun
	///
	virtual void vRun() noexcept = 0;

	os::ThreadContext context; ///<

private:
	///
	/// @brief task
	/// @param data
	/// @return
	///
	static os::ThreadTaskTrait::Return task(ThreadBase *data) noexcept;

	os::Status status; ///<
};

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

template<typename Implementer>
class ThreadCrtp: public ThreadBase
{
public:
	virtual ~ThreadCrtp() noexcept override = default;

	/// @brief NEED TO IMPLEMENT
	// void body() noexcept;

private:
	virtual void vRun() noexcept override;

	Implementer &implementer() noexcept;

};

}}} // namespace flame_ide::os::threads

namespace flame_ide
{namespace os
{namespace threads
{

template<typename Implementer>
void ThreadCrtp<Implementer>::vRun() noexcept
{
	implementer().body();
}

template<typename Implementer>
Implementer &ThreadCrtp<Implementer>::implementer() noexcept
{
	return *static_cast<Implementer *>(this);
}

}}} // namespace flame_ide::os::threads

#endif // FLAMEIDE_OS_THREADS_THREAD_HPP
