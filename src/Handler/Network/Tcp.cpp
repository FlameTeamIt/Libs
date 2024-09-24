#include <FlameIDE/../../src/Handler/Network/Tcp.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::ExpectedServerHandle Handler::Tcp::push(os::network::TcpServer &&server) noexcept
{
	flame_ide::unused(server);
	return { os::STATUS_FAILED };
}

Handler::ExpectedSessionHandle Handler::Tcp::push(os::network::TcpClient &&client) noexcept
{
	flame_ide::unused(client);
	return { os::STATUS_FAILED };
}

Handler::ExpectedTcpServer Handler::Tcp::pop(Handler::ServerHandle &handle)
{
	flame_ide::unused(handle);
	return { os::STATUS_FAILED };
}

Handler::ExpectedTcpClient Handler::Tcp::pop(Handler::SessionHandle &handle)
{
	flame_ide::unused(handle);
	return { os::STATUS_FAILED };
}

}}} // namespace flame_ide::handler::network
