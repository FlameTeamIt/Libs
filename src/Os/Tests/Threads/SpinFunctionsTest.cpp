#include <FlameIDE/../../src/Os/Tests/Threads/SpinFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Threads/SpinFunctions.hpp>

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
	os::SpinContext context;

	status = spin::init(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);
	IN_CASE_CHECK(
			!flame_ide::isEqual(context, os::SPINLOCK_CONTEXT_INITIALIZER)
	);

	status = spin::destroy(context);
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == status);
}

auto lock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::SpinContext context;

	auto raii = templates::makeRaiiCaller(
			[&context]() { spin::init(context); }
			, [&context]() { spin::destroy(context); }
	);

	status = spin::lock(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	auto tryLockStatus = spin::tryLock(context);
	IN_CASE_CHECK_END(threads::TryLockStatus::TRY_LOCK_BUSY == tryLockStatus);
}

auto unlock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::SpinContext context;

	auto raii = templates::makeRaiiCaller(
			[&context]()
			{
				spin::init(context);
				spin::lock(context);
			}
			, [&context]() { spin::destroy(context); }
	);

	status = spin::unlock(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	auto tryLockStatus = spin::tryLock(context);
	IN_CASE_CHECK_END(threads::TryLockStatus::TRY_LOCK_OK == tryLockStatus);
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

SpinFunctionsTest::SpinFunctionsTest() : ::AbstractTest("SpinFunctions")
{}

int SpinFunctionsTest::vStart()
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
