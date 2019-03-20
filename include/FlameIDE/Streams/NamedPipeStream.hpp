#ifndef FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP

#include <FlameIDE/Streams/FileStreamReader.hpp>
#include <FlameIDE/Streams/FileStreamWriter.hpp>
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
	/// @brief getFileDescriptor
	/// @param continueOwning
	/// @return
	///
	os::FileDescriptor getFileDescriptor(bool continueOwning = false) noexcept;

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
	void deinit();

	templates::String fname; ///<
	FileStreamWriter writer; ///<
	FileStreamReader reader; ///<
	bool delPipe; ///<
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
