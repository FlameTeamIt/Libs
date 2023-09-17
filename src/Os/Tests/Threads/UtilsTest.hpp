#ifndef FLAMEIDE_OS_THREADS_TESTS_UTILSTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_UTILSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct UtilsTest: public ::AbstractTest
{
	UtilsTest();
	~UtilsTest() override = default;

	virtual int vStart() override;

private:
	int withSemaphore();
	int withMutex();
	int withSpin();
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_UTILSTEST_HPP
