#include <FlameIDE/../../src/Os/Tests/Threads/ConditionVariableTest.hpp>

#include <FlameIDE/Os/Threads/ConditionVariable.hpp>

#include <FlameIDE/Os/Threads/Mutex.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{namespace anonymous{ namespace
{

template<typename Lock>
class ConditionVariableWaitThreadTest : public ThreadCrtp<ConditionVariableWaitThreadTest<Lock>>
{
public:
	ConditionVariableWaitThreadTest(Lock &lock) : condvar{ lock }
	{}

	void body() noexcept
	{
		condvar.wait();
	}

public:
	auto &getConditionVariable() noexcept
	{
		return condvar;
	}

private:
	ConditionVariable condvar;
};

template<typename Lock>
class ConditionVariableWaitWithFunctionalThreadTest:
		public ThreadCrtp<ConditionVariableWaitWithFunctionalThreadTest<Lock>>
{
public:
	ConditionVariableWaitWithFunctionalThreadTest(Lock &lock) : condvar{ lock }
	{}

	void body() noexcept
	{
		condvar.wait([this](){ return value; });
	}

	void setValue(bool updatingValue)
	{
		value = updatingValue;
	}

public:
	ConditionVariable &getConditionVariable() noexcept
	{
		return condvar;
	}

private:
	ConditionVariable condvar;
	bool value = false;
};

template<typename Lock>
::AbstractTest::ResultType waitTest() noexcept
{
	Lock lock;
	ConditionVariableWaitThreadTest<Lock> thread{ lock };
	ConditionVariable &condvar = thread.getConditionVariable();

	thread.run();
	condvar.notify();
	thread.join();

	return ::AbstractTest::SUCCESS;
}

template<typename Lock>
::AbstractTest::ResultType waitWithFunctionalTest() noexcept
{
	Lock lock;
	ConditionVariableWaitWithFunctionalThreadTest<Lock> thread{ lock };
	ConditionVariable &condvar = thread.getConditionVariable();

	thread.run();
	thread.setValue(true);
	condvar.notify();
	thread.join();

	return ::AbstractTest::SUCCESS;
}

}} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

ConditionVariableTest::ConditionVariableTest() : ::AbstractTest("ConditionVariable")
{}

int ConditionVariableTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"wait mutex", [] { return anonymous::waitTest<Mutex>(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"wait mutex condition", [] { return anonymous::waitWithFunctionalTest<Mutex>(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"wait spin", [] { return anonymous::waitTest<Spin>(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"wait spin condition", [] { return anonymous::waitWithFunctionalTest<Spin>(); }
	));

	return ::AbstractTest::SUCCESS;
}

}}}} // flame_ide::os::threads::tests
