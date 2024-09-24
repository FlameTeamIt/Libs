#include <FlameIDE/Os/Network/UdpServer.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/UdpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{namespace network
{

UdpServer::UdpServer(UdpServer &&udpServer) noexcept :
		NetworkBase(move(static_cast<NetworkBase &&>(udpServer)))
{}

UdpServer::UdpServer(Ipv4::Port port) noexcept : NetworkBase(socket::createUdpServer(port))
{}

UdpServer &UdpServer::operator=(UdpServer &&server) noexcept
{
	operator=(move(static_cast<NetworkBase &&>(server)));
	return *this;
}

UdpServer::WithClient UdpServer::wait() noexcept
{
	SocketReceive socketReceive;
	Types::ssize_t result = socket::udp::waitServer(socket, socketReceive);
	WithClient sendler{ socket, result };
	return sendler;
}

const UdpServer::NativeCallbacks &UdpServer::callbacks() noexcept
{
	static const NativeCallbacks nativeCallbacks = []()
	{
		NativeCallbacks callbacks;
		callbacks = NetworkBase::callbacks();
		callbacks.create = socket::createUdpServer;
		callbacks.send = socket::udp::send;
		callbacks.receive = socket::udp::receiveServer;
		callbacks.wait = socket::udp::waitServer;
		return callbacks;
	} ();
	return nativeCallbacks;
}

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

UdpServer::WithClient::WithClient(Socket &socket, Types::ssize_t result) noexcept :
		receiveBytesResult(result)
		, socketServer(&socket)
{}

UdpServer::WithClient::operator bool() const noexcept
{
	return getStatus() >= 0;
}

Types::ssize_t UdpServer::WithClient::getStatus() const noexcept
{
	return receiveBytesResult;
}

Types::ssize_t UdpServer::WithClient::receive(NetworkBase::Range range) noexcept
{
	receiveBytesResult = socket::udp::receiveServer(
			*socketServer, range, {}, socketClient
	);
	return getStatus();
}

Types::ssize_t UdpServer::WithClient::send(NetworkBase::ConstRange range) noexcept
{
	receiveBytesResult = socket::udp::send(socketClient, range);
	return getStatus();
}

}}} // namespace flame_ide::os::network
