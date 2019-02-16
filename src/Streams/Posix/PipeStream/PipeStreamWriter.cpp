#include <unistd.h>

#include <FlameIDE/Streams/PipeStream/PipeStreamWriter.hpp>

namespace flame_ide
{namespace streams
{

// public

PipeStreamWriter::PipeStreamWriter(os::FileDescriptor fileDescriptor)
		: fd(fileDescriptor)
{}

PipeStreamWriter::~PipeStreamWriter()
{
	setFileDescriptor(os::INVALID_DESCRIPTOR);
}

SizeTraits::SsizeType PipeStreamWriter::write(InputByteRange range)
{
	SizeTraits::SsizeType countBytes = stream_utils::INVALID_COUNT_BYTES;
	SizeTraits::SsizeType rangeSize = range.end() - range.begin();
	if (rangeSize > 0)
	{
		countBytes = ::write(
				fd
				, getPointer(range.begin())
				, static_cast<SizeTraits::SizeType>(rangeSize)
		);
	}
	return countBytes;
}

SizeTraits::SsizeType PipeStreamWriter::write(InputCircularByteRange range)
{
	auto ranges = Parent::getContiniousInputRanges(range);
	SizeTraits::SsizeType countBytes[ranges.CAPACITY] = {
			write(ranges[0]), stream_utils::INVALID_COUNT_BYTES
	};
	if (countBytes[0] != stream_utils::INVALID_COUNT_BYTES
			&& (ranges[1].end() - ranges[1].begin() > 0))
	{
		countBytes[1] = write(ranges[1]);
		if (countBytes[1] < 0)
		{
			return countBytes[1];
		}
	}
	return countBytes[0] + countBytes[1];
}

// private

PipeStreamWriter::PipeStreamWriter() : fd(os::INVALID_DESCRIPTOR)
{}

PipeStreamWriter::PipeStreamWriter(PipeStreamWriter &&writer) : fd(writer.fd)
{
	writer.fd = os::INVALID_DESCRIPTOR;
}

PipeStreamWriter &PipeStreamWriter::operator=(PipeStreamWriter &&writer)
{
	fd = writer.fd;
	writer.fd = os::INVALID_DESCRIPTOR;
	return *this;
}

void PipeStreamWriter::setFileDescriptor(os::FileDescriptor fileDescriptor)
{
	if (fd != os::INVALID_DESCRIPTOR)
	{
		close(fd);
	}
	fd = fileDescriptor;
}

}}
