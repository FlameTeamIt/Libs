#ifndef SOCKETFUNCTIONS_HPP
#define SOCKETFUNCTIONS_HPP

#include <FlameIDE/Os/Network/Ipv4.hpp>
#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{

// UDP

Socket createUdpServer(Ipv4::Port port) noexcept;

Socket createUdpClient(Ipv4 ipServer) noexcept;

// TCP

Socket createTcpServer(Ipv4::Port port) noexcept;

Socket createTcpClient(Ipv4 ipServer) noexcept;

// Common

Status destroy(Socket &socket) noexcept;

Types::ssize_t receivingBytesNumber(const Socket &socket) noexcept;

Ipv4 getIpv4(const Socket &socket) noexcept;

}}}} // namespace flame_ide::os::network::socket

#endif // SOCKETFUNCTIONS_HPP
