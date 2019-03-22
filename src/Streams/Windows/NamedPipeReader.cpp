#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/Windows/InternalWinApiFunctions.hpp>
#include <FlameIDE/Streams/NamedPipeReader.hpp>

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
		Parent(makeNamedPipe(name, os::ActionType::READER), true)
		, fname(name)
		, delPipe(deletePipe)
{}

NamedPipeReader::~NamedPipeReader() noexcept
{
	this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);
	if (delPipe)
	{
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

	os::FileDescriptor fd = makeNamedPipe(name, os::ActionType::READER);
	if (fd == os::INVALID_DESCRIPTOR)
	{
		return GetLastError();
	}
	this->setFileDescriptor(fd, true);
	delPipe = deletePipe;

	return os::SUCCESS_STATUS;
}

const templates::String &NamedPipeReader::getName() const noexcept
{
	return fname;
}

}}

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
