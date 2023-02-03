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
	UdpServer() noexcept = delete;
	UdpServer(UdpServer &&udpServer) noexcept;
	UdpServer(Ipv4::Port port) noexcept;
	~UdpServer() noexcept = default;

	WithClient wait();

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
	WithClient(const SocketReceive &socket, Types::ssize_t result) noexcept;
	~WithClient() noexcept = default;

	WithClient &operator=(const WithClient &) noexcept = default;

	operator bool() const noexcept;

	Types::ssize_t bytes() const noexcept;
	Types::ssize_t receive(NetworkBase::Range range) noexcept;
	Types::ssize_t send(NetworkBase::ConstRange range) noexcept;

private:
	Types::ssize_t receiveBytesResult;
	SocketReceive socket;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_UDPSERVER_HPP
