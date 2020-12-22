#include <FlameIDE/../../src/Threads/Tests/ThreadTest.hpp>
#include <FlameIDE/../../src/Threads/Tests/MutexTest.hpp>
#include <FlameIDE/../../src/Threads/Tests/SemaphoreTest.hpp>

#include <FlameIDE/../../src/Threads/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace threads
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Threads aggregator")
{
	pushBackTest(std::make_shared<ThreadTest>());
	pushBackTest(std::make_shared<MutexTest>());
	pushBackTest(std::make_shared<SemaphoreTest>());
}

TestAggregator::~TestAggregator() = default;

}}}
