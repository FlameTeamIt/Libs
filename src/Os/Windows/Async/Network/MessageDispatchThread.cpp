#include <FlameIDE/../../src/Os/Windows/Async/Network/MessageDispatchThread.hpp>
#include <FlameIDE/../../src/Os/Async/Network/EventCatcherBase.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{namespace anonymous{ namespace{

constexpr char WINDOW_CLASS_NAME[] = "AsyncSelect";

}} // namespace anonymous
}}}}} // namespace flame_ide::os::windows::async::network

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{

// public - thread

MessageDispatchThread::MessageDispatchThread() noexcept
{}

void MessageDispatchThread::body() noexcept
{
	constexpr auto MESSAGE_VALUE_MIN = static_cast<MessageValue>(Message::SOCKET);
	constexpr auto MESSAGE_VALUE_MAX = static_cast<MessageValue>(Message::FINISH);

	constexpr auto MESSAGE_FINISH = static_cast<MessageValue>(Message::FINISH);

	init();

	os::Status localStatus = 1;
	os::windows::OsMessage message = {};
	while (localStatus)
	{
		localStatus = ::GetMessageA(
				&message, window.handle, MESSAGE_VALUE_MIN, MESSAGE_VALUE_MAX
		);
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
MessageDispatchThread::getWindow() const noexcept
{
	os::threads::Locker lock{ spin };
	return window;
}

void MessageDispatchThread::wait() const noexcept
{
	while (!isWindowInited());
}

void MessageDispatchThread::stop() noexcept
{
	constexpr auto FINISH_MESSAGE = static_cast<MessageValue>(Message::FINISH);
	if (getWindow().handle)
		::PostMessageA(window.handle, FINISH_MESSAGE, {}, {});
}

// private - help

void MessageDispatchThread::init() noexcept
{
	os::threads::Locker lock{ spin };
	window = MessageDispatchThread::makeWindow(anonymous::WINDOW_CLASS_NAME);
	started = true;
	if (!window.handle)
		return;
}

void MessageDispatchThread::destroy() noexcept
{
	os::threads::Locker lock{ spin };
	MessageDispatchThread::destroyWindow(window, anonymous::WINDOW_CLASS_NAME);
}

bool MessageDispatchThread::isWindowInited() const noexcept
{
	os::threads::Locker lock{ spin };
	return started;
}

// private - WSA + static

os::windows::OsWindow MessageDispatchThread::makeWindow(const char *className) noexcept
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

void MessageDispatchThread::destroyWindow(
		os::windows::OsWindow &window, const char *className
)
{
	::DestroyWindow(window.handle);
	::UnregisterClassA(className, nullptr);
}

os::windows::OsResult MessageDispatchThread::action(
		os::windows::OsWindowHandle window, Message message
		, os::SocketDescriptor descriptor, os::windows::OsParam param
)
{
	if ((message != Message::SOCKET) || (WSAGETSELECTERROR(param)))
		return ::DefWindowProcA(
				window, static_cast<MessageValue>(message), descriptor, param
		);

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
	os::async::network::EventCatcherBase::get().notify();

	return ::DefWindowProcA(
			window, static_cast<MessageValue>(message), descriptor, param
	);
}

void MessageDispatchThread::handleUdp(
		os::SocketDescriptor descriptor, os::windows::OsParam param
)
{
	const auto eventValue = event(param);
	auto &queues = os::async::network::EventCatcherBase::get().queues();
	switch (eventValue)
	{
		case Event::READ:
		case Event::WRITE:
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

void MessageDispatchThread::handleTcp(
		os::SocketDescriptor descriptor, os::windows::OsParam param
)
{
	flame_ide::unused(descriptor);

	const auto eventValue = event(param);
	auto &queues = os::async::network::EventCatcherBase::get().queues();
	switch (eventValue)
	{
		case Event::ACCEPT:
		{
			auto status = os::STATUS_SUCCESS;
			auto client = os::network::TcpServer::callbacks().accept(
					Socket{ descriptor }, &status
			);
			if (os::STATUS_SUCCESS == status)
				queues.tcpAcceptedConnections().push({ descriptor, client });
			return;
		}
		case Event::READ:
		case Event::WRITE:
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
