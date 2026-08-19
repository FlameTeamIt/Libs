#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

SocketQueues &EventCatcherBase::queues() noexcept
{
	return socketQueues;
}

void EventCatcherBase::setNotificator(UdpServerNotificatorBase &notificator) noexcept
{
	notificationObjects.udpServer
			= decltype(notificationObjects.udpServer){ notificator };
}

void EventCatcherBase::setNotificator(UdpClientNotificatorBase &notificator) noexcept
{
	notificationObjects.udpClient
			= decltype(notificationObjects.udpClient){ notificator };
}

void EventCatcherBase::setNotificator(TcpServerNotificatorBase &notificator) noexcept
{
	notificationObjects.tcpServer
			= decltype(notificationObjects.tcpServer){ notificator };
}

void EventCatcherBase::setNotificator(
		TcpAcceptedConnectionNotificatorBase &notificator
) noexcept
{
	notificationObjects.tcpAcceptedConnection
			= decltype(notificationObjects.tcpAcceptedConnection){ notificator };
}

void EventCatcherBase::setNotificator(TcpClientNotificatorBase &notificator) noexcept
{
	notificationObjects.tcpClient
			= decltype(notificationObjects.tcpClient){ notificator };
}

void EventCatcherBase::unsetNotificator(tag::UdpServer) noexcept
{
	notificationObjects.udpServer = nullptr;
}

void EventCatcherBase::unsetNotificator(tag::UdpClient) noexcept
{
	notificationObjects.udpClient = nullptr;
}

void EventCatcherBase::unsetNotificator(tag::TcpServer) noexcept
{
	notificationObjects.tcpServer = nullptr;
}

void EventCatcherBase::unsetNotificator(tag::TcpAcceptedConnection) noexcept
{
	notificationObjects.tcpAcceptedConnection = nullptr;
}

void EventCatcherBase::unsetNotificator(tag::TcpClient) noexcept
{
	notificationObjects.tcpClient = nullptr;
}

void EventCatcherBase::unsetNotificators() noexcept
{
	unsetNotificator(tag::UdpServer{});
	unsetNotificator(tag::UdpClient{});
	unsetNotificator(tag::TcpServer{});
	unsetNotificator(tag::TcpAcceptedConnection{});
	unsetNotificator(tag::TcpClient{});
}

void EventCatcherBase::notify(tag::UdpServer) const noexcept
{
	if (notificationObjects.udpServer)
		notificationObjects.udpServer.get()();
}

void EventCatcherBase::notify(tag::UdpClient) const noexcept
{
	if (notificationObjects.udpClient)
		notificationObjects.udpClient.get()();
}

void EventCatcherBase::notify(tag::TcpServer) const noexcept
{
	if (notificationObjects.tcpServer)
		notificationObjects.tcpServer.get()();
}

void EventCatcherBase::notify(tag::TcpAcceptedConnection) const noexcept
{
	if (notificationObjects.tcpAcceptedConnection)
		notificationObjects.tcpAcceptedConnection.get()();
}

void EventCatcherBase::notify(tag::TcpClient) const noexcept
{
	if (notificationObjects.tcpClient)
		notificationObjects.tcpClient.get()();
}

}}}} // namespace flame_ide::os::async::network
