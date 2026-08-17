#ifndef HANDLER_INTERNAL_UDPSERVER_HPP
#define HANDLER_INTERNAL_UDPSERVER_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Endpoint.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct ServerMessage: public Message
{
	void fill(flame_ide::os::network::UdpServer &endpoint) noexcept;

	::flame_ide::os::network::UdpServer::WithClient client;
};

class Server: public Endpoint<
	::flame_ide::os::network::UdpServer, ServerMessage
	, Constants::SERVER_INPUT_QUEUE_SIZE, Constants::SERVER_OUTPUT_QUEUE_SIZE
>
{};

struct ServerCommunicationData
{
	::flame_ide::ReferenceWrapper<ServerMessage> message;
	::flame_ide::ReferenceWrapper<Server::ActualOutput> output;

	Types::ssize_t bytesToRead() const noexcept;
	Types::ssize_t receive(templates::Range<byte_t *> range) noexcept;
	Types::ssize_t send(templates::Range<const byte_t *> range) noexcept;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDPSERVER_HPP
