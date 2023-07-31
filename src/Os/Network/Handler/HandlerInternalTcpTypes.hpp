#ifndef HANDLERINTERNALTCPTYPES_HPP
#define HANDLERINTERNALTCPTYPES_HPP

#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/CircularArray.hpp>

#include <FlameIDE/Os/Constants.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tcp
{

template<Types::size_t BUFFER_SIZE>
using Buffer = templates::CircularArray<byte_t, BUFFER_SIZE>;

template<Types::size_t BUFFER_SIZE1, Types::size_t BUFFER_SIZE2>
using TemporaryBuffer = templates::Array<
	byte_t
	, ChooseType<
		(BUFFER_SIZE1 > BUFFER_SIZE2)
		, IntegralConstant<Types::size_t, BUFFER_SIZE1>
		, IntegralConstant<Types::size_t, BUFFER_SIZE2>
	>::Type::VALUE
>;

struct AcceptedConnection
{
	constexpr AcceptedConnection() = default;
	constexpr bool operator==(AcceptedConnection connection) const noexcept
	{
		return server == connection.server && client == connection.client;
	}

	os::SocketAddressIn address = {};
	os::SocketDescriptor server = os::SOCKET_INVALID.descriptor;
	os::SocketDescriptor client = os::SOCKET_INVALID.descriptor;

};

}}}} // namespace flame_ide::os::network::tcp

#endif // HANDLERINTERNALTCPTYPES_HPP
