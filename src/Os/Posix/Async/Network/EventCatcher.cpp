#include <FlameIDE/../../src/Os/Posix/Async/Network/EventCatcher.hpp>

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>
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

static constexpr decltype(SIGPOLL) SIGNAL_POLLING = os::posix::Signal::POLL;

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

	/*
	https://man7.org/linux/man-pages/man2/sigaction.2.html

	The following values can be placed in si_code for a SIGIO/SIGPOLL
	signal:

		POLL_IN
			Data input available.

		POLL_OUT
			Output buffers available.

		POLL_MSG
			Input message available.

		POLL_ERR
			I/O error.

		POLL_PRI
			High priority input available.

		POLL_HUP
			Device disconnected.
	*/
	const auto code = info->si_code;

	/*
	https://man7.org/linux/man-pages/man2/poll.2.html

	The bits that may be set/returned in events and revents are defined in <poll.h>:

		POLLIN There is data to read.

		POLLPRI
			There is some exceptional condition on the file descriptor.
			Possibilities include:
			•  There is out-of-band data on a TCP socket (see tcp(7)).
			•  A pseudoterminal master in packet mode has seen a state
			change on the slave (see ioctl_tty(2)).
			•  A cgroup.events file has been modified (see cgroups(7)).

		POLLOUT
			Writing is now possible, though a write larger than the
			available space in a socket or pipe will still block
			(unless O_NONBLOCK is set).

		POLLRDHUP (since Linux 2.6.17)
			Stream socket peer closed connection, or shut down writing
			half of connection.  The _GNU_SOURCE feature test macro
			must be defined (before including any header files) in
			order to obtain this definition.

		POLLERR
			Error condition (only returned in revents; ignored in
			events).  This bit is also set for a file descriptor
			referring to the write end of a pipe when the read end has
			been closed.

		POLLHUP
			Hang up (only returned in revents; ignored in events).
			Note that when reading from a channel such as a pipe or a
			stream socket, this event merely indicates that the peer
			closed its end of the channel.  Subsequent reads from the
			channel will return 0 (end of file) only after all
			outstanding data in the channel has been consumed.

		POLLNVAL
			Invalid request: fd not open (only returned in revents;
			ignored in events).

	When compiling with _XOPEN_SOURCE defined, one also has the
	following, which convey no further information beyond the bits
	listed above:

		POLLRDNORM
			Equivalent to POLLIN.

		POLLRDBAND
			Priority band data can be read (generally unused on Linux).

		POLLWRNORM
			Equivalent to POLLOUT.

		POLLWRBAND
			Priority data may be written.
	*/
	const auto events = info->si_band;
	flame_ide::unused(code, events);

	switch (NetworkBase::callbacks().type(Socket{ {}, descriptor }))
	{
		case NetworkBase::SocketType::STREAM:
			handleTcp(descriptor);
			break;

		case NetworkBase::SocketType::DATAGRAM:
			handleUdp(descriptor);
			break;

		case NetworkBase::SocketType::UNKNOWN:
		default:
			return;
	}
}

void EventCatcher::handleTcp(SocketDescriptor descriptor) noexcept
{
	using os::network::TcpServer;

	const auto &serverControl = TcpServer::callbacks;
	const auto socket = Socket{ {}, descriptor };
	if (!serverControl().isServer(socket))
	{
		// Signal has been received from client's socket
		EventCatcher::get().queues().tcpClients().push(descriptor);
		EventCatcher::get().notify(EventCatcher::TcpClientTag{});
		return;
	}
	if (!serverControl().isListener(socket))
	{
		// Signal has been received from accepted server's socket
		EventCatcher::get().queues().tcpServers().push(descriptor);
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

void EventCatcher::handleUdp(SocketDescriptor descriptor) noexcept
{
	using os::network::NetworkBase;
	if(NetworkBase::callbacks().isServer(Socket{ {}, descriptor }))
	{
		EventCatcher::get().queues().udpServers().push(descriptor);
		EventCatcher::get().notify(EventCatcher::UdpServerTag{});
	}
	else
	{
		EventCatcher::get().queues().udpClients().push(descriptor);
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
