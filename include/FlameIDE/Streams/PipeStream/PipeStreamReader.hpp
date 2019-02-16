#ifndef FLAMEIDE_STREAMS_PIPESTREAM_PIPESTREAMREADER_HPP
#define FLAMEIDE_STREAMS_PIPESTREAM_PIPESTREAMREADER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

class PipeStream;

///
/// @brief The PipeStreamReader class
///
class PipeStreamReader: public stream_utils::AbstractByteStreamReader
{
public:
	friend class PipeStream;

	using Parent = stream_utils::AbstractByteStreamReader;

	PipeStreamReader(os::FileDescriptor fileDescriptor);

	PipeStreamReader(const PipeStreamReader &) = delete;
	PipeStreamReader &operator=(const PipeStreamReader &) = delete;

	virtual ~PipeStreamReader();

	virtual SizeTraits::SsizeType read(OutputByteRange range);
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range);

protected:
	PipeStreamReader();

	PipeStreamReader(PipeStreamReader &&reader);

	PipeStreamReader &operator=(PipeStreamReader &&reader);

	void setFileDescriptor(os::FileDescriptor fileDescriptor);

	os::FileDescriptor fd;
};

}}

#endif // FLAMEIDE_STREAMS_PIPESTREAM_PIPESTREAMREADER_HPP
