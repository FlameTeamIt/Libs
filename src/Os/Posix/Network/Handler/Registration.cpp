#include <FlameIDE/../../src/Os/Posix/Network/Handler/Registration.hpp>

#include <fcntl.h>
#include <unistd.h>

// low-level polling difinition
namespace flame_ide
{namespace os
{namespace network
{namespace posix
{namespace polling
{
namespace // anonymous
{

enum class SocketType: int
{
	Unknown = -1
	, Stream = SOCK_STREAM
	, Datagram = SOCK_DGRAM
};

SocketType getSocketType(os::SocketDescriptor descriptor) noexcept;

void pollHandler(int signalNumber, const siginfo_t *info, ucontext_t *) noexcept;

SignalActionHandler getPollHandler() noexcept;

os::Status initSignalAction(SignalAction &action) noexcept;

} // namespace anonymous
}}}}} // flame_ide::os::network::posix::polling

// private difinition
namespace flame_ide
{namespace os
{namespace network
{namespace posix
{
namespace // anonymous
{

threads::Spin globalRegistrationSpin;
Registration *globalRegistration = nullptr;

os::Status registrateSocket(os::SocketDescriptor descriptor) noexcept;

os::Status deregistrateSocket(os::SocketDescriptor descriptor);

} // namespace anonymous
}}}} // flame_ide::os::network::posix

// public implemetation
namespace flame_ide
{namespace os
{namespace network
{namespace posix
{

Registration::Registration() noexcept
{
	if (polling::initSignalAction(action) < 0)
		return;

	if (!Registration::setGlobal(*this))
		return;

	::sigaction(FLAME_SIGNAL_POLLING, &action, &oldAction);
}

Registration::~Registration() noexcept
{
	if (!Registration::resetGlobal(*this))
		return;

	::sigaction(FLAME_SIGNAL_POLLING, &oldAction, nullptr);
}

void Registration::registerUdpQueue(DescriptorIterator iterator)
{
	Registration::registerQueue(udpQueue, iterator);
}

os::SocketDescriptor Registration::popUdp() noexcept
{
	return Registration::pop(udpQueue);
}

void Registration::pushUdp(os::SocketDescriptor descriptor) noexcept
{
	push(udpQueue, descriptor);
}

void Registration::registerTcpQueue(DescriptorIterator iterator)
{
	Registration::registerQueue(tcpQueue, iterator);
}

os::SocketDescriptor Registration::popTcp() noexcept
{
	return Registration::pop(tcpQueue);
}

void Registration::pushTcp(os::SocketDescriptor descriptor) noexcept
{
	Registration::push(tcpQueue, descriptor);
}

bool Registration::setGlobal(Registration &registration) noexcept
{
	const threads::Locker locker{ globalRegistrationSpin };

	if (globalRegistration)
		return false;

	globalRegistration = &registration;
	return globalRegistration;
}

bool Registration::resetGlobal(Registration &registration) noexcept
{
	const threads::Locker locker{ globalRegistrationSpin };

	if (globalRegistration != &registration)
		return false;

	globalRegistration = nullptr;
	return !globalRegistration;
}

os::Status Registration::registrate(os::SocketDescriptor descriptor) noexcept
{
	return registrateSocket(descriptor);
}

os::Status Registration::registrate(tcp::AcceptedConnection) noexcept
{
	return os::STATUS_SUCCESS;
}

void Registration::deregistrate(os::SocketDescriptor descriptor) noexcept
{
	deregistrateSocket(descriptor);
}

void Registration::deregistrate(tcp::AcceptedConnection) noexcept
{}

//

Registration *GlobalRegistration::get()	noexcept
{
	const threads::Locker locker{ globalRegistrationSpin };
	return globalRegistration;
}

}}}} // flame_ide::os::network::posix

// low-level polling implementation
namespace flame_ide
{namespace os
{namespace network
{namespace posix
{namespace polling
{
namespace // anonymous
{

SocketType getSocketType(os::SocketDescriptor descriptor) noexcept
{
	auto type = SocketType::Unknown;
	socklen_t length = sizeof(type);

	auto result = ::getsockopt(descriptor, SOL_SOCKET, SO_TYPE, &type, &length);
	if (result < 0)
		return SocketType::Unknown;

	return type;
}

bool isSocketAcceptor(os::SocketDescriptor descriptor)
{
	int isAcceptor = 0;
	socklen_t length = sizeof(isAcceptor);

	auto result = ::getsockopt(
			descriptor, SOL_SOCKET, SO_ACCEPTCONN, &isAcceptor, &length
	);
	if (result < 0)
		return false;

	return isAcceptor;
}

void pollHandler(int signalNumber, const siginfo_t *info, ucontext_t *) noexcept
{
	if (signalNumber != FLAME_SIGNAL_POLLING)
		return;

	const os::SocketDescriptor descriptor = info->si_fd;
	switch (getSocketType(descriptor))
	{
		case SocketType::Stream:
		{
			// TODO:
			// to TCP
			if (isSocketAcceptor(descriptor))
			{
				// это серверный сокет -- пришёл сигнал о подключении
				// хотя это надо проверить
			}
			break;
		}

		case SocketType::Datagram:
		{
			globalRegistration->pushUdp(descriptor);
			break;
		}

		case SocketType::Unknown:
			return;
	}
}

SignalActionHandler getPollHandler() noexcept
{
	return reinterpret_cast<SignalActionHandler>(pollHandler);
}

os::Status initSignalAction(SignalAction &action) noexcept
{
	os::Status status = os::STATUS_SUCCESS;

	status = ::sigemptyset(&action.sa_mask);
	if (status < 0)
		return -errno;

	status = ::sigaddset(&action.sa_mask, FLAME_SIGNAL_POLLING);
	if (status < 0)
		return -errno;

	action.sa_sigaction = getPollHandler();
	action.sa_flags = SA_RESTART | SA_SIGINFO;

	return 0;
}

} // namespace anonymous
}}}}} // flame_ide::os::network::posix::polling

// private implementation
namespace flame_ide
{namespace os
{namespace network
{namespace posix
{
namespace // anonymous
{

os::Status registrateSocket(os::SocketDescriptor descriptor) noexcept
{
	os::Status result = os::STATUS_SUCCESS;
	{
		int flags = ::fcntl(descriptor, F_GETFL);
		result = ::fcntl(descriptor, F_SETFL, flags | O_ASYNC | O_NONBLOCK);
		if (result < 0)
		{
			return -errno;
		}
	}

	result = ::fcntl(descriptor, F_SETOWN, ::getpid());
	if (result < 0)
	{
		return -errno;
	}

	result = ::fcntl(descriptor, F_SETSIG, FLAME_SIGNAL_POLLING);
	if (result < 0)
	{
		return -errno;
	}

	return {};
}

os::Status deregistrateSocket(os::SocketDescriptor descriptor)
{
	os::Status result = os::STATUS_SUCCESS;
	{
		int flags = ::fcntl(descriptor, F_GETFL);
		result = ::fcntl(descriptor, F_SETFL, (~(O_ASYNC | O_NONBLOCK)) & flags);
		if (result < 0)
		{
			return -errno;
		}
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

} // namespace anonymous
}}}} // flame_ide::os::network::posix
