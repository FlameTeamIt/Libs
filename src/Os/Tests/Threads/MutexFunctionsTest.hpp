#ifndef FLAMEIDE_OS_THREADS_TESTS_MUTEXFUNSTIONSTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_MUTEXFUNSTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct MutexFunctionsTest: public ::AbstractTest
{
	MutexFunctionsTest();
	~MutexFunctionsTest() = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_MUTEXFUNSTIONSTEST_HPP
