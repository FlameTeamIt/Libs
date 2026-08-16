#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

#include <FlameIDE/Os/Network/TcpClient.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>

#include <Generated/Network/Config.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{
namespace anonymous { namespace {

static constexpr auto ASYNC_EVENT_INIT_VALUE = AsyncEvent{};

}} // namespace anonymous
}}}} // namespace flame_ide::os::async::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

bool operator==(const AsyncEvent &ae1, const AsyncEvent &ae2) noexcept
{
	return ((ae1.descriptor == ae2.descriptor) && (ae1.event == ae2.event));
}

bool operator!=(const AsyncEvent &ae1, const AsyncEvent &ae2) noexcept
{
	return !(ae1 == ae2);
}

}}}} // namespace flame_ide::os::async::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

Registrar::Registrar() noexcept = default;

Registrar::~Registrar() noexcept = default;

SocketsInfo Registrar::getInfo() const noexcept
{
	static constexpr SocketsInfo::Info MAX_INFO = SocketsInfo::Info {
			generated::network::Config::UDP_SERVERS
			, generated::network::Config::UDP_CLIENTS
			, generated::network::Config::TCP_SERVERS
			, generated::network::Config::TCP_CLIENTS
	};

	auto &queues = EventCatcherBase::get().queues();
	SocketsInfo config = { MAX_INFO, SocketsInfo::Info {
			queues.udpServers().getSize(), queues.udpClients().getSize()
			, queues.tcpServers().getSize(), queues.tcpClients().getSize()
	} };
	return config;
}

// Registrar::add

os::Status Registrar::add(const os::network::UdpServer &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().udpServers();
	if (!queue)
		queue.init(anonymous::ASYNC_EVENT_INIT_VALUE);
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::UdpClient &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().udpClients();
	if (!queue)
		queue.init(anonymous::ASYNC_EVENT_INIT_VALUE);
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
		queue.init(anonymous::ASYNC_EVENT_INIT_VALUE);
	return EventCatcherBase::get().enable(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::TcpClient &socket) noexcept
{
	auto &queue = EventCatcherBase::get().queues().tcpClients();
	if (!queue)
		queue.init(anonymous::ASYNC_EVENT_INIT_VALUE);
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

AsyncEvent Registrar::popUdpServer() noexcept
{
	AsyncEvent descriptor = anonymous::ASYNC_EVENT_INIT_VALUE;
	EventCatcherBase::get().queues().udpServers().pop(anonymous::ASYNC_EVENT_INIT_VALUE)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

AsyncEvent Registrar::popUdpClient() noexcept
{
	AsyncEvent descriptor = anonymous::ASYNC_EVENT_INIT_VALUE;
	EventCatcherBase::get().queues().udpClients().pop(anonymous::ASYNC_EVENT_INIT_VALUE)
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

AsyncEvent Registrar::popTcpServer() noexcept
{
	AsyncEvent descriptor = anonymous::ASYNC_EVENT_INIT_VALUE;
	EventCatcherBase::get().queues().tcpServers().pop(anonymous::ASYNC_EVENT_INIT_VALUE)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

AsyncEvent Registrar::popTcpClient() noexcept
{
	AsyncEvent descriptor = anonymous::ASYNC_EVENT_INIT_VALUE;
	EventCatcherBase::get().queues().tcpClients().pop(anonymous::ASYNC_EVENT_INIT_VALUE)
			.ifResult([&descriptor](auto &&actualDescriptor)
					{
						descriptor = actualDescriptor;
					}
			).done();
	return descriptor;
}

// notificator

void Registrar::setNotificator(const UdpServerNotificatorBase &notificator) noexcept
{
	EventCatcherBase::get().setNotificator(notificator);
}
void Registrar::setNotificator(const UdpClientNotificatorBase &notificator) noexcept
{
	EventCatcherBase::get().setNotificator(notificator);
}
void Registrar::setNotificator(const TcpServerNotificatorBase &notificator) noexcept
{
	EventCatcherBase::get().setNotificator(notificator);
}
void Registrar::setNotificator(const TcpAcceptedConnectionNotificatorBase &notificator) noexcept
{
	EventCatcherBase::get().setNotificator(notificator);
}
void Registrar::setNotificator(const TcpClientNotificatorBase &notificator) noexcept
{
	EventCatcherBase::get().setNotificator(notificator);
}

void Registrar::unsetNotificators() noexcept
{
	EventCatcherBase::get().unsetNotificators();
}

// other

void Registrar::clear() noexcept
{
	while (popUdpServer() != anonymous::ASYNC_EVENT_INIT_VALUE);
	while (popUdpClient() != anonymous::ASYNC_EVENT_INIT_VALUE);
	while (popTcpServerAcception());
	while (popTcpServer() != anonymous::ASYNC_EVENT_INIT_VALUE);
	while (popTcpClient() != anonymous::ASYNC_EVENT_INIT_VALUE);
}

}}}} // namespace flame_ide::os::async::network
