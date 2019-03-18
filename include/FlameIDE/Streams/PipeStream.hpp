#ifndef FLAMEIDE_STREAMS_PIPESTREAM_HPP
#define FLAMEIDE_STREAMS_PIPESTREAM_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/FileStreamReader.hpp>
#include <FlameIDE/Streams/FileStreamWriter.hpp>

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

	PipeStream() noexcept;
	PipeStream(const PipeStream &) = delete;
	PipeStream(PipeStream &&pipes) noexcept;

	PipeStream(os::FileDescriptor fileDescriptorReader, bool readerOwn
			, os::FileDescriptor fileDescriptorWriter, bool writerOwn) noexcept;

	virtual ~PipeStream() noexcept = default;

	PipeStream &operator=(const PipeStream &) = delete;
	PipeStream &operator=(PipeStream &&) noexcept;

	os::Status getStatus() const;

protected:
	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

	virtual void flush() noexcept;

private:
	os::Status status;
	FileStreamReader reader;
	FileStreamWriter writer;
};

}}

#endif // FLAMEIDE_STREAMS_PIPESTREAM_HPP
