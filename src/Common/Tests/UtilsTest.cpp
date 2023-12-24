#include <FlameIDE/../../src/Common/Tests/UtilsTest.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

UtilsTest::UtilsTest() : AbstractTest("Utils")
{}

UtilsTest::~UtilsTest() = default;

int UtilsTest::vStart()
{
	IN_CASE_CHECK_END((length() == ResultType::SUCCESS));
}

int UtilsTest::length() noexcept
{
	constexpr Types::size_t expectStringLength = sizeof("Hello, world!") - 1;
	const char *testString = "Hello, world!";

	const Types::size_t testStringLength = flame_ide::length(testString);
	if (testStringLength != expectStringLength)
	{
		return ResultType::FAILED;
	}
	return ResultType::SUCCESS;
}

}}} // flame_ide::common::tests
