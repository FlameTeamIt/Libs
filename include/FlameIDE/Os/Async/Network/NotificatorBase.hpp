#ifndef FLAMEIDE_OS_ASYNC_NETWORK_NOTIFICATORBASE_HPP
#define FLAMEIDE_OS_ASYNC_NETWORK_NOTIFICATORBASE_HPP

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

struct NotificatorBase
{
	virtual ~NotificatorBase() noexcept = default;
	virtual void operator()() const noexcept = 0;
};

}}}} // namespace flame_ide::os::async::network

#endif // FLAMEIDE_OS_ASYNC_NETWORK_NOTIFICATORBASE_HPP
