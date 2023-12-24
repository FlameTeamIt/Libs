#ifndef HANDLERINTERNAL_HPP
#define HANDLERINTERNAL_HPP

#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/Templates/Pointers.hpp>
#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp.hpp>
#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Handler::Internal
{
public:
	Internal() noexcept;
	~Internal() noexcept;

	Handler::ServerHandle push(os::network::UdpServer &&server) noexcept;
	Handler::CommunicationHandle push(os::network::UdpClient &&client) noexcept;

	Handler::ServerHandle push(os::network::TcpServer &&server) noexcept;
	Handler::CommunicationHandle push(os::network::TcpClient &&client) noexcept;

private:
	Handler::ServerHandle::CallbackGetCommunicationHandle
	getUdpServerHandleCallback() const noexcept;

private:
	udp::Udp udp;
	tcp::Tcp tcp;
	Workers workers;

	os::async::network::Registrar registration;
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERINTERNAL_HPP
