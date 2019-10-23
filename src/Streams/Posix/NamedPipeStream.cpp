#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Streams/NamedPipeStream.hpp>
#include "FlameIDE/../../src/Streams/CommonFuncitons.hpp"

namespace flame_ide
{namespace streams
{

NamedPipeStream::NamedPipeStream() noexcept = default;

NamedPipeStream::NamedPipeStream(NamedPipeStream &&stream) noexcept :
		writer(move(stream.writer))
		, reader(move(stream.reader))
{}

NamedPipeStream::NamedPipeStream(const char *name, bool deletePipe) noexcept
{
	auto descriptors = makeNamedPipe(name, os::ActionType::BIDIRECTIONAL);

	writer.setFileDescriptor(descriptors.writer.fd, true);
	writer.setName(name, deletePipe);

	reader.setFileDescriptor(descriptors.reader.fd, true);
}

NamedPipeStream::~NamedPipeStream() noexcept
{
	deinit();
}

NamedPipeStream &NamedPipeStream::operator=(NamedPipeStream &&stream) noexcept
{
	deinit();

	writer = move(stream.writer);
	reader = move(stream.reader);

	return *this;
}

SizeTraits::SsizeType NamedPipeStream::read(OutputByteRange range) noexcept
{
	return reader.read(range);
}

SizeTraits::SsizeType NamedPipeStream::read(OutputCircularByteRange range) noexcept
{
	return reader.read(range);
}

SizeTraits::SsizeType NamedPipeStream::write(InputByteRange range) noexcept
{
	return writer.write(range);
}

SizeTraits::SsizeType NamedPipeStream::write(InputCircularByteRange range) noexcept
{
	return writer.write(range);
}

void NamedPipeStream::flush() noexcept
{
	writer.flush();
}

os::FileDescriptor NamedPipeStream::getReaderFileDescriptor(
		bool continueOwning) noexcept
{
	return reader.getFileDescriptor(continueOwning);
}

os::FileDescriptor NamedPipeStream::getWriterFileDescriptor(
		bool continueOwning) noexcept
{
	return writer.getFileDescriptor(continueOwning);
}

os::Status NamedPipeStream::open(const char *name, bool deletePipe) noexcept
{
	deinit();

	auto descriptors = makeNamedPipe(name, os::ActionType::BIDIRECTIONAL);

	writer.setFileDescriptor(descriptors.writer.fd, true);
	writer.setName(name, deletePipe);

	reader.setFileDescriptor(descriptors.reader.fd, true);

	return os::STATUS_SUCCESS;
}

const templates::String &NamedPipeStream::getName() const noexcept
{
	return writer.getName();
}

void NamedPipeStream::deinit()
{
	reader = NamedPipeReader{};
	writer = NamedPipeWriter{};
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
