#include <FlameIDE/../../src/Os/Tests/Threads/MutexTest.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{
namespace // anonymous
{

auto initDestroy() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	Mutex* pMutex = nullptr;
	{
		Mutex mutex;
		pMutex = &mutex;

		IN_CASE_CHECK(os::STATUS_SUCCESS == mutex.getSatus());
	}
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == pMutex->getSatus());
}

auto lock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	Mutex mutex;
	mutex.lock();
	IN_CASE_CHECK(os::STATUS_SUCCESS == mutex.getSatus());
	IN_CASE_CHECK(false == mutex.tryLock());
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == mutex.getSatus());
}

auto unlock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	Mutex mutex;
	mutex.lock();

	mutex.unlock();
	IN_CASE_CHECK(os::STATUS_SUCCESS == mutex.getSatus());

	IN_CASE_CHECK(true == mutex.tryLock());
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == mutex.getSatus());
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

MutexTest::MutexTest() : ::AbstractTest("Mutex")
{}

int MutexTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"init/destroy", [] { return initDestroy(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"lock/tryLock", [] { return lock(); }
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			"unlock/tryLock", [] { return unlock(); }
	));
}

}}}} // flame_ide::os::threads::tests
