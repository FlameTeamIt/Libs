#include <FlameIDE/Common/Macros.hpp>
#include <FlameIDE/Os/Constants.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/TcpSocketFunctions.hpp>

#include <arpa/inet.h>
#include <unistd.h>

namespace flame_ide
{namespace os
{namespace tcp
{

namespace
{

struct AddressInfo
{
	AddressInfo(const Address &address) :
			address {
					address.isIpv4
							? reinterpret_cast<const ::sockaddr *>(&address.ipv4)
							: reinterpret_cast<const ::sockaddr *>(&address.ipv6)
			}
			, length {
					address.isIpv4
							? sizeof(address.ipv4)
							: sizeof(address.ipv6)
			}
	{}
	const ::sockaddr *address;
	const Types::size_t length;
};

}

namespace ipv4
{

::flame_ide::os::Socket createSocket(Types::ushort_t port, const char *address) noexcept
{
	::flame_ide::os::Socket socket = SOCKET_IPV4_INITIALIZER;

	socket.fd = ::socket(AF_INET, SOCK_STREAM, 0);
	socket.address.ipv4.sin_port = htons(port);
	inet_aton(address, &socket.address.ipv4.sin_addr);
	return socket;
}

} // namespace ipv4

namespace ipv6
{

::flame_ide::os::Socket createSocket(Types::ushort_t port, const char *address) noexcept
{
	::flame_ide::os::Socket socket = SOCKET_IPV6_INITIALIZER;
	socket.fd = ::socket(AF_INET6, SOCK_STREAM, 0);
	socket.address.ipv6.sin6_port = htons(port);
	inet_pton(AF_INET6, address, &socket.address.ipv6.sin6_addr);
	return socket;
}

} // namespace ipv6

void destroySocket(::flame_ide::os::Socket &socket)
{
	if (socket.fd != INVALID_DESCRIPTOR)
	{
		::close(socket.fd);
		socket = ::flame_ide::os::Socket{};
	}
}

namespace server
{

Status bindSocket(const ::flame_ide::os::Socket &socket) noexcept
{
	AddressInfo info{ socket.address };
	return bind(socket.fd, info.address, info.length);
}

Status listenSocket(::flame_ide::os::Socket &socket, Types::ssize_t maxClients) noexcept
{
	return listen(socket.fd, maxClients);
}

::flame_ide::os::Socket acceptSocket(const ::flame_ide::os::Socket &server) noexcept
{
	::flame_ide::os::Socket client = [&server]() {
		return (server.address.isIpv4)
				? SOCKET_IPV4_INITIALIZER
				: SOCKET_IPV6_INITIALIZER;
	}();

	sockaddr *address = [&client]() {
		return (client.address.isIpv4)
				? reinterpret_cast<sockaddr *>(&client.address.ipv4)
				: reinterpret_cast<sockaddr *>(&client.address.ipv6);
	}();

	::socklen_t addressLength = 0;
	client.fd = ::accept(server.fd, address, &addressLength);
	return client;
}

} // namespace server

namespace client
{

::flame_ide::os::Status connectSocket(const ::flame_ide::os::Socket &socket,
		const ::flame_ide::os::Address &address)
{
	AddressInfo info{ address };
	if (connect(socket.fd, info.address, info.length))
	{
		return -errno;
	}
	return 0;
}

} // namespace client

::flame_ide::Types::ssize_t read(const ::flame_ide::os::Socket &socket
		, byte_t *data, Types::size_t size)
{
	return recv(socket.fd, data, size, {});
}

::flame_ide::Types::ssize_t write(const ::flame_ide::os::Socket &socket
		, const byte_t *data, Types::size_t size)
{
	return send(socket.fd, data, size, {});
}

}}} // namespace flame_ide::os::tcp

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
