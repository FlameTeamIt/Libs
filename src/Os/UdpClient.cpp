#include <FlameIDE/Os/UdpClient.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/UdpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{

UdpClient::UdpClient(UdpClient &&udpClient) noexcept : NetworkBase(move(static_cast<NetworkBase &>(udpClient)))
{}

UdpClient::UdpClient(Ipv4 ip) noexcept : NetworkBase(socket::createUdpClient(ip))
{}

Types::ssize_t UdpClient::wait() noexcept
{
	return socket::udp::waitClient(socket);
}

Types::ssize_t UdpClient::send(ConstRange range) noexcept
{
	return socket::udp::send(socket, range);
}

Types::ssize_t UdpClient::receive(Range range) noexcept
{
	return socket::udp::receiveClient(socket, range, {});
}

}} // namespace flame_ide::os
