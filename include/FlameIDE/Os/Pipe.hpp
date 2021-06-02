#ifndef FLAMEIDE_OS_PIPE_HPP
#define FLAMEIDE_OS_PIPE_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{

class Pipe
{
public:
	Pipe() noexcept;
	Pipe(const Pipe &pipe) noexcept = delete;
	Pipe(Pipe &&pipe) noexcept;

	~Pipe() noexcept;

	Pipe &operator=(const Pipe &pipe) noexcept = delete;
	Pipe &operator=(Pipe &&pipe) noexcept;

	os::FileDescriptor getReader() const noexcept;
	os::FileDescriptor getWriter() const noexcept;

private:
	static constexpr Types::size_t COUNT_PIPES = 2;
	os::FileDescriptor descriptors[COUNT_PIPES];
	os::Status creationStatus = os::STATUS_SUCCESS;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_PIPE_HPP
