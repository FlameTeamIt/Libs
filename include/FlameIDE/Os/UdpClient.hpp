#ifndef FLAMEIDE_OS_UDPCLIENT_HPP
#define FLAMEIDE_OS_UDPCLIENT_HPP

#include <FlameIDE/Os/NetworkBase.hpp>

namespace flame_ide
{namespace os
{

class UdpClient final: public NetworkBase
{
public:
	UdpClient(UdpClient &&udpClient) noexcept;
	UdpClient(Ipv4 ip) noexcept;

	~UdpClient() noexcept = default;

	Types::ssize_t wait() noexcept;
	Types::ssize_t send(NetworkBase::ConstRange range) noexcept;
	Types::ssize_t receive(NetworkBase::Range range) noexcept;

private:
	using NetworkBase::socket;
};

}} // namespace flame_ide::os

#endif // FLAMEIDE_OS_UDPCLIENT_HPP
