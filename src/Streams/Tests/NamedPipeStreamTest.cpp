#include "NamedPipeStreamTest.hpp"

#include <FlameIDE/Streams/NamedPipeStream.hpp>

#include <array>

namespace flame_ide
{namespace streams
{namespace tests
{

NamedPipeStreamTest::NamedPipeStreamTest() : AbstractTest("NamedPipeStream")
{}

NamedPipeStreamTest::~NamedPipeStreamTest() = default;

int NamedPipeStreamTest::vStart()
{
	NamedPipeStream stream;
	stream.open("/tmp/test.named.pipe", true);

	std::array<byte_t, 16> writtableArray;
	std::array<byte_t, 16> readableArray;

	Types::uichar_t byte = 0;
	for (auto &i : writtableArray)
	{
		i = toByte(++byte);
	}

	auto writtableRange = templates::makeRange(
			NamedPipeStream::ConstByteIterator(&writtableArray.front())
			, NamedPipeStream::ConstByteIterator(
					&writtableArray.front() + writtableArray.size()
			)
	);
	auto result = stream.getWriter().write(writtableRange);
	IN_CASE_CHECK(result == writtableArray.size())

	auto readableRange = NamedPipeStream::OutputByteRange(
			NamedPipeStream::ByteIterator(&readableArray.front())
			, NamedPipeStream::ByteIterator(
					&readableArray.front() + readableArray.size()
			)
	);

	result = stream.getReader().read(readableRange);
	IN_CASE_CHECK(result == writtableArray.size() && result == readableArray.size())

	IN_CASE_CHECK(std::equal(
			readableArray.begin(), readableArray.end(), writtableArray.begin()
	))

	return 0;
}

}}}
