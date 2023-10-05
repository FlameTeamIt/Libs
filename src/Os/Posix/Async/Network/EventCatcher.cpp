#include <FlameIDE/../../src/Os/Posix/Async/Network/EventCatcher.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <fcntl.h>

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

EventCatcher::EventCatcher() noexcept : os::async::network::EventCatcherBase()
		, action{ makeSigAction() }
{
	if (action.sa_flags < 0)
		return;

	status = ::sigaction(anonymous::SIGNAL_POLLING, &action, &oldAction);
	if (status < 0)
		status = -errno;
}

EventCatcher::~EventCatcher() noexcept
{
	if (status)
		return;

	::sigaction(anonymous::SIGNAL_POLLING, &oldAction, &action);
}

// private - virtual functions

os::Status EventCatcher::enable(SocketDescriptor descriptor) noexcept
{
	if (status)
		return status;

	return enableSignal(descriptor);
}

os::Status EventCatcher::disable(SocketDescriptor descriptor) noexcept
{
	if (status)
		return status;

	return disableSignal(descriptor);
}

// private - platform specific

EventCatcher::SigAction EventCatcher::makeSigAction() noexcept
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
			reinterpret_cast<SigActionHandler>(EventCatcher::signalHandler);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	return action;
}

void EventCatcher::signalHandler(int signal, const siginfo_t *info, ucontext_t *) noexcept
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

void EventCatcher::handleTcp(SocketDescriptor descriptor) noexcept
{
	using os::network::TcpServer;

	const auto serverControl = TcpServer::nativeServerControl;
	const auto socket = Socket{ {}, descriptor };
	if (!serverControl().isServer(socket))
	{
		// Signal has been received from client's socket
		EventCatcher::get().queues().tcpClients().push(descriptor);
		return;
	}
	if (!serverControl().isListener(socket))
	{
		// Signal has been received from accepted server's socket
		EventCatcher::get().queues().tcpServers().push(descriptor);
		return;
	}

	// Signal has been received from listening socket
	os::Status result = os::STATUS_SUCCESS;
	const auto client = serverControl().accept(socket, &result);
	if (result < 0)
		return;
	EventCatcher::get().queues().tcpAcceptedConnections()
			.push({ socket.descriptor, client });
	return;
}

void EventCatcher::handleUdp(SocketDescriptor descriptor) noexcept
{
	using os::network::NetworkBase;
	(NetworkBase::nativeControl().isServer(Socket{ {}, descriptor }))
			? EventCatcher::get().queues().udpServers().push(descriptor)
			: EventCatcher::get().queues().udpClients().push(descriptor);
}

os::Status EventCatcher::enableSignal(SocketDescriptor descriptor) noexcept
{
	os::Status result = os::STATUS_SUCCESS;
	int flags = ::fcntl(descriptor, F_GETFL);
	result = ::fcntl(descriptor, F_SETFL, flags | O_ASYNC | O_NONBLOCK);
	if (result < 0)
		return -errno;
	result = ::fcntl(descriptor, F_SETOWN, ::getpid());
	if (result < 0)
		return -errno;
	result = ::fcntl(descriptor, F_SETSIG, anonymous::SIGNAL_POLLING);
	if (result < 0)
		return -errno;
	return os::STATUS_SUCCESS;
}

os::Status EventCatcher::disableSignal(SocketDescriptor descriptor) noexcept
{
	os::Status result = os::STATUS_SUCCESS;
	int flags = ::fcntl(descriptor, F_GETFL);
	result = ::fcntl(descriptor, F_SETFL, (~(O_ASYNC | O_NONBLOCK)) & flags);
	if (result < 0)
		return -errno;
	result = ::fcntl(descriptor, F_SETOWN, 0);
	if (result < 0)
		return -errno;
	result = ::fcntl(descriptor, F_SETSIG, 0);
	if (result < 0)
		return -errno;
	return os::STATUS_SUCCESS;
}

}}}}} // namespace flame_ide::os::posix::async::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

EventCatcherBase &EventCatcherBase::get() noexcept
{
	static os::posix::async::network::EventCatcher catcher;
	return catcher;
}

}}}} // namespace flame_ide::os::async::network
