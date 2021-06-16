#include <FlameIDE/../../src/Os/Tests/PipeTest.hpp>

#include <FlameIDE/Os/Pipe.hpp>
#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

PipeTest::PipeTest() : ::AbstractTest("Pipe")
{}

PipeTest::~PipeTest() = default;

int PipeTest::vStart()
{
	constexpr Types::size_t dataSize = 32;
	Types::uichar_t inputData[dataSize];
	{
		Types::uichar_t i = 0;
		templates::foreach(templates::makeRange(inputData)
				, [&i](auto &v)
				{
					v = i++;
				}
		);
	}
	Pipe pipe;
	auto writeSize = write(pipe, reinterpret_cast<byte_t *>(inputData), dataSize);
	if (writeSize != dataSize)
	{
		return FAILED;
	}

	Types::uichar_t outputData[dataSize];
	auto readSize = read(pipe, reinterpret_cast<byte_t *>(outputData), dataSize);
	if (readSize != dataSize)
	{
		return FAILED;
	}

	if (!isEqual(
			reinterpret_cast<byte_t *>(inputData)
			, reinterpret_cast<byte_t *>(inputData) + dataSize
			, reinterpret_cast<byte_t *>(outputData)
			, reinterpret_cast<byte_t *>(outputData) + dataSize))
	{
		return FAILED;
	}

	return SUCCESS;
}

}}} // namespace flame_ide::os::tests
