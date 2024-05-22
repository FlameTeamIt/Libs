#include <FlameIDE/../../src/Os/Tests/Threads/ThreadTest.hpp>

#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

#include <future>

// Thread's difinitions

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{
namespace // anonymous
{

struct TestThread: public ThreadBase
{
	virtual void vRun() noexcept
	{
		isStarted = true;
	}
	bool isStarted = false;
};

struct TestThreadDetach: public ThreadBase
{
	virtual void vRun() noexcept
	{
		promise.set_value();
	}
	std::promise<void> promise;
};

struct TestThreadCrtp: public ThreadCrtp<TestThreadCrtp>
{
	void body() noexcept
	{
		isStarted = true;
	}
	bool isStarted = false;
};

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{
namespace // anonymous
{

auto initDestroyThreadBase()
{
	using ResultType = ::AbstractTest::ResultType;

	TestThread thread;

	IN_CASE_CHECK(thread.getStatus() == os::STATUS_SUCCESS);
	IN_CASE_CHECK_END(thread.isStarted == false);
}

auto runJoinThreadBase()
{
	using ResultType = ::AbstractTest::ResultType;

	TestThread thread;
	thread.run();
	thread.join();

	IN_CASE_CHECK(thread.getStatus() == os::STATUS_SUCCESS);
	IN_CASE_CHECK_END(thread.isStarted == true);
}

auto runDetachThreadBase()
{
	using ResultType = ::AbstractTest::ResultType;

	TestThreadDetach thread;
	auto future = thread.promise.get_future();
	thread.run();
	thread.detach();

	IN_CASE_CHECK(thread.getStatus() == os::STATUS_SUCCESS);
	IN_CASE_CHECK_END(
		future.wait_for(std::chrono::seconds{5}) == std::future_status::ready
	);
}

auto runJoinThreadCrtp()
{
	using ResultType = ::AbstractTest::ResultType;

	TestThreadCrtp thread;
	thread.run();
	thread.join();

	IN_CASE_CHECK(thread.getStatus() == os::STATUS_SUCCESS);
	IN_CASE_CHECK_END(thread.isStarted == true);
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

ThreadTest::ThreadTest() : ::AbstractTest("Thread")
{}

ThreadTest::~ThreadTest() = default;

int ThreadTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			 "init/destroy ThreadBase"
			 , [&]()
			{
				return initDestroyThreadBase();
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			 "run/join ThreadBase"
			 , [&]()
			{
				return runJoinThreadBase();
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			 "run/detach ThreadBase"
			 , [&]()
			{
				return runDetachThreadBase();
			}
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			 "run/join ThreadCrtp"
			 , [&]()
			{
				return runJoinThreadCrtp();
			}
	));
}

}}}} // flame_ide::os::threads::tests
