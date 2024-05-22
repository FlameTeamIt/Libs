#ifndef FLAMEIDE_OS_THREADS_TESTS_SEMAPHORETEST_HPP
#define FLAMEIDE_OS_THREADS_TESTS_SEMAPHORETEST_HPP

#include <FlameIDE/Os/Threads/Thread.hpp>
#include <FlameIDE/Os/Threads/Semaphore.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

struct SemaphoreTest: public ::AbstractTest
{
	SemaphoreTest();
	~SemaphoreTest() override = default;

	virtual int vStart() override;
};

}}}} // flame_ide::os::threads::tests

#endif // FLAMEIDE_OS_THREADS_TESTS_SEMAPHORETEST_HPP
