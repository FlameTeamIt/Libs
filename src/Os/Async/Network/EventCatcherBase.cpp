#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

SocketQueues &EventCatcherBase::queues() noexcept
{
	return socketQueues;
}

}}}} // namespace flame_ide::os::async::network
