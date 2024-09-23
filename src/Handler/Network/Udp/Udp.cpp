#include <FlameIDE/../../src/Handler/Network/Functions.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Udp.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

/*

Server *Udp::push(os::network::UdpServer &&server) noexcept
{
	if (!initPointer(servers, serversSpin))
		return nullptr;

	auto check = [](const Server &i) -> bool
	{
		return !i.empty();
	};
	auto assignTo = [&server](Server &handle)
	{
		handle.attach(flame_ide::move(server));
	};

	return pushData(servers, serversSpin, check, assignTo);
}

os::network::UdpServer Udp::pop(Server *server) noexcept
{
	if (!server)
		return {};

	auto check = [](const Server &input, const Server &internal) -> bool
	{
		if (input.empty() || internal.empty())
			return false;

		const auto inputDescriptor = input.server()->native().descriptor;
		const auto internalDescriptor = internal.server()->native().descriptor;
		return (inputDescriptor == internalDescriptor);
	};
	auto returnData = [](Server &internal) -> os::network::UdpServer
	{
		os::network::UdpServer server = flame_ide::move(internal.detach());
		return server;
	};

	return popData(servers, serversSpin, server, check, returnData);
}

Client *Udp::push(os::network::UdpClient &&client) noexcept
{
	if (!initPointer(clients, clientsSpin))
		return nullptr;

	auto check = [](const Client &i) -> bool
	{
		return !i.empty();
	};
	auto assignTo = [&client](Client &handle)
	{
		handle.attach(flame_ide::move(client));
	};

	return pushData(clients, clientsSpin, check, assignTo);
}

os::network::UdpClient Udp::pop(Client *client) noexcept
{
	if (!client)
		return {};

	auto check = [](const Client &input, const Client &internal) -> bool
	{
		if (!(input.client) || !(internal.client))
			return false;

		const auto inputDescriptor = input.client->native().descriptor;
		const auto internalDescriptor = internal.client->native().descriptor;
		return (inputDescriptor == internalDescriptor);
	};
	auto returnData = [](Client &internal) -> os::network::UdpClient
	{
		os::network::UdpClient client = flame_ide::move(*internal.client);
		return client;
	};

	return popData(clients, clientsSpin, client, check, returnData);
}

*/

}}}} // namespace flame_ide::handler::network::udp
