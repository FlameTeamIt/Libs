#ifndef FLAMEIDE_OS_ASYNC_NETWORK_REGISTRAR_HPP
#define FLAMEIDE_OS_ASYNC_NETWORK_REGISTRAR_HPP

#include <FlameIDE/Os/Async/Network/AcceptedConnection.hpp>
#include <FlameIDE/Templates/Variant.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class UdpServer;
class UdpClient;
class TcpServer;
class TcpClient;

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

struct Config
{
	struct Info
	{
		Types::size_t udpServers;
		Types::size_t udpClients;

		Types::size_t tcpServers;
		Types::size_t tcpClients;
	};

	Info max;
	Info current;
};

class Registrar
{
public:
	Registrar() noexcept;
	Registrar(const Registrar &) noexcept = default;
	Registrar(Registrar &&) noexcept = default;
	~Registrar() noexcept;

	Registrar &operator=(const Registrar &) noexcept = default;
	Registrar &operator=(Registrar &&) noexcept = default;

public:
	const Config &getConfig() const noexcept;

public:
	os::Status add(const os::network::UdpServer &socket) noexcept;
	os::Status add(const os::network::UdpClient &socket) noexcept;
	os::Status add(const os::network::TcpServer &socket) noexcept;
	os::Status add(const os::network::TcpClient &socket) noexcept;

	os::Status remove(const os::network::UdpServer &socket) noexcept;
	os::Status remove(const os::network::UdpClient &socket) noexcept;
	os::Status remove(const os::network::TcpServer &socket) noexcept;
	os::Status remove(const os::network::TcpClient &socket) noexcept;

	os::SocketDescriptor popUdpServer() noexcept;
	os::SocketDescriptor popUdpClient() noexcept;
	AcceptedConnection popTcpServer() noexcept;
	os::SocketDescriptor popTcpClient() noexcept;
};

}}}} // namespace flame_ide::os::async::network

#endif // FLAMEIDE_OS_ASYNC_NETWORK_REGISTRAR_HPP
