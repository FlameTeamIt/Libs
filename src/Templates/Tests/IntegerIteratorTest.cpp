#include "IntegerIteratorTest.hpp"

#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

IntegerIteratorTest::IntegerIteratorTest() : AbstractTest("IntegerIterator")
{}

IntegerIteratorTest::~IntegerIteratorTest()
{}

int IntegerIteratorTest::vStart()
{
	size_t begin = 0;
	size_t end = 10;

	using namespace flame_ide::templates;
	CHECK_RESULT_SUCCESS_END(doTestCase(
		std::string("check (") + std::to_string(begin) + ":" + std::to_string(end) + ")"
		, [&]()
		{
			size_t value = 0;
			auto range = makeRange<SizeTypeIterator>(begin, end);

			for (auto i : range)
			{
				IN_CASE_CHECK(i == value++);
			}
			return ResultType::SUCCESS;
		}
	));
}

}}}
