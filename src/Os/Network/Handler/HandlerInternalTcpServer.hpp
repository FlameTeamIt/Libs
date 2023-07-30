#ifndef HANDLERINTERNALTCPSERVER_HPP
#define HANDLERINTERNALTCPSERVER_HPP

#include <FlameIDE/Templates/CircularArray.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpConfig.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpTypes.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{

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
	using InputBuffer = Buffer<Constants::SERVER_INPUT_BUFFER_SIZE>;
	using OutputBuffer = Buffer<Constants::SERVER_OUTPUT_BUFFER_SIZE>;
	using TempBuffer = TemporaryBuffer<
		Constants::SERVER_INPUT_BUFFER_SIZE, Constants::SERVER_OUTPUT_BUFFER_SIZE
	>;

	using Optional = templates::Optional<flame_ide::os::network::TcpServer>;
	using OptionalConnection = templates::Optional<network::TcpServer::WithClient>;

public:
	struct Connection
	{
		templates::UniquePointer<InputBuffer> input;
		templates::UniquePointer<OutputBuffer> output;
		templates::UniquePointer<TempBuffer> tmp;

		OptionalConnection client;
	};
	using Connections = ::flame_ide::templates::StaticArray<
		Connection, Constants::NUMBER_OF_SERVERS_CONNECTIONS
	>;

public:
	Optional server;
	Connections connections;
};

}}}} // namespace flame_ide::os::network::tcp

#endif // HANDLERINTERNALTCPSERVER_HPP
