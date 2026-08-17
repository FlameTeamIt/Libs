#ifndef HANDLER_INTERNAL_UDPCLIENT_HPP
#define HANDLER_INTERNAL_UDPCLIENT_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Endpoint.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>

#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct ClientMessage: public Message
{
	void fill(flame_ide::os::network::UdpClient &endpoint) noexcept;
};

class Client: public Endpoint<
	::flame_ide::os::network::UdpClient, ClientMessage
	, Constants::CLIENT_INPUT_QUEUE_SIZE, Constants::CLIENT_OUTPUT_QUEUE_SIZE
>
{};

struct ClientCommunicationData
{
	::flame_ide::ReferenceWrapper<Client> client;

	Types::ssize_t bytesToRead() const noexcept;
	Types::ssize_t receive(templates::Range<byte_t *> range) noexcept;
	Types::ssize_t send(templates::Range<const byte_t *> range) noexcept;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDPCLIENT_HPP
