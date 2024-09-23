#include <FlameIDE/../../src/Handler/Network/Internal.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp/InternalData.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/InternalData.hpp>

#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

// Hanler::Udp

Handler::ExpectedServerHandle Handler::Udp::push(os::network::UdpServer &&server) noexcept
{
	flame_ide::unused(server);

	udp::Server *udpServer = udp.push(move(server));
	flame_ide::unused(udpServer);
	return { os::STATUS_FAILED };
}

Handler::ExpectedSessionHandle Handler::Udp::push(os::network::UdpClient &&client) noexcept
{
	flame_ide::unused(client);

	udp::Client *udpClient = udp.push(move(client));
	flame_ide::unused(udpClient);
	return { os::STATUS_FAILED };
}

Handler::ExpectedUdpServer Handler::Udp::pop(Handler::ServerHandle &handle)
{
	flame_ide::unused(handle);
	return { os::STATUS_FAILED };
}

Handler::ExpectedUdpClient Handler::Udp::pop(Handler::SessionHandle &handle)
{
	flame_ide::unused(handle);
	return { os::STATUS_FAILED };
}

// Handler::Tcp

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

// Handler::Internal implementation
namespace flame_ide
{namespace handler
{namespace network
{

Handler::Internal::Internal() noexcept
{}

Handler::Internal::~Internal() = default;

Handler::Udp &Handler::Internal::udp() noexcept
{
	return udpData;
}

Handler::Tcp &Handler::Internal::tcp() noexcept
{
	return tcpData;
}

os::async::network::Registrar &Handler::Internal::registrar() noexcept
{
	return registration;
}

os::Status Handler::Internal::start() noexcept
{
	return workers.start();
}

os::Status Handler::Internal::stop() noexcept
{
	return workers.stop();
}

}}} // namespace flame_ide::os::network
