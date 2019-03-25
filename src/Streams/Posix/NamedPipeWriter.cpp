#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include "InternalPosixFunctions.hpp"

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
		Parent(makeFifo(name, os::ActionType::WRITER), true)
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

os::Status NamedPipeWriter::open(const char *name, bool deletePipe) noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);

	os::FileDescriptor fd = makeFifo(name, os::ActionType::WRITER);
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

}}


#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
