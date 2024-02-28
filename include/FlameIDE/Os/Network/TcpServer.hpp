#ifndef FLAMEIDE_OS_NETWORK_TCPSERVER_HPP
#define FLAMEIDE_OS_NETWORK_TCPSERVER_HPP

#include <FlameIDE/Os/Network/NetworkBase.hpp>

// TcpServer

namespace flame_ide
{namespace os
{namespace network
{

class TcpServer final: public NetworkBase
{
public:
	using NetworkBase::ConstRange;
	using NetworkBase::Range;

public:
	class WithClient;
	struct NativeCallbacks;

public:
	TcpServer() noexcept = delete;
	TcpServer(const TcpServer &tcpServer) noexcept = delete;

	TcpServer(TcpServer &&tcpServer) noexcept;
	TcpServer(Ipv4::Port port) noexcept;
	~TcpServer() noexcept = default;

	TcpServer &operator=(const TcpServer &tcpServer) = delete;
	TcpServer &operator=(TcpServer &&tcpServer) noexcept;

	WithClient accept() const noexcept;

public:
	static const NativeCallbacks &callbacks() noexcept;

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

}}} // namespace flame_ide::os::network

// TcpServer::WithClient
namespace flame_ide
{namespace os
{namespace network
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
	const Socket &native() const noexcept;

	Types::ssize_t send(TcpServer::ConstRange range) noexcept;
	Types::ssize_t receive(TcpServer::Range range) noexcept;

private:
	Socket socket;
	Status status;
};

}}} // namespace flame_ide::os::network

// TcpServer::NativeCallbacks
namespace flame_ide
{namespace os
{namespace network
{

struct TcpServer::NativeCallbacks: public NetworkBase::NativeCallbacks
{
	NativeCallbacks() noexcept = default;
	NativeCallbacks(const NativeCallbacks &) noexcept = default;
	NativeCallbacks(NativeCallbacks &&) noexcept = default;
	~NativeCallbacks() noexcept = default;

	using NetworkBase::NativeCallbacks::operator=;
	NativeCallbacks &
	operator=(const NativeCallbacks &) noexcept = default;
	NativeCallbacks &
	operator=(NativeCallbacks &&) noexcept = default;

	Socket (*create)(Ipv4::Port port) noexcept = nullptr;
	Status (*listen)(const Socket &socket, Types::size_t backlog) noexcept;
	Socket (*accept)(const Socket &socket, Status *result) noexcept;
	Types::ssize_t (*send)(const Socket &socket, ConstRange range) noexcept;
	Types::ssize_t (*receive)(const Socket &socket, Range range) noexcept;
	Types::ssize_t (*waitBytes)(const Socket &socket, Types::size_t number) noexcept;
	bool (*alive)(const Socket &socket) noexcept;
};


}}} // namespace flame_ide::os::network

#endif // FLAMEIDE_OS_NETWORK_TCPSERVER_HPP
