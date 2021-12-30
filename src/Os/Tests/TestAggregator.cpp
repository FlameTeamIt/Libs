#include <FlameIDE/../../src/Os/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Os/Tests/LibraryTest.hpp>
#include <FlameIDE/../../src/Os/Tests/PipeTest.hpp>
#include <FlameIDE/../../src/Os/Tests/ThreadTest.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Os")
{
	pushBackTest(std::make_shared<LibraryTest>());
	pushBackTest(std::make_shared<PipeTest>());
	pushBackTest(std::make_shared<ThreadTest>());
}

}}} // namespace flame_ide::os::tests
