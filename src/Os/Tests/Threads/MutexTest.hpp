#ifndef FLAMEIDE_OS_THREADS_TESTS_MUTEXTEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_MUTEXTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct MutexTest: public ::AbstractTest
{
	MutexTest();
	~MutexTest() override = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_MUTEXTEST_HPP
