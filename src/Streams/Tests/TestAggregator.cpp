#include "TestAggregator.hpp"

#include "RamStreamTest.hpp"
#include "PipeStreamTest.hpp"
#include "NamedPipeStreamTest.hpp"
#include "NamedPipeReaderTest.hpp"
#include "NamedPipeWriterTest.hpp"

namespace flame_ide
{namespace streams
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Streams")
{
	pushBackTest(std::make_shared<RamStreamTest>());
	pushBackTest(std::make_shared<PipeStreamTest>());
	pushBackTest(std::make_shared<NamedPipeStreamTest>());
	pushBackTest(std::make_shared<NamedPipeWriterTest>());
	pushBackTest(std::make_shared<NamedPipeReaderTest>());
}

}}}

