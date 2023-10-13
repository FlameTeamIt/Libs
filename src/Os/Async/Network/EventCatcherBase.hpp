#ifndef ASYNC_NETWORK_EVENTCATCHERBASE_HPP
#define ASYNC_NETWORK_EVENTCATCHERBASE_HPP

#include <FlameIDE/Common/ReferenceWrapper.hpp>

#include <FlameIDE/Os/Async/Network/NotificatorBase.hpp>
#include <FlameIDE/Os/Types.hpp>

#include <FlameIDE/../../src/Os/Async/Network/SocketQueues.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

///
/// @brief Interface for asynchronous catching socket events
///
class EventCatcherBase
{
public:
	virtual ~EventCatcherBase() noexcept = default;

	///
	/// @brief Enable catching events for input socket descriptor
	/// @param descriptor socket descriptor
	/// @return Status
	///
	virtual os::Status enable(SocketDescriptor descriptor) noexcept = 0;

	///
	/// @brief Disable catching events for input socket descriptor
	/// @param descriptor socket descriptor
	/// @return Status
	///
	virtual os::Status disable(SocketDescriptor descriptor) noexcept = 0;

	///
	/// @brief Getting reference of queue aggregator
	/// @return Reference of queue aggregator
	///
	SocketQueues &queues() noexcept;

	///
	/// @brief setNotifcator
	/// @param notificator
	/// @note Implementation of NotificatorBase needs thread and signal safe
	///
	void setNotificator(const NotificatorBase &notificator) noexcept;

	///
	/// @brief unsetNotifcator
	///
	void unsetNotificator() noexcept;

	///
	/// @brief notify
	///
	void notify() const noexcept;

public:
	static EventCatcherBase &get() noexcept; // platform impl

protected:
	EventCatcherBase() noexcept = default;

private:
	SocketQueues socketQueues;
	ConstReferenceWrapper<NotificatorBase> notificationObject = nullptr;
};

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_EVENTCATCHERBASE_HPP
