#ifndef HANDLER_INTERNAL_UDP_PROCESSING_HPP
#define HANDLER_INTERNAL_UDP_PROCESSING_HPP

#include <FlameIDE/Common/FunctorBase.hpp>
#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/ContainerTypes.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

// Base class for processing clients and servers

template<typename Container>
class EndpointProcessor: public flame_ide::FunctorBase<
	Container, HandlerEndpointUdpData<Container> &, os::async::network::AsyncEvent
>
{
public:
	virtual bool operator()(
			HandlerEndpointUdpData<Container> &storage
			, os::async::network::AsyncEvent event
	) noexcept = 0;
};

//

class ServerProcessor:
		public flame_ide::FunctorBase<
			bool, HandlerEndpointUdpData<Servers> &, os::async::network::AsyncEvent
		>
{
public:
	virtual bool operator()(
			HandlerEndpointUdpData<Servers> &storage, os::async::network::AsyncEvent event
	) noexcept override;

private:
	static bool checkEndpoint(
			const ::flame_ide::templates::UniquePointer<Server> &endpoint
			, os::SocketDescriptor descriptor
	);
};

//

class ClientProcessor:
		public flame_ide::FunctorBase<
			bool, HandlerEndpointUdpData<Clients> &, os::async::network::AsyncEvent
		>
{
public:
	virtual bool operator()(
			HandlerEndpointUdpData<Clients> &storage, os::async::network::AsyncEvent event
	) noexcept override;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_PROCESSING_HPP
