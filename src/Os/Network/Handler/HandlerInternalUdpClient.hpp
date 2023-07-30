#ifndef HANDLERINTERNALUDPCLIENT_HPP
#define HANDLERINTERNALUDPCLIENT_HPP

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpConfig.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalUdpTypes.hpp>

#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace udp
{

class Client
{
public:
	struct Message
	{
		::flame_ide::templates::StaticArray<
			::flame_ide::byte_t, Constants::MESSAGE_SIZE
		> bytes;
		Types::ssize_t size = 0;
		MessageState state = MessageState::EMPTY;
		mutable threads::Spin spin;
	};

public:
	using Optional = ::flame_ide::templates::Optional<
		::flame_ide::os::network::UdpClient
	>;

	using ActualInput = ActualData<Message, Constants::CLIENT_INPUT_QUEUE_SIZE>;
	using ActualOutput = ActualData<Message, Constants::CLIENT_OUTPUT_QUEUE_SIZE>;

public:
	Optional client;
	ActualInput input;
	ActualOutput output;
};

}}}} // namespace flame_ide::os::network::udp

#endif // HANDLERINTERNALUDPCLIENT_HPP
