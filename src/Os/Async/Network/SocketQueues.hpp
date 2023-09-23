#ifndef ASYNC_NETWORK_SOCKETQUEUES_HPP
#define ASYNC_NETWORK_SOCKETQUEUES_HPP

#include <FlameIDE/../../src/Os/Async/Network/QueuedArray.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

class SocketQueues
{
public:
	SocketQueues() noexcept = default;
	~SocketQueues() noexcept = default;

public:
	template<typename Array>
	using Queue = ConcreteQueueArrayByArray<Array>;

	using UdpServers = Queue<UdpServers>;
	using UdpClients = Queue<UdpClients>;
	using TcpAcceptedConnections = Queue<AcceptedConnections>;
	using TcpServers = Queue<TcpServers>;
	using TcpClients = Queue<TcpClients>;

	UdpServers &udpServers() noexcept;
	UdpClients &udpClients() noexcept;
	TcpAcceptedConnections &tcpAcceptedConnections() noexcept;
	TcpServers &tcpServers() noexcept;
	TcpClients &tcpClients() noexcept;

private:
	UdpServers udpServersQueue;
	UdpClients udpClientsQueue;
	TcpAcceptedConnections tcpAcceptedConnectionsQueue;
	TcpServers tcpServersQueue;
	TcpClients tcpClientsQueue;
};

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_SOCKETQUEUES_HPP
