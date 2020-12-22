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
	PipeStream(const PipeStream &) noexcept = delete;
	PipeStream(PipeStream &&pipes) noexcept;

	///
	/// @brief PipeStream
	/// @param fileDescriptorReader
	/// @param readerOwn
	/// @param fileDescriptorWriter
	/// @param writerOwn
	///
	PipeStream(os::FileDescriptor fileDescriptorReader, bool readerOwn
			, os::FileDescriptor fileDescriptorWriter, bool writerOwn) noexcept;

	virtual ~PipeStream() noexcept = default;

	PipeStream &operator=(const PipeStream &) noexcept = delete;
	PipeStream &operator=(PipeStream &&) noexcept;

	///
	/// @brief setReaderFileDescriptor
	/// @param fileDescriptor
	/// @param owner
	///
	void setReaderFileDescriptor(os::FileDescriptor fileDescriptor
			, bool owner = true) noexcept;

	///
	/// @brief setFileDescriptor
	/// @param fileDescriptor
	/// @param owner
	///
	void setWriterFileDescriptor(os::FileDescriptor fileDescriptor
			, bool owner = true) noexcept;

	///
	/// @brief getReaderFileDescriptor
	/// @param continueOwning
	/// @return
	///
	os::FileDescriptor getReaderFileDescriptor(bool continueOwning = false) noexcept;

	///
	/// @brief getWriterFileDescriptor
	/// @param continueOwning
	/// @return
	///
	os::FileDescriptor getWriterFileDescriptor(bool continueOwning = false) noexcept;

	///
	/// @brief getStatus
	/// @return
	///
	os::Status getStatus() const;

protected:
	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

	virtual void flush() noexcept;

private:
	os::Status status; ///<
	FileStreamReader reader; ///<
	FileStreamWriter writer; ///<
};

}}

#endif // FLAMEIDE_STREAMS_PIPESTREAM_HPP
