#ifndef FLAMEIDE_STREAMS_SOCKETSERVER_HPP
#define FLAMEIDE_STREAMS_SOCKETSERVER_HPP

#include <FlameIDE/Streams/Socket.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The SocketServer class
///
class SocketServer
{
public:
	class Connection: public stream_utils::AbstractByteStream
	{
	public:
		friend class flame_ide::streams::SocketServer;

		virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
		virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

		virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
		virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

		virtual void flush() noexcept;

	private:
	};

	SocketServer() noexcept;
	~SocketServer() noexcept;

private:
	Socket sockServer; ///<

};

}}

#endif // FLAMEIDE_STREAMS_SOCKETSERVER_HPP
