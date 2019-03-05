#include "StringTest.hpp"

#define TEST_STRING "Hello, world!"

#define TO_TEXT(some) #some

using namespace flame_ide::test;

StringTest::StringTest() : AbstractTest("String")
		, string(TEST_STRING)
{}

StringTest::~StringTest()
{}

int StringTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
		"bufferSize from string_utils"
		, [&]()
		{
			int i = 100500;
			Types::size_t size_100500 = sizeof( TO_TEXT(100500) ) - 1;
			Types::size_t size_minus100500 = sizeof( TO_TEXT(-100500) ) - 1;
			Types::size_t size_uint64MAX = sizeof( TO_TEXT(18446744073709551615ul) ) - 1;

			IN_TEST_CHECK(templates::string_utils::bufferSize(i) == size_100500);
			IN_TEST_CHECK(templates::string_utils::bufferSize(-i) == size_minus100500);
			IN_TEST_CHECK_END(templates::string_utils::bufferSize(UINT64_MAX) != size_uint64MAX);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"toString()"
		, [&]()
		{
			int i = 100500;
			auto string = templates::toString(i);
			std::string stdstring("100500");
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(string, stdstring));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"output (reverse)"
		, [&]()
		{
			string = templates::String(TEST_STRING); // FIXME: нужно присвоение const char *!
			stdstring = TEST_STRING;
			auto range = templates::makeRange(string.rbegin(), string.rend());
			auto stdrange = templates::makeRange(stdstring.rbegin(), stdstring.rend());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range, stdrange));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"pushBack(object)"
		, [&]()
		{
			string.pushBack('_');
			stdstring.push_back('_');
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(string, stdstring));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"popBack()"
		, [&]()
		{
			string.popBack();
			stdstring.pop_back();
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(string, stdstring));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"pushBack(array)"
		, [&]()
		{
			string.pushBack(" My name is John.");
			stdstring += " My name is John.";
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(string, stdstring));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"erase(range)"
		, [&]()
		{
			log << "Add" << std::endl;
			return ResultType::SUCCESS;
		}
	));

	auto temp = *(string.begin() + 4);
	CHECK_RESULT_SUCCESS(doTestCase(
		"erase(iterator)"
		, [&]()
		{
			string.erase(string.begin() + 4);
			stdstring.erase(stdstring.begin() + 4);
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(string, stdstring));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"insert(iterator)"
		, [&]()
		{
			string.insert(string.begin() + 4, temp);
			stdstring.insert(stdstring.begin() + 4, temp);
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(string, stdstring));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"operator=(ConstReference)"
		, [&]()
		{
			templates::String copiedString = string;
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(copiedString, string));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"operator=(MoveReference)"
		, [&]()
		{
			templates::String copiedString = string;
			templates::String movedString = templates::String();
			movedString = flame_ide::move(string);
			IN_CASE_CHECK(ResultType::SUCCESS == compareContainers(copiedString, movedString));
			string = flame_ide::move(movedString);
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(copiedString, string));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"operator=(PointerToConst)"
		, [&]()
		{
			templates::String stringFromArray = templates::String();
			stringFromArray = string.data();
			IN_CASE_CHECK(string.length() == stringFromArray.length());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(stringFromArray, string));
		}
	));

	return 0;
}
