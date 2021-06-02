#include <FlameIDE/Os/Pipe.hpp>

#include <FlameIDE/../../src/Os/PipeFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Common/Constants.hpp>

namespace flame_ide
{namespace os
{

Pipe::Pipe() noexcept
{
	creationStatus = createPipes(*reinterpret_cast<PipeDescriptors*>(descriptors));
}

Pipe::Pipe(Pipe &&pipe) noexcept
{
	operator=(move(pipe));
}

Pipe::~Pipe() noexcept
{
	if (descriptors[0] != INVALID_DESCRIPTOR && descriptors[1] != INVALID_DESCRIPTOR)
	{
		destroyPipes(*reinterpret_cast<PipeDescriptors*>(descriptors));
	}
}

Pipe &Pipe::operator=(Pipe &&pipe) noexcept
{
	descriptors[0] = pipe.descriptors[0];
	descriptors[1] = pipe.descriptors[1];

	pipe.descriptors[0] = -1;
	pipe.descriptors[1] = -1;

	return *this;
}

os::FileDescriptor Pipe::getReader() const noexcept
{
	return descriptors[static_cast<int>(ActionType::READER)];
}

os::FileDescriptor Pipe::getWriter() const noexcept
{
	return descriptors[static_cast<int>(ActionType::WRITER)];
}

}} // namespace flame_ide::os
