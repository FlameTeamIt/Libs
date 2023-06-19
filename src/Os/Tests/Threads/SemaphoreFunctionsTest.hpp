#ifndef FLAMEIDE_OS_THREADS_TESTS_SEMAPHOREFUNSTIONSTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_SEMAPHOREFUNSTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct SemaphoreFunctionsTest: public ::AbstractTest
{
	SemaphoreFunctionsTest();
	~SemaphoreFunctionsTest() override = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_SEMAPHOREFUNSTIONSTEST_HPP
