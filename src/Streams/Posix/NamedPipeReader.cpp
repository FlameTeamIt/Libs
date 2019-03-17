#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include "InternalPosixFunctions.hpp"

#include <FlameIDE/Streams/NamedPipeReader.hpp>

#include <unistd.h>

namespace flame_ide
{namespace streams
{

NamedPipeReader::NamedPipeReader() noexcept : Parent()
{}

NamedPipeReader::NamedPipeReader(NamedPipeReader &&reader) noexcept :
		Parent(move(reader)), delPipe(reader.delPipe)
{
	reader.delPipe = false;
}

NamedPipeReader::NamedPipeReader(const char *name, bool deletePipe) noexcept :
		Parent(makeFifo(name, os::ActionType::READER), true)
		, string(name)
		, delPipe(deletePipe)
{}

NamedPipeReader::~NamedPipeReader() noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);
	if (delPipe)
	{
		unlink(string.data());
	}
}

NamedPipeReader &NamedPipeReader::operator=(NamedPipeReader &&reader) noexcept
{
	this->Parent::operator=(move(reader));

	delPipe = reader.delPipe;
	reader.delPipe = false;

	return *this;
}

os::Status NamedPipeReader::open(const char *name, bool deletePipe) noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);

	os::FileDescriptor fd = makeFifo(name, os::ActionType::READER);
	if (fd < 0)
	{
		return os::INVALID_DESCRIPTOR;
	}
	this->setFileDescriptor(fd, true);
	delPipe = deletePipe;

	return os::SUCCESS_STATUS;
}


}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
