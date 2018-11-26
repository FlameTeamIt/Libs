#include "TestAggregator.hpp"
#include "Utils.hpp"

namespace flame_ide
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Common")
{
	pushBackTest(std::make_shared<Utils>());
}

}} // namespace flame_ide::tests
