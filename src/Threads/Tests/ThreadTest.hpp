#ifndef FLAMEIDE_THREADS_TESTS_THREADTEST_HPP
#define FLAMEIDE_THREADS_TESTS_THREADTEST_HPP

#include <FlameIDE/Threads/Thread.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

class TestThread: public Thread
{
public:
	virtual void vRun()
	{
		isStarted = true;
	}

	bool isStarted = false;
};

class ThreadTest: public AbstractTest
{
public:
	ThreadTest();
	virtual ~ThreadTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_THREADS_TESTS_THREADTEST_HPP
