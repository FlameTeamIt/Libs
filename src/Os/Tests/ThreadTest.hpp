#ifndef FLAMEIDE_SRC_OS_TESTS_THREADTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_THREADTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class ThreadTest: public ::AbstractTest
{
public:
	ThreadTest();
	virtual ~ThreadTest();

private:
	virtual int vStart();
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_THREADTEST_HPP
