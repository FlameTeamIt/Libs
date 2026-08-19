#include <FlameIDE/../../src/Handler/Network/Notificator.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tcp
{

void ServerNotificator::operator()() noexcept
{}

void AcceptedConnectonNotificator::operator()() noexcept
{}

void ClientNotificator::operator()() noexcept
{}

}}}} // namespace flame_ide::handler::network::tcp

namespace flame_ide
{namespace handler
{namespace network
{

Notificators::Notificators(
		WorkerBase::Notifier udpServerNotifier
		, WorkerBase::Notifier udpClientNotifier
) noexcept
		: udpServer{ udpServerNotifier }
		, udpClient{ udpClientNotifier }
{}

}}} // namespace flame_ide::handler::network

