#include <FlameIDE/../../src/Os/Tests/Threads/SemaphoreTest.hpp>
#include <FlameIDE/Os/Threads/Semaphore.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{
namespace // anonymous
{

#if FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_GCC
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wdangling-pointer"
#endif

auto initDestroy() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	threads::Semaphore *pSemaphore = nullptr;
	{
		threads::Semaphore semaphore;

		IN_CASE_CHECK(os::SEMAPHORE_VALUE_DEFAULT == semaphore.getValue());
		IN_CASE_CHECK(os::STATUS_SUCCESS == semaphore.getStatus());

		pSemaphore = &semaphore;
	}
	IN_CASE_CHECK(os::STATUS_SUCCESS == pSemaphore->getStatus());

	{
		constexpr auto INIT_VALUE = os::SemaphoreValue{ 2 };

		threads::Semaphore semaphore{ INIT_VALUE };

		IN_CASE_CHECK(INIT_VALUE == semaphore.getValue());
		IN_CASE_CHECK(os::STATUS_SUCCESS == semaphore.getStatus());

		pSemaphore = &semaphore;
	}
	IN_CASE_CHECK(os::STATUS_SUCCESS == pSemaphore->getStatus());

	{
		threads::Semaphore semaphore;
		{
			threads::Semaphore semaphoreSlave{ flame_ide::move(semaphore) };

			IN_CASE_CHECK(os::SEMAPHORE_VALUE_DEFAULT == semaphoreSlave.getValue());
			IN_CASE_CHECK(os::STATUS_SUCCESS == semaphoreSlave.getStatus());
		}
		IN_CASE_CHECK(os::SEMAPHORE_CONTEXT_INITIALIZER == semaphore.native());
	}

	return ResultType::SUCCESS;
}

#if FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_GCC
#	pragma GCC diagnostic pop
#endif

auto wait() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	threads::Semaphore semaphore;

	semaphore.wait();
	IN_CASE_CHECK(0 == semaphore.getValue());
	IN_CASE_CHECK(os::STATUS_SUCCESS == semaphore.getStatus());

	const auto isLocked = semaphore.tryWait();
	IN_CASE_CHECK(false == isLocked);

	return ResultType::SUCCESS;
}

auto post() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	threads::Semaphore semaphore;
	semaphore.wait();

	semaphore.post();
	IN_CASE_CHECK(os::SEMAPHORE_VALUE_DEFAULT == semaphore.getValue());
	IN_CASE_CHECK(os::STATUS_SUCCESS == semaphore.getStatus());

	const auto isLocked = semaphore.tryWait();
	IN_CASE_CHECK(true == isLocked);

	return ResultType::SUCCESS;

}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

SemaphoreTest::SemaphoreTest() : ::AbstractTest("Semaphore")
{}

int SemaphoreTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"init/destroy", [] { return initDestroy(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"wait/tryWait", [] { return wait(); }
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			"post/tryWait", [] { return post(); }
	));
}

}}}} // flame_ide::os::threads::tests
