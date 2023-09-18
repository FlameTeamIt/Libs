#ifndef WINDOWS_REGISTRAR_HPP
#define WINDOWS_REGISTRAR_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#include <FlameIDE/../../src/Os/Async/Network/Types.hpp>

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{

class Registrar
{
public:
	using AcceptedConnection = os::async::network::AcceptedConnection;

public:
	~Registrar() noexcept;

	operator bool() const noexcept;

	static Registrar &get() noexcept;

	os::Status enableUdpServer(SocketDescriptor descriptor) noexcept;
	os::Status enableUdpCleint(SocketDescriptor descriptor) noexcept;
	os::Status enableTcpServerAcceptor(SocketDescriptor descriptor) noexcept;
	os::Status enableTcpServer(SocketDescriptor descriptor) noexcept;
	os::Status enableTcpClient(SocketDescriptor descriptor) noexcept;

	os::Status disableSocket(SocketDescriptor descriptor) noexcept;

	SocketDescriptor popUdpServer() noexcept;
	SocketDescriptor popUdpCleint() noexcept;
	AcceptedConnection popTcpServerAcception() noexcept;
	SocketDescriptor popTcpServer() noexcept;
	SocketDescriptor popTcpClient() noexcept;

private:
	Registrar() noexcept;

private:
	// System-depend methods
	static os::windows::OsWindow makeWindow() noexcept;

	static os::windows::OsResult action(
		os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
			, os::windows::OsParam param
	);
	static os::windows::OsResult handleUdp(
		os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
			, os::windows::OsParam param
	);
	static os::windows::OsResult handleTcpAcceptor(
		os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
			, os::windows::OsParam param
	);
	static os::windows::OsResult handleTcp(
		os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
			, os::windows::OsParam param
	);

private:
	bool pushUdpServer(SocketDescriptor descriptor) noexcept;
	bool pushUdpClient(SocketDescriptor descriptor) noexcept;
	bool pushTcpServerAcception(AcceptedConnection connection) noexcept;
	bool pushTcpServer(SocketDescriptor connection) noexcept;
	bool pushTcpClient(SocketDescriptor connection) noexcept;

private:
	// System-depend members
	os::windows::OsWindow window;

private:
	using UdpServers = os::async::network::UdpServers;
	using UdpClients = os::async::network::UdpClients;
	using AcceptedConnections = os::async::network::AcceptedConnections;
	using TcpServers = os::async::network::TcpServers;
	using TcpClients = os::async::network::TcpClients;

	UdpServers udpServers = UdpServers::makeEmpty();
	UdpClients udpClients = UdpClients::makeEmpty();
	AcceptedConnections tcpServerAcceptions = AcceptedConnections::makeEmpty();
	TcpServers tcpServers = TcpServers::makeEmpty();
	TcpClients tcpClients = TcpClients::makeEmpty();

private:
	template<typename IteratorType>
	using Queue = os::async::network::Queue<IteratorType>;

	Queue<os::async::network::DescriptorIterator> udpServersQueue;
	Queue<os::async::network::DescriptorIterator> udpClientsQueue;
	Queue<os::async::network::AcceptedConnectionInterator> tcpServerAcceptionsQueue;
	Queue<os::async::network::DescriptorIterator> tcpServersQueue;
	Queue<os::async::network::DescriptorIterator> tcpClientsQueue;
};

}}}}} // namespace flame_ide::os::windows::async::network

#define FLAMEIDE_REGISTAR_NAMESPACE flame_ide::os::windows::async::network

#endif // FLAMEIDE_OS_CURRENT == FLAMEIDE_OS_WINDOWS

#endif // WINDOWS_REGISTRAR_HPP
