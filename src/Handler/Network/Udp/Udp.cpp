#include <FlameIDE/../../src/Handler/Network/Functions.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Udp.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

Server *Udp::push(os::network::UdpServer &&server) noexcept
{
	if (!initPointer(servers, serversSpin))
		return nullptr;

	return pushData(servers, serversSpin
			, /* check = */ [](const Server &i) -> bool
			{
				return (i.server);
			}
			, /* assignTo = */ [&server](Server &handle)
			{
				handle.server = flame_ide::move(server);
			}
	);
}

os::network::UdpServer Udp::pop(Server *server) noexcept
{
	if (!server)
		return {};

	return popData(servers, serversSpin, server
			, /* check = */ [](const Server &input, const Server &internal) -> bool
			{
				if (!(input.server) || !(internal.server))
					return false;

				return input.server->native().descriptor
						== internal.server->native().descriptor;
			}
			, /* returnData = */ [](Server &internal) -> os::network::UdpServer
			{
				os::network::UdpServer server = flame_ide::move(*internal.server);
				return server;
			}
	);
}

Client *Udp::push(os::network::UdpClient &&/*client*/) noexcept
{
//	if (!initPointer(clients, clientsSpin))
		return nullptr;

//	return pushData(clients, clientsSpin
//			, /* check = */ [](const Client &i) -> const auto &
//			{
//				return i.client;
//			}
//			, /* assignTo = */ [&client](Client &handle)
//			{
//				handle.client = flame_ide::move(client);
//			}
//	);
}

os::network::UdpClient Udp::pop(Client *client) noexcept
{
	if (!client)
		return {};

	return {};

//	flame_ide::unused(client);
}

}}}} // namespace flame_ide::handler::network::udp
