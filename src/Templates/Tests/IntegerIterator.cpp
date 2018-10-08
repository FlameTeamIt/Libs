#include "IntegerIterator.hpp"

#include <Templates/View.hpp>

namespace flame_ide
{namespace test
{

IntegerIterator::IntegerIterator() : AbstractTest("IntegerIterator")
{}

IntegerIterator::~IntegerIterator()
{}

int IntegerIterator::vStart()
{
	using namespace flame_ide::templates;
	auto range = makeRange<templates::SizeTypeIterator>(0, 10);
	for (auto i : range)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}

}}
