#ifndef HANDLERINTERNALUDPCONFIG_HPP
#define HANDLERINTERNALUDPCONFIG_HPP

#include <Generated/Network/Config.hpp>
#include <FlameIDE/Common/Constants.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct Constants: ::flame_ide::NonCreational
{
	static constexpr Types::size_t NUMBER_OF_SERVERS =
			generated::network::Config::UDP_SERVERS;
	static constexpr Types::size_t NUMBER_OF_CLIENTS =
			generated::network::Config::UDP_CLIENTS;

	static constexpr Types::size_t MESSAGE_SIZE =
			generated::network::Config::UDP_MESSAGE_SIZE;

	static constexpr Types::size_t SERVER_INPUT_QUEUE_SIZE =
			generated::network::Config::UDP_SERVER_INPUT_QUEUE_SIZE;
	static constexpr Types::size_t SERVER_OUTPUT_QUEUE_SIZE =
			generated::network::Config::UDP_SERVER_OUTPUT_QUEUE_SIZE;

	static constexpr Types::size_t CLIENT_INPUT_QUEUE_SIZE =
			generated::network::Config::UDP_CLIENT_INPUT_QUEUE_SIZE;
	static constexpr Types::size_t CLIENT_OUTPUT_QUEUE_SIZE =
			generated::network::Config::UDP_CLIENT_OUTPUT_QUEUE_SIZE;

private:
	static_assert(
			MESSAGE_SIZE < ::flame_ide::Constants::MAX_UDP_IPV4_MESSAGE_SIZE
			, "UDP IPv4 message is too big. Max size is 65507"
	);
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPCONFIG_HPP
