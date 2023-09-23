#ifndef POSIX_REGISTRAR_HPP
#define POSIX_REGISTRAR_HPP

#include <FlameIDE/Common/Macros/DetectOs.hpp>

#if FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#include <FlameIDE/../../src/Os/Async/Network/Types.hpp>
#include <FlameIDE/../../src/Os/Async/Network/QueuedArray.hpp>

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

private: // TODO: Move to platform specific
	using SigAction = struct ::sigaction;
	using SigActionHandler = decltype(SigAction{}.sa_sigaction);

	static SigAction makeSigAction() noexcept;
	static void signalHandler(int signal, const siginfo_t *info, ucontext_t *) noexcept;
	static void handleTcp(SocketDescriptor descriptor) noexcept;
	static void handleUdp(SocketDescriptor descriptor) noexcept;

	static os::Status enableSignal(SocketDescriptor descriptor) noexcept;
	static os::Status disableSignal(SocketDescriptor descriptor) noexcept;

private:
	bool pushUdpServer(SocketDescriptor descriptor) noexcept;
	bool pushUdpClient(SocketDescriptor descriptor) noexcept;
	bool pushTcpServerAcception(AcceptedConnection connection) noexcept;
	bool pushTcpServer(SocketDescriptor connection) noexcept;
	bool pushTcpClient(SocketDescriptor connection) noexcept;

private:
	SigAction action;
	SigAction oldAction = SigAction{};
	os::Status status = os::STATUS_SUCCESS;

private:
	template<typename Array>
	using Queue = os::async::network::ConcreteQueueArrayByArray<Array>;

	using UdpServers = Queue<os::async::network::UdpServers>;
	using UdpClients = Queue<os::async::network::UdpClients>;
	using AcceptedConnections = Queue<os::async::network::AcceptedConnections>;
	using TcpServers = Queue<os::async::network::TcpServers>;
	using TcpClients = Queue<os::async::network::TcpClients>;

	UdpServers udpServers;
	UdpClients udpClients;
	AcceptedConnections tcpServerAcceptions;
	TcpServers tcpServers;
	TcpClients tcpClients;
};

}}}}} // namespace flame_ide::os::posix::async::network

#define FLAMEIDE_REGISTAR_NAMESPACE flame_ide::os::posix::async::network

#endif // FLAMEIDE_OS_POSIX != FLAMEIDE_OS_NULL

#endif // POSIX_REGISTRAR_HPP
