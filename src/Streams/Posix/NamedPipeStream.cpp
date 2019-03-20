#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Streams/NamedPipeStream.hpp>

#include <FlameIDE/../../src/Streams/Posix/InternalPosixFunctions.hpp>

#include <unistd.h>

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
		, writer(makeFifo(name, os::ActionType::BIDIRECTIONAL))
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

	os::FileDescriptor fd = makeFifo(name, os::ActionType::BIDIRECTIONAL);
	if (fd < 0)
	{
		return fd;
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
	if (fd > 0)
	{
		::close(fd);
		if (delPipe)
		{
			::remove(fname.data());
		}
		fd = os::INVALID_DESCRIPTOR;
	}
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
