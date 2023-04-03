#include <FlameIDE/Os/UdpServer.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/UdpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{

UdpServer::UdpServer(UdpServer &&udpServer) noexcept :
		NetworkBase(move(static_cast<NetworkBase &&>(udpServer)))
{}

UdpServer::UdpServer(Ipv4::Port port) noexcept : NetworkBase(socket::createUdpServer(port))
{}

UdpServer &UdpServer::operator=(UdpServer &&server) noexcept
{
	NetworkBase &&base = static_cast<NetworkBase &&>(server);
	operator=(move(base));
	return *this;
}

UdpServer::WithClient UdpServer::wait() noexcept
{
	SocketReceive socketReceive;
	Types::ssize_t result = socket::udp::waitServer(socket, socketReceive);
	WithClient sendler{ socketReceive, result };
	return sendler;
}

}} // namespace flame_ide::os

namespace flame_ide
{namespace os
{

UdpServer::WithClient::WithClient(const SocketReceive &socket, Types::ssize_t result) noexcept :
		receiveBytesResult(result)
		, socket(socket)
{}

UdpServer::WithClient::operator bool() const noexcept
{
	return getStatus() >= 0;
}

Status UdpServer::WithClient::getStatus() const noexcept
{
	return receiveBytesResult;
}

Types::ssize_t UdpServer::WithClient::receive(NetworkBase::Range range) noexcept
{
	SocketReceive receiveSocket;
	receiveBytesResult = socket::udp::receiveServer(socket, range, {}, receiveSocket);
	if (getStatus() < 0)
	{
		return STATUS_FAILED;
	}
	return getStatus();
}

Types::ssize_t UdpServer::WithClient::send(NetworkBase::ConstRange range) noexcept
{
	receiveBytesResult = socket::udp::send(socket, range);
	if (getStatus() < 0)
	{
		return STATUS_FAILED;
	}
	return getStatus();
}

}} // namespace flame_ide::os
