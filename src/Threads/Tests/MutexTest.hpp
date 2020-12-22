#ifndef FLAMEIDE_THREADS_TESTS_MUTEXTEST_HPP
#define FLAMEIDE_THREADS_TESTS_MUTEXTEST_HPP

#include <FlameIDE/Threads/Thread.hpp>
#include <FlameIDE/Threads/Mutex.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

class MutexLockerTestThread: public Thread
{
public:
	MutexLockerTestThread(Mutex &mutex) : mtx(mutex)
	{}

	virtual void vRun()
	{
		mtx.lock();
	}

	Mutex &mtx;
};

class MutexUnlockerTestThread: public Thread
{
public:
	MutexUnlockerTestThread(Mutex &mutex) : mtx(mutex)
	{}

	virtual void vRun()
	{
		mtx.unlock();
	}

	Mutex &mtx;
};

class MutexTest: public AbstractTest
{
public:
	MutexTest();
	virtual ~MutexTest();

private:
	virtual int vStart();
};


}}}

#endif // FLAMEIDE_THREADS_TESTS_MUTEXTEST_HPP
