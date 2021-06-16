#ifndef COMMONFUNCTIONS_HPP
#define COMMONFUNCTIONS_HPP

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace os
{

/// @brief
/// @param fd
/// @param data
/// @param size
/// @return
Types::ssize_t read(FileDescriptor fd, byte_t *data, Types::size_t size);

///
/// @brief
/// @param fd
/// @param data
/// @param size
/// @return
///
Types::ssize_t write(FileDescriptor fd, const byte_t *data, Types::size_t size);

}} // namespace flame_ide::os

#endif // COMMONFUNCTIONS_HPP
