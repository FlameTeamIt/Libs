#ifndef HANDLERINTERNALUDPCONFIG_HPP
#define HANDLERINTERNALUDPCONFIG_HPP

#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

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

}}}} // namespace flame_ide::os::network::udp

#undef NETWORK_HANDLER_UDP_SERVERS
#undef NETWORK_HANDLER_UDP_CLIENTS
#undef NETWORK_HANDLER_UDP_MESSAGE_SIZE_KB
#undef NETWORK_HANDLER_UDP_SERVER_INPUT_QUEUE_SIZE
#undef NETWORK_HANDLER_UDP_MESSAGE_OUTPUT_QUEUE_SIZE
#undef NETWORK_HANDLER_UDP_CLIENT_INPUT_QUEUE_SIZE
#undef NETWORK_HANDLER_UDP_CLIENT_OUTPUT_QUEUE_SIZE

#endif // HANDLERINTERNALUDPCONFIG_HPP
