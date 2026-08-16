#include <FlameIDE/../../src/Os/Posix/Async/Network/EventCatcher.hpp>

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>
#include <FlameIDE/Os/Async/Network/Registrar.hpp>
#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <fcntl.h>
#include <poll.h>

namespace flame_ide
{namespace os
{namespace posix
{namespace async
{namespace network
{
namespace anonymous{namespace{

static constexpr decltype(SIGPOLL) SIGNAL_POLLING = os::posix::Signal::POLL;

using BandEvent = decltype(siginfo_t{}.si_band);

enum PollingFlags: BandEvent
{
	INPUT = POLLIN
	, PRIORITY = POLLPRI
	, OUTPUT = POLLOUT
	, ERROR = POLLERR
	, HANG_UP = POLLHUP
	, INVALID_REQUEST = POLLNVAL
	, READ_NORMAL = POLLRDNORM
	, READ_PRIORITY = POLLRDBAND
	, WRITE_NORMAL = POLLWRNORM
	, WRITE_PRIORITY = POLLWRBAND
};

::flame_ide::os::async::network::EventType
convertBandEventsToAsyncEvent(BandEvent events)
{
	using ::flame_ide::os::async::network::EventType;

	if ((events & PollingFlags::ERROR) || (events & PollingFlags::INVALID_REQUEST))
		return EventType::INVALID;

	auto eventType = EventType::INIT;

	if ((events & PollingFlags::INPUT) || (events & PollingFlags::READ_NORMAL))
		eventType = EventType::READ;

	if ((events & PollingFlags::OUTPUT) || (events & PollingFlags::WRITE_NORMAL))
	{
		eventType = (eventType == EventType::READ)
				? EventType::READ_WRITE
				: EventType::WRITE;
	}

	return eventType;
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

void EventCatcher::signalHandler(
		int signal, const siginfo_t *info, ucontext_t *
) noexcept
{
	using os::network::NetworkBase;

	if (signal != anonymous::SIGNAL_POLLING)
		return;

	const auto descriptor = info->si_fd;

	/*
	POLLIN     = (bin)              1 // 0x001 // There is data to read
	POLLPRI    = (bin)             10 // 0x002 // There is urgent data to read
	POLLOUT    = (bin)            100 // 0x004 // Writing now will not block
	POLLERR    = (bin)           1000 // 0x008 // Error condition
	POLLHUP    = (bin)          10000 // 0x010 // Hung up
	POLLNVAL   = (bin)         100000 // 0x020 // Invalid polling request

	// defined __USE_XOPEN || defined __USE_XOPEN2K8
	POLLRDNORM = (bin)        1000000 // 0x040 // Normal data may be read
	POLLRDBAND = (bin)       10000000 // 0x080 // Priority data may be read
	POLLWRNORM = (bin)      100000000 // 0x100 // Writing now will not block
	POLLWRBAND = (bin)     1000000000 // 0x200 // Priority data may be written

	// __USE_GNU
	POLLMSG    = (bin)    10000000000 // 0x400
	POLLREMOVE = (bin)  1000000000000 // 0x1000
	POLLRDHUP  = (bin) 10000000000000 // 0x2000
	*/
	const auto events = info->si_band;

	switch (NetworkBase::callbacks().type(Socket{ {}, descriptor }))
	{
		case NetworkBase::SocketType::STREAM:
			handleTcp(descriptor, events);
			break;

		case NetworkBase::SocketType::DATAGRAM:
			handleUdp(descriptor, events);
			break;

		case NetworkBase::SocketType::UNKNOWN:
		default:
			return;
	}
}

void EventCatcher::handleTcp(SocketDescriptor descriptor, SigEvents events) noexcept
{
	using os::network::TcpServer;

	const auto &serverControl = TcpServer::callbacks;
	const auto socket = Socket{ {}, descriptor };
	if (!serverControl().isServer(socket))
	{
		// Signal has been received from client's socket
		EventCatcher::get().queues().tcpClients().push(
				flame_ide::os::async::network::AsyncEvent {
						descriptor
						, anonymous::convertBandEventsToAsyncEvent(events)
				}
		);
		EventCatcher::get().notify(EventCatcher::TcpClientTag{});
		return;
	}
	if (!serverControl().isListener(socket))
	{
		// Signal has been received from accepted server's socket
		EventCatcher::get().queues().tcpServers().push(
				flame_ide::os::async::network::AsyncEvent {
						descriptor
						, anonymous::convertBandEventsToAsyncEvent(events)
				}
		);
		EventCatcher::get().notify(EventCatcher::TcpServerTag{});
		return;
	}

	// Signal has been received from listening socket
	os::Status result = os::STATUS_SUCCESS;
	const auto client = serverControl().accept(socket, &result);
	if (result < 0)
		return;
	EventCatcher::get().queues().tcpAcceptedConnections()
			.push({ socket.descriptor, client });
	EventCatcher::get().notify(EventCatcher::TcpAcceptedConnectionTag{});
	return;
}

void EventCatcher::handleUdp(SocketDescriptor descriptor, SigEvents events) noexcept
{
	using os::network::NetworkBase;
	if(NetworkBase::callbacks().isServer(Socket{ {}, descriptor }))
	{
		EventCatcher::get().queues().udpServers().push(
				flame_ide::os::async::network::AsyncEvent {
						descriptor
						, anonymous::convertBandEventsToAsyncEvent(events)
				}
		);
		EventCatcher::get().notify(EventCatcher::UdpServerTag{});
	}
	else
	{
		EventCatcher::get().queues().udpClients().push(
				flame_ide::os::async::network::AsyncEvent {
						descriptor
						, anonymous::convertBandEventsToAsyncEvent(events)
				}
		);
		EventCatcher::get().notify(EventCatcher::UdpClientTag{});
	}
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
