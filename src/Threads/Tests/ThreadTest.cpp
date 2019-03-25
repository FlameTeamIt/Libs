#include "ThreadTest.hpp"

namespace flame_ide
{namespace threads
{namespace tests
{

ThreadTest::ThreadTest() : ::AbstractTest("Thread")
{}

ThreadTest::~ThreadTest() = default;

int ThreadTest::vStart()
{
	TestThread thread;
	thread.run();
	thread.join();

	IN_TEST_CHECK(thread.isStarted == true);

	return 0;
}

}}}
