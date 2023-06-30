#ifndef FLAMEIDE_OS_UDPSERVER_HPP
#define FLAMEIDE_OS_UDPSERVER_HPP

#include <FlameIDE/Os/NetworkBase.hpp>

// UdpServer

namespace flame_ide
{namespace os
{

class UdpServer final: public NetworkBase
{
public:
	class WithClient;

public:
	using NetworkBase::Range;
	using NetworkBase::ConstRange;

public:
	UdpServer(UdpServer &&udpServer) noexcept;
	UdpServer(Ipv4::Port port) noexcept;
	~UdpServer() noexcept = default;

	UdpServer &operator=(UdpServer &&server) noexcept;
	WithClient wait() noexcept;

public:
	using NetworkBase::operator bool;
	using NetworkBase::getStatus;

private:
	using NetworkBase::NetworkBase;
	using NetworkBase::setStatus;
	using NetworkBase::operator=;

private:
	using NetworkBase::socket;
};

}} // namespace flame_ide::os

// UdpServer::WithClient

namespace flame_ide
{namespace os
{

class UdpServer::WithClient
{
public:
	WithClient() noexcept = default;
	WithClient(const WithClient &) noexcept = default;
	WithClient(Socket &socket, Types::ssize_t result) noexcept;
	~WithClient() noexcept = default;

	WithClient &operator=(const WithClient &) noexcept = default;

	operator bool() const noexcept;

	Status getStatus() const noexcept;
	Types::ssize_t receive(UdpServer::Range range) noexcept;
	Types::ssize_t send(UdpServer::ConstRange range) noexcept;

private:
	Types::ssize_t receiveBytesResult;
	SocketReceive socketClient;
	Socket *socketServer;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_UDPSERVER_HPP
