#include <FlameIDE/Common/Macroses.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Streams/FileStreamReader.hpp>

namespace flame_ide
{namespace streams
{

FileStreamReader::FileStreamReader() noexcept : fd(os::INVALID_DESCRIPTOR)
{}

FileStreamReader::FileStreamReader(FileStreamReader &&reader) noexcept :
		fd(reader.fd), own(reader.own)
{
	reader.fd = os::INVALID_DESCRIPTOR;
	reader.own = false;
}

FileStreamReader::FileStreamReader(os::FileDescriptor fileDescriptor
		, bool owner) noexcept :
		fd(fileDescriptor), own(owner)
{}

FileStreamReader::~FileStreamReader() noexcept
{
	if (own && fd != os::INVALID_DESCRIPTOR)
	{
		::CloseHandle(fd);
	}
}

FileStreamReader &FileStreamReader::operator=(FileStreamReader &&reader) noexcept
{
	fd = reader.fd;
	own = reader.own;

	reader.fd = os::INVALID_DESCRIPTOR;
	reader.own = false;

	return *this;
}

SizeTraits::SsizeType FileStreamReader::read(OutputByteRange range) noexcept
{
	SizeTraits::SsizeType countBytes = stream_utils::INVALID_COUNT_BYTES;
	SizeTraits::SsizeType rangeSize = range.end() - range.begin();
	if (rangeSize > 0)
	{
		DWORD countBytes1 = 0;
		auto status = ::ReadFile(
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

SizeTraits::SsizeType FileStreamReader::read(OutputCircularByteRange range) noexcept
{
	auto ranges = Parent::getContinuousOutputRanges(range);
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

void FileStreamReader::setFileDescriptor(os::FileDescriptor fileDescriptor
		, bool owner) noexcept
{
	if (own && fd != os::INVALID_DESCRIPTOR)
	{
		::CloseHandle(fd);
	}
	fd = fileDescriptor;
	own = owner;
}

os::FileDescriptor FileStreamReader::getFileDescriptor(
		bool continueOwning) noexcept
{
	own = continueOwning;
	return fd;
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
