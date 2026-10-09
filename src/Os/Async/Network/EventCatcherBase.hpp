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
	using UdpServerTag = tag::UdpServer;
	using UdpClientTag = tag::UdpClient;
	using TcpServerTag = tag::TcpServer;
	using TcpAcceptedConnectionTag = tag::TcpAcceptedConnection;
	using TcpClientTag = tag::TcpServer;

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
	void setNotificator(UdpServerNotificatorBase &notificator) noexcept;
	void setNotificator(UdpClientNotificatorBase &notificator) noexcept;
	void setNotificator(TcpServerNotificatorBase &notificator) noexcept;
	void setNotificator(TcpAcceptedConnectionNotificatorBase &notificator) noexcept;
	void setNotificator(TcpClientNotificatorBase &notificator) noexcept;

	///
	/// @brief unsetNotifcator
	///
	void unsetNotificator(tag::UdpServer) noexcept;
	void unsetNotificator(tag::UdpClient) noexcept;
	void unsetNotificator(tag::TcpServer) noexcept;
	void unsetNotificator(tag::TcpAcceptedConnection) noexcept;
	void unsetNotificator(tag::TcpClient) noexcept;

	///
	/// @brief unsetNotifcators
	///
	void unsetNotificators() noexcept;

	///
	/// @brief notify
	///
	void notify(tag::UdpServer) const noexcept;
	void notify(tag::UdpClient) const noexcept;
	void notify(tag::TcpServer) const noexcept;
	void notify(tag::TcpAcceptedConnection) const noexcept;
	void notify(tag::TcpClient) const noexcept;

public:
	static EventCatcherBase &get() noexcept; // platform impl

protected:
	EventCatcherBase() noexcept = default;

private:
	SocketQueues socketQueues;
	struct
	{
		ReferenceWrapper<UdpServerNotificatorBase> udpServer = nullptr;
		ReferenceWrapper<UdpClientNotificatorBase> udpClient = nullptr;
		ReferenceWrapper<TcpServerNotificatorBase> tcpServer = nullptr;
		ReferenceWrapper<TcpAcceptedConnectionNotificatorBase>
				tcpAcceptedConnection = nullptr;
		ReferenceWrapper<TcpClientNotificatorBase> tcpClient = nullptr;
	} notificationObjects;
};

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_EVENTCATCHERBASE_HPP
