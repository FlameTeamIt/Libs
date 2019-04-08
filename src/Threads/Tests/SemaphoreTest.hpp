#ifndef FLAMEIDE_THREADS_TESTS_SEMAPHORETEST_HPP
#define FLAMEIDE_THREADS_TESTS_SEMAPHORETEST_HPP

#include <FlameIDE/Threads/Thread.hpp>
#include <FlameIDE/Threads/Semaphore.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

class SemaphoreWaiterTestThread: public Thread
{
public:
	SemaphoreWaiterTestThread(Semaphore &semaphore) : sem(semaphore)
	{}

	virtual void vRun()
	{
		sem.wait();
	}

	Semaphore &sem;
};

class SemaphorePosterTestThread: public Thread
{
public:
	SemaphorePosterTestThread(Semaphore &semaphore) : sem(semaphore)
	{}

	virtual void vRun()
	{
		sem.post();
	}

	Semaphore &sem;
};

class SemaphoreTest: public AbstractTest
{
public:
	SemaphoreTest();
	virtual ~SemaphoreTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_THREADS_TESTS_SEMAPHORETEST_HPP
