#include <FlameIDE/../../src/Os/Tests/Threads/UtilsTest.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Os/Threads/Semaphore.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

template<typename LockPrimrtive>
int check(LockPrimrtive &primitive)
{
	using ResultType = ::AbstractTest::ResultType;

	IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);
	{
		UniqueLocker uniqueLocker{ primitive };
		IN_CASE_CHECK(uniqueLocker.getStatus() == os::STATUS_SUCCESS);
	}
	IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);
	{
		UniqueLocker uniqueLocker{ primitive, UniqueLocker::Lock{} };
		IN_CASE_CHECK(uniqueLocker.getStatus() == os::STATUS_SUCCESS);
		IN_CASE_CHECK(uniqueLocker.tryLock() == false);
	}
	IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);
	{
		UniqueLocker uniqueLocker{ primitive, UniqueLocker::TryLock{} };
		IN_CASE_CHECK(uniqueLocker.getStatus() == os::STATUS_SUCCESS);
		IN_CASE_CHECK(uniqueLocker.tryLock() == false);
	}
	IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);
	{
		UniqueLocker uniqueLocker{ primitive };
		IN_CASE_CHECK(uniqueLocker.getStatus() == os::STATUS_SUCCESS);
		IN_CASE_CHECK(uniqueLocker.tryLock() == true);
	}
	IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);
	{
		Locker locker{ primitive };
		IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);
	}
	IN_CASE_CHECK(primitive.getStatus() == os::STATUS_SUCCESS);

	return ::AbstractTest::SUCCESS;
}

}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

UtilsTest::UtilsTest() : ::AbstractTest("Thread Utils")
{}

int UtilsTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
		"with semaphore", [this] { return withSemaphore(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"with mutex", [this] { return withMutex(); }
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
		"with spin", [this] { return withSpin(); }
	));
}

int UtilsTest::withSemaphore()
{
	Semaphore semaphore{ 1 };

	IN_CASE_CHECK(semaphore.getStatus() == os::STATUS_SUCCESS);

	return check(semaphore);
}

int UtilsTest::withMutex()
{
	Mutex mutex;

	IN_CASE_CHECK(mutex.getStatus() == os::STATUS_SUCCESS);

	return check(mutex);
}

int UtilsTest::withSpin()
{
	Spin spin;

	IN_CASE_CHECK(spin.getStatus() == os::STATUS_SUCCESS);

	return check(spin);
}

}}}} // flame_ide::os::threads::tests
