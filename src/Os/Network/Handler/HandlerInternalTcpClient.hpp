#ifndef HANDLERINTERNALTCPCLIENT_HPP
#define HANDLERINTERNALTCPCLIENT_HPP

#include <FlameIDE/Templates/CircularArray.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/Os/Network/TcpClient.hpp>

#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpConfig.hpp>
#include <FlameIDE/../../src/Os/Network/Handler/HandlerInternalTcpTypes.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{

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

}}}} // namespace flame_ide::os::network::tcp

#endif // HANDLERINTERNALTCPCLIENT_HPP
