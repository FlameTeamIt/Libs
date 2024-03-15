#include <FlameIDE/../../src/Os/Windows/Async/Network/EventCatcher.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{namespace anonymous{ namespace{

const char WINDOW_CLASS_NAME[] = "AsyncSelect";

enum class Event
{
	UNKNOWN = -1
	, ACCEPT = FD_ACCEPT
	, CONNECT = FD_CONNECT
	, READ = FD_READ
	, WRITE = FD_WRITE
	, CLOSE = FD_CLOSE
};

inline Event event(os::windows::OsParam param)
{
	return static_cast<Event>(WSAGETSELECTEVENT(param));
}

inline auto value(Event event) -> decltype(FD_ACCEPT)
{
	using EventValue = decltype(FD_ACCEPT);
	return static_cast<EventValue>(event);
}

inline Event operator|(Event event1, Event event2)
{
	return static_cast<Event>(value(event1) | value(event2));
}

}} // namespace anonymous
}}}}} // namespace flame_ide::os::windows::async::network

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{

// public

EventCatcher::EventCatcher() noexcept : os::async::network::EventCatcherBase()
{
	thread.run();
	thread.wait();
}

EventCatcher::~EventCatcher() noexcept
{
	if (!thread.getWindow().handle)
		return;

	thread.stop();
	thread.join();
}

// private - virutal functions

os::Status EventCatcher::enable(SocketDescriptor descriptor) noexcept
{
	auto socket = Socket{ descriptor, {} };
	auto event = anonymous::Event::UNKNOWN;

	const auto &control = os::network::NetworkBase::callbacks();
	const auto type = control.type(Socket{ descriptor, {} });
	switch(type)
	{
		case os::network::NetworkBase::SocketType::DATAGRAM:
			event = anonymous::Event::READ | anonymous::Event::WRITE;
			break;

		case os::network::NetworkBase::SocketType::STREAM:
		{
			if (control.isListener(socket))
				event = anonymous::Event::ACCEPT;
			else
				if (control.isServer)
					event = anonymous::Event::READ | anonymous::Event::WRITE;
				else
					event = anonymous::Event::READ | anonymous::Event::WRITE
							| anonymous::Event::CONNECT;
			break;
		}

		case os::network::NetworkBase::SocketType::UNKNOWN:
		default:
			break;
	}

	const auto handle = thread.getWindow().handle;
	if (!handle)
		return os::STATUS_FAILED;

	constexpr auto MESSAGE_SOCKET = static_cast<MessageValue>(Message::SOCKET);
	os::Status result = os::STATUS_SUCCESS;
	result = ::WSAAsyncSelect(
			descriptor, handle, MESSAGE_SOCKET, anonymous::value(event)
	);
	if (result == SOCKET_ERROR)
		result = -static_cast<os::Status>(::GetLastError());
	return result;
}

os::Status EventCatcher::disable(SocketDescriptor descriptor) noexcept
{
	const auto handle = thread.getWindow().handle;
	if (!handle)
		return os::STATUS_FAILED;

	if (SOCKET_ERROR == ::WSAAsyncSelect(descriptor, handle, 0, 0))
		return -static_cast<os::Status>(::GetLastError());
	return os::STATUS_SUCCESS;
}

}}}}} // namespace flame_ide::os::windows::async::network

