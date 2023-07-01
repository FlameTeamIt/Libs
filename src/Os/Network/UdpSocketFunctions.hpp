#ifndef UDOSOCKETFUNCTIONS_HPP
#define UDOSOCKETFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace udp
{

using ByteRange = templates::Range<byte_t *>;
using ConstByteRange = templates::Range<const byte_t *>;

///
/// @brief Send bytes
/// @param[in] socket Socket
/// @param[in] range Bytes
/// @return Count sent bytes
///
Types::ssize_t send(const Socket &socket, ConstByteRange range) noexcept;

///
/// @brief Receive bytes from server socket
/// @param[in] socket
/// @param[out] range Receiving bytes
/// @param[in] flags
/// @param[out] socketFrom
/// @return Count received bytes
///
Types::ssize_t receiveServer(
		const Socket &socket, ByteRange range, int flags, SocketReceive &socketFrom
) noexcept;

///
/// @brief Receive bytes from client socket
/// @param[in] socket
/// @param[out] range Receiving bytes
/// @param[in] flags
/// @return Count received bytes
///
Types::ssize_t receiveClient(const Socket &socket, ByteRange range, int flags) noexcept;

///
/// @brief Wait message
/// @param[in] socket Server socket
/// @param[out] socketFrom Receive socket
/// @return Count bytes for reading
///
Types::ssize_t waitServer(const Socket &socket, SocketReceive &socketFrom) noexcept;

///
/// @brief Wait message
/// @param[in] socket Client socket
/// @return Count bytes for reading
///
Types::ssize_t waitClient(const Socket &socket) noexcept;

}}}}} // namespace flame_ide::os::network::socket::udp

#endif // UDOSOCKETFUNCTIONS_HPP
