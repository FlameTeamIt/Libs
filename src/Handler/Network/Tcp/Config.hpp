#ifndef HANDLERINTERNALTCPCONFIG_HPP
#define HANDLERINTERNALTCPCONFIG_HPP

#include <Generated/Network/Config.hpp>
#include <FlameIDE/Common/Constants.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tcp
{

struct Constants: ::flame_ide::NonCreational
{
	static constexpr Types::size_t NUMBER_OF_SERVERS =
			generated::network::Config::TCP_SERVERS;
	static constexpr Types::size_t NUMBER_OF_SERVERS_CONNECTIONS =
			generated::network::Config::TCP_SERVER_BACKLOG;

	static constexpr Types::size_t NUMBER_OF_CLIENTS =
			generated::network::Config::TCP_CLIENTS;

	static constexpr Types::size_t SERVER_INPUT_BUFFER_SIZE =
			generated::network::Config::TCP_SERVER_INPUT_BUFFER_SIZE;
	static constexpr Types::size_t SERVER_OUTPUT_BUFFER_SIZE =
			generated::network::Config::TCP_SERVER_OUTPUT_BUFFER_SIZE;

	static constexpr Types::size_t CLIENT_INPUT_BUFFER_SIZE =
			generated::network::Config::TCP_CLIENT_INPUT_BUFFER_SIZE;
	static constexpr Types::size_t CLIENT_OUTPUT_BUFFER_SIZE =
			generated::network::Config::TCP_CLIENT_OUTPUT_BUFFER_SIZE;

	static constexpr Types::size_t NUMBER_OF_SOCKETS =
			Constants::NUMBER_OF_SERVERS * (1 + Constants::NUMBER_OF_SERVERS_CONNECTIONS)
			+ Constants::NUMBER_OF_CLIENTS;
};

}}}} // namespace flame_ide::handler::network::tcp

#endif // HANDLERINTERNALTCPCONFIG_HPP
