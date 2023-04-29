#include <FlameIDE/Os/UdpServer.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <fcntl.h>
#include <signal.h>

#include <iostream>

namespace os = flame_ide::os;
namespace templates = flame_ide::templates;

using SignalAction = struct ::sigaction;
using SignalActionHandler = decltype(SignalAction{}.sa_sigaction);

namespace // anonymous
{

const os::Socket *registredSocket = nullptr;

using os::socket::enableNonblock;
os::Status enableAsync(os::Socket &socket)
{
	{
		int flags = ::fcntl(socket.descriptor, F_GETFL);
		os::Status result = ::fcntl(socket.descriptor, F_SETFL, flags | O_ASYNC);
		if (result < 0)
		{
			return result;
		}
	}

	{
		os::Status result = ::fcntl(socket.descriptor, F_SETOWN, getpid());
		if (result < 0)
		{
			return result;
		}
	}

	{
		os::Status result = ::fcntl(socket.descriptor, F_SETSIG, SIGPOLL);
		if (result < 0)
		{
			return result;
		}
	}
	return {};
}

void signalHandler(int, const siginfo_t *info, ucontext_t *) noexcept
{
	if (info->si_signo == SIGPOLL && info->si_fd == registredSocket->descriptor)
	{
		std::cout << "signal come!" << std::endl;
	}
}

} // namespace anonymous

os::Ipv4 getServerIpv4() noexcept;
SignalAction getSignalAction(int signalNum);

int main(int /*argc*/, char */*argv*/[])
{
	const os::Ipv4 serverAddress = getServerIpv4();
	const int sigNum = SIGPOLL;
	const char messageTo[] = "pong";
	char messageFrom[sizeof("ping")];

	SignalAction action = getSignalAction(sigNum);
	::sigaction(sigNum, &action, nullptr);

	os::UdpServer server{ serverAddress.getPort() };
	{
		os::Socket socket = server.native();
		enableNonblock(socket);
		enableAsync(socket);
		registredSocket = &server.native();
	}

	std::size_t counter = 0;
	while (true)
	{
		std::cout << counter++ << std::endl;
		::siginfo_t info;
		::sigwaitinfo(&action.sa_mask, &info);

		auto client = server.wait();
		{
			auto result = client.receive(templates::makeRange<flame_ide::byte_t *>(
					reinterpret_cast<flame_ide::byte_t *>(messageFrom)
					, reinterpret_cast<flame_ide::byte_t *>(messageFrom)
						+ sizeof(messageFrom)
			));
			if (result < 0)
			{
				std::cerr << "server.receive() error " << result
						  << std::endl;
				return EXIT_FAILURE;
			}
			std::cout << "server.receive() -> " << messageTo << std::endl;
		}

		{
			auto result = client.send(templates::makeRange<const flame_ide::byte_t *>(
					reinterpret_cast<const flame_ide::byte_t *>(messageTo)
					, reinterpret_cast<const flame_ide::byte_t *>(messageTo)
							+ sizeof(messageTo)
			));
			if (result < 0)
			{
				std::cerr << "server.send(\"" << messageTo << "\") error " << result
						  << std::endl;
				return EXIT_FAILURE;
			}
			std::cout << "server.send(\"" << messageTo << "\")" << std::endl;
		}
	}

	return 0;
}

os::Ipv4 getServerIpv4() noexcept
{
	os::Ipv4::Port port = 65001;
	return os::Ipv4{ os::Ipv4::localhost(port) };
}

SignalAction getSignalAction(int signalNum)
{
	SignalAction action{};
	action.sa_sigaction = reinterpret_cast<SignalActionHandler>(signalHandler);
	::sigemptyset(&action.sa_mask);
	::sigaddset(&action.sa_mask, signalNum);
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	return action;
}
