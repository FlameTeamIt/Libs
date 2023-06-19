#ifndef FLAMEIDE_OS_THREADS_TESTS_THREADTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_THREADTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

class ThreadTest: public AbstractTest
{
public:
	ThreadTest();
	virtual ~ThreadTest();

private:
	virtual int vStart();
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_THREADTEST_HPP
