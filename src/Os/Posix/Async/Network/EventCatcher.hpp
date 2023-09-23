#ifndef POSIX_ASYNC_NETWORK_EVENTCATCHER_HPP
#define POSIX_ASYNC_NETWORK_EVENTCATCHER_HPP

#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

#include <signal.h>

namespace flame_ide
{namespace os
{namespace posix
{namespace async
{namespace network
{

class EventCatcher: public os::async::network::EventCatcherBase
{
public:
	EventCatcher() noexcept;
	virtual ~EventCatcher() noexcept;

private:
	virtual os::Status enable(SocketDescriptor descriptor) noexcept override;
	virtual os::Status disable(SocketDescriptor descriptor) noexcept override;

private:
	using SigAction = struct ::sigaction;
	using SigActionHandler = decltype(SigAction{}.sa_sigaction);

	static SigAction makeSigAction() noexcept;
	static void signalHandler(int signal, const siginfo_t *info, ucontext_t *) noexcept;
	static void handleTcp(SocketDescriptor descriptor) noexcept;
	static void handleUdp(SocketDescriptor descriptor) noexcept;

	static os::Status enableSignal(SocketDescriptor descriptor) noexcept;
	static os::Status disableSignal(SocketDescriptor descriptor) noexcept;

private:
	SigAction action;
	SigAction oldAction = SigAction{};
	os::Status status = os::STATUS_SUCCESS;
};

}}}}} // namespace flame_ide::os::posix::async::network

#endif // POSIX_ASYNC_NETWORK_EVENTCATCHER_HPP
