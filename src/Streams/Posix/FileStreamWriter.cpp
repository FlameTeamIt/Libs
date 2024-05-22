#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <unistd.h>
#include <FlameIDE/Streams/FileStreamWriter.hpp>

namespace flame_ide
{namespace streams
{

FileStreamWriter::FileStreamWriter() noexcept : fd(os::INVALID_DESCRIPTOR), own(false)
{}

FileStreamWriter::FileStreamWriter(FileStreamWriter &&writer) noexcept :
		fd(writer.fd), own(writer.own)
{
	writer.fd = os::INVALID_DESCRIPTOR;
	writer.own = false;
}

FileStreamWriter::FileStreamWriter(os::FileDescriptor fileDescriptor
		, bool owner) noexcept :
		fd(fileDescriptor), own(owner)
{}

FileStreamWriter::~FileStreamWriter() noexcept
{
	if (own && fd != os::INVALID_DESCRIPTOR)
	{
		::close(fd);
	}
}

SizeTraits::SsizeType FileStreamWriter::write(InputByteRange range) noexcept
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

SizeTraits::SsizeType FileStreamWriter::write(InputCircularByteRange range) noexcept
{
	auto ranges = Parent::getContinuousInputRanges(range);
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

void FileStreamWriter::flush() noexcept
{
	::fsync(fd);
}

FileStreamWriter &FileStreamWriter::operator=(FileStreamWriter &&writer) noexcept
{
	fd = writer.fd;
	own = writer.own;

	writer.fd = os::INVALID_DESCRIPTOR;
	writer.own = false;

	return *this;
}

void FileStreamWriter::setFileDescriptor(os::FileDescriptor fileDescriptor
		, bool owner) noexcept
{
	if (own && fd != os::INVALID_DESCRIPTOR)
	{
		::close(fd);
	}
	fd = fileDescriptor;
	own = owner;
}

os::FileDescriptor FileStreamWriter::getFileDescriptor(
		bool continueOwning) noexcept
{
	own = continueOwning;
	return fd;
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
