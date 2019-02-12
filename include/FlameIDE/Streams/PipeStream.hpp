#ifndef FLAMEIDE_STREAMS_PIPESTREAM_HPP
#define FLAMEIDE_STREAMS_PIPESTREAM_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The PipeStreamReader class
///
class PipeStreamReader: public stream_utils::AbstractByteStreamReader
{
public:
	using Parent = stream_utils::AbstractByteStreamReader;

	virtual ~PipeStreamReader();

	virtual SizeTraits::SsizeType read(OutputByteRange range);
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range);

protected:
	PipeStreamReader(os::FileDescriptor fd) : fileDescriptor(fd)
	{}

	os::FileDescriptor fileDescriptor;
};

///
/// @brief The PipeStreamWriter class
///
class PipeStreamWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	friend class PipeStream;

	virtual ~PipeStreamWriter();

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

private:
	PipeStreamWriter(os::FileDescriptor fd) : fileDescriptor(fd)
	{}

	os::FileDescriptor fileDescriptor;
};

///
/// @brief The PipeStream class
///
class PipeStream: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	PipeStream();
	PipeStream(os::FileDescriptor fdReader, os::FileDescriptor fdWriter);

	PipeStream(const PipeStream &) = delete;
	PipeStream(PipeStream &&);

	virtual ~PipeStream();

	PipeStream &operator=(const PipeStream &) = delete;
	PipeStream &operator=(PipeStream &&);

	PipeStreamReader getReader();
	PipeStreamWriter getWriter();

	os::FileDescriptor &getFdRead();
	os::FileDescriptor &getFdWrite();

protected:
	virtual SizeTraits::SsizeType read(OutputByteRange range);
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range);

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

private:
	os::FileDescriptor fileDescriptors[2];
};

}}

#endif // FLAMEIDE_STREAMS_PIPESTREAM_HPP
