#ifndef FLAMEIDE_OS_THREADS_TESTS_THREADFUNSTIONSTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_THREADFUNSTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct ThreadFunctionsTest: public ::AbstractTest
{
	ThreadFunctionsTest();
	~ThreadFunctionsTest() = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_THREADFUNSTIONSTEST_HPP
