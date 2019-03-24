#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/Windows/InternalWinApiFunctions.hpp>
#include <FlameIDE/Streams/NamedPipeStream.hpp>

#include <FlameIDE/Templates/RaiiCaller.hpp>

namespace flame_ide
{namespace streams
{

auto LambdaConnect = [](os::FileDescriptor fd)
{
	return ConnectNamedPipe(fd, nullptr);
};

auto LambdaDisconnect = [](os::FileDescriptor fd)
{
	return DisconnectNamedPipe(fd);
};

NamedPipeStream::NamedPipeStream() noexcept = default;

NamedPipeStream::NamedPipeStream(NamedPipeStream &&stream) noexcept :
		writer(move(stream.writer))
		, reader(move(stream.reader))
{
}

NamedPipeStream::NamedPipeStream(const char *name, bool deletePipe) noexcept :
		writer(name, deletePipe), reader(name)
{}

NamedPipeStream::~NamedPipeStream() noexcept
{
	deinit();
}

NamedPipeStream &NamedPipeStream::operator=(NamedPipeStream &&stream) noexcept
{
	deinit();

	writer = move(stream.writer);
	reader = move(stream.reader);

	return *this;
}

SizeTraits::SsizeType NamedPipeStream::read(OutputByteRange range) noexcept
{
	return reader.read(range);
}

SizeTraits::SsizeType NamedPipeStream::read(OutputCircularByteRange range) noexcept
{
	return reader.read(range);
}

SizeTraits::SsizeType NamedPipeStream::write(InputByteRange range) noexcept
{
	return writer.write(range);
}

SizeTraits::SsizeType NamedPipeStream::write(InputCircularByteRange range) noexcept
{
	return writer.write(range);
}

void NamedPipeStream::flush() noexcept
{
	writer.flush();
}

void NamedPipeStream::setFileDescriptor(os::FileDescriptor fileDescriptor
		, bool owner) noexcept
{
	writer.setFileDescriptor(fileDescriptor, owner);
	reader.setFileDescriptor(fileDescriptor, false);
}

os::FileDescriptor NamedPipeStream::getReaderFileDescriptor(bool continueOwning) noexcept
{
	return reader.getFileDescriptor(continueOwning);
}

os::FileDescriptor NamedPipeStream::getWriterFileDescriptor(bool continueOwning) noexcept
{
	return writer.getFileDescriptor(continueOwning);
}

os::Status NamedPipeStream::open(const char *name, bool deletePipe) noexcept
{
	deinit();

	Descriptors fd = makeNamedPipe(name, os::ActionType::BIDIRECTIONAL);
	if (fd.reader == os::INVALID_DESCRIPTOR || fd.writer == os::INVALID_DESCRIPTOR)
	{
		return GetLastError();
	}
	writer.setFileDescriptor(fd.writer);
	reader.setFileDescriptor(fd.reader);

	return os::SUCCESS_STATUS;
}

const templates::String &NamedPipeStream::getName() const noexcept
{
	return writer.getName();
}

void NamedPipeStream::deinit()
{
	os::FileDescriptor fd = reader.getFileDescriptor();
	if (fd != INVALID_HANDLE_VALUE || fd != os::INVALID_DESCRIPTOR)
	{
		CloseHandle(fd);
	}
	fd = writer.getFileDescriptor();
	if (fd != INVALID_HANDLE_VALUE || fd != os::INVALID_DESCRIPTOR)
	{
		CloseHandle(fd);
	}
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
