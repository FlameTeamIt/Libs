#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/Windows/InternalWinApiFunctions.hpp>
#include <FlameIDE/Streams/NamedPipeStream.hpp>

namespace flame_ide
{namespace streams
{

NamedPipeStream::NamedPipeStream() noexcept = default;

NamedPipeStream::NamedPipeStream(NamedPipeStream &&stream) noexcept :
		fname(move(stream.fname))
		, writer(move(stream.writer))
		, reader(move(stream.reader))
		, delPipe(stream.delPipe)
{
	stream.delPipe = false;
}

NamedPipeStream::NamedPipeStream(const char *name, bool deletePipe) noexcept :
		fname(name)
		, writer(makeNamedPipe(name, os::ActionType::BIDIRECTIONAL))
		, reader(writer.getFileDescriptor(true), false)
		, delPipe(deletePipe)
{}

NamedPipeStream::~NamedPipeStream() noexcept
{
	deinit();
}

NamedPipeStream &NamedPipeStream::operator=(NamedPipeStream &&stream) noexcept
{
	deinit();

	fname = move(stream.fname);
	writer = move(stream.writer);
	reader = move(stream.reader);
	delPipe = stream.delPipe;

	stream.delPipe = false;

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

os::FileDescriptor NamedPipeStream::getFileDescriptor(bool continueOwning) noexcept
{
	return writer.getFileDescriptor(continueOwning);
}

os::Status NamedPipeStream::open(const char *name, bool deletePipe) noexcept
{
	deinit();

	fname = name;
	delPipe = deletePipe;

	os::FileDescriptor fd = makeNamedPipe(name, os::ActionType::BIDIRECTIONAL);
	if (fd == os::INVALID_DESCRIPTOR)
	{
		return GetLastError();
	}
	writer.setFileDescriptor(fd);
	reader.setFileDescriptor(writer.getFileDescriptor(true), false);

	return os::SUCCESS_STATUS;
}

const templates::String &NamedPipeStream::getName() const noexcept
{
	return fname;
}

void NamedPipeStream::deinit()
{
	os::FileDescriptor fd = writer.getFileDescriptor();
	if (fd != INVALID_HANDLE_VALUE || fd != os::INVALID_DESCRIPTOR)
	{
		CloseHandle(fd);
	}
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
