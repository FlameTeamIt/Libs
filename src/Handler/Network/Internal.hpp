#ifndef HANDLERINTERNAL_HPP
#define HANDLERINTERNAL_HPP

#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/Templates/Pointers.hpp>
#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Handler/Network/Notificator.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp.hpp>
#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

namespace flame_ide
{namespace handler
{namespace network
{
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

	/// @brief udp
	/// @return
	Udp &udp() noexcept;

	/// @brief tcp
	/// @return
	Tcp &tcp() noexcept;

	/// @brief registrar
	/// @return
	os::async::network::Registrar &registrar() noexcept;

	/// @brief start
	/// @return
	os::Status start() noexcept;

	/// @brief stop
	/// @return
	os::Status stop() noexcept;

private:
	Handler::Udp udpData; ///<
	Handler::Tcp tcpData; ///<
	Workers workers; ///<

	struct
	{
		udp::ServerNotificator udpServerNotificator;
		udp::ClientNotificator udpClientNotificator;

		tcp::ServerNotificator tcpServerNotificator;
		tcp::AcceptedConnectonNotificator tcpAcceptedConnectonNotificator;
		tcp::ClientNotificator tcpClientNotificator;
	} notificators; ///<

	os::async::network::Registrar registration; ///<
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERINTERNAL_HPP
