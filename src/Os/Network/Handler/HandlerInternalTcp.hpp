#ifndef HANDLERINTERNALTCP_HPP
#define HANDLERINTERNALTCP_HPP

#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Network/TcpClient.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/CircularArray.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#if !defined(NETWORK_HANDLER_TCP_SERVERS)
#	define NETWORK_HANDLER_TCP_SERVERS ::flame_ide::Types::size_t{ 2 }
#endif // !defined(NETWORK_HANDLER_TCP_SERVERS)

#if !defined(NETWORK_HANDLER_TCP_SERVER_BACKLOG)
#	define NETWORK_HANDLER_TCP_SERVER_BACKLOG ::flame_ide::Types::size_t{ 127 }
#endif // !defined(NETWORK_HANDLER_TCP_SERVER_BACKLOG)

#if !defined(NETWORK_HANDLER_TCP_CLIENTS)
#	define NETWORK_HANDLER_TCP_CLIENTS ::flame_ide::Types::size_t{ 8 }
#endif // !defined(NETWORK_HANDLER_TCP_CLIENTS)

#if !defined(NETWORK_HANDLER_TCP_SERVER_INPUT_BUFFER_KB)
#	define NETWORK_HANDLER_TCP_SERVER_INPUT_BUFFER_KB \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_TCP_SERVER_INPUT_BUFFER_KB)

#if !defined(NETWORK_HANDLER_TCP_SERVER_OUTPUT_BUFFER_KB)
#	define NETWORK_HANDLER_TCP_SERVER_OUTPUT_BUFFER_KB \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_TCP_SERVER_OUTPUT_BUFFER_KB)

#if !defined(NETWORK_HANDLER_TCP_CLIENT_INPUT_BUFFER_KB)
#	define NETWORK_HANDLER_TCP_CLIENT_INPUT_BUFFER_KB \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_TCP_CLIENT_INPUT_BUFFER_KB)

#if !defined(NETWORK_HANDLER_TCP_CLIENT_OUTPUT_BUFFER_KB)
#	define NETWORK_HANDLER_TCP_CLIENT_OUTPUT_BUFFER_KB \
		::flame_ide::Types::size_t{ 32 }
