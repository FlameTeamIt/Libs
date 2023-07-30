#ifndef HANDLERINTERNALUDP_HPP
#define HANDLERINTERNALUDP_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/CircularArray.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#if !defined(NETWORK_HANDLER_UDP_SERVERS)
#	define NETWORK_HANDLER_UDP_SERVERS ::flame_ide::Types::size_t{ 4 }
#endif // !defined(NETWORK_HANDLER_UDP_SERVERS)

#if !defined(NETWORK_HANDLER_UDP_CLIENTS)
#	define NETWORK_HANDLER_UDP_CLIENTS ::flame_ide::Types::size_t{ 4 }
#endif // !defined(NETWORK_HANDLER_UDP_CLIENTS)

#if !defined(NETWORK_HANDLER_UDP_MESSAGE_SIZE_KB)
#	define NETWORK_HANDLER_UDP_MESSAGE_SIZE_KB ::flame_ide::Types::size_t{ 63 }
#endif // !defined(NETWORK_HANDLER_UDP_MESSAGE_SIZE_KB)

#if !defined(NETWORK_HANDLER_UDP_SERVER_INPUT_QUEUE_SIZE)
#	define NETWORK_HANDLER_UDP_SERVER_INPUT_QUEUE_SIZE \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_UDP_SERVER_INPUT_QUEUE_SIZE)

#if !defined(NETWORK_HANDLER_UDP_SERVER_OUTPUT_QUEUE_SIZE)
#	define NETWORK_HANDLER_UDP_SERVER_OUTPUT_QUEUE_SIZE \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_UDP_SERVER_OUTPUT_QUEUE_SIZE)

#if !defined(NETWORK_HANDLER_UDP_CLIENT_INPUT_QUEUE_SIZE)
#	define NETWORK_HANDLER_UDP_CLIENT_INPUT_QUEUE_SIZE \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_UDP_CLIENT_INPUT_QUEUE_SIZE)

#if !defined(NETWORK_HANDLER_UDP_CLIENT_OUTPUT_QUEUE_SIZE)
#	define NETWORK_HANDLER_UDP_CLIENT_OUTPUT_QUEUE_SIZE \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_UDP_CLIENT_OUTPUT_QUEUE_SIZE)

namespace flame_ide
{namespace os
{namespace network
{namespace udp
{

enum class MessageState
{
	EMPTY
	, PROCESSING
	, READY
};

struct Constants: ::flame_ide::NonCreational
{
	static constexpr Types::size_t NUMBER_OF_SERVERS = NETWORK_HANDLER_UDP_SERVERS;
	static constexpr Types::size_t NUMBER_OF_CLIENTS = NETWORK_HANDLER_UDP_CLIENTS;

	static constexpr Types::size_t MESSAGE_SIZE =
			::flame_ide::Constants::KILOBYTE * NETWORK_HANDLER_UDP_MESSAGE_SIZE_KB;

	static constexpr Types::size_t SERVER_INPUT_QUEUE_SIZE =
			NETWORK_HANDLER_UDP_SERVER_INPUT_QUEUE_SIZE;
	static constexpr Types::size_t SERVER_OUTPUT_QUEUE_SIZE =
			NETWORK_HANDLER_UDP_SERVER_OUTPUT_QUEUE_SIZE;

	static constexpr Types::size_t CLIENT_INPUT_QUEUE_SIZE =
			NETWORK_HANDLER_UDP_CLIENT_INPUT_QUEUE_SIZE;
	static constexpr Types::size_t CLIENT_OUTPUT_QUEUE_SIZE =
			NETWORK_HANDLER_UDP_CLIENT_OUTPUT_QUEUE_SIZE;

private:
	static_assert(
			MESSAGE_SIZE < ::flame_ide::Constants::MAX_UDP_IPV4_MESSAGE_SIZE
			, "UDP IPv4 message is too big. Max size is 65507"
	);

};

template<typename MessageType, Types::size_t SIZE>
struct ActualData
{
	using Messages = ::flame_ide::templates::StaticArray<
		templates::UniquePointer<MessageType>, SIZE
	>;
	using MessagesCircularIterator =
			templates::defaults::CircularForwardIterator<
				typename Messages::Iterator
			>;

	Messages messages;
	MessagesCircularIterator first = MessagesCircularIterator{
			messages.begin()
			, templates::makeRange(messages.begin(), messages.end())
	};
	MessagesCircularIterator last = first;
	mutable threads::Spin spin;
};

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

// WARNING: using UniquePointer because malloc doen't work with big sizes
using Servers = ::flame_ide::templates::StaticArray<
	templates::UniquePointer<Server>, Constants::NUMBER_OF_SERVERS
>;

// WARNING: using UniquePointer because malloc doen't work with big sizes
using Clients = ::flame_ide::templates::StaticArray<
	templates::UniquePointer<Client>, Constants::NUMBER_OF_CLIENTS
>;

using SocketDescriptors = ::flame_ide::templates::StaticArray<
	::flame_ide::os::SocketDescriptor
	, Constants::NUMBER_OF_SERVERS + Constants::NUMBER_OF_CLIENTS
>;

struct Udp
{
	templates::UniquePointer<Servers> servers/* = decltype(servers)::makeEmpty()*/;
	templates::UniquePointer<Clients> clients/* = decltype(clients)::makeEmpty()*/;
	SocketDescriptors socketDescriptors;
};

}}}} // namespace flame_ide::os::network::udp

#undef NETWORK_HANDLER_UDP_SERVERS
#undef NETWORK_HANDLER_UDP_CLIENTS
#undef NETWORK_HANDLER_UDP_MESSAGE_SIZE_KB
#undef NETWORK_HANDLER_UDP_SERVER_INPUT_QUEUE_SIZE
#undef NETWORK_HANDLER_UDP_MESSAGE_OUTPUT_QUEUE_SIZE
#undef NETWORK_HANDLER_UDP_CLIENT_INPUT_QUEUE_SIZE
#undef NETWORK_HANDLER_UDP_CLIENT_OUTPUT_QUEUE_SIZE

#endif // HANDLERINTERNALUDP_HPP
