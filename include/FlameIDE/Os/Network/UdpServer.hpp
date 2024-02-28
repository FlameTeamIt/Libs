#ifndef FLAMEIDE_OS_NETWORK_UDPSERVER_HPP
#define FLAMEIDE_OS_NETWORK_UDPSERVER_HPP

#include <FlameIDE/Os/Network/NetworkBase.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class UdpServer final: public NetworkBase
{
public:
	using NetworkBase::Range;
	using NetworkBase::ConstRange;

public:
	class WithClient;
	struct NativeCallbacks;

public:
	UdpServer(UdpServer &&udpServer) noexcept;
	UdpServer(Ipv4::Port port) noexcept;
	~UdpServer() noexcept = default;

	UdpServer &operator=(UdpServer &&server) noexcept;
	WithClient wait() noexcept;

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

namespace flame_ide
{namespace os
{namespace network
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

	Types::ssize_t getStatus() const noexcept;
	Types::ssize_t receive(UdpServer::Range range) noexcept;
	Types::ssize_t send(UdpServer::ConstRange range) noexcept;

private:
	Types::ssize_t receiveBytesResult;
	SocketReceive socketClient;
	Socket *socketServer;
};

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

struct UdpServer::NativeCallbacks: public NetworkBase::NativeCallbacks
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
	Types::ssize_t (*send)(
			const Socket &socket, ConstRange range
	) noexcept = nullptr;
	Types::ssize_t (*receive)(
			const Socket &socket, Range range, int flags, SocketReceive &socketFrom
	) noexcept = nullptr;
	Types::ssize_t (*wait)(
			const Socket &socket, SocketReceive &socketFrom
	) noexcept = nullptr;
};

}}} // namespace flame_ide::os::network

#endif // FLAMEIDE_OS_NETWORK_UDPSERVER_HPP
