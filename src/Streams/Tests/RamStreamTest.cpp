#include "RamStreamTest.hpp"

#include <FlameIDE/Streams/RamStream.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

RamStreamTest::RamStreamTest() : ::AbstractTest("RamStream")
{}

RamStreamTest::~RamStreamTest() = default;

int RamStreamTest::vStart()
{
	std::array<byte_t, 16> writtableArray;
	std::array<byte_t, 16> readableArray;

	Types::uichar_t byte = 0;
	for (auto &i : writtableArray)
	{
		i = toByte(++byte);
	}

	RamStream stream;
	auto writtableRange = templates::makeRange(
			RamStream::ConstByteIterator(&writtableArray.front())
			, RamStream::ConstByteIterator(&writtableArray.front() + writtableArray.size())
	);
	auto result = stream.write(writtableRange);
	IN_CASE_CHECK(result == writtableArray.size());

	auto readableRange = RamStream::OutputByteRange(
			RamStream::ByteIterator(&readableArray.front())
			, RamStream::ByteIterator(&readableArray.front() + readableArray.size())
	);

	result = stream.read(readableRange);
	IN_CASE_CHECK(result == writtableArray.size() && result == readableArray.size());

	IN_CASE_CHECK(std::equal(readableArray.begin(), readableArray.end(), writtableArray.begin()));

	return 0;
}

}}}
