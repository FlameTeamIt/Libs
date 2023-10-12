#ifndef FLAMEIDE_OS_THREADS_TESTS_CONDITIONVARIABLETEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_CONDITIONVARIABLETEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct ConditionVariableTest: public ::AbstractTest
{
	ConditionVariableTest();
	~ConditionVariableTest() = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_CONDITIONVARIABLETEST_HPP
