#include <FlameIDE/Os/Pipe.hpp>

#include <FlameIDE/../../src/Os/PipeFunctions.hpp>
#include <FlameIDE/../../src/Os/CommonFunctions.hpp>

#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace os
{

Pipe::Pipe() noexcept
{
	auto expectPipes = createPipes();
	expectPipes.ifResult(
			[this](PipeDescriptors &&descriptors)
			{
				pair = descriptors.pair;
			}
	).ifError(
			[this](Status &&status)
			{
				creationStatus = status;
			}
	).done();
}

Pipe::Pipe(Pipe &&pipe) noexcept
{
	operator=(move(pipe));
}

Pipe::~Pipe() noexcept
{
	if (pair.descriptors[0] != INVALID_DESCRIPTOR && pair.descriptors[1] != INVALID_DESCRIPTOR)
	{

		destroyPipes(*reinterpret_cast<PipeDescriptors*>(pair.descriptors));
	}
}

Pipe &Pipe::operator=(Pipe &&pipe) noexcept
{
	pair = pipe.pair;
	pipe.pair = DESCRIPTOR_PAIR_INITIALIZER;

	return *this;
}

const DescriptorPair &Pipe::native() const noexcept
{
	return pair;
}

Types::ssize_t read(const Pipe &pipe, byte_t *data, Types::size_t size)
{
	FileDescriptor readFd = pipe.native().descriptors[
			static_cast<int>(ActionType::READER)
	];
	return read(readFd, data, size);
}

Types::ssize_t write(const Pipe &pipe, const byte_t *data, Types::size_t size)
{
	FileDescriptor writeFd = pipe.native().descriptors[
			static_cast<int>(ActionType::WRITER)
	];
	return write(writeFd, data, size);
}

}} // namespace flame_ide::os
