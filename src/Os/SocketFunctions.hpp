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

// UDP

Socket createUdpServer(Ipv4::Port port) noexcept;

Socket createUdpClient(Ipv4 ipServer) noexcept;

// TCP

Socket createTcpServer(Ipv4::Port port) noexcept;

Socket createTcpClient(Ipv4 ipServer) noexcept;

// Common

void destroy(Socket &socket) noexcept;

}}} // namespace flame_ide::os::socket

#endif // SOCKETFUNCTIONS_HPP
