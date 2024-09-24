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

	os::async::network::Registrar registration; ///<
};

}}} // namespace flame_ide::handler::network

#endif // HANDLERINTERNAL_HPP
