#include <FlameIDE/../../src/Os/Network/TcpSocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

#define RETURN_RESULT(condition, result) \
{ \
	result = condition; \
	if (result != os::STATUS_SUCCESS) \
	{ \
		result = -errno; \
	} \
}

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{
namespace // anonumous
{

Types::ssize_t receive(
		const SocketDescriptor &descriptor, ByteRange range, int flags
) noexcept
{
	auto buffer = reinterpret_cast<char *>(range.begin());
	auto size = range.end() - range.begin();
	auto result = ::recv(descriptor, buffer, size, flags);
	return (result < 0)
			? -errno
			: result;
}

} // namesapce anonumous
}}}}} // namespace flame_ide::os::network::socket::tcp


namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{namespace server
{

Status listen(const Socket &socket, Types::size_t backlog) noexcept
{
	return (::listen(socket.descriptor, backlog) < 0)
			? -errno
			: os::STATUS_SUCCESS;
}

Socket accept(const Socket &socket, Status *result) noexcept
{
	auto client = os::SOCKET_INITIALIZER;
	socklen_t length = sizeof(client.address);
	client.descriptor = ::accept(
			socket.descriptor
			, reinterpret_cast<::sockaddr *>(&client.address)
			, &length
	);
	if (result)
	{
		*result = os::STATUS_SUCCESS;
		if (client.descriptor == os::SOCKET_INVALID.descriptor)
		{
			*result = -errno;
		}
	}
	return client;
}

}}}}}} // namespace flame_ide::os::network::socket::tcp::server

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{namespace client
{

Status connect(const Socket &socket) noexcept
{
	socklen_t length = sizeof(socket.address);
	auto result = ::connect(
			socket.descriptor
			, reinterpret_cast<const ::sockaddr *>(&socket.address)
			, length
	);
	return (result < 0)
			? -errno
			: result;
}

}}}}}} // namespace flame_ide::os::network::socket::tcp::client

namespace flame_ide
{namespace os
{namespace network
{namespace socket
{namespace tcp
{

Types::ssize_t send(const Socket &socket, ConstByteRange range) noexcept
{
	auto buffer = reinterpret_cast<const void *>(range.begin());
	auto size = range.end() - range.begin();
	auto result = ::send(socket.descriptor, buffer, size, {});
	return (result < 0)
			? -errno
			: result;
}

Types::ssize_t receive(const Socket &socket, ByteRange range) noexcept
{
	return receive(socket.descriptor, range, {});
}

Types::ssize_t waitBytes(const Socket &socket, Types::size_t number) noexcept
{
	Types::ssize_t result = 0;
	while (static_cast<Types::size_t>(result) != number)
	{
		result = socket::receivingBytesNumber(socket);
		if (result < 0)
		{
			break;
		}
	}
	return result;
}

}}}}} // namespace flame_ide::os::network::socket::tcp
