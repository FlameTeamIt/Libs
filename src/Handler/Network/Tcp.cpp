#include <FlameIDE/../../src/Handler/Network/Functions.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tcp
{

Server *Tcp::push(os::network::TcpServer &&server) noexcept
{
	if (!initPointer(servers, serversSpin))
		return nullptr;

	return pushData(servers, serversSpin
			, /* check = */ [](const Server &i) -> const auto &
			{
				return i.server;
			}
			, /* assignTo = */ [&server](Server &handle)
			{
				handle.server = flame_ide::move(server);
			}
	);
}

os::network::TcpServer Tcp::pop(Server *server) noexcept
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
			, /* returnData = */ [](Server &internal) -> os::network::TcpServer
			{
				os::network::TcpServer server = flame_ide::move(*internal.server);
				return server;
			}
	);
}

Client *Tcp::push(os::network::TcpClient &&/*client*/) noexcept
{
//	if (!initPointer(clients, clientsSpin))
		return nullptr;

//	return assignData(clients, clientsSpin
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

os::network::TcpClient Tcp::pop(Client */*client*/) noexcept
{
//	if (!client)
		return {};
//	if (!isPointer(clients, clientsSpin))
//		return;
//
//	flame_ide::unused(client);
}

}}}} // namespace flame_ide::handler::network::tcp
