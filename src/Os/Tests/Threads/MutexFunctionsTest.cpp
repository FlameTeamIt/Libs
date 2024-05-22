#include <FlameIDE/../../src/Os/Tests/Threads/MutexFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Threads/MutexFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Templates/RaiiCaller.hpp>

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

	os::Status status = os::STATUS_SUCCESS;
	os::MutexContext context;

	status = mutex::init(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);
	IN_CASE_CHECK(
			!flame_ide::isEqual(context, os::MUTEX_CONTEXT_INITIALIZER)
	);

	status = mutex::destroy(context);
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == status);
}

auto lock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::MutexContext context;

	auto raii = templates::makeRaiiCaller(
			[&context]() { mutex::init(context); }
			, [&context]() { mutex::destroy(context); }
	);

	status = mutex::lock(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	auto tryLockStatus = mutex::tryLock(context);
	IN_CASE_CHECK_END(threads::TryLockStatus::TRY_LOCK_BUSY == tryLockStatus);
}

auto unlock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::MutexContext context;

	auto raii = templates::makeRaiiCaller(
			[&context]()
			{
				mutex::init(context);
				mutex::lock(context);
			}
			, [&context]() { mutex::destroy(context); }
	);

	status = mutex::unlock(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	auto tryLockStatus = mutex::tryLock(context);
	IN_CASE_CHECK_END(threads::TryLockStatus::TRY_LOCK_OK == tryLockStatus);
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

MutexFunctionsTest::MutexFunctionsTest() : ::AbstractTest("MutexFunctions")
{}

int MutexFunctionsTest::vStart()
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