#endif // !defined(NETWORK_HANDLER_TCP_CLIENT_OUTPUT_BUFFER_KB)

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{

struct Constants: ::flame_ide::NonCreational
{
	static constexpr Types::size_t NUMBER_OF_SERVERS = NETWORK_HANDLER_TCP_SERVERS;
	static constexpr Types::size_t NUMBER_OF_SERVERS_CONNECTIONS =
			NETWORK_HANDLER_TCP_SERVER_BACKLOG;

	static constexpr Types::size_t NUMBER_OF_CLIENTS = NETWORK_HANDLER_TCP_CLIENTS;

	static constexpr Types::size_t SERVER_INPUT_BUFFER_SIZE =
			::flame_ide::Constants::KILOBYTE
			* NETWORK_HANDLER_TCP_SERVER_INPUT_BUFFER_KB;
	static constexpr Types::size_t SERVER_OUTPUT_BUFFER_SIZE =
			::flame_ide::Constants::KILOBYTE
			* NETWORK_HANDLER_TCP_SERVER_OUTPUT_BUFFER_KB;

	static constexpr Types::size_t CLIENT_INPUT_BUFFER_SIZE =
			::flame_ide::Constants::KILOBYTE
			* NETWORK_HANDLER_TCP_CLIENT_INPUT_BUFFER_KB;
	static constexpr Types::size_t CLIENT_OUTPUT_BUFFER_SIZE =
			::flame_ide::Constants::KILOBYTE
			* NETWORK_HANDLER_TCP_CLIENT_OUTPUT_BUFFER_KB;

	static constexpr Types::size_t NUMBER_OF_SOCKETS =
			Constants::NUMBER_OF_SERVERS * (1 + Constants::NUMBER_OF_SERVERS_CONNECTIONS)
			+ Constants::NUMBER_OF_CLIENTS;
};

class Server
{
public:
	static_assert(
			Constants::SERVER_INPUT_BUFFER_SIZE != 0
			, "Input buffer size for TCP servers is 0"
	);
	static_assert(
			Constants::SERVER_OUTPUT_BUFFER_SIZE != 0
			, "Output buffer size for TCP servers is 0"
	);
	static_assert(
			Constants::NUMBER_OF_SERVERS_CONNECTIONS != 0
			, "TCP server's backlog is 0"
	);

public:
	using InputBuffer = ::flame_ide::templates::CircularArray<
		::flame_ide::byte_t, Constants::SERVER_INPUT_BUFFER_SIZE
	>;
	using OutputBuffer = ::flame_ide::templates::CircularArray<
		::flame_ide::byte_t, Constants::SERVER_OUTPUT_BUFFER_SIZE
	>;
	using TempBuffer = ::flame_ide::templates::Array<
		::flame_ide::byte_t
		, (
				Constants::SERVER_INPUT_BUFFER_SIZE
						> Constants::SERVER_OUTPUT_BUFFER_SIZE
		) ? Constants::SERVER_INPUT_BUFFER_SIZE : Constants::SERVER_OUTPUT_BUFFER_SIZE
	>;

	using Optional = ::flame_ide::templates::Optional<flame_ide::os::network::TcpServer>;
	using OptionalConnection =
			::flame_ide::templates::Optional<network::TcpServer::WithClient>;

	template<typename ConnectionType>
	using Connections = ::flame_ide::templates::StaticArray<
		ConnectionType, Constants::NUMBER_OF_SERVERS_CONNECTIONS
	>;

public:
	struct Connection
	{
		templates::UniquePointer<InputBuffer> input;
		templates::UniquePointer<OutputBuffer> output;
		templates::UniquePointer<TempBuffer> tmp;

		OptionalConnection client;
	};

public:
	Optional server;
	Connections<Connection> connections;
};

class Client
{
public:
	static_assert(
			Constants::CLIENT_INPUT_BUFFER_SIZE != 0
			, "Input buffer size for TCP clients is 0"
	);
	static_assert(
			Constants::CLIENT_OUTPUT_BUFFER_SIZE != 0
			, "Output buffer size for TCP clients is 0"
	);

public:
	using Optional = ::flame_ide::templates::Optional<flame_ide::os::network::TcpClient>;

	using InputBuffer = ::flame_ide::templates::CircularArray<
		::flame_ide::byte_t, Constants::CLIENT_INPUT_BUFFER_SIZE
	>;
	using OutputBuffer = ::flame_ide::templates::CircularArray<
		::flame_ide::byte_t, Constants::CLIENT_OUTPUT_BUFFER_SIZE
	>;
	using TempBuffer = ::flame_ide::templates::Array<
		::flame_ide::byte_t
		, (
				Constants::CLIENT_INPUT_BUFFER_SIZE
						> Constants::CLIENT_OUTPUT_BUFFER_SIZE
		) ? Constants::CLIENT_INPUT_BUFFER_SIZE : Constants::CLIENT_OUTPUT_BUFFER_SIZE
	>;

public:
	templates::UniquePointer<InputBuffer> input;
	templates::UniquePointer<OutputBuffer> output;
	templates::UniquePointer<TempBuffer> tmp;

	Optional client;
};

using Servers = ::flame_ide::ChooseType<
	Constants::NUMBER_OF_SERVERS != 0
	, ::flame_ide::templates::StaticArray<Server, Constants::NUMBER_OF_SERVERS>
	, ::flame_ide::Empty
>::Type;

using Clients = ::flame_ide::ChooseType<
	Constants::NUMBER_OF_CLIENTS != 0
	, ::flame_ide::templates::StaticArray<Client, Constants::NUMBER_OF_CLIENTS>
	, ::flame_ide::Empty
>::Type;

using SocketDescriptors = ::flame_ide::ChooseType<
	Constants::NUMBER_OF_SOCKETS != 0
	, ::flame_ide::templates::StaticArray<
		::flame_ide::os::SocketDescriptor, Constants::NUMBER_OF_SOCKETS
	>
	, ::flame_ide::Empty
>::Type;

struct Tcp
{
	templates::UniquePointer<Servers> servers = decltype(servers)::makeEmpty();
	templates::UniquePointer<Clients> clients = decltype(clients)::makeEmpty();
	SocketDescriptors socketDescriptors;
};

}}}} // namespace flame_ide::os::network::tcp

#undef NETWORK_HANDLER_TCP_SERVERS
#undef NETWORK_HANDLER_TCP_SERVER_BACKLOG
#undef NETWORK_HANDLER_TCP_CLIENTS
#undef NETWORK_HANDLER_TCP_SERVER_INPUT_BUFFER_KB
#undef NETWORK_HANDLER_TCP_SERVER_OUTPUT_BUFFER_KB
#undef NETWORK_HANDLER_TCP_CLIENT_INPUT_BUFFER_KB
#undef NETWORK_HANDLER_TCP_CLIENT_OUTPUT_BUFFER_KB

#endif // HANDLERINTERNALTCP_HPP
