#ifndef FLAMEIDE_STREAMS_SOCKETSERVER_HPP
#define FLAMEIDE_STREAMS_SOCKETSERVER_HPP

/**
 * Идея для клиента и сервера следующая:
 *
 * 1. Вариант нужен для переключения в режимы чтения и записи.
 *
 */

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Common/OsTypes.hpp>
#include <FlameIDE/Templates/Variant.hpp>

#include <FlameIDE/Streams/Socket.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The SocketServer class
///
class SocketServer: public stream_utils::AbstractByteStream
{
public:
	SocketServer() noexcept;
	~SocketServer() noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept = 0;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept = 0;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept = 0;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept = 0;

	virtual void flush() noexcept = 0;

private:
	os::Socket sockServer; ///<
	Socket socketClient; ///<
};

}}

#endif // FLAMEIDE_STREAMS_SOCKETSERVER_HPP
