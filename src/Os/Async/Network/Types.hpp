#ifndef ASYNC_NETWORK_TYPES_HPP
#define ASYNC_NETWORK_TYPES_HPP

#include <Generated/Network/Config.hpp>

#include <FlameIDE/Os/Async/Network/AcceptedConnection.hpp>
#include <FlameIDE/Os/Async/Network/Registrar.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

static constexpr Types::size_t FACTOR = 4;

template<Types::size_t SIZE>
using Events = templates::StaticArray<AsyncEvent, SIZE>;

using UdpServers = Events<generated::network::Config::UDP_SERVERS * FACTOR>;
using UdpClients = Events<generated::network::Config::UDP_CLIENTS * FACTOR>;
using TcpServers = Events<
	generated::network::Config::TCP_SERVERS
			* generated::network::Config::TCP_SERVER_BACKLOG
			* FACTOR
>;
using TcpClients = Events<generated::network::Config::TCP_CLIENTS * FACTOR>;

using AcceptedConnections = templates::StaticArray<
	AcceptedConnection, generated::network::Config::TCP_SERVER_BACKLOG * FACTOR
>;

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_TYPES_HPP
