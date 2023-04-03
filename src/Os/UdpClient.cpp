#include <FlameIDE/Os/UdpClient.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/UdpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{

UdpClient::UdpClient(UdpClient &&udpClient) noexcept :
		NetworkBase(move(static_cast<NetworkBase &>(udpClient)))
{}

UdpClient::UdpClient(Ipv4 ip) noexcept : NetworkBase(socket::createUdpClient(ip))
{}

Types::ssize_t UdpClient::wait() noexcept
{
	setStatus(socket::udp::waitClient(socket));
	return checkStatus(getStatus());
}

Types::ssize_t UdpClient::send(ConstRange range) noexcept
{
	setStatus(socket::udp::send(socket, range));
	return checkStatus(getStatus());
}

Types::ssize_t UdpClient::receive(Range range) noexcept
{
	setStatus(socket::udp::receiveClient(socket, range, {}));
	return checkStatus(getStatus());
}

}} // namespace flame_ide::os
