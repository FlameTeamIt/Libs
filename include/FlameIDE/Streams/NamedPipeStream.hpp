#ifndef FLAMEIDE_STREAMS_NAMEDNamedPipeStream_HPP
#define FLAMEIDE_STREAMS_NAMEDNamedPipeStream_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeStreamReader class
///
class NamedPipeStreamReader: public stream_utils::AbstractByteStreamReader
{
public:
	using Parent = stream_utils::AbstractByteStreamReader;

	NamedPipeStreamReader();
	virtual ~NamedPipeStreamReader();

	virtual SizeTraits::SsizeType read(OutputByteRange range) = 0;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) = 0;

private:
};

///
/// @brief The NamedPipeStreamWriter class
///
class NamedPipeStreamWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	NamedPipeStreamWriter();
	virtual ~NamedPipeStreamWriter();

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

private:
};

///
/// @brief The NamedPipeStream class
///
class NamedPipeStream: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	NamedPipeStream();
	virtual ~NamedPipeStream();

	virtual SizeTraits::SsizeType read(OutputByteRange range);
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range);

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

	NamedPipeStreamReader getReader();
	NamedPipeStreamWriter getWriter();
};


}}

#endif // FLAMEIDE_STREAMS_NAMEDNamedPipeStream_HPP
