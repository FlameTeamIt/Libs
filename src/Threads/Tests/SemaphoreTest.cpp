#include <FlameIDE/../../src/Threads/Tests/SemaphoreTest.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

SemaphoreTest::SemaphoreTest() : ::AbstractTest("Semaphore")
{}

SemaphoreTest::~SemaphoreTest() = default;

int SemaphoreTest::vStart()
{
	Semaphore sem(1);

	SemaphoreWaiterTestThread thread1(sem);
	thread1.run();
	thread1.join();

	IN_CASE_CHECK(sem.getValue() == 0);
	IN_CASE_CHECK(sem.getStatus() == 0);

	SemaphorePosterTestThread thread2(sem);
	thread2.run();
	thread2.join();

	IN_CASE_CHECK(sem.getValue() == 1);
	IN_CASE_CHECK_END(sem.getStatus() == 0);
}

}}}
