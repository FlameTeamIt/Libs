#include <FlameIDE/../../src/Threads/Tests/ThreadTest.hpp>

#include <FlameIDE/../../src/Threads/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Threads aggregator")
{
	pushBackTest(std::make_shared<ThreadTest>());
}

TestAggregator::~TestAggregator() = default;

}}}
