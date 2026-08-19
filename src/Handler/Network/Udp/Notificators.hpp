#ifndef HANDLER_INTERNAL_UDP_NOTIFICATORS_HPP
#define HANDLER_INTERNAL_UDP_NOTIFICATORS_HPP

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>

#include <FlameIDE/../../src/Handler/Network/WorkerBase.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

///
/// \brief The ServerNotificator class
///
class ServerNotificator:
		public ::flame_ide::os::async::network::UdpServerNotificatorBase
{
public:
	ServerNotificator(WorkerBase::Notifier notifierInit);
	virtual void operator()() noexcept override;

private:
	WorkerBase::Notifier notifier;
};

///
/// \brief The ClientNotificator class
///
class ClientNotificator:
		public ::flame_ide::os::async::network::UdpClientNotificatorBase
{
public:
	ClientNotificator(WorkerBase::Notifier notifierInit);
	virtual void operator()() noexcept override;

private:
	WorkerBase::Notifier notifier;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_NOTIFICATORS_HPP
