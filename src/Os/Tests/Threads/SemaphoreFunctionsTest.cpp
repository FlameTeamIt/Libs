#include <FlameIDE/../../src/Os/Tests/Threads/SemaphoreFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Threads/SemaphoreFunctions.hpp>

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

constexpr auto DEFAULT_INIT_VALUE = os::SemaphoreValue{ 1 };

auto initDestroy() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::SemaphoreContext context;

	status = semaphore::init(context, DEFAULT_INIT_VALUE);
	IN_CASE_CHECK(status == os::STATUS_SUCCESS);

	status = semaphore::destroy(context);
	IN_CASE_CHECK_END(status == os::STATUS_SUCCESS);
}

auto wait() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::SemaphoreContext context;

	auto raiiCaller = templates::makeRaiiCaller(
			[&context]() { semaphore::init(context, DEFAULT_INIT_VALUE); }
			, [&context]() { semaphore::destroy(context); }
	);

	status = semaphore::wait(context);
	IN_CASE_CHECK(status == os::STATUS_SUCCESS);

	auto tryLockResult = semaphore::tryWait(context);
	IN_CASE_CHECK_END(TryLockStatus::TRY_LOCK_BUSY == tryLockResult);
}

auto post() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::Status status = os::STATUS_SUCCESS;
	os::SemaphoreContext context;

	auto raiiCaller = templates::makeRaiiCaller(
			[&context]()
			{
				semaphore::init(context, DEFAULT_INIT_VALUE);
				semaphore::wait(context);
			}
			, [&context]() { semaphore::destroy(context); }
	);

	status = semaphore::post(context);
	IN_CASE_CHECK(status == os::STATUS_SUCCESS);

	auto tryLockResult = semaphore::tryWait(context);
	IN_CASE_CHECK_END(TryLockStatus::TRY_LOCK_OK == tryLockResult);
}

auto value() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	constexpr auto INIT_VALUE = os::SemaphoreValue{ 2 };

	os::Status status = os::STATUS_SUCCESS;
	os::SemaphoreContext context;

	auto raiiCaller = templates::makeRaiiCaller(
			[&context]() { semaphore::init(context, INIT_VALUE); }
			, [&context]() { semaphore::destroy(context); }
	);

	status = semaphore::value(context);
	IN_CASE_CHECK(INIT_VALUE == status);

	semaphore::wait(context); // decrement
	status = semaphore::value(context);
	IN_CASE_CHECK((INIT_VALUE - 1) == status);

	semaphore::post(context); // increment
	status = semaphore::value(context);
	IN_CASE_CHECK_END(INIT_VALUE == status);
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

SemaphoreFunctionsTest::SemaphoreFunctionsTest() : ::AbstractTest("SemaphoreFunctions")
{}

int SemaphoreFunctionsTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"init/destroy", [] { return initDestroy(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"wait/tryWait", [] { return wait(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"post/tryWait", [] { return post(); }
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			"value", [] { return value(); }
	));
}

}}}} // flame_ide::os::threads::tests
