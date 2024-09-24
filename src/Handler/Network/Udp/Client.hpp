#ifndef HANDLERINTERNALUDPCLIENT_HPP
#define HANDLERINTERNALUDPCLIENT_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Types.hpp>

#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct ClientMessage: public Message
{};
using ClientEndpoint = Endpoint<
	::flame_ide::os::network::UdpClient, ClientMessage
	, Constants::CLIENT_INPUT_QUEUE_SIZE, Constants::CLIENT_OUTPUT_QUEUE_SIZE
>;

class Client: public ClientEndpoint
{
public:
	inline ClientEndpoint::Optional &client() noexcept
	{
		return this->osEndpoint;
	}

	inline const ClientEndpoint::Optional &client() const noexcept
	{
		return this->osEndpoint;
	}
};

struct ClientCommunicationData
{
	os::network::UdpClient *client;
	ClientMessage *message;
	Client::ActualOutput *output;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPCLIENT_HPP
