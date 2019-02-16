#ifndef FLAMEIDE_STREAMS_PIPESTREAM_PIPESTREAM_HPP
#define FLAMEIDE_STREAMS_PIPESTREAM_PIPESTREAM_HPP

#include <FlameIDE/Streams/PipeStream/PipeStreamReader.hpp>
#include <FlameIDE/Streams/PipeStream/PipeStreamWriter.hpp>

namespace flame_ide
{namespace streams
{

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
	PipeStream(PipeStream &&) = default;

	virtual ~PipeStream();

	PipeStream &operator=(const PipeStream &) = delete;
	PipeStream &operator=(PipeStream &&);

protected:
	virtual SizeTraits::SsizeType read(OutputByteRange range);
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range);

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

private:
	PipeStreamReader reader;
	PipeStreamWriter writer;
};

}}

#endif // FLAMEIDE_STREAMS_PIPESTREAM_PIPESTREAM_HPP
