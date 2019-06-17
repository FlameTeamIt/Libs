#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include "../CommonFuncitons.hpp"

#include <FlameIDE/Streams/NamedPipeWriter.hpp>

#include <unistd.h>

namespace flame_ide
{namespace streams
{

NamedPipeWriter::NamedPipeWriter() noexcept : Parent()
{}

NamedPipeWriter::NamedPipeWriter(NamedPipeWriter &&writer) noexcept :
		Parent(move(writer)), delPipe(writer.delPipe)
{
	writer.delPipe = false;
}

NamedPipeWriter::NamedPipeWriter(const char *name, bool deletePipe) noexcept :
		Parent(makeNamedWriter(name).fd, true)
		, fname(name)
		, delPipe(deletePipe)
{}

NamedPipeWriter::~NamedPipeWriter() noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);
	if (delPipe)
	{
		remove(fname.data());
	}
}

NamedPipeWriter &NamedPipeWriter::operator=(NamedPipeWriter &&writer) noexcept
{
	this->Parent::operator=(move(writer));

	delPipe = writer.delPipe;
	writer.delPipe = false;

	return *this;
}

SizeTraits::SsizeType NamedPipeWriter::write(InputByteRange range) noexcept
{
	return this->FileStreamWriter::write(range);
}

SizeTraits::SsizeType NamedPipeWriter::write(InputCircularByteRange range) noexcept
{
	return this->FileStreamWriter::write(range);
}

os::Status NamedPipeWriter::open(const char *name, bool deletePipe) noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);

	os::FileDescriptor fd = makeNamedWriter(name).fd;
	if (fd < 0)
	{
		return os::INVALID_DESCRIPTOR;
	}
	this->setFileDescriptor(fd, true);
	delPipe = deletePipe;

	return os::STATUS_SUCCESS;
}

const templates::String &NamedPipeWriter::getName() const noexcept
{
	return fname;
}

void NamedPipeWriter::setName(const templates::String &name, bool deletePipe)
{
	fname = name;
	delPipe = deletePipe;
}

}}


#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
