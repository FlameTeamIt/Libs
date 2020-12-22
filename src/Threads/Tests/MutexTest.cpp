#include <FlameIDE/../../src/Threads/Tests/MutexTest.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

MutexTest::MutexTest() : ::AbstractTest("Mutex")
{}

MutexTest::~MutexTest() = default;

int MutexTest::vStart()
{
	Mutex mutex;

	MutexLockerTestThread thread1(mutex);
	thread1.run();
	thread1.join();

	IN_CASE_CHECK(mutex.getState() == Mutex::State::LOCKED)

	MutexUnlockerTestThread thread2(mutex);
	thread2.run();
	thread2.join();

	IN_CASE_CHECK(mutex.getState() == Mutex::State::UNLOCKED)

	return 0;
}

}}}
