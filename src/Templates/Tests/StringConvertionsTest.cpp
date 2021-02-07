#include "StringConvertionsTest.hpp"

#include <FlameIDE/Templates/StringConvertions.hpp>

#define TO_TEXT(some) #some

namespace flame_ide
{namespace templates
{namespace test
{

StringConvertionsTest::StringConvertionsTest() : AbstractTest("StringConvertions")
{}

StringConvertionsTest::~StringConvertionsTest() = default;

int StringConvertionsTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
		"bufferSize from string_utils"
		, [&]()
		{
			int i = 100500;
			Types::size_t size_100500 = sizeof( TO_TEXT(100500) ) - 1;
			Types::size_t size_minus100500 = sizeof( TO_TEXT(-100500) ) - 1;
			Types::size_t size_uint64MAX = sizeof( TO_TEXT(18446744073709551615ul) ) - 1;

			IN_CASE_CHECK(
					templates::string_utils::bufferSize(i) == size_100500
			);
			IN_CASE_CHECK(
					templates::string_utils::bufferSize(-i) == size_minus100500
			);
			IN_CASE_CHECK_END(
					templates::string_utils::bufferSize(UINT64_MAX) == size_uint64MAX
			);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"toString()"
		, [&]()
		{
			int i = 100500;
			auto string = templates::toString(i);
			std::string stdstring("100500");
			IN_CASE_CHECK_END(
					ResultType::SUCCESS == compareContainers(string, stdstring)
			);
		}
	));

	return 0;
}

}}}
