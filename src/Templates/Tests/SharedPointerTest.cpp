#include "SharedPointerTest.hpp"
#include "src/Templates/Tests/TestClass.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

SharedPointerTest::SharedPointerTest() : AbstractTest("SharedPointer")
		, pointer {TestClass{1000, 100, 10, 1}}
		, stdpointer {std::make_shared<TestClass>(1000, 100, 10, 1)}
{}

SharedPointerTest::~SharedPointerTest()
{}

int SharedPointerTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
		"initializing"
		, [&]()
		{
			IN_CASE_CHECK_END(*pointer == *stdpointer);
		}

	));

//	CHECK_RESULT_SUCCESS(doTestCase(
//		"copying"
//		, [&]()
//		{
//			auto copyPointer = pointer;
//			auto stdcopyPointer = stdpointer;
//			IN_CASE_CHECK_END(*copyPointer == *stdcopyPointer);
//		}

//	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"moving"
		, [&]()
		{
			decltype(pointer) movePointer = flame_ide::move(pointer);
			decltype(stdpointer) stdmovePointer = std::move(stdpointer);
			IN_CASE_CHECK_END(*movePointer == *stdmovePointer);
		}

	));

	return 0;
}

}}}
