#ifndef FLAMEIDE_STREAMS_PIPESTREAM_HPP
#define FLAMEIDE_STREAMS_PIPESTREAM_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

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

	PipeStreamReader();
	virtual ~PipeStreamReader();

	virtual SizeTraits::SsizeType read(OutputByteRange range) = 0;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) = 0;

private:
};

///
/// @brief The PipeStreamWriter class
///
class PipeStreamWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	PipeStreamWriter();
	virtual ~PipeStreamWriter();

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

private:
};

///
/// @brief The PipeStream class
///
class PipeStream: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	PipeStream();
	virtual ~PipeStream();

	virtual SizeTraits::SsizeType read(OutputByteRange range);
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range);

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

	PipeStreamReader getReader();
	PipeStreamWriter getWriter();
};


}}

#endif // FLAMEIDE_STREAMS_PIPESTREAM_HPP
