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

template<typename Pointer, typename Queue, typename Value>
inline bool initPointerAndQueue(Pointer &pointer, Queue &queue, Value initValue)
{
	pointer = Pointer{};
	if (!pointer)
		return false;

	if (initValue)
		for (auto &i : *pointer)
			i = initValue;

	queue.first = decltype(queue.first) {
			pointer->data()
			, templates::makeRange(
					pointer->data()
					, pointer->data() + pointer->capacity()
			)
	};
	queue.last = queue.first;

	return true;
}

template<
	typename Descriptors, typename Queue, typename Value = decltype(*Queue{}.first)
>
inline os::Status checkInitialization(
		Descriptors &descriptors, Queue &queue, Value &&value
)
{
	const os::threads::Locker locker{ queue.spin };
	if (!descriptors && !initPointerAndQueue(descriptors, queue, value))
		return os::STATUS_FAILED;
	return os::STATUS_SUCCESS;
}

template<typename Queue, typename Value = decltype(*Queue{}.first)>
inline auto popFromQueue(Queue &queue, Value initValue = {})
{
	os::threads::Locker locker{ queue.spin };

	if (!queue.count)
		return initValue;
	--queue.count;

	auto &first = queue.first;
	const Value value = *first;
	*first = initValue;
	++first;
	return value;
}

template<typename Queue, typename Value = decltype(*Queue{}.first)>
inline auto pushToQueue(Queue &queue, Types::size_t queueCapacity, Value value)
{
	os::threads::Locker locker{ queue.spin };

	if (queue.count >= queueCapacity)
		return false;
	++queue.count;

	auto &last = queue.last;
	*last = value;
	++last;
	return true;
}

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
	if (0 > anonymous::checkInitialization(
			udpServers, udpServersQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableUdpCleint(SocketDescriptor descriptor) noexcept
{
	if (0 > anonymous::checkInitialization(
			udpClients, udpClientsQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableTcpServerAcceptor(SocketDescriptor descriptor) noexcept
{
	if (0 > anonymous::checkInitialization(
			tcpServerAcceptions, tcpServerAcceptionsQueue, AcceptedConnection{}
	))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableTcpServer(SocketDescriptor descriptor) noexcept
{
	if (0 > anonymous::checkInitialization(
			tcpServers, tcpServersQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}
// TODO
//	os::Status Registrar::pushTcpClient(SocketDescriptor descriptor) noexcept {}

os::Status Registrar::disableSocket(SocketDescriptor descriptor) noexcept
{
	return Registrar::disableSignal(descriptor);
}

SocketDescriptor Registrar::popUdpServer() noexcept
{
	return anonymous::popFromQueue(
			udpServersQueue, os::SOCKET_INVALID.descriptor
	);
}

SocketDescriptor Registrar::popUdpCleint() noexcept
{
	return anonymous::popFromQueue(
			udpClientsQueue, os::SOCKET_INVALID.descriptor
	);
}

Registrar::AcceptedConnection Registrar::popTcpServerAcception() noexcept
{
	return anonymous::popFromQueue(
			tcpServerAcceptionsQueue, AcceptedConnection{}
	);
}

SocketDescriptor Registrar::popTcpServer() noexcept
{
	return anonymous::popFromQueue(
			tcpServersQueue, os::SOCKET_INVALID.descriptor
	);
}

// TODO
//	SocketDescriptor Registrar::popTcpClient() noexcept;

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
		// TODO
		// Сигнал пришёл от клиентского сокета
		// Registrar::get().pushTcpClient(descriptor);
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
	return anonymous::pushToQueue(udpServersQueue, udpServers->capacity(), descriptor);
}

bool Registrar::pushUdpClient(SocketDescriptor descriptor) noexcept
{
	return anonymous::pushToQueue(udpClientsQueue, udpClients->capacity(), descriptor);
}

bool Registrar::pushTcpServerAcception(AcceptedConnection connection) noexcept
{
	return anonymous::pushToQueue(tcpServerAcceptionsQueue, tcpServerAcceptions->capacity(), connection);
}

bool Registrar::pushTcpServer(SocketDescriptor descriptor) noexcept
{
	return anonymous::pushToQueue(tcpServersQueue, tcpServers->capacity(), descriptor);
}
// TODO
//	bool Registrar::pushTcpClient(SocketDescriptor connection) noexcept {}

}}}}} // namespace flame_ide::os::posix::async::network
