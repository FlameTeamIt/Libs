#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

class WinSockLibrary: public flame_ide::NonAssignable
{
public:
	static volatile WinSockLibrary &signeton() noexcept;

	operator bool() const volatile noexcept;

	void init() volatile noexcept;
	void destroy() volatile noexcept;

private:
	WinSockLibrary() noexcept = default;
	~WinSockLibrary() noexcept;

private:
	::WSADATA wsaData;
	flame_ide::os::Status wsaStatus = 0;
	bool inited = false;
};

//

bool winsockInit() noexcept;

//

namespace flame_ide
{namespace os
{namespace socket
{

Socket udpCreateServerSocket(Ipv4::Port port) noexcept
{
	Socket socket;

	if (!winsockInit())
		return socket;

	socket.descriptor = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	socket.address.sin_family = AF_INET;
	socket.address.sin_port = ::htons(static_cast<Types::ushort_t>(port));
	socket.address.sin_addr.S_un.S_addr = INADDR_ANY;

	const auto result = ::bind(socket.descriptor, (::SOCKADDR *)(&socket.address), sizeof(socket.address));
	if (result == SOCKET_ERROR)
	{
		socket = Socket{};
	}
	return socket;
}

Socket udpCreateClientSocket(const Ipv4& ipServer) noexcept
{
	Socket socket;

	if (!winsockInit())
		return socket;

	Ipv4::Address address = ipServer;

	socket.descriptor = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	socket.address.sin_family = AF_INET;
	socket.address.sin_port = ::htons(static_cast<Types::ushort_t>(address.port));
	socket.address.sin_addr.S_un.S_addr = ::inet_addr(address.ip);

	return socket;
}

void destroySocket(Socket &socket)
{
	::closesocket(socket.descriptor);
	socket = Socket{};
}

Types::ssize_t
udpSend(const Socket &socket, templates::Range<const byte_t *> range)
{
	const Types::size_t size = range.end() - range.begin();
	const auto buffer = reinterpret_cast<const char *>(range.begin());
	auto address = reinterpret_cast<const SOCKADDR *>(&socket.address);

	auto result = ::sendto(socket.descriptor, buffer, size, 0, address, sizeof(socket.address));
	if (result < 0)
	{
		return -WSAGetLastError();
	}
	return result;
}

Types::ssize_t
udpReceive(const Socket &socket, templates::Range<byte_t *> range, SocketReceive &socketFrom)
{
	const Types::size_t size = range.end() - range.begin();

	auto buffer = reinterpret_cast<char *>(range.begin());
	auto address = reinterpret_cast<SOCKADDR *>(&socketFrom.address);
	int addressLength = sizeof(socketFrom.address);

	auto result = ::recvfrom(socket.descriptor, buffer, size, 0, address, &addressLength);
	if (result < 0)
	{
		return -WSAGetLastError();
	}
	socketFrom.descriptor = &socket.descriptor;
	return result;
}

}}} // namespace flame_ide::os::socket

//

volatile WinSockLibrary &WinSockLibrary::signeton() noexcept
{
	static volatile WinSockLibrary winsock;
	return winsock;
}

WinSockLibrary::operator bool() const volatile noexcept
{
	return inited;
}

void WinSockLibrary::init() volatile noexcept
{
	if (inited)
		return;

	auto result = ::WSAStartup(MAKEWORD(2, 2), (::WSADATA *)(&wsaData));
	if (result)
	{
		wsaStatus = ::WSAGetLastError();
		return;
	}

	inited = true;
}

void WinSockLibrary::destroy() volatile noexcept
{
	if (!inited)
		return;

	wsaStatus = WSACleanup();
}

WinSockLibrary::~WinSockLibrary() noexcept
{
	destroy();
}

//

bool winsockInit() noexcept
{
	auto &winsock = WinSockLibrary::signeton();
	winsock.init();
	return winsock.operator bool();
}
