#include <FlameIDE/../../src/Os/TcpSocketFunctions.hpp>
#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <FlameIDE/Os/Constants.hpp>

#define GET_LAST_ERROR \
		-static_cast<flame_ide::os::Status>(::GetLastError())

namespace flame_ide
{namespace os
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
	auto result = ::recv(descriptor, buffer, static_cast<Types::int_t>(size), flags);
	return (result < 0)
			? GET_LAST_ERROR
			: result;
}

} // namesapce anonumous
}}}} // namespace flame_ide::os::socket::tcp

namespace flame_ide
{namespace os
{namespace socket
{namespace tcp
{namespace server
{

Status listen(const Socket &socket, Types::size_t backlog) noexcept
{
	return (::listen(socket.descriptor, static_cast<Types::int_t>(backlog)) < 0)
			? GET_LAST_ERROR
			: os::STATUS_SUCCESS;
}

Socket accept(const Socket &socket, Status *result) noexcept
{
	auto client = os::SOCKET_INITIALIZER;
	int length = sizeof(client.address);
	client.descriptor = ::accept(
			socket.descriptor
			, reinterpret_cast<::SOCKADDR *>(&client.address)
			, &length
	);
	if (result)
	{
		*result = os::STATUS_SUCCESS;
		if (client.descriptor == os::SOCKET_INVALID.descriptor)
		{
			*result = GET_LAST_ERROR;
		}
	}
	return client;
}

}}}}} // namespace flame_ide::os::socket::tcp::server

namespace flame_ide
{namespace os
{namespace socket
{namespace tcp
{namespace client
{

Status connect(const Socket &socket) noexcept
{
	int length = sizeof(socket.address);
	auto result = ::connect(
			socket.descriptor
			, reinterpret_cast<const ::SOCKADDR *>(&socket.address)
			, length
	);
	return (result < 0)
			? GET_LAST_ERROR
			: result;
}

}}}}} // namespace flame_ide::os::socket::tcp::client

namespace flame_ide
{namespace os
{namespace socket
{namespace tcp
{

Types::ssize_t send(const Socket &socket, ConstByteRange range) noexcept
{
	auto buffer = reinterpret_cast<const char *>(range.begin());
	auto size = range.end() - range.begin();
	auto result = ::send(socket.descriptor, buffer, static_cast<Types::int_t>(size), {});
	return (result < 0)
			? GET_LAST_ERROR
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

}}}} // namespace flame_ide::os::socket::tcp
