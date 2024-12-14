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
using Server = Endpoint<
	::flame_ide::os::network::UdpServer, ServerMessage
	, Constants::SERVER_INPUT_QUEUE_SIZE, Constants::SERVER_OUTPUT_QUEUE_SIZE
>;

struct ServerCommunicationData
{
	ServerMessage *message;
	Server::ActualOutput *output;

	Types::ssize_t bytesToRead() const noexcept;
	Types::ssize_t receive(templates::Range<byte_t *> range) noexcept;
	Types::ssize_t send(templates::Range<const byte_t *> range) noexcept;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPSERVER_HPP
