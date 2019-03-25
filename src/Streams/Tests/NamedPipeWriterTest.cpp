#include "NamedPipeWriterTest.hpp"

#include <FlameIDE/Streams/NamedPipeWriter.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

NamedPipeWriterTest::NamedPipeWriterTest() : AbstractTest("NamedPipeWriter")
{}

NamedPipeWriterTest::~NamedPipeWriterTest() = default;

int NamedPipeWriterTest::vStart()
{
	return 0;
}

}}}
