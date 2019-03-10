#ifndef FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP

#include <FlameIDE/Streams/NamedPipeReader.hpp>
#include <FlameIDE/Streams/NamedPipeWriter.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeStream class
///
class NamedPipeStream: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	NamedPipeStream();
	NamedPipeStream(const char *name) noexcept;
	virtual ~NamedPipeStream();

	os::Status open(const char *name) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

private:
	NamedPipeReader writer;
	NamedPipeReader reader;
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
