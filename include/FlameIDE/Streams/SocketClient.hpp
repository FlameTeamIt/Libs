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
class SocketClient: public stream_utils::AbstractByteStream
{
public:
	SocketClient() noexcept;
	~SocketClient() noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept = 0;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept = 0;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept = 0;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept = 0;

	virtual void flush() noexcept = 0;

private:
	Socket socket; ///<
};

}}

#endif // SOCKETCLIENT_HPP
