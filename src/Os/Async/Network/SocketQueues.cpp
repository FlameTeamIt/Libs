#include <FlameIDE/../../src/Os/Async/Network/SocketQueues.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

SocketQueues::UdpServers &SocketQueues::udpServers() noexcept
{
	return udpServersQueue;
}

SocketQueues::UdpClients &SocketQueues::udpClients() noexcept
{
	return udpClientsQueue;
}

SocketQueues::TcpAcceptedConnections &SocketQueues::tcpAcceptedConnections() noexcept
{
	return tcpAcceptedConnectionsQueue;
}

SocketQueues::TcpServers &SocketQueues::tcpServers() noexcept
{
	return tcpServersQueue;
}

SocketQueues::TcpClients &SocketQueues::tcpClients() noexcept
{
	return tcpClientsQueue;
}

}}}} // namespace flame_ide::os::async::network

