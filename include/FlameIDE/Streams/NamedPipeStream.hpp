#ifndef FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP

#include <FlameIDE/Streams/NamedPipeReader.hpp>
#include <FlameIDE/Streams/NamedPipeWriter.hpp>
#include <FlameIDE/Templates/String.hpp>

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

	NamedPipeStream() noexcept;
	NamedPipeStream(const NamedPipeStream &stream) noexcept = delete;
	NamedPipeStream(NamedPipeStream &&stream) noexcept;

	///
	/// @brief NamedPipeStream
	/// @param name
	/// @param deletePipe
	///
	NamedPipeStream(const char *name, bool deletePipe = true) noexcept;

	virtual ~NamedPipeStream() noexcept;

	NamedPipeStream &operator=(const NamedPipeStream &stream) noexcept = delete;
	NamedPipeStream &operator=(NamedPipeStream &&stream) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

	virtual void flush() noexcept;

	///
	/// @brief setFileDescriptor
	/// @param fileDescriptor
	/// @param owner
	///
	void setFileDescriptor(os::FileDescriptor fileDescriptor
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
	/// @brief open
	/// @param name
	/// @param deletePipe
	/// @return
	///
	os::Status open(const char *name, bool deletePipe = true) noexcept;

	///
	/// @brief getName
	/// @return
	///
	const templates::String &getName() const noexcept;

private:
	void init();
	void deinit();

	NamedPipeWriter writer; ///<
	NamedPipeReader reader; ///<
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
