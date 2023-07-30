#ifndef HANDLERINTERNALUDP_HPP
#define HANDLERINTERNALUDP_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

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
	UNKNOWN
	, READING
	, WRITING
	, READY_TO_SEND
	, READY_TO_RECEIVE
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

class Server
{
public:
	struct Message
	{
		::flame_ide::templates::StaticArray<
			::flame_ide::byte_t, Constants::MESSAGE_SIZE
		> bytes;
		Types::ssize_t size;
		network::UdpServer::WithClient client;
		MessageState state = MessageState::UNKNOWN;
	};

public:
	using Optional = ::flame_ide::templates::Optional<
		::flame_ide::os::network::UdpServer
	>;

	using InputMessages = ::flame_ide::templates::StaticArray<
		templates::UniquePointer<Message>, Constants::SERVER_INPUT_QUEUE_SIZE
	>;
	using OutputMessages = ::flame_ide::templates::StaticArray<
		templates::UniquePointer<Message>, Constants::SERVER_OUTPUT_QUEUE_SIZE
	>;

public:
	Optional server;
	InputMessages inputMessages;
	OutputMessages outputMessages;
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
		MessageState state = MessageState::UNKNOWN;
	};

public:
	using Optional = ::flame_ide::templates::Optional<
		::flame_ide::os::network::UdpClient
	>;

	using InputMessages = ::flame_ide::templates::StaticArray<
		templates::UniquePointer<Message>, Constants::CLIENT_INPUT_QUEUE_SIZE
	>;
	using OutputMessages = ::flame_ide::templates::StaticArray<
		templates::UniquePointer<Message>, Constants::CLIENT_OUTPUT_QUEUE_SIZE
	>;

public:
	Optional client;
	InputMessages inputMessages;
	OutputMessages outputMessages;
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
