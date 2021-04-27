#include <FlameIDE/../../src/Os/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Os/Tests/LibraryTest.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Os")
{
	pushBackTest(std::make_shared<LibraryTest>());
}

}}} // namespace flame_ide::os::tests
