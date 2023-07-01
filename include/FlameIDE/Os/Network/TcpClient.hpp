#ifndef FLAMEIDE_OS_NETWORK_TCPCLIENT_HPP
#define FLAMEIDE_OS_NETWORK_TCPCLIENT_HPP

#include <FlameIDE/Os/Network/NetworkBase.hpp>

namespace flame_ide
{namespace os
{namespace network
{

class TcpClient final: public NetworkBase
{
public:
	using NetworkBase::ConstRange;
	using NetworkBase::Range;

public:
	TcpClient() noexcept = delete;
	TcpClient(const TcpClient &) noexcept = delete;

	TcpClient(TcpClient &&client) noexcept;
	TcpClient(Ipv4 ip) noexcept;

	~TcpClient() noexcept = default;

	TcpClient &operator=(const TcpClient &client) noexcept = delete;
	TcpClient &operator=(TcpClient &&client) noexcept;

	Status connect() noexcept;
	Status disconnect() noexcept;
	Status reconnect() noexcept;

	Types::ssize_t numberBytesToRead() const noexcept;

	Types::ssize_t send(ConstRange range) noexcept;
	Types::ssize_t receive(Range range) noexcept;

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

#endif // FLAMEIDE_OS_NETWORK_TCPCLIENT_HPP
