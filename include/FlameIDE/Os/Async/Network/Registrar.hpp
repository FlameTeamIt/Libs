#ifndef FLAMEIDE_OS_ASYNC_NETWORK_REGISTRAR_HPP
#define FLAMEIDE_OS_ASYNC_NETWORK_REGISTRAR_HPP

#include <FlameIDE/Os/Async/Network/AcceptedConnection.hpp>
#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class UdpServer;
class UdpClient;
// class TcpServer; // included
class TcpClient;

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

enum class EventType: Types::int_t
{
	INVALID = -1
	, INIT = 0
	, READ
	, WRITE
	, READ_WRITE
	, CLOSE
};


struct SocketsInfo
{
	struct Info
	{
		Types::size_t udpServers;
		Types::size_t udpClients;

		Types::size_t tcpServers;
		Types::size_t tcpClients;
	};

	const Info max;
	const Info current;
};

struct AsyncEvent
{
	os::SocketDescriptor descriptor = os::SOCKET_INVALID.descriptor;
	EventType event = EventType::INVALID;
};
bool operator==(const AsyncEvent &ae1, const AsyncEvent &ae2) noexcept;
bool operator!=(const AsyncEvent &ae1, const AsyncEvent &ae2) noexcept;

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
	SocketsInfo getInfo() const noexcept;

public:
	os::Status add(const os::network::UdpServer &socket) noexcept;
	os::Status add(const os::network::UdpClient &socket) noexcept;
	os::Status add(const os::network::TcpServer &socket) noexcept;
	os::Status add(const os::network::TcpServer::WithClient &socket) noexcept;
	os::Status add(const os::network::TcpClient &socket) noexcept;

	os::Status remove(const os::network::UdpServer &socket) noexcept;
	os::Status remove(const os::network::UdpClient &socket) noexcept;
	os::Status remove(const os::network::TcpServer &socket) noexcept;
	os::Status remove(const os::network::TcpServer::WithClient &socket) noexcept;
	os::Status remove(const os::network::TcpClient &socket) noexcept;

	AsyncEvent popUdpServer() noexcept;
	AsyncEvent popUdpClient() noexcept;
	AcceptedConnection popTcpServerAcception() noexcept;
	AsyncEvent popTcpServer() noexcept;
	AsyncEvent popTcpClient() noexcept;

	void setNotificator(UdpServerNotificatorBase &notificator) noexcept;
	void setNotificator(UdpClientNotificatorBase &notificator) noexcept;
	void setNotificator(TcpServerNotificatorBase &notificator) noexcept;
	void setNotificator(TcpAcceptedConnectionNotificatorBase &notificator) noexcept;
	void setNotificator(TcpClientNotificatorBase &notificator) noexcept;

	void unsetNotificators() noexcept;

	void clear() noexcept;
};

}}}} // namespace flame_ide::os::async::network

#endif // FLAMEIDE_OS_ASYNC_NETWORK_REGISTRAR_HPP
