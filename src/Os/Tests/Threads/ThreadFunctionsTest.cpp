#include <FlameIDE/../../src/Os/Tests/Threads/ThreadFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Threads/ThreadFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Semaphore.hpp>

#include <FlameIDE/Templates/RaiiCaller.hpp>


flame_ide::os::ThreadTaskTrait::Return
taskJoin(flame_ide::os::ThreadTaskTrait::Argument)
{
	return {};
}

flame_ide::os::ThreadTaskTrait::Return
taskDetach(flame_ide::os::threads::Semaphore *semaphore)
{
	semaphore->wait();
	return {};
}

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

	os::ThreadContext context = os::THREAD_CONTEXT_INITIALIZER;

	os::Status status = thread::init(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);
	IN_CASE_CHECK(!isEqual(
			os::THREAD_CONTEXT_INITIALIZER, context
	));

	status = thread::destroy(context);
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == status);
}

auto createJoin() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::ThreadContext context = os::THREAD_CONTEXT_INITIALIZER;
	auto raii = templates::makeRaiiCaller(
			[&context]() { thread::init(context); }
			, [&context]() { thread::destroy(context); }
	);

	os::Status status = thread::create(context, taskJoin, {});
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	os::ThreadTaskTrait::Return returnValue = {};
	status = thread::join(context, returnValue);
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == status);
}

auto createDetach() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	os::ThreadContext context = os::THREAD_CONTEXT_INITIALIZER;
	auto raii = templates::makeRaiiCaller(
			[&context]() { thread::init(context); }
			, [&context]() { thread::destroy(context); }
	);

	Semaphore semaphore;
	os::Status status = thread::create(
			context, (os::ThreadTaskTrait::Task)(taskDetach), &semaphore
	);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	status = thread::detach(context);
	IN_CASE_CHECK(os::STATUS_SUCCESS == status);

	while (semaphore.getValue()) {}

	return ResultType::SUCCESS;
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

ThreadFunctionsTest::ThreadFunctionsTest() : ::AbstractTest("ThreadFunctions")
{}

int ThreadFunctionsTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"init/destroy", [] { return initDestroy(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"create/join", [] { return createJoin(); }
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			"create/detach", [] { return createDetach(); }
	));
}

}}}} // flame_ide::os::threads::tests
