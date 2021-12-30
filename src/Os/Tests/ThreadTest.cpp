#include <FlameIDE/../../src/Os/Tests/ThreadTest.hpp>

#include <FlameIDE/Os/Thread.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

namespace
{

void *testFunction(void *argument)
{
	int &value = *reinterpret_cast<int *>(argument);
	value = 1;
	return nullptr;
}

} // namespace

ThreadTest::ThreadTest() : ::AbstractTest("Thread")
{}

ThreadTest::~ThreadTest() = default;

int ThreadTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"thread running"
			, [&]()
			{
				int testValue = 0;
				const int result = 1;

				ThreadTask task{ testFunction, &testValue };

				Thread thread(task, false);
				thread.run();

				IN_CASE_CHECK(thread.status() == STATUS_SUCCESS);

				thread.join();

				IN_CASE_CHECK(thread.status() == STATUS_SUCCESS);
				IN_CASE_CHECK_END(result == testValue);
			}
	));

	return 0;
}

}}} // namespace flame_ide::os::tests
