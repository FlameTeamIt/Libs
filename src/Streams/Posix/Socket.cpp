#include <FlameIDE/Common/Macroses.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <unistd.h>

#include <FlameIDE/Streams/Socket.hpp>

namespace flame_ide
{namespace streams
{

Socket::Socket() noexcept : sock(os::SOCKET_INITIALIZER), own(false)
{}

Socket::Socket(Socket &&socket) noexcept :
		sock(socket.sock), own(socket.own)
{
	socket.sock = os::SOCKET_INITIALIZER;
	socket.own = false;
}

Socket::Socket(os::Socket socket, bool owner) noexcept :
		sock(socket), own(owner)
{}

Socket::~Socket() noexcept
{
	if (own)
	{
		::close(sock.fd);
	}
}

Socket &Socket::operator=(Socket &&socket) noexcept
{
	if (own)
	{
		::close(sock.fd);
	}
	sock = socket.sock;
	own = socket.own;

	socket.sock = os::SOCKET_INITIALIZER;
	socket.own = false;

	return *this;
}

SizeTraits::SsizeType Socket::read(OutputByteRange range) noexcept
{
	auto countBytes = range.end() - range.begin();
	if (countBytes > 0)
	{
		return ::recv(sock.fd, getPointer(range.begin())
			 , static_cast<SizeTraits::SizeType>(countBytes), 0);
	}
	return stream_utils::INVALID_COUNT_BYTES;
}

SizeTraits::SsizeType Socket::read(OutputCircularByteRange range) noexcept
{
	ContiniousOutputRanges ranges = Parent::getContinuousOutputRanges(range);
	SizeTraits::SsizeType countRead = this->read(ranges[0]);
	if (countRead != stream_utils::INVALID_COUNT_BYTES)
	{
		SizeTraits::SsizeType countRead1 = this->read(ranges[1]);
		if (countRead1 != stream_utils::INVALID_COUNT_BYTES)
		{
			return countRead + countRead1;
		}
		else
		{
			return countRead;
		}
	}
	return stream_utils::INVALID_COUNT_BYTES;
}

SizeTraits::SsizeType Socket::write(InputByteRange range) noexcept
{
	auto countBytes = range.end() - range.begin();
	if (countBytes > 0)
	{
		return ::send(sock.fd, getPointer(range.begin())
				, static_cast<SizeTraits::SizeType>(countBytes), 0);
	}
	return stream_utils::INVALID_COUNT_BYTES;
}

SizeTraits::SsizeType Socket::write(InputCircularByteRange range) noexcept
{
	ContiniousInputRanges ranges = Parent::getContinuousInputRanges(range);
	SizeTraits::SsizeType countWritten = this->write(ranges[0]);
	if (countWritten != stream_utils::INVALID_COUNT_BYTES)
	{
		SizeTraits::SsizeType countWritten1 = this->write(ranges[1]);
		if (countWritten1 != stream_utils::INVALID_COUNT_BYTES)
		{
			return countWritten + countWritten1;
		}
		else
		{
			return countWritten;
		}
	}
	return stream_utils::INVALID_COUNT_BYTES;
}

void Socket::flush() noexcept
{
	::fsync(sock.fd);
}

void Socket::setSocket(os::Socket socket, bool owner) noexcept
{
	if (own && sock.fd != os::INVALID_DESCRIPTOR)
	{
		close(sock.fd);
	}
	sock = socket;
	own = owner;
}

os::Socket Socket::getSocket(bool continueOwning) noexcept
{
	own = continueOwning;
	return sock;
}

}}

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL
