#include <FlameIDE/../../src/Os/Windows/Async/Network/EventCatcher.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

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

EventCatcher::EventCatcher() noexcept :
		os::async::network::EventCatcherBase()
		, window{ EventCatcher::makeWindow(anonymous::WINDOW_CLASS_NAME) }
		, thread{ window }
{
	if (!window.handle)
		return;

	thread.run();
}

EventCatcher::~EventCatcher() noexcept
{
	constexpr auto finish = static_cast<MessageValue>(Message::FINISH);

	if (window.handle)
		::SendMessageA(window.handle, finish, {}, {});
	if (thread.isWorking())
		thread.join();

	destroyWindow(window, anonymous::WINDOW_CLASS_NAME);
}

// private - virutal functions

os::Status EventCatcher::enable(SocketDescriptor descriptor) noexcept
{
	auto socket = Socket{ descriptor, {} };
	auto event = anonymous::Event::UNKNOWN;

	const auto &control = os::network::NetworkBase::nativeControl();
	const auto type = control.type(Socket{ descriptor, {} });
	switch(type)
	{
		case os::network::NetworkBase::SocketType::DATAGRAM:
			event = anonymous::Event::READ | anonymous::Event::WRITE;
			break;

		case os::network::NetworkBase::SocketType::STREAM:
		{
			if (control.isAcceptor(socket))
				event = anonymous::Event::ACCEPT;
			else
				event = anonymous::Event::READ | anonymous::Event::WRITE;
			break;
		}

		case os::network::NetworkBase::SocketType::UNKNOWN:
		default:
			break;
	}

	constexpr auto messageSocket = static_cast<MessageValue>(Message::SOCKET);
	os::Status result = os::STATUS_SUCCESS;
	result = ::WSAAsyncSelect(
			descriptor, window.handle, messageSocket, anonymous::value(event)
	);
	if (result == SOCKET_ERROR)
		result = -::GetLastError();
	return result;
}

os::Status EventCatcher::disable(SocketDescriptor descriptor) noexcept
{
	if (0 == ::WSAAsyncSelect(descriptor, nullptr, {}, {}))
		return -::GetLastError();
	return os::STATUS_SUCCESS;
}

// private - WSAAsync

os::windows::OsWindow EventCatcher::makeWindow(const char *className) noexcept
{
	if (!className)
		return {};

	os::windows::OsWindowClass windowsClass = {};
	windowsClass.style = CS_HREDRAW | CS_VREDRAW;
	windowsClass.lpfnWndProc = reinterpret_cast<os::windows::OsWindowCallback>(
			EventCatcher::action
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

void EventCatcher::destroyWindow(os::windows::OsWindow &window, const char *className)
{
	::DestroyWindow(window.handle);
	::UnregisterClassA(className, nullptr);
}

// TODO
os::windows::OsResult EventCatcher::action(
		os::windows::OsWindowHandle window, Message message, os::SocketDescriptor descriptor
		, os::windows::OsParam param
)
{
	if ((message != Message::SOCKET) || (WSAGETSELECTERROR(param)))
		return ::DefWindowProcA(window, static_cast<MessageValue>(message), descriptor, param);

	const auto &control = os::network::NetworkBase::nativeControl();
	const auto type = control.type(Socket{ descriptor, {} });
	switch(type)
	{
		case os::network::NetworkBase::SocketType::DATAGRAM:
			handleUdp(descriptor, param);
			break;

		case os::network::NetworkBase::SocketType::STREAM:
			handleTcp(descriptor, param);
			break;

		case os::network::NetworkBase::SocketType::UNKNOWN:
		default:
			break;
	}

	return ::DefWindowProcA(window, static_cast<MessageValue>(message), descriptor, param);
}

// TODO
void EventCatcher::handleUdp(os::SocketDescriptor descriptor, os::windows::OsParam param)
{
	flame_ide::unused(descriptor);

	const auto event = anonymous::event(param);
	auto &queues = EventCatcher::get().queues();
	switch (event)
	{
		case anonymous::Event::READ:
		case anonymous::Event::WRITE:
		{
			if (os::network::NetworkBase::nativeControl().isServer(Socket{ descriptor, {} }))
				queues.udpServers().push(descriptor);
			else
				queues.udpClients().push(descriptor);
			return;
		}
		default:
			return;
	}
}

// TODO
void EventCatcher::handleTcp(os::SocketDescriptor descriptor, os::windows::OsParam param)
{
	flame_ide::unused(descriptor);

	const auto event = anonymous::event(param);
	auto &queues = EventCatcher::get().queues();
	switch (event)
	{
		case anonymous::Event::ACCEPT:
		{
			auto status = os::STATUS_SUCCESS;
			auto client = os::network::TcpServer::nativeServerControl()
					.accept(Socket{ descriptor, {} }, &status);
			if (os::STATUS_SUCCESS == status)
				queues.tcpAcceptedConnections().push({ descriptor, client });
			return;
		}
		case anonymous::Event::READ:
		case anonymous::Event::WRITE:
		{
			if (os::network::NetworkBase::nativeControl().isServer(Socket{ descriptor, {} }))
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

// MessageDispatchThread
namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{

EventCatcher::MessageDispatchThread::MessageDispatchThread(
		os::windows::OsWindow &initWindow
) noexcept
		: window{ initWindow }
{}

void EventCatcher::MessageDispatchThread::body() noexcept
{
	constexpr auto messageValueMin = static_cast<MessageValue>(Message::SOCKET);
	constexpr auto messageValueMax = static_cast<MessageValue>(Message::FINISH) + 1;

	constexpr auto messageFinish = static_cast<MessageValue>(Message::FINISH);

	// если нужно уничтожить -- send post quit message на window handle
	auto status = os::STATUS_SUCCESS;
	os::windows::OsMessage message = {};
	while ((status = ::GetMessageA(&message, window.handle, messageValueMin, messageValueMax)))
	{
		if (status < 0)
			break;

		if (messageFinish == message.message)
			break;

		::DispatchMessageA(&message);
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
