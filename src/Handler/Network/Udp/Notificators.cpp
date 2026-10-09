#include <FlameIDE/../../src/Handler/Network/Udp/Notificators.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

//

ServerNotificator::ServerNotificator(WorkerBase::Notifier notifierInit)
		: notifier{ ::flame_ide::move(notifierInit) }
{}

void ServerNotificator::operator()() noexcept
{
	notifier();
}

//

ClientNotificator::ClientNotificator(WorkerBase::Notifier notifierInit)
		: notifier{ ::flame_ide::move(notifierInit) }
{}

void ClientNotificator::operator()() noexcept
{
	notifier();
}

}}}} // namespace flame_ide::handler::network::udp
