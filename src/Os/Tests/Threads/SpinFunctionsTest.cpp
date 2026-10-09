#include <FlameIDE/../../src/Os/Tests/Threads/SpinFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Threads/SpinFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

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

//

struct Ping: ThreadCrtp<Ping>
{
	Ping(
			Types::size_t initAmountOfIterations
			, os::SpinContext &initContext
			, Types::long_t &initCounter
	) :
			amountOfIterations{ initAmountOfIterations }
			, context{ initContext }
			, counter{ initCounter }
	{}

	const Types::size_t amountOfIterations;
	os::SpinContext &context;
	Types::long_t &counter;

	void body() noexcept
	{
		for (RemoveAllType<decltype(amountOfIterations)> i = 0
				; i < amountOfIterations; ++i)
		{
			spin::lock(context);
			++counter;
			spin::unlock(context);
		}
	}
};

struct Pong: ThreadCrtp<Pong>
{
	Pong(
			Types::size_t initAmountOfIterations
			, os::SpinContext &initContext
			, Types::long_t &initCounter
	) :
			amountOfIterations{ initAmountOfIterations }
			, context{ initContext }
			, counter{ initCounter }
	{}

	const Types::size_t amountOfIterations;
	os::SpinContext &context;
	Types::long_t &counter;

	void body() noexcept
	{
		for (RemoveAllType<decltype(amountOfIterations)> i = 0
				; i < amountOfIterations; ++i)
		{
			spin::lock(context);
			// std::cout << "Ping: " << i << std::endl;
			--counter;
			spin::unlock(context);
		}
	}
};

auto pingPong() noexcept
{
	constexpr Types::size_t AMOUNT_OF_ITERATIONS = 65535;
	constexpr Types::size_t AMOUNT_OF_TRIES = 1;

	const Types::long_t expected = 0;
	Types::long_t counter = expected;

	os::SpinContext context;
	auto raii = templates::makeRaiiCaller(
			[&context]() { spin::init(context); }
			, [&context]() { spin::destroy(context); }
	);

	for (RemoveAllType<decltype(AMOUNT_OF_TRIES)> i = 0; i < AMOUNT_OF_TRIES; ++i)
	{
		Ping ping{ AMOUNT_OF_ITERATIONS, context, counter };
		Pong pong{ AMOUNT_OF_ITERATIONS, context, counter };

		ping.run();
		pong.run();

		ping.join();
		pong.join();

		if (counter != expected)
		{
			std::cout << "Failed: iteration = " << i << std::endl;
		}
		IN_CASE_CHECK(counter == expected);
	}
	return ::AbstractTest::ResultType::SUCCESS;
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

	CHECK_RESULT_SUCCESS(doTestCase(
			"unlock/tryLock", [] { return unlock(); }
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			"ping/pong", [] { return pingPong(); }
	));
}

}}}} // flame_ide::os::threads::tests