// MessageDispatchThread
namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{

// public - thread

EventCatcher::MessageDispatchThread::MessageDispatchThread() noexcept
{}

void EventCatcher::MessageDispatchThread::body() noexcept
{
	constexpr auto MESSAGE_VALUE_MIN = static_cast<MessageValue>(Message::SOCKET);
	constexpr auto MESSAGE_VALUE_MAX = static_cast<MessageValue>(Message::FINISH);

	constexpr auto MESSAGE_FINISH = static_cast<MessageValue>(Message::FINISH);

	init();

	auto localStatus = os::STATUS_SUCCESS;
	os::windows::OsMessage message = {};
	while (localStatus)
	{
		localStatus = ::GetMessageA(&message, window.handle, MESSAGE_VALUE_MIN, MESSAGE_VALUE_MAX);
		if (localStatus < 0)
			break;

		::TranslateMessage(&message);
		if (MESSAGE_FINISH == message.message)
		{
			::PostQuitMessage(0);
			break;
		}
		::DispatchMessageA(&message);
	}

	destroy();
}

// public - api

const os::windows::OsWindow &
EventCatcher::MessageDispatchThread::getWindow() const noexcept
{
	os::threads::Locker lock{ spin };
	return window;
}

void EventCatcher::MessageDispatchThread::wait() const noexcept
{
	while (!isWindowInited());
}

void EventCatcher::MessageDispatchThread::stop() noexcept
{
	constexpr auto FINISH_MESSAGE = static_cast<MessageValue>(Message::FINISH);
	if (getWindow().handle)
		::PostMessageA(window.handle, FINISH_MESSAGE, {}, {});
}

// private - help

void EventCatcher::MessageDispatchThread::init() noexcept
{
	os::threads::Locker lock{ spin };
	window = EventCatcher::MessageDispatchThread::makeWindow(anonymous::WINDOW_CLASS_NAME);
	started = true;
	if (!window.handle)
		return;
}

void EventCatcher::MessageDispatchThread::destroy() noexcept
{
	os::threads::Locker lock{ spin };
	EventCatcher::MessageDispatchThread::destroyWindow(window, anonymous::WINDOW_CLASS_NAME);
}

bool EventCatcher::MessageDispatchThread::isWindowInited() const noexcept
{
	os::threads::Locker lock{ spin };
	return started;
}

// private - WSA + static

os::windows::OsWindow
EventCatcher::MessageDispatchThread::makeWindow(const char *className) noexcept
{
	if (!className)
		return {};

	os::windows::OsWindowClass windowsClass = {};
	windowsClass.style = CS_HREDRAW | CS_VREDRAW;
	windowsClass.lpfnWndProc = reinterpret_cast<os::windows::OsWindowCallback>(
			MessageDispatchThread::action
	);
	windowsClass.cbClsExtra = 0;
	windowsClass.cbWndExtra = 0;
	windowsClass.hInstance = nullptr;
	windowsClass.hIcon = LoadIconA(nullptr, IDI_APPLICATION);
	windowsClass.hCursor = LoadCursorA(nullptr, IDC_ARROW);
	windowsClass.hbrBackground = reinterpret_cast<os::windows::OsBrush>(
			GetStockObject(WHITE_BRUSH)
	);
	windowsClass.lpszMenuName = nullptr;
	windowsClass.lpszClassName = className;
	const auto atom = ::RegisterClassA(&windowsClass);
	if (!atom)
		return os::windows::OsWindow{
				{}, static_cast<os::windows::OsAtom>(::GetLastError())
		};

	auto handle = ::CreateWindowA(
			className, nullptr, WS_OVERLAPPEDWINDOW
			, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT
			, nullptr, nullptr, nullptr, nullptr
	);
	if (!handle)
	{
		os::windows::OsWindow result{
				{}, static_cast<os::windows::OsAtom>(::GetLastError())
		};
		::UnregisterClassA(className, nullptr);
		return result;
	}
	auto window = os::windows::OsWindow{ handle, atom };
	return window;
}

void EventCatcher::MessageDispatchThread::destroyWindow(
		os::windows::OsWindow &window, const char *className
)
{
	::DestroyWindow(window.handle);
	::UnregisterClassA(className, nullptr);
}

os::windows::OsResult
EventCatcher::MessageDispatchThread::action(
		os::windows::OsWindowHandle window, Message message, os::SocketDescriptor descriptor
		, os::windows::OsParam param
)
{
	if ((message != Message::SOCKET) || (WSAGETSELECTERROR(param)))
		return ::DefWindowProcA(window, static_cast<MessageValue>(message), descriptor, param);

	const auto type = os::network::NetworkBase::callbacks().type(Socket{ descriptor });
	switch(type)
	{
		case os::network::NetworkBase::SocketType::DATAGRAM:
			MessageDispatchThread::handleUdp(descriptor, param);
			break;

		case os::network::NetworkBase::SocketType::STREAM:
			MessageDispatchThread::handleTcp(descriptor, param);
			break;

		case os::network::NetworkBase::SocketType::UNKNOWN:
		default:
			break;
	}
    EventCatcher::get().notify();

	return ::DefWindowProcA(window, static_cast<MessageValue>(message), descriptor, param);
}

void EventCatcher::MessageDispatchThread::handleUdp(
		os::SocketDescriptor descriptor, os::windows::OsParam param
)
{
	const auto event = anonymous::event(param);
	auto &queues = EventCatcher::get().queues();
	switch (event)
	{
		case anonymous::Event::READ:
		case anonymous::Event::WRITE:
		{
			if (os::network::NetworkBase::callbacks().isServer(Socket{ descriptor }))
				queues.udpServers().push(descriptor);
			else
				queues.udpClients().push(descriptor);
			return;
		}
		default:
			return;
	}
}

void EventCatcher::MessageDispatchThread::handleTcp(
		os::SocketDescriptor descriptor, os::windows::OsParam param
)
{
	flame_ide::unused(descriptor);

	const auto event = anonymous::event(param);
	auto &queues = EventCatcher::get().queues();
	switch (event)
	{
		case anonymous::Event::ACCEPT:
		{
			auto status = os::STATUS_SUCCESS;
			auto client = os::network::TcpServer::callbacks().accept(
					Socket{ descriptor }, &status
			);
			if (os::STATUS_SUCCESS == status)
				queues.tcpAcceptedConnections().push({ descriptor, client });
			return;
		}
		case anonymous::Event::READ:
		case anonymous::Event::WRITE:
		{
			if (os::network::NetworkBase::callbacks().isServer(Socket{ descriptor }))
				queues.tcpServers().push(descriptor);
			else
				queues.tcpClients().push(descriptor);
			return;
		}
		default:
			return;
	}
}

}}}}} // namespace flame_ide::os::windows::async::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

EventCatcherBase &EventCatcherBase::get() noexcept
{
	static os::windows::async::network::EventCatcher catcher;
	return catcher;
}

}}}} // namespace flame_ide::os::async::network
