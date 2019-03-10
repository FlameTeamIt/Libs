#ifndef FLAMEIDE_STREAMS_NAMEDPIPEWRITER_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPEWRITER

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/FileStreamWriter.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeWriter class
///
class NamedPipeWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	NamedPipeWriter();
	NamedPipeWriter(const char *name) noexcept;
	NamedPipeWriter(os::FileDescriptor fileDescriptor) noexcept;
	~NamedPipeWriter() noexcept;

	os::Status open(const char *name) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

private:
	FileStreamWriter writer;
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPEWRITER
