#include <FlameIDE/../../src/Handler/Network/Udp/Processing.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

bool ServerProcessor::operator()(
		HandlerEndpointUdpData<Servers> &storage, os::async::network::AsyncEvent event
) noexcept
{
	::flame_ide::ReferenceWrapper<Server> endpointData{ nullptr };
	{
		::flame_ide::os::threads::Locker lock{ storage.spin };
		for (templates::UniquePointer<Server> &pointer : *storage.container)
		{
			if (!checkEndpoint(pointer, event.descriptor))
				continue;

			endpointData = decltype(endpointData){ pointer.pointer() };
		}
	}
	if (!endpointData)
		return false;

	switch (event.event)
	{
		case decltype(event.event)::INVALID:
		{
			return false;
		}

		case decltype(event.event)::READ:
		{
			os::network::UdpServer &endpoint = *endpointData->endpoint();

			// Message in processing state
			::flame_ide::ReferenceWrapper<ServerMessage> message
					= endpointData->input().getEmptyMessage();
			if (message)
				return false;
			return message->fill(endpoint);
		}

		case decltype(event.event)::WRITE:
		{
			return false;
		}

		case decltype(event.event)::READ_WRITE:
		{
			return false;
		}

		default:
			return false;
	}
}

bool ServerProcessor::checkEndpoint(
		const ::flame_ide::templates::UniquePointer<Server> &endpoint
		, os::SocketDescriptor descriptor
)
{
	if (!endpoint || endpoint->empty())
		return false;

	if (endpoint->endpoint()->native().descriptor != descriptor)
		return false;

	return true;
}

//

bool ClientProcessor::operator()(
		HandlerEndpointUdpData<Clients> &storage, os::async::network::AsyncEvent event
) noexcept
{
	flame_ide::unused(storage, event);
	return false;
}

}}}} // namespace flame_ide::handler::network::udp
