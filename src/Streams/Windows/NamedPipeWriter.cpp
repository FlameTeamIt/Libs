#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Streams/CommonFuncitons.hpp>
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
		Parent(makeNamedWriter(name).fd, true), fname(name), delPipe(deletePipe)
{}

NamedPipeWriter::~NamedPipeWriter() noexcept
{
	if (delPipe)
	{
		auto fd = getFileDescriptor();
		destroyNamedWriter(Descriptors::ResultValue{ fd, os::STATUS_SUCCESS });
		setFileDescriptor(os::INVALID_DESCRIPTOR, false);
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
	auto result = this->FileStreamWriter::write(range);
	return result;
}

SizeTraits::SsizeType NamedPipeWriter::write(InputCircularByteRange range) noexcept
{
	auto result = this->FileStreamWriter::write(range);
	return result;
}

os::Status NamedPipeWriter::open(const char *name, bool deletePipe) noexcept
{
	setFileDescriptor(os::INVALID_DESCRIPTOR, false);

	os::FileDescriptor fd = makeNamedWriter(name).fd;
	if (fd < 0)
	{
		return GetLastError();
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


#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS
