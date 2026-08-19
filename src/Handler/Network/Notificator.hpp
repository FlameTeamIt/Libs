#ifndef HANDLERNOTIFICATOR_HPP
#define HANDLERNOTIFICATOR_HPP

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Notificators.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tcp
{

class ServerNotificator:
		public ::flame_ide::os::async::network::TcpServerNotificatorBase
{
public:
	virtual void operator()() noexcept override;
};

class AcceptedConnectonNotificator:
		public ::flame_ide::os::async::network
				::TcpAcceptedConnectionNotificatorBase
{
public:
	virtual void operator()() noexcept override;
};

class ClientNotificator:
		public ::flame_ide::os::async::network::TcpClientNotificatorBase
{
public:
	virtual void operator()() noexcept override;
};

}}}} // namespace flame_ide::handler::network::tcp

namespace flame_ide
{namespace handler
{namespace network
{

struct Notificators
{
	Notificators(
			WorkerBase::Notifier udpServerNotifier
			, WorkerBase::Notifier udpClientNotifier
	) noexcept;

	udp::ServerNotificator udpServer;
	udp::ClientNotificator udpClient;

	tcp::ServerNotificator tcpServer;
	tcp::AcceptedConnectonNotificator tcpAcceptedConnecton;
	tcp::ClientNotificator tcpClient;
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERNOTIFICATOR_HPP
