#ifndef FLAMEIDE_OS_PIPE_HPP
#define FLAMEIDE_OS_PIPE_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Common/Byte.hpp>

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

	Status getCreationStatus() const noexcept;

	const DescriptorPair &native() const noexcept;

	DescriptorPair detachNative() noexcept;

private:
	DescriptorPair pair;
	Status creationStatus = os::STATUS_SUCCESS;
};

/// @brief read
/// @param pipe
/// @param data
/// @param size
/// @return
Types::ssize_t read(const Pipe &pipe, byte_t *data, Types::size_t size);

/// @brief write
/// @param pipe
/// @param data
/// @param size
/// @return
Types::ssize_t write(const Pipe &pipe, const byte_t *data, Types::size_t size);

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_PIPE_HPP
