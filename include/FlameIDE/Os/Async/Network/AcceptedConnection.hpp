#ifndef FLAMEIDE_OS_ASYNC_NETWORK_ACCEPTEDCONNECTION_HPP
#define FLAMEIDE_OS_ASYNC_NETWORK_ACCEPTEDCONNECTION_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

struct AcceptedConnection
{
	constexpr AcceptedConnection() = default;
	constexpr bool operator==(AcceptedConnection connection) const noexcept
	{
		return server == connection.server
			&& client.descriptor == connection.client.descriptor;
	}

	inline operator bool() const noexcept
	{
		return server != os::SOCKET_INVALID.descriptor
				&& client.descriptor != os::SOCKET_INVALID.descriptor;
	}

	os::SocketDescriptor server = os::SOCKET_INVALID.descriptor;
	os::Socket client = os::SOCKET_INVALID;
};

}}}} // namespace flame_ide::os::async::network

#endif // FLAMEIDE_OS_ASYNC_NETWORK_ACCEPTEDCONNECTION_HPP
