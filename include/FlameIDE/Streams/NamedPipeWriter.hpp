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

	NamedPipeWriter() noexcept;
	NamedPipeWriter(const NamedPipeWriter &) = delete;
	NamedPipeWriter(NamedPipeWriter &&writer) noexcept;

	///
	/// @brief NamedPipeWriter
	/// @param name
	/// @param deletePipe
	///
	NamedPipeWriter(const char *name, bool deletePipe = true) noexcept;

	~NamedPipeWriter() noexcept;

	NamedPipeWriter &operator=(const NamedPipeWriter &) = delete;
	NamedPipeWriter &operator=(NamedPipeWriter &&reader) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

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

private:
	FileStreamWriter writer; ///<
	bool delPipe; ///<
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPEWRITER
