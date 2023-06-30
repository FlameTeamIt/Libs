#ifndef FLAMEIDE_OS_TCPSERVER_HPP
#define FLAMEIDE_OS_TCPSERVER_HPP

#include <FlameIDE/Os/NetworkBase.hpp>

// TcpServer

namespace flame_ide
{namespace os
{

class TcpServer final: public NetworkBase
{
public:
	class WithClient;

public:
	using NetworkBase::ConstRange;
	using NetworkBase::Range;

public:
	TcpServer() noexcept = delete;
	TcpServer(const TcpServer &tcpServer) noexcept = delete;

	TcpServer(TcpServer &&tcpServer) noexcept;
	TcpServer(Ipv4::Port port, Types::size_t backlog) noexcept;
	~TcpServer() noexcept = default;

	TcpServer &operator=(const TcpServer &tcpServer) = delete;

	TcpServer &operator=(TcpServer &&tcpServer) noexcept;

	WithClient accept() const noexcept;

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

// TcpServer::WithClient

namespace flame_ide
{namespace os
{

class TcpServer::WithClient
{
public:
	WithClient() noexcept = delete;
	WithClient(const WithClient &client) noexcept = delete;

	WithClient(WithClient &&client) noexcept;
	WithClient(Socket socket, Status result) noexcept;
	~WithClient() noexcept;

	WithClient &operator=(const WithClient &client) noexcept = delete;

	WithClient &operator=(WithClient &&client) noexcept;

	Types::ssize_t numberBytesToRead() const noexcept;

	Status getStatus() const noexcept;
	Types::ssize_t send(TcpServer::ConstRange range) noexcept;
	Types::ssize_t receive(TcpServer::Range range) noexcept;

private:
	Socket socket;
	Status status;
};

}} // namespace flame_ide::os
#endif // FLAMEIDE_OS_TCPSERVER_HPP
