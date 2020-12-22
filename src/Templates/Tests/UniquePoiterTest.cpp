#include "UniquePoiterTest.hpp"

using namespace flame_ide;
using namespace flame_ide::templates::test;

UniquePointerTest::UniquePointerTest() : AbstractTest("UniquePointer")
		, pointer {{1000, 100, 10, '1'}}
		, stdpointer {std::make_unique<TestClass>(1000, 100, 10, '1')}
{}

UniquePointerTest::~UniquePointerTest()
{}

int UniquePointerTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
		"initializing"
		, [&]()
		{
			IN_CASE_CHECK_END(*pointer == *stdpointer);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"moving"
		, [&]()
		{
			decltype(pointer) movePointer = flame_ide::move(pointer);
			IN_CASE_CHECK_END(*movePointer == *stdpointer);

			pointer = flame_ide::move(movePointer);
			IN_CASE_CHECK_END(*pointer == *stdpointer);
		}
	));

	return 0;
}
