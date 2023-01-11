#include "Utils.hpp"

namespace flame_ide
{namespace common
{namespace tests
{

Utils::Utils() : AbstractTest("Utils")
{}

Utils::~Utils() = default;

int Utils::vStart()
{
	IN_CASE_CHECK_END((length() == ResultType::SUCCESS));
}

int Utils::length() noexcept
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
