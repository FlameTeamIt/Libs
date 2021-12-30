#ifndef TCPSOCKETFUNCTIONS_HPP
#define TCPSOCKETFUNCTIONS_HPP

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Os/Types.hpp>

#include <errno.h>

namespace flame_ide
{namespace os
{namespace tcp
{

namespace ipv4
{

::flame_ide::os::Socket createSocket(Types::ushort_t port, const char *address) noexcept;

} // namespace ipv4

namespace ipv6
{

::flame_ide::os::Socket createSocket(Types::ushort_t port, const char *address) noexcept;

} // namespace ipv6

void destroySocket(::flame_ide::os::Socket &tcp);

namespace server
{

::flame_ide::os::Status bindSocket(const ::flame_ide::os::Socket &socket) noexcept;

::flame_ide::os::Status listenSocket(::flame_ide::os::Socket &socket,
		Types::ssize_t maxClients = Constants::LISTEN_CLIENTS_COUNT) noexcept;

::flame_ide::os::Socket acceptSocket(const ::flame_ide::os::Socket &server) noexcept;

} // namespace server

namespace client
{

::flame_ide::os::Status connectSocket(const ::flame_ide::os::Socket &socket,
		const ::flame_ide::os::Address &address);

} // namespace client

::flame_ide::Types::ssize_t read(const ::flame_ide::os::Socket &socket
		, byte_t *data, Types::size_t size);

::flame_ide::Types::ssize_t write(const ::flame_ide::os::Socket &socket
		, const byte_t *data, Types::size_t size);

}}} // namespace flame_ide::os::tcp

#endif // TCPSOCKETFUNCTIONS_HPP
