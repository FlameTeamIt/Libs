#include <FlameIDE/../../src/Os/Posix/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

#include <fcntl.h>
#include <poll.h>

namespace flame_ide
{namespace os
{namespace posix
{namespace async
{namespace network
{
namespace anonymous{namespace{

static constexpr decltype(SIGPOLL) SIGNAL_POLLING = SIGPOLL;

}} // namespace anonymous
}}}}} // namespace flame_ide::os::posix::async::network

namespace flame_ide
{namespace os
{namespace posix
{namespace async
{namespace network
{

// public

Registrar::~Registrar() noexcept
{
	auto result = ::sigaction(anonymous::SIGNAL_POLLING, &oldAction, &action);
	if (result < 0)
		result = -errno;
	(void)result;
}

Registrar::operator bool() const noexcept
{
	return status == os::STATUS_SUCCESS;
}

Registrar &Registrar::get() noexcept
{
	static Registrar registrar;
	return registrar;
}

os::Status Registrar::enableUdpServer(SocketDescriptor descriptor) noexcept
{
	if (!udpServers && !udpServers.init(os::SOCKET_INVALID.descriptor))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableUdpCleint(SocketDescriptor descriptor) noexcept
{
	if (udpClients && !udpClients.init(os::SOCKET_INVALID.descriptor))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableTcpServerAcceptor(SocketDescriptor descriptor) noexcept
{
	if (tcpServerAcceptions && !tcpServerAcceptions.init())
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableTcpServer(SocketDescriptor descriptor) noexcept
{
	if (tcpServers && !tcpServers.init(os::SOCKET_INVALID.descriptor))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableTcpClient(SocketDescriptor descriptor) noexcept
{
	if (tcpClients && !tcpClients.init(os::SOCKET_INVALID.descriptor))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::disableSocket(SocketDescriptor descriptor) noexcept
{
	return Registrar::disableSignal(descriptor);
}

SocketDescriptor Registrar::popUdpServer() noexcept
{
	SocketDescriptor result = os::SOCKET_INVALID.descriptor;
	udpServers.pop(result).ifResult(
			[&result](SocketDescriptor &&descriptor)
			{
				result = descriptor;
			}
	).done();
	return result;
}

SocketDescriptor Registrar::popUdpCleint() noexcept
{
	SocketDescriptor result = os::SOCKET_INVALID.descriptor;
	udpClients.pop(result).ifResult(
			[&result](SocketDescriptor &&descriptor)
			{
				result = descriptor;
			}
	).done();
	return result;
}

Registrar::AcceptedConnection Registrar::popTcpServerAcception() noexcept
{
	AcceptedConnection result;
	tcpServerAcceptions.pop(result).ifResult(
			[&result](AcceptedConnection &&connection)
			{
				result = connection;
			}
	).done();
	return result;
}

SocketDescriptor Registrar::popTcpServer() noexcept
{
	SocketDescriptor result = os::SOCKET_INVALID.descriptor;
	tcpServers.pop(result).ifResult(
			[&result](SocketDescriptor &&descriptor)
			{
				result = descriptor;
			}
	).done();
	return result;
}

SocketDescriptor Registrar::popTcpClient() noexcept
{
	SocketDescriptor result = os::SOCKET_INVALID.descriptor;
	tcpClients.pop(result).ifResult(
			[&result](SocketDescriptor &&descriptor)
			{
				result = descriptor;
			}
	).done();
	return result;
}

// private - Constructor

Registrar::Registrar() noexcept : action{ Registrar::makeSigAction() }
{
	auto result = ::sigaction(anonymous::SIGNAL_POLLING, &action, &oldAction);
	if (result < 0)
		status = -errno;
	(void)result;
}

// private - SignalAction

Registrar::SigAction Registrar::makeSigAction() noexcept
{
	auto action = SigAction{};
	auto status = os::STATUS_SUCCESS;
	status = ::sigemptyset(&action.sa_mask);
	if (status < 0)
	{
		action.sa_flags = -errno;
		return action;
	}
	status = ::sigaddset(&action.sa_mask, anonymous::SIGNAL_POLLING);
	if (status < 0)
	{
		action.sa_flags = -errno;
		return action;
	}
	action.sa_sigaction =
			reinterpret_cast<SigActionHandler>(Registrar::signalHandler);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	return action;
}

void Registrar::signalHandler(int signal, const siginfo_t *info, ucontext_t *) noexcept
{
	using os::network::NetworkBase;

	if (signal != anonymous::SIGNAL_POLLING)
		return;

	const auto descriptor = info->si_fd;
	switch (NetworkBase::nativeControl().type(Socket{ {}, descriptor }))
	{
		case NetworkBase::SocketType::STREAM:
			handleTcp(descriptor);
			return;

		case NetworkBase::SocketType::DATAGRAM:
			handleUdp(descriptor);
			return;

		case NetworkBase::SocketType::UNKNOWN:
			return;
	}
}

void Registrar::handleTcp(SocketDescriptor descriptor) noexcept
{
	using os::network::TcpServer;

	const auto serverControl = TcpServer::nativeServerControl;
	const auto socket = Socket{ {}, descriptor };
	if (!serverControl().isServer(socket))
	{
		// Сигнал пришёл от клиентского сокета
		Registrar::get().pushTcpClient(descriptor);
		return;
	}
	if (!serverControl().isAcceptor(socket))
	{
		// Сигнал пришёл от сокета, который получен через accept()
		Registrar::get().pushTcpServer(descriptor);
		return;
	}

	// Сигнал пришёл от сокета-акцептора
	os::Status result = os::STATUS_SUCCESS;
	const auto client = serverControl().accept(socket, &result);
	if (result < 0)
		return;
	Registrar::get().pushTcpServerAcception(
			AcceptedConnection{ socket.descriptor, client }
	);
	return;
}

void Registrar::handleUdp(SocketDescriptor descriptor) noexcept
{
	using os::network::NetworkBase;
	(NetworkBase::nativeControl().isServer(Socket{ {}, descriptor }))
			? Registrar::get().pushUdpServer(descriptor)
			: Registrar::get().pushUdpClient(descriptor);
}

os::Status Registrar::enableSignal(SocketDescriptor descriptor) noexcept
{
	os::Status result = os::STATUS_SUCCESS;
	int flags = ::fcntl(descriptor, F_GETFL);
	result = ::fcntl(descriptor, F_SETFL, flags | O_ASYNC | O_NONBLOCK);
	if (result < 0)
	{
		return -errno;
	}
	result = ::fcntl(descriptor, F_SETOWN, ::getpid());
	if (result < 0)
	{
		return -errno;
	}
	result = ::fcntl(descriptor, F_SETSIG, anonymous::SIGNAL_POLLING);
	if (result < 0)
	{
		return -errno;
	}
	return os::STATUS_SUCCESS;
}

os::Status Registrar::disableSignal(SocketDescriptor descriptor) noexcept
{
	os::Status result = os::STATUS_SUCCESS;
	int flags = ::fcntl(descriptor, F_GETFL);
	result = ::fcntl(descriptor, F_SETFL, (~(O_ASYNC | O_NONBLOCK)) & flags);
	if (result < 0)
	{
		return -errno;
	}
	result = ::fcntl(descriptor, F_SETOWN, 0);
	if (result < 0)
	{
		return -errno;
	}
	result = ::fcntl(descriptor, F_SETSIG, 0);
	if (result < 0)
	{
		return -errno;
	}
	return os::STATUS_SUCCESS;
}

// private - push sockets

bool Registrar::pushUdpServer(SocketDescriptor descriptor) noexcept
{
	return udpServers.push(descriptor);
}

bool Registrar::pushUdpClient(SocketDescriptor descriptor) noexcept
{
	return udpClients.push(descriptor);
}

bool Registrar::pushTcpServerAcception(AcceptedConnection connection) noexcept
{
	return tcpServerAcceptions.push(connection);
}

bool Registrar::pushTcpServer(SocketDescriptor descriptor) noexcept
{
	return tcpServers.push(descriptor);
}

bool Registrar::pushTcpClient(SocketDescriptor descriptor) noexcept
{
	return tcpClients.push(descriptor);
}

}}}}} // namespace flame_ide::os::posix::async::network
