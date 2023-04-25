#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <unistd.h>

namespace flame_ide
{namespace os
{namespace socket
{
namespace // anonymous
{

SocketDescriptor udpСreateSocket() noexcept
{
	return ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

SocketDescriptor tcpCreateSocket() noexcept
{
	return ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

SocketAddressIn ipAddressServer(Ipv4::Port port) noexcept
{
	SocketAddressIn sockaddr = SOCKET_INITIALIZER.address;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = ::htons(static_cast<Types::ushort_t>(port));
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	return sockaddr;
}

SocketAddressIn ipAddressClient(Ipv4::Address serverAddress) noexcept
{
	SocketAddressIn sockaddr = SOCKET_INITIALIZER.address;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = ::htons(static_cast<Types::ushort_t>(serverAddress.port));
	sockaddr.sin_addr.s_addr = ::inet_addr(serverAddress.ip);
	return sockaddr;
}

} // namespace anonymous
}}} // namespace flame_ide::os::socket

namespace flame_ide
{namespace os
{namespace socket
{

// UDP

Socket createUdpServer(Ipv4::Port port) noexcept
{
	auto socket = Socket{ ipAddressServer(port), udpСreateSocket() };

	const auto address = reinterpret_cast<const ::sockaddr *>(&socket.address);
	const auto result = ::bind(socket.descriptor, address, sizeof(socket.address));
	if (result == STATUS_FAILED)
	{
		socket = Socket{};
	}

	return socket;
}

Socket createUdpClient(Ipv4 ipServer) noexcept
{
	auto socket = Socket{ ipAddressClient(ipServer), udpСreateSocket() };
	if (socket.descriptor == STATUS_FAILED)
	{
		socket = Socket{};
	}
	return socket;

}

// TCP

Socket createTcpServer(Ipv4::Port port) noexcept
{
	auto socket = Socket{ ipAddressServer(port), tcpCreateSocket() };
	if (socket.descriptor == STATUS_FAILED)
	{
		socket = Socket{};
	}
	return socket;
}

Socket createTcpClient(Ipv4 ipServer) noexcept
{
	auto socket = Socket{ ipAddressClient(ipServer), tcpCreateSocket() };
	if (socket.descriptor == STATUS_FAILED)
	{
		socket = Socket{};
	}
	return socket;
}

// Common

void destroy(Socket &socket) noexcept
{
	::close(socket.descriptor);
	socket = SOCKET_INVALID;
}

}}} // namespace flame_ide::os::socket
