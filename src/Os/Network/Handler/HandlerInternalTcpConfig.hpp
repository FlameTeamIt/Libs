#ifndef HANDLERINTERNALTCPCONFIG_HPP
#define HANDLERINTERNALTCPCONFIG_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

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

}}}} // namespace flame_ide::os::network::tcp

#undef NETWORK_HANDLER_TCP_SERVERS
#undef NETWORK_HANDLER_TCP_SERVER_BACKLOG
#undef NETWORK_HANDLER_TCP_CLIENTS
#undef NETWORK_HANDLER_TCP_SERVER_INPUT_BUFFER_KB
#undef NETWORK_HANDLER_TCP_SERVER_OUTPUT_BUFFER_KB
#undef NETWORK_HANDLER_TCP_CLIENT_INPUT_BUFFER_KB
#undef NETWORK_HANDLER_TCP_CLIENT_OUTPUT_BUFFER_KB

#endif // HANDLERINTERNALTCPCONFIG_HPP
