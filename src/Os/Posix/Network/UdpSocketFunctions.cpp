#include <FlameIDE/../../src/Os/Network/UdpSocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>

#include <fcntl.h>
#include <sys/ioctl.h>

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace udp
{

Types::ssize_t
send(const Socket &socket, ConstByteRange range) noexcept
{
	const Types::size_t size = range.end() - range.begin();
	const auto buffer = reinterpret_cast<const char *>(range.begin());
	auto address = reinterpret_cast<const ::sockaddr *>(&socket.address);

	auto result = ::sendto(
			socket.descriptor, buffer, size, 0, address
			, sizeof(socket.address)
	);
	if (result < 0)
	{
		return -errno;
	}
	return result;
}

Types::ssize_t receiveServer(
		const Socket &socket, ByteRange range, int flags, SocketReceive &socketFrom
) noexcept
{
	const Types::size_t size = range.end() - range.begin();
	auto buffer = reinterpret_cast<void *>(range.begin());
	auto address = reinterpret_cast<::sockaddr *>(&socketFrom.address);
	unsigned addressLength = sizeof(socketFrom.address);

	auto result = ::recvfrom(
			socket.descriptor
			, buffer, size
			, flags
			, address, &addressLength
	);
	if (result < 0)
	{
		return -errno;
	}
	socketFrom.descriptor = &socket.descriptor;
	return result;
}

Types::ssize_t receiveClient(const Socket &socket, ByteRange range, int flags) noexcept
{
	const Types::size_t size = range.end() - range.begin();
	auto buffer = reinterpret_cast<void *>(range.begin());
	auto tmpAddress = socket.address;
	unsigned addressLength = sizeof(tmpAddress);

	auto result = ::recvfrom(
			socket.descriptor
			, buffer, size
			, flags
			, reinterpret_cast<::sockaddr *>(&tmpAddress), &addressLength
	);
	if (result < 0)
	{
		return -errno;
	}
	return result;
}

Types::ssize_t waitServer(const Socket &socket, SocketReceive &socketFrom) noexcept
{
	auto byte = byte_t{};
	auto result = receiveServer(
			socket
			, templates::makeRange(&byte, &byte + 1)
			, MSG_PEEK
			, socketFrom
	);
	if (result < 0 && result != -EMSGSIZE)
	{
		return result;
	}
	return socket::receivingBytesNumber(socket);
}

Types::ssize_t waitClient(const Socket &socket) noexcept
{
	auto byte = byte_t{};
	auto result = receiveClient(
			socket
			, templates::makeRange(&byte, &byte + 1)
			, MSG_PEEK
	);
	if (result < 0 && result != -EMSGSIZE)
	{
		return result;
	}
	return socket::receivingBytesNumber(socket);
}

}}}}} // namespace flame_ide::os::network::socket::udp
