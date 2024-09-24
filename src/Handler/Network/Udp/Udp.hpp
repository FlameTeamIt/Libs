#ifndef HANDLERINTERNALUDPUDP_HPP
#define HANDLERINTERNALUDPUDP_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Endpoint.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

class Udp
{
public:
	template<typename OsEndpoint>
	auto *push(OsEndpoint &&osEndpoint) noexcept
	{
		static_assert(
			IsOsEndpoint<OsEndpoint>::VALUE
			, "Input type is not flame_ide::os::network::UdpServer or"
					" flame_ide::os::network::UdpClient"
		);

		using HandlerEndpoint = typename EndpointTypeMapper<OsEndpoint>::Type;
		using HandlerEndpointPointer =
				typename ::flame_ide::DefaultTraits<HandlerEndpoint>::Pointer;
		using HandlerEndpointData = typename HandlerEndpointDataMapper<
			HandlerEndpoint
		>::Type;

		HandlerEndpointData &data = getData<HandlerEndpointData>();
		// Init container if need
		{
			os::threads::Locker lock{ data.spin };
			if (!data.container)
				data.container = decltype(data.container){};
			if (!data.container)
				return HandlerEndpointPointer{ nullptr };
		}

		// Push
		HandlerEndpointPointer handlerEndpointPointer = nullptr;
		{
			os::threads::Locker lock{ data.spin };
			for (auto &i : data.container.reference())
			{
				if (!i->empty())
					continue;

				handlerEndpointPointer = i.pointer();
				break;
			}
			if (handlerEndpointPointer)
				handlerEndpointPointer->attach(flame_ide::move(osEndpoint));
		}
		return handlerEndpointPointer;
	}

	template<typename HandlerEndpoint>
	auto pop(HandlerEndpoint *handlerEndpoint) noexcept
	{
		static_assert(
			IsHandlerEndpoint<HandlerEndpoint>::VALUE
			, "Input type is not flame_ide::handler::udp::Server or"
					" flame_ide::handler::udp::UdpClient"
		);

		using OsEndpoint = typename EndpointTypeMapper<HandlerEndpoint>::Type;
		using HandlerEndpointData = typename HandlerEndpointDataMapper<
			HandlerEndpoint
		>::Type;

		if (!handlerEndpoint || handlerEndpoint->empty())
			return OsEndpoint{};

		HandlerEndpointData &data = getData<HandlerEndpointData>();
		const auto endpointDescriptor = handlerEndpoint->endpoint()->native().descriptor;

		// Pop
		{
			os::threads::Locker lock{ data.spin };
			for (auto &i : data.container.reference())
			{
				if (i->empty())
					continue;

				const auto internalDescriptor = i->endpoint()->native().descriptor;
				if (endpointDescriptor != internalDescriptor)
					continue;

				OsEndpoint osEndpoint = flame_ide::move(i->detach());
				return osEndpoint;
			}
		}
		return OsEndpoint{};
	}

private:
	template<typename T>
	T &getData() noexcept;

private:
	HandlerEndpointUdpData<Servers> servers;
	HandlerEndpointUdpData<Clients> clients;

};

}}}} // namespace flame_ide::handler::network::udp

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

template<> inline
HandlerEndpointUdpData<Servers> &
Udp::getData<HandlerEndpointUdpData<Servers>>() noexcept
{
	return servers;
}

template<> inline
HandlerEndpointUdpData<Clients> &
Udp::getData<HandlerEndpointUdpData<Clients>>() noexcept
{
	return clients;
}

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPUDP_HPP
