#include <FlameIDE/../../src/Os/Posix/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

#include <fcntl.h>
#include <iostream>

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
os::Status checkInitialization(Descriptors &descriptors, Queue &queue)
{
	constexpr auto initValue = os::SOCKET_INVALID.descriptor;
	const os::threads::Locker locker{ queue.spin };
	if (!descriptors && !initPointerAndQueue(descriptors, queue, initValue))
		return os::STATUS_FAILED;
	return os::STATUS_SUCCESS;
}

template<typename Queue, typename Value = decltype(*Queue{}.first)>
auto popFromQueue(Queue &queue, Value initValue = {})
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
auto pushToQueue(Queue &queue, Types::size_t queueCapacity, Value value)
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
	if (anonymous::checkInitialization(udpServers, udpServersQueue) < 0)
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}

os::Status Registrar::enableUdpCleint(SocketDescriptor descriptor) noexcept
{
	if (anonymous::checkInitialization(udpClients, udpClientsQueue) < 0)
		return os::STATUS_FAILED;
	return Registrar::enableSignal(descriptor);
}
// TODO
//	os::Status Registrar::pushTcpServer(SocketDescriptor descriptor) noexcept {}
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
// TODO
//	AcceptedConnection popTcpServer() noexcept;
//	SocketDescriptor popTcpClient() noexcept;

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
	if (signal != anonymous::SIGNAL_POLLING)
		return;

	enum class SocketType: int
	{
		Unknown = -1
		, Stream = SOCK_STREAM
		, Datagram = SOCK_DGRAM
	};
	const auto descriptor = info->si_fd;
	auto socketType = SocketType::Unknown;
	bool isAcceptor = false;
	bool isServer = false;
	{
		auto socketGetType = [](os::SocketDescriptor descriptor) -> SocketType
		{
			auto type = SocketType::Unknown;
			socklen_t length = sizeof(type);

			auto result = ::getsockopt(descriptor, SOL_SOCKET, SO_TYPE, &type, &length);
			if (result < 0)
				return SocketType::Unknown;

			return type;
		};
		socketType = socketGetType(descriptor);

		auto socketIsServer = [](os::SocketDescriptor descriptor) -> bool
		{
			int isServer = false;
			socklen_t length = sizeof(isServer);
			auto result = ::getsockopt(
					descriptor, SOL_SOCKET, SO_REUSEADDR, &isServer, &length
			);
			if (result < 0)
				return false;
			return isServer;
		};
		isServer = socketIsServer(descriptor);

		auto socketIsAcceptor = [](os::SocketDescriptor descriptor) -> bool
		{
			int isAcceptor = 0;
			socklen_t length = sizeof(isAcceptor);
			auto result = ::getsockopt(
					descriptor, SOL_SOCKET, SO_ACCEPTCONN, &isAcceptor, &length
			);
			if (result < 0)
				return false;
			return isAcceptor;
		};
		isAcceptor = socketIsAcceptor(descriptor);
	}

	switch (socketType)
	{
		case SocketType::Stream:
		{
			// TODO:
			// to TCP
			if (isAcceptor)
			{
				// это серверный сокет -- пришёл сигнал о подключении
				// хотя это надо проверить

				// accept();
				// Registrar::get().pushTcpServer(descriptor);
				return;
			}
			// Registrar::get().pushTcpClient(descriptor);
			break;
		}

		case SocketType::Datagram:
		{
			if (isServer)
			{
				Registrar::get().pushUdpServer(descriptor);
				return;
			}
			Registrar::get().pushUdpClient(descriptor);
			break;
		}

		case SocketType::Unknown:
			return;
	}
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
// TODO
//	bool Registrar::pushTcpServer(AcceptedConnection connection) noexcept {}
//	bool Registrar::pushTcpClient(SocketDescriptor connection) noexcept {}

}}}}} // namespace flame_ide::os::posix::async::network
