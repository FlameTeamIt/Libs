#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/Windows/InternalWinApiFunctions.hpp>
#include <FlameIDE/Streams/NamedPipeReader.hpp>

namespace flame_ide
{namespace streams
{

NamedPipeReader::NamedPipeReader() noexcept : Parent()
{}

NamedPipeReader::NamedPipeReader(NamedPipeReader &&reader) noexcept :
		Parent(move(reader)), delPipe(reader.delPipe)
{
	reader.delPipe = false;
}

NamedPipeReader::NamedPipeReader(const char *name, bool deletePipe) noexcept :
		Parent(makeNamedPipe(name, os::ActionType::READER).reader, true)
		, fname(name)
		, delPipe(deletePipe)
{}

NamedPipeReader::~NamedPipeReader() noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);
	if (delPipe)
	{
	}
}

NamedPipeReader &NamedPipeReader::operator=(NamedPipeReader &&reader) noexcept
{
	this->Parent::operator=(move(reader));

	delPipe = reader.delPipe;
	reader.delPipe = false;

	return *this;
}

SizeTraits::SsizeType NamedPipeReader::read(OutputByteRange range) noexcept
{
	if (!ConnectNamedPipe(this->fd, nullptr))
	{
		return -static_cast<SizeTraits::SsizeType>(GetLastError());
	}
	auto result = this->FileStreamReader::read(range);
	if (result < 0)
	{
		if (!DisconnectNamedPipe(this->fd))
		{
			return -static_cast<SizeTraits::SsizeType>(GetLastError());
		}
		return stream_utils::INVALID_COUNT_BYTES;
	}
	if (!DisconnectNamedPipe(this->fd))
	{
		return -static_cast<SizeTraits::SsizeType>(GetLastError());
	}
	return result;
}

SizeTraits::SsizeType NamedPipeReader::read(OutputCircularByteRange range) noexcept
{
	if (!ConnectNamedPipe(this->fd, nullptr))
	{
		return -static_cast<SizeTraits::SsizeType>(GetLastError());
	}
	auto result = this->FileStreamReader::read(range);
	if (result < 0)
	{
		if (!DisconnectNamedPipe(this->fd))
		{
			return -static_cast<SizeTraits::SsizeType>(GetLastError());
		}
		return stream_utils::INVALID_COUNT_BYTES;
	}
	if (!DisconnectNamedPipe(this->fd))
	{
		return -static_cast<SizeTraits::SsizeType>(GetLastError());
	}
	return result;
}


os::Status NamedPipeReader::open(const char *name, bool deletePipe) noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);

	os::FileDescriptor fd = makeNamedPipe(name, os::ActionType::READER).reader;
	if (fd == os::INVALID_DESCRIPTOR)
	{
		return GetLastError();
	}
	this->setFileDescriptor(fd, true);
	delPipe = deletePipe;

	return os::STATUS_SUCCESS;
}

const templates::String &NamedPipeReader::getName() const noexcept
{
	return fname;
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
