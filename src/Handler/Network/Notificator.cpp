#include <FlameIDE/../../src/Handler/Network/Notificator.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

void ServerNotificator::operator()() const noexcept
{}

void ClientNotificator::operator()() const noexcept
{}

}}}} // namespace flame_ide::handler::network::udp

namespace flame_ide
{namespace handler
{namespace network
{namespace tcp
{

void ServerNotificator::operator()() const noexcept
{}

void AcceptedConnectonNotificator::operator()() const noexcept
{}

void ClientNotificator::operator()() const noexcept
{}

}}}} // namespace flame_ide::handler::network::tcp
