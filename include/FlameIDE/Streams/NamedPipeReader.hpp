#ifndef FLAMEIDE_STREAMS_NAMEDPIPEREADER
#define FLAMEIDE_STREAMS_NAMEDPIPEREADER

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/FileStreamReader.hpp>
#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeReader class
///
class NamedPipeReader: public stream_utils::AbstractByteStreamReader
{
public:
	using Parent = stream_utils::AbstractByteStreamReader;

	NamedPipeReader() noexcept;
	NamedPipeReader(const char *name) noexcept;
	NamedPipeReader(os::FileDescriptor fileDescriptor) noexcept;
	virtual ~NamedPipeReader() noexcept;

	os::Status open(const char *name) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

private:
	FileStreamReader reader;
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPEREADER
