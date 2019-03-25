#include <FlameIDE/Common/Macroses/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/Windows/InternalWinApiFunctions.hpp>
#include <FlameIDE/Streams/NamedPipeWriter.hpp>

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
		Parent(makeNamedPipe(name, os::ActionType::WRITER).writer, true)
		, fname(name)
		, delPipe(deletePipe)
{}

NamedPipeWriter::~NamedPipeWriter() noexcept
{
	if (delPipe)
	{
		this->setFileDescriptor(os::INVALID_DESCRIPTOR, false);
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

	os::FileDescriptor fd = makeNamedPipe(name, os::ActionType::WRITER).writer;
	if (fd < 0)
	{
		return GetLastError();
	}
	this->setFileDescriptor(fd, true);
	delPipe = deletePipe;

	return os::SUCCESS_STATUS;
}

const templates::String &NamedPipeWriter::getName() const noexcept
{
	return fname;
}

}}


#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
