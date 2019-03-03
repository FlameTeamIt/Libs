#ifndef FLAMEIDE_STREAMS_FILESTREAMREADER_HPP
#define FLAMEIDE_STREAMS_FILESTREAMREADER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

class PipeStream;

///
class FileStreamReader: public stream_utils::AbstractByteStreamReader
{
public:
	friend class PipeStream;

	using Parent = stream_utils::AbstractByteStreamReader;

	FileStreamReader();
	FileStreamReader(const FileStreamReader &) = delete;
	FileStreamReader(FileStreamReader &&reader) noexcept;

	///
	FileStreamReader(os::FileDescriptor fileDescriptor
			, bool owner = true) noexcept;

	virtual ~FileStreamReader();

	FileStreamReader &operator=(const FileStreamReader &) = delete;
	FileStreamReader &operator=(FileStreamReader &&reader) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	///
	void setFileDescriptor(os::FileDescriptor fileDescriptor
			, bool owner = true) noexcept;

	///
	os::FileDescriptor getFileDescriptor(bool continueOwning = false) noexcept;

protected:
	os::FileDescriptor fd;
	bool own;
};

}}

#endif // FLAMEIDE_STREAMS_FILESTREAMREADER_HPP
