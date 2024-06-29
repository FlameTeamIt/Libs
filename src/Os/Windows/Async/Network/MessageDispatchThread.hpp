#ifndef WINDOWS_ASYNC_NETWORK_MESSAGEDISPATCHTHREAD_HPP
#define WINDOWS_ASYNC_NETWORK_MESSAGEDISPATCHTHREAD_HPP

#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{

// Events

enum class Event
{
	UNKNOWN = -1
	, ACCEPT = FD_ACCEPT
	, CONNECT = FD_CONNECT
	, READ = FD_READ
	, WRITE = FD_WRITE
	, CLOSE = FD_CLOSE
};

inline constexpr auto value(Event event) -> decltype(FD_ACCEPT)
{
	using EventValue = decltype(FD_ACCEPT);
	return static_cast<EventValue>(event);
}

inline constexpr Event event(os::windows::OsParam param)
{
	return static_cast<Event>(WSAGETSELECTEVENT(param));
}

inline constexpr Event operator|(Event event1, Event event2)
{
	return static_cast<Event>(value(event1) | value(event2));
}

// Messages

using MessageValue = Types::uint_t;
enum class Message: MessageValue
{
	SOCKET = WM_USER + 1
	, FINISH = SOCKET + 1
};

class MessageDispatchThread: public os::threads::ThreadCrtp<MessageDispatchThread>
{
public:
	MessageDispatchThread() noexcept;

	void body() noexcept;

public:
	const os::windows::OsWindow &getWindow() const noexcept;
	void wait() const noexcept;
	void stop() noexcept;

private:
	void init() noexcept;
	void destroy() noexcept;

	bool isWindowInited() const noexcept;

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
	mutable os::threads::Spin spin;
	os::windows::OsWindow window;
	bool started = false;
};

}}}}} // namespace flame_ide::os::windows::async::network

#endif // WINDOWS_ASYNC_NETWORK_MESSAGEDISPATCHTHREAD_HPP
