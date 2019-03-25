#include "TestAggregator.hpp"

#include "ThreadTest.hpp"

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
