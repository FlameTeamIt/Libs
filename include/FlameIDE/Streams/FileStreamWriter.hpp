#ifndef FLAMEIDE_STREAMS_FILESTREAMWRITER_HPP
#define FLAMEIDE_STREAMS_FILESTREAMWRITER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

class PipeStream;

///
class FileStreamWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	friend class PipeStream;

	FileStreamWriter();
	FileStreamWriter(const FileStreamWriter &) = delete;
	FileStreamWriter(FileStreamWriter &&writer) noexcept;

	///
	FileStreamWriter(os::FileDescriptor fileDescriptor
			, bool owner = true) noexcept;

	virtual ~FileStreamWriter() noexcept;

	FileStreamWriter &operator=(const FileStreamWriter &) = delete;
	FileStreamWriter &operator=(FileStreamWriter &&writer) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

	virtual void flush() noexcept;

	///
	void setFileDescriptor(os::FileDescriptor fileDescriptor
			, bool owner = true) noexcept;

	///
	os::FileDescriptor getFileDescriptor(bool continueOwning = false) noexcept;

private:
	os::FileDescriptor fd; ///
	bool own; ///
};


}}

#endif // FLAMEIDE_STREAMS_FILESTREAMWRITER_HPP
