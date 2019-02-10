#include "TestAggregator.hpp"

#include "RamStreamTest.hpp"

namespace flame_ide
{namespace streams
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Streams")
{
	pushBackTest(std::make_shared<RamStreamTest>());
}

}}}

