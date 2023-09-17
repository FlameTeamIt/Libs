#include <FlameIDE/Os/Network/UdpClient.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/UdpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{namespace network
{

UdpClient::UdpClient(UdpClient &&udpClient) noexcept :
		NetworkBase(move(static_cast<NetworkBase &&>(udpClient)))
{}

UdpClient::UdpClient(Ipv4 ip) noexcept : NetworkBase(socket::createUdpClient(ip))
{}

UdpClient &UdpClient::operator=(UdpClient &&client) noexcept
{
	operator=(move(static_cast<NetworkBase &&>(client)));
	return *this;
}

Types::ssize_t UdpClient::wait() noexcept
{
	auto result = socket::udp::waitClient(socket);
	if (result < 0)
		setStatus(static_cast<Status>(result));
	return result;
}

Types::ssize_t UdpClient::send(ConstRange range) noexcept
{
	auto result = socket::udp::send(socket, range);
	if (result < 0)
		setStatus(static_cast<Status>(result));
	return result;
}

Types::ssize_t UdpClient::receive(Range range) noexcept
{
	auto result = socket::udp::receiveClient(socket, range, {});
	if (result < 0)
		setStatus(static_cast<Status>(result));
	return result;
}

const UdpClient::NativeClientControl &UdpClient::nativeClientControl() noexcept
{
	static const NativeClientControl control = []()
	{
		NativeClientControl control;
		static_cast<NativeControl &>(control).operator=(nativeControl());
		control.create = socket::createUdpClient;
		control.send = socket::udp::send;
		control.receive = socket::udp::receiveClient;
		control.wait = socket::udp::waitClient;
		return control;
	} ();
	return control;
}

}}} // namespace flame_ide::os::network
