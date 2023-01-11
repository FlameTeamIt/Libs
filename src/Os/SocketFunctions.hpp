#ifndef SOCKETFUNCTIONS_HPP
#define SOCKETFUNCTIONS_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Ipv4.hpp>

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace socket
{

Socket udpCreateServerSocket(Ipv4::Port port) noexcept;

Socket udpCreateClientSocket(const Ipv4& ip) noexcept;

void destroySocket(Socket &socket);

Types::ssize_t
udpSend(const Socket &socket, templates::Range<const byte_t *> range);

Types::ssize_t
udpReceive(const Socket &socket, templates::Range<byte_t *> range, SocketReceive &socketFrom);

}}} // namespace flame_ide::os::socket

#endif // SOCKETFUNCTIONS_HPP
