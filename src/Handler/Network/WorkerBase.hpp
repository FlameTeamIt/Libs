#ifndef HANDLER_INTERNAL_WORKER_BASE_HPP
#define HANDLER_INTERNAL_WORKER_BASE_HPP

#include <FlameIDE/Common/FunctorBase.hpp>
#include <FlameIDE/Os/Threads/ConditionVariable.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class WorkerBase: private os::threads::ThreadBase
{
	using Parent = os::threads::ThreadBase;
	friend Parent;

public:
	class Notifier: public ::flame_ide::DefaultFunctorBase
	{
	public:
		Notifier(const WorkerBase::Notifier &) = default;
		Notifier(WorkerBase::Notifier &&) = default;
		Notifier(os::threads::ConditionVariable &condvar) noexcept;

		Notifier &operator=(const WorkerBase::Notifier &) = default;
		Notifier &operator=(WorkerBase::Notifier &&) = default;

		virtual void operator()() noexcept override;

	private:
		Notifier() = default;

	private:
		os::threads::ConditionVariable *condvar;
	};

public:
	using Parent::getStatus;

	///
	/// @brief getNotifier
	/// @return
	///
	Notifier notifier() noexcept;

	///
	/// @brief start
	/// @return
	///
	os::Status start() noexcept;

	///
	/// @brief stop
	/// @return
	///
	os::Status stop() noexcept;

protected:
	virtual void processing() noexcept = 0;

	bool needStop() noexcept;

private:
	virtual void vRun() noexcept override;


private:
	os::threads::Mutex mutex;
	os::threads::ConditionVariable condvar{ mutex };

	os::threads::Spin stopSpin;
	bool stopFlag = false;
};

//


}}} // namespace flame_ide::handler::network

#endif // HANDLER_INTERNAL_WORKER_BASE_HPP
