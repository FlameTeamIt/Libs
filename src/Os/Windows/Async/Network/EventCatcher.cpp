#include <FlameIDE/../../src/Os/Windows/Async/Network/EventCatcher.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <FlameIDE/Os/Threads/Utils.hpp>

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
	auto event = Event::UNKNOWN;

	const auto &control = os::network::NetworkBase::callbacks();
	const auto type = control.type(Socket{ descriptor, {} });
	switch(type)
	{
		case os::network::NetworkBase::SocketType::DATAGRAM:
			event = Event::READ | Event::WRITE;
			break;

		case os::network::NetworkBase::SocketType::STREAM:
		{
			if (control.isListener(socket))
				event = Event::ACCEPT;
			else
				if (control.isServer)
					event = Event::READ | Event::WRITE;
				else
					event = Event::READ | Event::WRITE | Event::CONNECT;
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
	result = ::WSAAsyncSelect(descriptor, handle, MESSAGE_SOCKET, value(event));
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
