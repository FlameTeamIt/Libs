#ifndef HANDLERINTERNALUDPSERVER_HPP
#define HANDLERINTERNALUDPSERVER_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Types.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct ServerMessage: public Message
{
	::flame_ide::os::network::UdpServer::WithClient client;
};
using ServerEndpoint = Endpoint<
	::flame_ide::os::network::UdpServer, ServerMessage
	, Constants::SERVER_INPUT_QUEUE_SIZE, Constants::SERVER_OUTPUT_QUEUE_SIZE
>;

class Server: public ServerEndpoint
{
public:
	inline ServerEndpoint::Optional &server() noexcept
	{
		return this->osEndpoint;
	}

	inline const ServerEndpoint::Optional &server() const noexcept
	{
		return this->osEndpoint;
	}
};

struct ServerCommunicationData
{
	ServerMessage *message;
	Server::ActualOutput *output;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPSERVER_HPP
