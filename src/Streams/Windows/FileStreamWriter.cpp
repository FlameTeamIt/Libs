#include <FlameIDE/Common/Macroses.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Streams/FileStreamWriter.hpp>

namespace flame_ide
{namespace streams
{

FileStreamWriter::FileStreamWriter() noexcept : fd(os::INVALID_DESCRIPTOR)
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
		::CloseHandle(fd);
	}
}

SizeTraits::SsizeType FileStreamWriter::write(InputByteRange range) noexcept
{
	SizeTraits::SsizeType countBytes = stream_utils::INVALID_COUNT_BYTES;
	SizeTraits::SsizeType rangeSize = range.end() - range.begin();
	if (rangeSize > 0)
	{
		DWORD countBytes1 = 0;
		auto status = ::WriteFile(
				fd
				, getPointer(range.begin())
				, static_cast<DWORD>(rangeSize)
				, &countBytes1
				, nullptr
		);
		if (status)
		{
			countBytes = static_cast<SizeTraits::SsizeType>(countBytes1);
		}
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
	::FlushFileBuffers(fd);
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
		::CloseHandle(fd);
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

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
