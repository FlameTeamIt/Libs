#include <FlameIDE/Common/Macros.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Streams/PipeStream.hpp>

namespace flame_ide
{namespace streams
{

enum
{
	PIPE_READER = static_cast<int32_t>(os::ActionType::READER)
	, PIPE_WRITER = static_cast<int32_t>(os::ActionType::WRITER)
	, PIPE_COUNT
};

PipeStream::PipeStream() noexcept : status(os::STATUS_SUCCESS), reader(), writer()
{
	os::FileDescriptor fds[PIPE_COUNT];
	status = ::CreatePipe(
			&fds[PIPE_READER].handle
			, &fds[PIPE_WRITER].handle
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
		status(os::STATUS_SUCCESS)
		, reader(fileDescriptorReader, readerOwn)
		, writer(fileDescriptorWriter, writerOwn)
{}

PipeStream &PipeStream::operator=(PipeStream &&pipes) noexcept
{
	status = os::STATUS_SUCCESS;
	reader = flame_ide::move(pipes.reader);
	writer = flame_ide::move(pipes.writer);
	return *this;
}

void PipeStream::setReaderFileDescriptor(os::FileDescriptor fileDescriptor, bool owner) noexcept
{
	reader.setFileDescriptor(fileDescriptor, owner);
}

void PipeStream::setWriterFileDescriptor(os::FileDescriptor fileDescriptor, bool owner) noexcept
{
	writer.setFileDescriptor(fileDescriptor, owner);
}

os::FileDescriptor PipeStream::getReaderFileDescriptor(bool continueOwning) noexcept
{
	return reader.getFileDescriptor(continueOwning);
}

os::FileDescriptor PipeStream::getWriterFileDescriptor(bool continueOwning) noexcept
{
	return writer.getFileDescriptor(continueOwning);
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
