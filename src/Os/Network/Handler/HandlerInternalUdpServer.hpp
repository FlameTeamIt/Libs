#ifndef HANDLERINTERNALUDPSERVER_HPP
#define HANDLERINTERNALUDPSERVER_HPP

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpConfig.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpTypes.hpp>

#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace udp
{

class Server
{
public:
	struct Message
	{
		mutable threads::Spin spin;

		Types::ssize_t size = 0;
		network::UdpServer::WithClient client;
		::flame_ide::templates::StaticArray<
			::flame_ide::byte_t, Constants::MESSAGE_SIZE
		> bytes;
		MessageState state = MessageState::EMPTY;
	};

public:
	using Optional = ::flame_ide::templates::Optional<
		::flame_ide::os::network::UdpServer
	>;

	using ActualInput = ActualData<Message, Constants::SERVER_INPUT_QUEUE_SIZE>;
	using ActualOutput = ActualData<Message, Constants::SERVER_OUTPUT_QUEUE_SIZE>;

public:
	Optional server;
	ActualInput input;
	ActualOutput output;
};

}}}} // namespace flame_ide::os::network::udp

#endif // HANDLERINTERNALUDPSERVER_HPP
