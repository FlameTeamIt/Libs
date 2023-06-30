#include <FlameIDE/../../src/Os/UdpSocketFunctions.hpp>
#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#define GET_LAST_ERROR \
		-static_cast<flame_ide::os::Status>(::GetLastError())

namespace flame_ide
{namespace os
{namespace socket
{namespace udp
{

Types::ssize_t
send(const Socket &socket, templates::Range<const byte_t *> range) noexcept
{
	const Types::size_t size = range.end() - range.begin();
	const auto buffer = reinterpret_cast<const char *>(range.begin());
	auto address = reinterpret_cast<const SOCKADDR *>(&socket.address);

	auto result = ::sendto(socket.descriptor, buffer, size, 0, address, sizeof(socket.address));
	if (result < 0)
	{
		return GET_LAST_ERROR;
	}
	return result;
}

Types::ssize_t
send(const SocketReceive &socket, ConstByteRange range) noexcept
{
	Socket tmpSocket;
	tmpSocket = socket;
	return send(tmpSocket, range);
}

Types::ssize_t
receiveServer(
		const Socket &socket, ByteRange range, int flags, SocketReceive &socketFrom
) noexcept
{
	const Types::size_t size = range.end() - range.begin();
	auto buffer = reinterpret_cast<char *>(range.begin());
	auto address = reinterpret_cast<SOCKADDR *>(&socketFrom.address);
	int addressLength = sizeof(socketFrom.address);

	auto result = ::recvfrom(socket.descriptor, buffer, size, flags, address, &addressLength);
	if (result < 0)
	{
		return GET_LAST_ERROR;
	}
	socketFrom.descriptor = &socket.descriptor;
	return result;
}

Types::ssize_t
receiveClient(const Socket &socket, ByteRange range, int flags) noexcept
{
	const Types::size_t size = range.end() - range.begin();
	auto buffer = reinterpret_cast<char *>(range.begin());
	auto tmpAddress = socket.address;
	int addressLength = sizeof(tmpAddress);

	auto result = ::recvfrom(
			socket.descriptor
			, buffer, size
			, flags
			, reinterpret_cast<SOCKADDR *>(&tmpAddress), &addressLength
	);
	if (result < 0)
	{
		return GET_LAST_ERROR;
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
	if (result < 0 && result != -WSAEMSGSIZE)
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
	if (result < 0 && result != -WSAEMSGSIZE)
	{
		return result;
	}
	return socket::receivingBytesNumber(socket);
}

}}}} // namespace flame_ide::os::socket::udp
