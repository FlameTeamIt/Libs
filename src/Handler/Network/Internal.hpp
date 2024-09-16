#ifndef HANDLERINTERNAL_HPP
#define HANDLERINTERNAL_HPP

#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/Templates/Pointers.hpp>
#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Udp.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp/Tcp.hpp>
#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

class Handler::Udp
{
public:
	using CallbackGetSessionHandle = Handler::ServerHandle::CallbackGetSessionHandle;

public:
	// TODO
	Handler::ExpectedServerHandle push(os::network::UdpServer &&server) noexcept;
	// TODO
	Handler::ExpectedSessionHandle push(os::network::UdpClient &&client) noexcept;

	// TODO
	Handler::ExpectedUdpServer pop(Handler::ServerHandle &handle);
	// TODO
	Handler::ExpectedUdpClient pop(Handler::SessionHandle &handle);

	/// @brief serverHandleCallback
	/// @return
	// TODO
	CallbackGetSessionHandle serverHandleCallback() const noexcept;

private:
	udp::Udp udp;
};

class Handler::Tcp
{
public:
	using CallbackGetSessionHandle = Handler::ServerHandle::CallbackGetSessionHandle;

public:
	// TODO
	Handler::ExpectedServerHandle push(os::network::TcpServer &&server) noexcept;
	// TODO
	Handler::ExpectedSessionHandle push(os::network::TcpClient &&client) noexcept;

	// TODO
	Handler::ExpectedTcpServer pop(Handler::ServerHandle &handle);
	// TODO
	Handler::ExpectedTcpClient pop(Handler::SessionHandle &handle);

	/// @brief serverHandleCallback
	/// @return
	// TODO
	CallbackGetSessionHandle serverHandleCallback() const noexcept;

private:
	tcp::Tcp tcp;
};

}}} // namespace flame_ide::handler::network

namespace flame_ide
{namespace handler
{namespace network
{

class Handler::Internal
{
public:
	Internal() noexcept;
	~Internal() noexcept;

	/// @brief pushUdp
	/// @param server
	/// @return
	Udp &udp() noexcept;

	/// @brief pushUdp
	/// @param server
	/// @return
	Tcp &tcp() noexcept;

	/// @brief start
	/// @return
	// TODO
	os::Status start() noexcept;

	/// @brief stop
	/// @return
	// TODO
	os::Status stop() noexcept;

private:
	Handler::Udp udpData; ///<
	Handler::Tcp tcpData; ///<
	Workers workers; ///<

	os::async::network::Registrar registration; ///<
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERINTERNAL_HPP
