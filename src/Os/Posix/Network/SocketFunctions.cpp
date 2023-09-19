#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{
namespace // anonymous
{

SocketDescriptor udpCreateSocket() noexcept
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

template<typename Option>
int getSocketOption(const os::Socket &socket, int option, Option &optionValue)
{
	socklen_t length = sizeof(option);
	auto result = ::getsockopt(
			socket.descriptor, SOL_SOCKET, option, &optionValue, &length
	);
	if (result < 0)
		return -errno;
	return os::STATUS_SUCCESS;
}

} // namespace anonymous
}}}} // namespace flame_ide::os::network::socket

namespace flame_ide
{namespace os
{namespace network
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

	const int reuseAddress = 1;
	auto status = ::setsockopt(socket.descriptor, SOL_SOCKET, SO_REUSEADDR
			, &reuseAddress, sizeof(reuseAddress));
	if (status < 0)
	{
		destroy(socket);
		return SOCKET_INVALID;
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

	const int reuseAddress = 1;
	auto status = ::setsockopt(socket.descriptor, SOL_SOCKET, SO_REUSEADDR
			, &reuseAddress, sizeof(reuseAddress));
	if (status < 0)
	{
		destroy(socket);
		return SOCKET_INVALID;
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

int getType(const Socket &socket) noexcept
{
	int type = 0;
	auto result = getSocketOption(socket, SO_TYPE, type);
	if (result < 0)
		return -1;
	return type;
}

int getError(const Socket &socket) noexcept
{
	int error = 0;
	auto result = getSocketOption<int>(socket, SO_ERROR, error);
	if (result < 0)
		return -1;
	return error;
}

bool isAcceptor(const Socket &socket) noexcept
{
	int isAcceptor = 0;
	auto result = getSocketOption<int>(socket, SO_ACCEPTCONN, isAcceptor);
	if (result < 0)
		return false;
	return isAcceptor;
}

bool isServer(const Socket &socket) noexcept
{
	int isServer = 0;
	auto result = getSocketOption<int>(socket, SO_REUSEADDR, isServer);
	if (result < 0)
		return false;
	return isServer;
}

int enableNonblock(const Socket &socket)
{
	int flags = ::fcntl(socket.descriptor, F_GETFL);
	auto result = ::fcntl(socket.descriptor, F_SETFL, flags | O_NONBLOCK);
	if (result < 0)
		return -errno;
	return os::STATUS_SUCCESS;
}

int disableNonblock(const Socket &socket)
{
	int flags = ::fcntl(socket.descriptor, F_GETFL);
	auto result = ::fcntl(socket.descriptor, F_SETFL, flags & (~O_NONBLOCK));
	if (result < 0)
		return -errno;
	return os::STATUS_SUCCESS;
}

}}}} // namespace flame_ide::os::network::socket
