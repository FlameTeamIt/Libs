#ifndef FLAMEIDE_STREAMS_SOCKETCLIENT_HPP
#define FLAMEIDE_STREAMS_SOCKETCLIENT_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Common/OsTypes.hpp>
#include <FlameIDE/Templates/Variant.hpp>

#include <FlameIDE/Streams/Socket.hpp>

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
