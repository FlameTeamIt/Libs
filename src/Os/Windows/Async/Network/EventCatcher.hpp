#ifndef WINDOWS_ASYNC_NETWORK_EVENTCATCHER_HPP
#define WINDOWS_ASYNC_NETWORK_EVENTCATCHER_HPP

#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

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
	using MessageValue = Types::uint_t;
	enum class Message: MessageValue
	{
		SOCKET = WM_USER + 1
		, FINISH = SOCKET + 1
	};

private:
	static os::windows::OsWindow makeWindow(const char *className) noexcept;
	static void destroyWindow(os::windows::OsWindow &window, const char *className);

	static os::windows::OsResult action(
			os::windows::OsWindowHandle window, Message message, os::SocketDescriptor socket
			, os::windows::OsParam param
	);
	static void handleUdp(os::SocketDescriptor socket, os::windows::OsParam param);
	static void handleTcp(os::SocketDescriptor socket, os::windows::OsParam param);

private:
	class MessageDispatchThread: public os::threads::ThreadCrtp<MessageDispatchThread>
	{
	public:
		MessageDispatchThread(os::windows::OsWindow &window) noexcept;

		void body() noexcept;

	private:
		os::windows::OsWindow &window;
	};

private:
	os::windows::OsWindow window;
	MessageDispatchThread thread;
};

}}}}} // namespace flame_ide::os::windows::async::network

#endif // WINDOWS_ASYNC_NETWORK_EVENTCATCHER_HPP
