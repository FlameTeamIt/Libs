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

void EventCatcherBase::setNotificator(const NotificatorBase &inputNotificator) noexcept
{
	notificationObject = decltype(notificationObject)(inputNotificator);
}

void EventCatcherBase::unsetNotificator() noexcept
{
	notificationObject = decltype(notificationObject)(nullptr);
}

// protected

void EventCatcherBase::notify() const noexcept
{
	if (notificationObject)
		notificationObject.get()();
}

}}}} // namespace flame_ide::os::async::network
