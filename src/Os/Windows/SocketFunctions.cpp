#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <FlameIDE/Os/Constants.hpp>

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
namespace // anonymous
{

::SOCKET udpСreateSocket() noexcept
{
	return ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

::SOCKET tcpCreateSocket() noexcept
{
	return ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

::SOCKADDR_IN ipAddressServer(Ipv4::Port port) noexcept
{
	::SOCKADDR_IN sockaddr = SOCKET_INITIALIZER.address;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = ::htons(static_cast<Types::ushort_t>(port));
	sockaddr.sin_addr.S_un.S_addr = INADDR_ANY;
	return sockaddr;
}

::SOCKADDR_IN ipAddressClient(Ipv4::Address serverAddress) noexcept
{
	::SOCKADDR_IN sockaddr = SOCKET_INITIALIZER.address;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = ::htons(static_cast<Types::ushort_t>(serverAddress.port));
	sockaddr.sin_addr.S_un.S_addr = ::inet_addr(serverAddress.ip);
	return sockaddr;
}

} // namespace anonymous
}}} // namespace flame_ide::os::socket

namespace flame_ide
{namespace os
{namespace socket
{

// UDP

Socket createUdpServer(Ipv4::Port port) noexcept
{
	Socket socket;

	if (!winsockInit())
		return socket;

	socket = Socket{ ipAddressServer(port), udpСreateSocket() };

	auto address = reinterpret_cast<const SOCKADDR *>(&socket.address);
	const auto result = ::bind(socket.descriptor, address, sizeof(socket.address));
	if (result == SOCKET_ERROR)
	{
		socket = Socket{};
	}
	return socket;
}

Socket createUdpClient(Ipv4 ipServer) noexcept
{
	Socket socket;

	if (!winsockInit())
		return socket;

	return Socket{ ipAddressClient(ipServer), udpСreateSocket() };
}

// TCP

Socket createTcpServer(Ipv4::Port port) noexcept
{
	Socket socket;

	if (!winsockInit())
		return socket;

	socket = Socket{ ipAddressServer(port), tcpCreateSocket() };

	auto address = reinterpret_cast<const SOCKADDR *>(&socket.address);
	const auto result = ::bind(socket.descriptor, address, sizeof(socket.address));
	if (result == SOCKET_ERROR)
	{
		socket = Socket{};
	}
	return socket;
}

Socket createTcpClient(Ipv4 ipServer) noexcept
{
	Socket socket;

	if (!winsockInit())
		return socket;

	return Socket{ ipAddressClient(ipServer), udpСreateSocket() };
}

// Common

void destroy(Socket &socket)
{
	::closesocket(socket.descriptor);
	socket = Socket{};
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
