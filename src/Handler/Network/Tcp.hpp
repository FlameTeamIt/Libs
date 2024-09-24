#ifndef HANDLERINTERNALTCP_HPP
#define HANDLERINTERNALTCP_HPP

#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/../../src/Handler/Network/Tcp/Tcp.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

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

#endif // HANDLERINTERNALTCP_HPP
