#ifndef FLAMEIDE_STREAMS_PIPESTREAMWRITER_HPP
#define FLAMEIDE_STREAMS_PIPESTREAMWRITER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

class PipeStream;

///
/// @brief The PipeStreamWriter class
///
class PipeStreamWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	friend class PipeStream;

	PipeStreamWriter(os::FileDescriptor fileDescriptor);

	PipeStreamWriter(const PipeStreamWriter &) = delete;
	PipeStreamWriter &operator=(const PipeStreamWriter &) = delete;

	virtual ~PipeStreamWriter();

	virtual SizeTraits::SsizeType write(InputByteRange range);
	virtual SizeTraits::SsizeType write(InputCircularByteRange range);

private:
	PipeStreamWriter();

	PipeStreamWriter(PipeStreamWriter &&writer);

	PipeStreamWriter &operator=(PipeStreamWriter &&writer);

	void setFileDescriptor(os::FileDescriptor fileDescriptor);

	os::FileDescriptor fd;
};


}}

#endif // FLAMEIDE_STREAMS_PIPESTREAMWRITER_HPP
