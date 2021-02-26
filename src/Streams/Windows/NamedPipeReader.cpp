#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>
#include <FlameIDE/Streams/NamedPipeReader.hpp>

namespace flame_ide
{namespace streams
{

NamedPipeReader::NamedPipeReader() noexcept : Parent()
{}

NamedPipeReader::NamedPipeReader(NamedPipeReader &&reader) noexcept :
		Parent(move(reader))
{}

NamedPipeReader::NamedPipeReader(const char *name) noexcept :
		Parent(makeNamedReader(name).fd, true), fname(name)
{}

NamedPipeReader::~NamedPipeReader() noexcept
{
	auto fd = getFileDescriptor();
	destroyNamedReader(Descriptors::ResultValue{ fd, os::STATUS_SUCCESS });
	setFileDescriptor(os::INVALID_DESCRIPTOR, false);
}

NamedPipeReader &NamedPipeReader::operator=(NamedPipeReader &&reader) noexcept
{
	this->Parent::operator=(move(reader));
	return *this;
}

SizeTraits::SsizeType NamedPipeReader::read(OutputByteRange range) noexcept
{
	auto result = this->FileStreamReader::read(range);
	return result;
}

SizeTraits::SsizeType NamedPipeReader::read(OutputCircularByteRange range) noexcept
{
	auto result = this->FileStreamReader::read(range);
	return result;
}


os::Status NamedPipeReader::open(const char *name) noexcept
{
	setFileDescriptor(os::INVALID_DESCRIPTOR, false);
	os::FileDescriptor fd = makeNamedReader(name).fd;
	if (fd == os::INVALID_DESCRIPTOR)
	{
		return GetLastError();
	}
	setFileDescriptor(fd, true);

	return os::STATUS_SUCCESS;
}

const templates::String &NamedPipeReader::getName() const noexcept
{
	return fname;
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
