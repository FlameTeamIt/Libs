#include "IntegerIterator.hpp"

#include <FlameIDE/Templates/View.hpp>

namespace flame_ide
{namespace test
{

IntegerIterator::IntegerIterator() : AbstractTest("IntegerIterator")
{}

IntegerIterator::~IntegerIterator()
{}

int IntegerIterator::vStart()
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

}}
