#ifndef FLAMEIDE_OS_THREADS_TESTS_SPINFUNSTIONSTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_SPINFUNSTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct SpinFunctionsTest: public ::AbstractTest
{
	SpinFunctionsTest();
	~SpinFunctionsTest() override = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_SPINFUNSTIONSTEST_HPP
