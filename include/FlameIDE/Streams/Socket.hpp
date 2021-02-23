#ifndef FLAMEIDE_STREAMS_SOCKET_HPP
#define FLAMEIDE_STREAMS_SOCKET_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Streams/SocketUtils.hpp>

#include <FlameIDE/Os/Types.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The SocketReader class
///
class Socket: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	Socket() noexcept;
	Socket(const Socket &) noexcept = delete;
	Socket(Socket &&socket) noexcept;

	///
	/// @brief SocketReader
	/// @param socket
	/// @param owner
	///
	Socket(os::Socket socket, bool owner = true) noexcept;

	Socket &operator=(const Socket &) noexcept = delete;
	Socket &operator=(Socket &&socket) noexcept;

	virtual ~Socket() noexcept;

	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept;

	virtual void flush() noexcept;

	///
	/// @brief setSocket
	/// @param socket
	/// @param owner
	///
	void setSocket(os::Socket socket, bool owner = true) noexcept;

	///
	/// @brief getSocket
	/// @param continueOwning
	/// @return
	///
	os::Socket getSocket(bool continueOwning = false) noexcept;

protected:
	os::Socket nativeSocket;
	bool own; ///< attribute
};

}}
#endif // FLAMEIDE_STREAMS_SOCKET_HPP
