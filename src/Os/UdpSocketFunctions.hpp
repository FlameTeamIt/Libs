#ifndef UDOSOCKETFUNCTIONS_HPP
#define UDOSOCKETFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace socket
{namespace udp
{

using ByteRange = templates::Range<byte_t *>;
using ConstByteRange = templates::Range<const byte_t *>;

Types::ssize_t send(const Socket &socket, ConstByteRange range) noexcept;

Types::ssize_t receiveServer(
		const Socket &socket, ByteRange range, int flags, SocketReceive &socketFrom
) noexcept;

Types::ssize_t receiveClient(const Socket &socket, ByteRange range, int flags) noexcept;

Types::ssize_t waitServer(const Socket &socket, SocketReceive &socketFrom) noexcept;

Types::ssize_t waitClient(const Socket &socket) noexcept;

}}}} // namespace flame_ide::os::socket::udp

#endif // UDOSOCKETFUNCTIONS_HPP
