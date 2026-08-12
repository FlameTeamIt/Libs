#ifndef HANDLERNOTIFICATOR_HPP
#define HANDLERNOTIFICATOR_HPP

#include <Generated/Network/Config.hpp>

#include <FlameIDE/Common/ReferenceWrapper.hpp>
#include <FlameIDE/Templates/Array.hpp>

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>
#include <FlameIDE/Os/Threads/ConditionVariable.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

class ServerNotificator:
		public ::flame_ide::os::async::network::UdpServerNotificatorBase
{
public:
	virtual void operator()() const noexcept override;
};

class ClientNotificator:
		public ::flame_ide::os::async::network::UdpClientNotificatorBase
{
public:
	virtual void operator()() const noexcept override;
};

}}}} // namespace flame_ide::handler::network::udp

namespace flame_ide
{namespace handler
{namespace network
{namespace tcp
{

class ServerNotificator:
		public ::flame_ide::os::async::network::TcpServerNotificatorBase
{
public:
	virtual void operator()() const noexcept override;
};

class AcceptedConnectonNotificator:
		public ::flame_ide::os::async::network
				::TcpAcceptedConnectionNotificatorBase
{
public:
	virtual void operator()() const noexcept override;
};

class ClientNotificator:
		public ::flame_ide::os::async::network::TcpClientNotificatorBase
{
public:
	virtual void operator()() const noexcept override;
};

}}}} // namespace flame_ide::handler::network::tcp

#endif // HANDLERNOTIFICATOR_HPP
