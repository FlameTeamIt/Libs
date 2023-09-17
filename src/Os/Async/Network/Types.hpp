#ifndef ASYNC_NETWORK_TYPES_HPP
#define ASYNC_NETWORK_TYPES_HPP

#include <Generated/Network/Config.hpp>

#include <FlameIDE/Os/Async/Network/AcceptedConnection.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

static constexpr Types::size_t FACTOR = 4;

template<Types::size_t SIZE>
using Descriptors = templates::StaticArray<os::SocketDescriptor, SIZE>;

template<Types::size_t SIZE>
using DescriptorsUniquePointer = templates::UniquePointer<Descriptors<SIZE>>;

using UdpServers = os::async::network::DescriptorsUniquePointer<
	generated::network::Config::UDP_SERVERS * FACTOR
>;
using UdpClients = os::async::network::DescriptorsUniquePointer<
	generated::network::Config::UDP_CLIENTS * FACTOR
>;
using TcpServers = os::async::network::DescriptorsUniquePointer<
	generated::network::Config::TCP_SERVERS * os::SOCKET_TCP_MAX_CLIENTS * FACTOR
>;
using TcpClients = os::async::network::DescriptorsUniquePointer<
	generated::network::Config::TCP_CLIENTS * FACTOR
>;

using AcceptedConnectionsArray = templates::StaticArray<
	AcceptedConnection, os::SOCKET_TCP_MAX_CLIENTS * FACTOR
>;
using AcceptedConnections = templates::UniquePointer<AcceptedConnectionsArray>;

template<typename Iterator>
struct Queue
{
	Iterator first;
	Iterator last;
	threads::Spin spin;
	Types::size_t count = 0;
};

using DescriptorIterator = templates::defaults::CircularForwardIterator<
	os::SocketDescriptor *
>;

using AcceptedConnectionInterator = templates::defaults::CircularForwardIterator<
	AcceptedConnection *
>;

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_TYPES_HPP
