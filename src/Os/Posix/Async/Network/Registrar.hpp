#ifndef POSIX_REGISTRAR_HPP
#define POSIX_REGISTRAR_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/Async/Network/Types.hpp>

#include <signal.h>

namespace flame_ide
{namespace os
{namespace posix
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
	// TODO
//	os::Status enableTcpServer(SocketDescriptor descriptor) noexcept;
//	os::Status enableTcpClient(SocketDescriptor descriptor) noexcept;

	os::Status disableSocket(SocketDescriptor descriptor) noexcept;

	SocketDescriptor popUdpServer() noexcept;
	SocketDescriptor popUdpCleint() noexcept;
	// TODO
//	AcceptedConnection popTcpServer() noexcept;
//	SocketDescriptor popTcpClient() noexcept;

private:
	Registrar() noexcept;

private:
	using SigAction = struct ::sigaction;
	using SigActionHandler = decltype(SigAction{}.sa_sigaction);

	static SigAction makeSigAction() noexcept;

	static void signalHandler(
			int signalNumber, const siginfo_t *info, ucontext_t *
	) noexcept;

	static os::Status enableSignal(SocketDescriptor descriptor) noexcept;
	static os::Status disableSignal(SocketDescriptor descriptor) noexcept;

private:
	bool pushUdpServer(SocketDescriptor descriptor) noexcept;
	bool pushUdpClient(SocketDescriptor descriptor) noexcept;
	// TODO
//	bool pushTcpServer(AcceptedConnection connection) noexcept;
//	bool pushTcpClient(SocketDescriptor connection) noexcept;

private:
	SigAction action;
	SigAction oldAction = SigAction{};
	os::Status status = os::STATUS_SUCCESS;

private:
	using UdpServers = os::async::network::UdpServers;
	using UdpClients = os::async::network::UdpClients;
	using AcceptedConnections = os::async::network::AcceptedConnections;
	using TcpClients = os::async::network::TcpClients;

	UdpServers udpServers = UdpServers::makeEmpty();
	UdpClients udpClients = UdpClients::makeEmpty();
	// TODO
//	AcceptedConnections tcpServers = AcceptedConnections::makeEmpty();
//	TcpServers tcpClients = TcpClients::makeEmpty();

private:
	template<typename IteratorType>
	using Queue = os::async::network::Queue<IteratorType>;

	Queue<os::async::network::DescriptorIterator> udpServersQueue;
	Queue<os::async::network::DescriptorIterator> udpClientsQueue;
	// TODO
//	Queue<os::async::network::AcceptedConnectionInterator> tcpServersQueue;
//	Queue<os::async::network::DescriptorIterator> tcpClientsQueue;
};

}}}}} // namespace flame_ide::os::posix::async::network

#define FLAMEIDE_REGISTAR_NAMESPACE flame_ide::os::posix::async::network

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // POSIX_REGISTRAR_HPP
