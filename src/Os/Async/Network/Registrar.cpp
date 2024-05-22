#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

#include <FlameIDE/Os/Network/TcpClient.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

Registrar::Registrar() noexcept = default;

Registrar::~Registrar() noexcept = default;

// Registrar::add

os::Status Registrar::add(const os::network::UdpServer &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().udpServers();
	if (!queue)
		queue.init(os::SOCKET_INVALID.descriptor);
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::UdpClient &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().udpClients();
	if (!queue)
		queue.init(os::SOCKET_INVALID.descriptor);
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::TcpServer &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().tcpAcceptedConnections();
	if (!queue)
		queue.init();
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::TcpServer::WithClient &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().tcpServers();
	if (!queue)
		queue.init(os::SOCKET_INVALID.descriptor);
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::TcpClient &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().tcpClients();
	if (!queue)
		queue.init(os::SOCKET_INVALID.descriptor);
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

// Registrar::remove

os::Status Registrar::remove(const os::network::UdpServer &socket) noexcept
{
	return EventCatcherBase::get().disable(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::UdpClient &socket) noexcept
{
	return EventCatcherBase::get().disable(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::TcpServer &socket) noexcept
{
	return EventCatcherBase::get().disable(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::TcpServer::WithClient &socket) noexcept
{
	return EventCatcherBase::get().disable(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::TcpClient &socket) noexcept
{
	return EventCatcherBase::get().disable(socket.native().descriptor);
}

// Registrar::pop*

os::SocketDescriptor Registrar::popUdpServer() noexcept
{
	os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
	EventCatcherBase::get().queues().udpServers().pop(os::SOCKET_INVALID.descriptor)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

os::SocketDescriptor Registrar::popUdpClient() noexcept
{
	os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
	EventCatcherBase::get().queues().udpClients().pop(os::SOCKET_INVALID.descriptor)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

AcceptedConnection Registrar::popTcpServerAcception() noexcept
{
	AcceptedConnection connection;
	EventCatcherBase::get().queues().tcpAcceptedConnections().pop().ifResult(
			[&connection](auto &&actualDescriptor)
			{
				connection = actualDescriptor;
			}
	).done();
	return connection;
}

os::SocketDescriptor Registrar::popTcpServer() noexcept
{
	os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
	EventCatcherBase::get().queues().tcpServers().pop(os::SOCKET_INVALID.descriptor)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

os::SocketDescriptor Registrar::popTcpClient() noexcept
{
	os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
	EventCatcherBase::get().queues().tcpClients().pop(os::SOCKET_INVALID.descriptor)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

// Registrar::push*

bool Registrar::pushUdpServer(os::SocketDescriptor socket) noexcept
{
	return EventCatcherBase::get().queues().udpServers().push(socket);
}

bool Registrar::pushUdpClient(os::SocketDescriptor socket) noexcept
{
	return EventCatcherBase::get().queues().udpClients().push(socket);
}

bool Registrar::pushTcpServerAcception(AcceptedConnection connection) noexcept
{
	return EventCatcherBase::get().queues().tcpAcceptedConnections().push(connection);
}

bool Registrar::pushTcpServer(os::SocketDescriptor socket) noexcept
{
	return EventCatcherBase::get().queues().tcpServers().push(socket);
}

bool Registrar::pushTcpClient(os::SocketDescriptor socket) noexcept
{
	return EventCatcherBase::get().queues().tcpClients().push(socket);
}

// notificator

void Registrar::setNotificator(const NotificatorBase &notificator) noexcept
{
	EventCatcherBase::get().setNotificator(notificator);
}

void Registrar::unsetNotificator() noexcept
{
	EventCatcherBase::get().unsetNotificator();
}

// other

void Registrar::clear() noexcept
{
	while (popUdpServer() != os::SOCKET_INVALID.descriptor);
	while (popUdpClient() != os::SOCKET_INVALID.descriptor);
	while (popTcpServerAcception());
	while (popTcpServer() != os::SOCKET_INVALID.descriptor);
	while (popTcpClient() != os::SOCKET_INVALID.descriptor);
}

}}}} // namespace flame_ide::os::async::network
