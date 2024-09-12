#ifndef WINDOWS_ASYNC_NETWORK_EVENTCATCHER_HPP
#define WINDOWS_ASYNC_NETWORK_EVENTCATCHER_HPP

#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>
#include <FlameIDE/../../src/Os/Windows/Async/Network/MessageDispatchThread.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

namespace flame_ide
{namespace os
{namespace windows
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
	MessageDispatchThread thread;
};

}}}}} // namespace flame_ide::os::windows::async::network

#endif // WINDOWS_ASYNC_NETWORK_EVENTCATCHER_HPP
