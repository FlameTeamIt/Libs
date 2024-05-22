#include <FlameIDE/../../src/Os/Tests/Threads/SpinTest.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

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

	threads::Spin* pSpin = nullptr;
	{
		threads::Spin spin;
		IN_CASE_CHECK(os::STATUS_SUCCESS == spin.getStatus());
		IN_CASE_CHECK(!flame_ide::isEqual(
				spin.native(), os::SPINLOCK_CONTEXT_INITIALIZER
		));

		pSpin = &spin;
	}
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == pSpin->getStatus());
}

#if FLAMEIDE_COMPILER == FLAMEIDE_COMPILER_GCC
#	pragma GCC diagnostic pop
#endif

auto lock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	threads::Spin spin;
	spin.lock();
	IN_CASE_CHECK(os::STATUS_SUCCESS == spin.getStatus());
	IN_CASE_CHECK(false == spin.tryLock());
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == spin.getStatus());
}

auto unlock() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	threads::Spin spin;
	spin.lock();

	spin.unlock();
	IN_CASE_CHECK(os::STATUS_SUCCESS == spin.getStatus());

	IN_CASE_CHECK(true == spin.tryLock());
	IN_CASE_CHECK_END(os::STATUS_SUCCESS == spin.getStatus());
}

} // namespace anonymous
}}}} // flame_ide::os::threads::tests

namespace flame_ide
{namespace os
{namespace threads
{namespace tests
{

SpinTest::SpinTest() : ::AbstractTest("Spin")
{}

int SpinTest::vStart()
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
