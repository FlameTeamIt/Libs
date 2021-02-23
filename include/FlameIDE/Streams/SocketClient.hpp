#ifndef FLAMEIDE_STREAMS_SOCKETCLIENT_HPP
#define FLAMEIDE_STREAMS_SOCKETCLIENT_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/Socket.hpp>

#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/Templates/Variant.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The SocketClient class
///
class SocketClient: public Socket
{
public:
	SocketClient() noexcept;
	~SocketClient() noexcept;
};

}}

#endif // SOCKETCLIENT_HPP
