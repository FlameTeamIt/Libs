#ifndef HANDLERINTERNALUDPCLIENT_HPP
#define HANDLERINTERNALUDPCLIENT_HPP

#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Types.hpp>

#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

namespace flame_ide
{namespace handler
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
		mutable os::threads::Spin spin;
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

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPCLIENT_HPP
