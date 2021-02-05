#include <FlameIDE/../../src/Streams/Tests/RamStreamTest.hpp>
#include <FlameIDE/../../src/Streams/Tests/PipeStreamTest.hpp>
#include <FlameIDE/../../src/Streams/Tests/NamedPipeStreamTest.hpp>
#include <FlameIDE/../../src/Streams/Tests/NamedPipeReaderTest.hpp>
#include <FlameIDE/../../src/Streams/Tests/NamedPipeWriterTest.hpp>
#include <FlameIDE/../../src/Streams/Tests/SocketUtilsTest.hpp>

#include <FlameIDE/../../src/Streams/Tests/TestAggregator.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Streams")
{
	pushBackTest(std::make_shared<RamStreamTest>());
	pushBackTest(std::make_shared<PipeStreamTest>());
	pushBackTest(std::make_shared<NamedPipeWriterTest>());
	pushBackTest(std::make_shared<NamedPipeReaderTest>());
	pushBackTest(std::make_shared<NamedPipeStreamTest>());
	pushBackTest(std::make_shared<SocketUtilsTest>());
}

}}}

