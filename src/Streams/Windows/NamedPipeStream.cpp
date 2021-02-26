#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>
#include <FlameIDE/Streams/NamedPipeStream.hpp>

#include <FlameIDE/Templates/RaiiCaller.hpp>

namespace flame_ide
{namespace streams
{

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

	Descriptors fds = makeNamedPipe(name, os::ActionType::BIDIRECTIONAL);
	if (fds.reader.fd == os::INVALID_DESCRIPTOR || fds.writer.fd == os::INVALID_DESCRIPTOR)
	{
		return GetLastError();
	}
	writer.setFileDescriptor(fds.writer.fd);
	reader.setFileDescriptor(fds.reader.fd);

	return os::STATUS_SUCCESS;
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
