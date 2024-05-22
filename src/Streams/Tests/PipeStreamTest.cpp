#include "PipeStreamTest.hpp"

#include <FlameIDE/Streams/PipeStream.hpp>

#include <array>

namespace flame_ide
{namespace streams
{namespace tests
{

PipeStreamTest::PipeStreamTest() : ::AbstractTest("PipeStream")
{}

PipeStreamTest::~PipeStreamTest() = default;

int PipeStreamTest::vStart()
{
	std::array<byte_t, 16> writtableArray;
	std::array<byte_t, 16> readableArray;

	Types::uichar_t byte = 0;
	for (auto &i : writtableArray)
	{
		i = toByte(++byte);
	}

	PipeStream stream;
	auto writtableRange = templates::makeRange(
			PipeStream::ConstByteIterator(&writtableArray.front())
			, PipeStream::ConstByteIterator(
					&writtableArray.front() + writtableArray.size()
			)
	);
	auto result = stream.getWriter().write(writtableRange);
	IN_CASE_CHECK(result == static_cast<Types::ssize_t>(writtableArray.size()));

	auto readableRange = PipeStream::OutputByteRange(
			PipeStream::ByteIterator(&readableArray.front())
			, PipeStream::ByteIterator(&readableArray.front() + readableArray.size())
	);

	result = stream.getReader().read(readableRange);
	IN_CASE_CHECK(result == static_cast<Types::ssize_t>(writtableArray.size())
			&& result == static_cast<Types::ssize_t>(readableArray.size()));

	IN_CASE_CHECK(std::equal(
			readableArray.begin(), readableArray.end(), writtableArray.begin()
	));

	return 0;
}

}}}
