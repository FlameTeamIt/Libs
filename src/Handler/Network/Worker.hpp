#ifndef WORKER_HPP
#define WORKER_HPP

#include <Generated/Network/Config.hpp>

#include <FlameIDE/Common/ReferenceWrapper.hpp>

#include <FlameIDE/Os/Threads/ConditionVariable.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

#include <FlameIDE/Templates/Array.hpp>

namespace flame_ide
{namespace handler
{namespace network
{



}}}

namespace flame_ide
{namespace handler
{namespace network
{

class Worker: private os::threads::ThreadCrtp<Worker>
{
	using Parent = os::threads::ThreadCrtp<Worker>;
	friend Parent;

public:
	using Parent::getStatus;

	///
	/// @brief getConditionVariable
	/// @return
	///
	os::threads::ConditionVariable &getConditionVariable() noexcept;

	///
	/// @brief start
	///
	void start() noexcept;

	///
	/// @brief stop
	///
	void stop() noexcept;

private:
	// os::threads::ThreadCrtp<Worker>
	// TODO
	void body() noexcept;

	bool needStop() noexcept;

private:
	os::threads::Mutex mutex;
	os::threads::ConditionVariable condvar{ mutex };

	os::threads::Spin stopSpin;
	bool stopFlag = false;
};

}}} // namespace flame_ide::handler::network

namespace flame_ide
{namespace handler
{namespace network
{

class Workers
{
	static constexpr auto NUMBER_OF_WORKERS =
			generated::network::Config::HANDLER_NUMBER_OF_WORKERS;

public:
	Workers() noexcept;
	~Workers() noexcept;

	///
	/// @brief getConditionVariables
	/// @return
	///
	templates::StaticArray<
		ReferenceWrapper<os::threads::ConditionVariable>, NUMBER_OF_WORKERS
	>
	getConditionVariables() noexcept;

	///
	/// @brief start
	/// @return
	///
	// TODO
	os::Status start() noexcept;

	///
	/// @brief stop
	/// @return
	///
	// TODO
	os::Status stop() noexcept;

private:
	templates::StaticArray<Worker, NUMBER_OF_WORKERS> workers;
};

}}} // namespace flame_ide::handler::network

#endif // WORKER_HPP
