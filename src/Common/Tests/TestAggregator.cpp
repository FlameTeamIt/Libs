#include <FlameIDE/../../src/Common/Tests/UtilsTest.hpp>
#include <FlameIDE/../../src/Common/Tests/ExpectedTest.hpp>

#include <FlameIDE/../../src/Common/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Common")
{
	pushBackTest(std::make_shared<UtilsTest>());
	pushBackTest(std::make_shared<ExpectedTest>());
}

}}} // namespace flame_ide::common::tests
