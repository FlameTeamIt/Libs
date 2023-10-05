#ifndef ASYNC_NETWORK_EVENTCATCHERBASE_HPP
#define ASYNC_NETWORK_EVENTCATCHERBASE_HPP

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/../../src/Os/Async/Network/SocketQueues.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

class EventCatcherBase
{
public:
	virtual ~EventCatcherBase() noexcept = default;

	virtual os::Status enable(SocketDescriptor descriptor) noexcept = 0;
	virtual os::Status disable(SocketDescriptor descriptor) noexcept = 0;

	SocketQueues &queues() noexcept;

public:
	static EventCatcherBase &get() noexcept; // platform impl

protected:
	EventCatcherBase() noexcept = default;

private:
	SocketQueues socketQueues;
};

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_EVENTCATCHERBASE_HPP
