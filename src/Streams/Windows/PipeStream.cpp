#include <FlameIDE/Common/Macroses.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Streams/PipeStream.hpp>

enum
{
	PIPE_READER
	, PIPE_WRITER
	, PIPE_COUNT
};

namespace flame_ide
{namespace streams
{

PipeStream::PipeStream() noexcept : status(os::SUCCESS_STATUS), reader(), writer()
{
	os::FileDescriptor fds[PIPE_COUNT];
	status = ::CreatePipe(
			&fds[PIPE_READER]
			, &fds[PIPE_WRITER]
			, nullptr
			, 0);
	if (status)
	{
		reader.setFileDescriptor(fds[PIPE_READER]);
		writer.setFileDescriptor(fds[PIPE_WRITER]);
	}
}

PipeStream::PipeStream(PipeStream &&pipes) noexcept :
		reader(flame_ide::move(pipes.reader))
		, writer(flame_ide::move(pipes.writer))
{}

PipeStream::PipeStream(os::FileDescriptor fileDescriptorReader, bool readerOwn
		, os::FileDescriptor fileDescriptorWriter, bool writerOwn) noexcept :
		status(os::SUCCESS_STATUS)
		, reader(fileDescriptorReader, readerOwn)
		, writer(fileDescriptorWriter, writerOwn)
{}

PipeStream &PipeStream::operator=(PipeStream &&pipes) noexcept
{
	status = os::SUCCESS_STATUS;
	reader = flame_ide::move(pipes.reader);
	writer = flame_ide::move(pipes.writer);
	return *this;
}

os::Status PipeStream::getStatus() const
{
	return status;
}

SizeTraits::SsizeType PipeStream::read(OutputByteRange range) noexcept
{
	auto readBytes = reader.read(range);
	if (readBytes == stream_utils::INVALID_COUNT_BYTES)
	{
		status = static_cast<os::Status>(readBytes);
	}
	return readBytes;
}

SizeTraits::SsizeType PipeStream::read(OutputCircularByteRange range) noexcept
{
	auto readBytes = reader.read(range);
	if (readBytes == stream_utils::INVALID_COUNT_BYTES)
	{
		status = static_cast<os::Status>(readBytes);
	}
	return readBytes;
}

SizeTraits::SsizeType PipeStream::write(InputByteRange range) noexcept
{
	auto writtenBytes = writer.write(range);
	if (writtenBytes == stream_utils::INVALID_COUNT_BYTES)
	{
		status = static_cast<os::Status>(writtenBytes);
	}
	return writtenBytes;
}

SizeTraits::SsizeType PipeStream::write(InputCircularByteRange range) noexcept
{
	auto writtenBytes = writer.write(range);
	if (writtenBytes == stream_utils::INVALID_COUNT_BYTES)
	{
		status = static_cast<os::Status>(writtenBytes);
	}
	return writtenBytes;
}

void PipeStream::flush() noexcept
{
	writer.flush();
}



}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
