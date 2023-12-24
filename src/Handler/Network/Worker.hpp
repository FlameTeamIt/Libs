#ifndef WORKER_HPP
#define WORKER_HPP

#include <Generated/Network/Config.hpp>

#include <FlameIDE/Os/Threads/ConditionVariable.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

#include <FlameIDE/Templates/Array.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Worker: public os::threads::ThreadCrtp<Worker>
{
	using Parent = os::threads::ThreadCrtp<Worker>;
	friend Parent;

public: //
	void init(os::threads::ConditionVariable &initCondvar) noexcept;

private: // os::threads::ThreadCrtp<Worker>
	void body() noexcept;

private:
	os::threads::ConditionVariable *condvar = nullptr;
};

}}} // namespace flame_ide::handler::network

namespace flame_ide
{namespace handler
{namespace network
{

class Workers
{
public:
	Workers() noexcept;
	~Workers() noexcept;

	void start();
	void stop();

private:
	void join() noexcept;

private:
	os::threads::Mutex mutex;
	os::threads::ConditionVariable condvar{ mutex };

	templates::StaticArray<
		Worker, generated::network::Config::HANDLER_NUMBER_OF_WORKERS
	> workers;
};

}}} // namespace flame_ide::handler::network

#endif // WORKER_HPP
