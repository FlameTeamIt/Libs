#ifndef FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
#define FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Common/OsTypes.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The NamedPipeStreamReader class
///
class NamedPipeStreamReader: public stream_utils::AbstractByteStreamReader
{
public:
	using Parent = stream_utils::AbstractByteStreamReader;

	NamedPipeStreamReader() noexcept;
	NamedPipeStreamReader(const char *name) noexcept;
	NamedPipeStreamReader(os::FileDescriptor fileDescriptor) noexcept;
	virtual ~NamedPipeStreamReader() noexcept;

	os::Status open(const char *name) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

private:
	os::Status status;
	os::FileDescriptor fd;
};

///
/// @brief The NamedPipeStreamWriter class
///
class NamedPipeStreamWriter: public stream_utils::AbstractByteStreamWriter
{
public:
	using Parent = stream_utils::AbstractByteStreamWriter;

	NamedPipeStreamWriter();
	NamedPipeStreamWriter(const char *name) noexcept;
	NamedPipeStreamWriter(os::FileDescriptor fileDescriptor) noexcept;
	~NamedPipeStreamWriter() noexcept;

	os::Status open(const char *name) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

private:
	os::Status status;
	os::FileDescriptor fd;
};

///
/// @brief The NamedPipeStream class
///
class NamedPipeStream: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	NamedPipeStream();
	virtual ~NamedPipeStream();

	os::Status open(const char *name) noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

private:
	NamedPipeStreamReader writer;
	NamedPipeStreamReader reader;
};

}}

#endif // FLAMEIDE_STREAMS_NAMEDPIPESTREAM_HPP
