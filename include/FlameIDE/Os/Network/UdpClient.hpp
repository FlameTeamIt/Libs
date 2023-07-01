#ifndef FLAMEIDE_OS_NETWORK_UDPCLIENT_HPP
#define FLAMEIDE_OS_NETWORK_UDPCLIENT_HPP

#include <FlameIDE/Os/Network/NetworkBase.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class UdpClient final: public NetworkBase
{
public:
	using NetworkBase::ConstRange;
	using NetworkBase::Range;

public:
	UdpClient(UdpClient &&udpClient) noexcept;
	UdpClient(Ipv4 ip) noexcept;

	~UdpClient() noexcept = default;

	UdpClient &operator=(UdpClient &&client) noexcept;

	Types::ssize_t wait() noexcept;
	Types::ssize_t send(NetworkBase::ConstRange range) noexcept;
	Types::ssize_t receive(NetworkBase::Range range) noexcept;

public:
	using NetworkBase::operator bool;
	using NetworkBase::getStatus;

private:
	using NetworkBase::NetworkBase;
	using NetworkBase::operator=;
	using NetworkBase::setStatus;
	using NetworkBase::checkStatus;

private:
	using NetworkBase::socket;
};

}}} // namespace flame_ide::os::network

#endif // FLAMEIDE_OS_NETWORK_UDPCLIENT_HPP
