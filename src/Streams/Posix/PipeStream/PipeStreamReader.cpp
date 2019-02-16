#include <unistd.h>

#include <FlameIDE/Streams/PipeStream/PipeStreamReader.hpp>

namespace flame_ide
{namespace streams
{

// public

PipeStreamReader::PipeStreamReader(os::FileDescriptor fileDescriptor)
		: fd(fileDescriptor)
{}

PipeStreamReader::~PipeStreamReader()
{
	setFileDescriptor(os::INVALID_DESCRIPTOR);
}

SizeTraits::SsizeType PipeStreamReader::read(OutputByteRange range)
{
	SizeTraits::SsizeType countBytes = stream_utils::INVALID_COUNT_BYTES;
	SizeTraits::SsizeType rangeSize = range.end() - range.begin();
	if (rangeSize > 0)
	{
		countBytes = ::read(
				fd
				, getPointer(range.begin())
				, static_cast<SizeTraits::SizeType>(rangeSize)
		);
	}
	return countBytes;
}

SizeTraits::SsizeType PipeStreamReader::read(OutputCircularByteRange range)
{
	auto ranges = Parent::getContiniousOutputRanges(range);
	SizeTraits::SsizeType countBytes[ranges.CAPACITY] = {
			read(ranges[0]), stream_utils::INVALID_COUNT_BYTES
	};
	if (countBytes[0] != stream_utils::INVALID_COUNT_BYTES)
	{
		countBytes[1] = read(ranges[1]);
		if (countBytes[1] < 0)
		{
			return countBytes[1];
		}
	}
	return countBytes[0] + countBytes[1];
}

// protected

PipeStreamReader::PipeStreamReader() : fd(os::INVALID_DESCRIPTOR)
{}

PipeStreamReader::PipeStreamReader(PipeStreamReader &&reader) : fd(reader.fd)
{
	reader.fd = os::INVALID_DESCRIPTOR;
}

PipeStreamReader &PipeStreamReader::operator=(PipeStreamReader &&reader)
{
	fd = reader.fd;
	reader.fd = os::INVALID_DESCRIPTOR;
	return *this;
}

void PipeStreamReader::setFileDescriptor(os::FileDescriptor fileDescriptor)
{
	if (fd != os::INVALID_DESCRIPTOR)
	{
		close(fd);
	}
	fd = fileDescriptor;
}

}}
