#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <unistd.h>
#include <sys/ioctl.h>

namespace flame_ide
{namespace os
{namespace socket
{
namespace // anonymous
{

SocketDescriptor udpCreateSocket() noexcept
{
	auto descriptor = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	const int reuseAddress = 1;
	auto status = ::setsockopt(descriptor, SOL_SOCKET, SO_REUSEADDR
			, &reuseAddress, sizeof(reuseAddress));
	if (status < 0)
	{
		Socket tmpSocket{ {}, descriptor };
		destroy(tmpSocket);
		return SOCKET_INVALID.descriptor;
	}

	return descriptor;
}

SocketDescriptor tcpCreateSocket() noexcept
{
	auto descriptor = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	const int reuseAddress = 1;
	auto status = ::setsockopt(descriptor, SOL_SOCKET, SO_REUSEADDR
			, &reuseAddress, sizeof(reuseAddress));
	if (status < 0)
	{
		Socket tmpSocket{ {}, descriptor };
		destroy(tmpSocket);
		return SOCKET_INVALID.descriptor;
	}

	return descriptor;
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
	auto socket = Socket{ ipAddressServer(port), udpCreateSocket() };
	if (socket.descriptor == STATUS_FAILED)
	{
		socket = SOCKET_INVALID;
		return socket;
	}

	const auto address = reinterpret_cast<const ::sockaddr *>(&socket.address);
	const auto result = ::bind(socket.descriptor, address, sizeof(socket.address));
	if (result == STATUS_FAILED)
	{
		destroy(socket);
		socket = SOCKET_INVALID;
	}
	return socket;
}

Socket createUdpClient(Ipv4 ipServer) noexcept
{
	auto socket = Socket{ ipAddressClient(ipServer), udpCreateSocket() };
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
		socket = SOCKET_INVALID;
		return socket;
	}

	const auto address = reinterpret_cast<const ::sockaddr *>(&socket.address);
	const auto result = ::bind(socket.descriptor, address, sizeof(socket.address));
	if (result == STATUS_FAILED)
	{
		destroy(socket);
		socket = SOCKET_INVALID;
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

Status destroy(Socket &socket) noexcept
{
	auto status = ::close(socket.descriptor);
	if (status < 0)
	{
		return -errno;
	}
	socket.descriptor = SOCKET_INVALID.descriptor;
	return STATUS_SUCCESS;
}

Types::ssize_t receivingBytesNumber(const Socket &socket) noexcept
{
	int value = 0;
	auto result = ::ioctl(socket.descriptor, FIONREAD, &value);
	if (result < 0)
	{
		return -errno;
	}

	return static_cast<Types::ssize_t>(value);
}

Ipv4 getIpv4(const Socket &socket) noexcept
{
	auto port = ::ntohs(socket.address.sin_port);
	union
	{
		Types::uint_t value;
		Ipv4::Number address[Ipv4::COUNT_NUMBERS];
	} in;
	in.value = socket.address.sin_addr.s_addr;

	return Ipv4{ in.address, port };
}

Types::ssize_t receivingBytesNumber(const SocketDescriptor &socket)
{
	u_long value = 0;
	auto result = ::ioctlsocket(socket, FIONREAD, &value);
	if (result < 0)
	{
		return -static_cast<flame_ide::os::Status>(::GetLastError());
	}
	return static_cast<Types::ssize_t>(value);
}

}}} // namespace flame_ide::os::socket
