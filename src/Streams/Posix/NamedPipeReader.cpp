#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/Streams/NamedPipeReader.hpp>
#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>

namespace flame_ide
{namespace streams
{

NamedPipeReader::NamedPipeReader() noexcept : Parent()
{}

NamedPipeReader::NamedPipeReader(NamedPipeReader &&reader) noexcept :
		Parent(move(reader))
{}

NamedPipeReader::NamedPipeReader(const char *name) noexcept :
		Parent(makeNamedReader(name).fd)
		, fname(templates::String(os::PIPE_NAME_PREFIX) + name)
{
}

NamedPipeReader::~NamedPipeReader() noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);
}

SizeTraits::SsizeType NamedPipeReader::read(OutputByteRange range) noexcept
{
	return this->FileStreamReader::read(range);
}

SizeTraits::SsizeType NamedPipeReader::read(OutputCircularByteRange range) noexcept
{
	return this->FileStreamReader::read(range);
}

NamedPipeReader &NamedPipeReader::operator=(NamedPipeReader &&reader) noexcept
{
	this->Parent::operator=(move(reader));
	return *this;
}

os::Status NamedPipeReader::open(const char *name) noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);

	os::FileDescriptor fd = makeNamedReader(name).fd;
	if (fd < 0)
	{
		return os::INVALID_DESCRIPTOR;
	}
	this->setFileDescriptor(fd, true);

	return os::STATUS_SUCCESS;
}

const templates::String &NamedPipeReader::getName() const noexcept
{
	return fname;
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
