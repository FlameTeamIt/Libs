#include <FlameIDE/../../src/Common/Tests/Utils.hpp>

#include <FlameIDE/../../src/Common/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Common")
{
	pushBackTest(std::make_shared<Utils>());
}

}}} // namespace flame_ide::common::tests
