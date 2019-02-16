#include <unistd.h>

#include <FlameIDE/Streams/PipeStream/PipeStream.hpp>

namespace flame_ide
{namespace streams
{

// public

PipeStream::PipeStream()
{
	os::FileDescriptor fd[2];
	auto status = ::pipe(fd);
	if (status == os::SUCCESS_STATUS)
	{
		reader.setFileDescriptor(fd[0]);
		writer.setFileDescriptor(fd[1]);
	}
}

PipeStream::PipeStream(os::FileDescriptor fdReader, os::FileDescriptor fdWriter) :
		reader(fdReader), writer(fdWriter)
{}

PipeStream::~PipeStream() = default;

PipeStream &PipeStream::operator=(PipeStream &&) = default;

// protected

SizeTraits::SsizeType PipeStream::read(OutputByteRange range)
{
	return reader.read(range);
}

SizeTraits::SsizeType PipeStream::read(OutputCircularByteRange range)
{
	return reader.read(range);
}

SizeTraits::SsizeType PipeStream::write(InputByteRange range)
{
	return writer.write(range);
}

SizeTraits::SsizeType PipeStream::write(InputCircularByteRange range)
{
	return writer.write(range);
}

}}
