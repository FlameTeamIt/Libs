#include <FlameIDE/../../src/Os/Windows/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Network/NetworkBase.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace windows
{namespace async
{namespace network
{
namespace anonymous{namespace{

template<typename Pointer, typename Queue, typename Value>
inline bool initPointerAndQueue(Pointer &pointer, Queue &queue, Value initValue)
{
	pointer = Pointer{};
	if (!pointer)
		return false;

	for (auto &i : *pointer)
		i = initValue;

	queue.first = decltype(queue.first) {
			pointer->data()
			, templates::makeRange(
					pointer->data()
					, pointer->data() + pointer->capacity()
			)
	};
	queue.last = queue.first;

	return true;
}

template<
	typename Descriptors, typename Queue, typename Value = decltype(*Queue{}.first)
	>
inline os::Status checkInitialization(
	Descriptors &descriptors, Queue &queue, Value &&value
	)
{
	const os::threads::Locker locker{ queue.spin };
	if (!descriptors && !initPointerAndQueue(descriptors, queue, value))
		return os::STATUS_FAILED;
	return os::STATUS_SUCCESS;
}

template<typename Queue, typename Value = decltype(*Queue{}.first)>
inline auto popFromQueue(Queue &queue, Value initValue = {})
{
	os::threads::Locker locker{ queue.spin };

	if (!queue.count)
		return initValue;
	--queue.count;

	auto &first = queue.first;
	const Value value = *first;
	*first = initValue;
	++first;
	return value;
}

template<typename Queue, typename Value = decltype(*Queue{}.first)>
inline auto pushToQueue(Queue &queue, Types::size_t queueCapacity, Value value)
{
	os::threads::Locker locker{ queue.spin };

	if (queue.count >= queueCapacity)
		return false;
	++queue.count;

	auto &last = queue.last;
	*last = value;
	++last;
	return true;
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

// TODO
Registrar::~Registrar() noexcept
{}

// TODO
Registrar::operator bool() const noexcept
{
	return true;
}

// TODO
Registrar &Registrar::get() noexcept
{
	static Registrar registrar;
	return registrar;
}

// TODO
os::Status Registrar::enableUdpServer(SocketDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
	if (0 > anonymous::checkInitialization(
			udpServers, udpServersQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return os::STATUS_FAILED;
	//return Registrar::enableSignal(descriptor);
}

// TODO
os::Status Registrar::enableUdpCleint(SocketDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
	if (0 > anonymous::checkInitialization(
			udpClients, udpClientsQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return os::STATUS_FAILED;
	//return Registrar::enableSignal(descriptor);
}

// TODO
os::Status Registrar::enableTcpServerAcceptor(SocketDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
	if (0 > anonymous::checkInitialization(
			tcpServerAcceptions, tcpServerAcceptionsQueue, AcceptedConnection{}
	))
		return os::STATUS_FAILED;
	return os::STATUS_FAILED;
	//return Registrar::enableSignal(descriptor);
}

// TODO
os::Status Registrar::enableTcpServer(SocketDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
	if (0 > anonymous::checkInitialization(
			tcpServers, tcpServersQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return os::STATUS_FAILED;
	//return Registrar::enableSignal(descriptor);
}

// TODO
os::Status Registrar::enableTcpClient(SocketDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
	if (0 > anonymous::checkInitialization(
			tcpClients, tcpClientsQueue, os::SOCKET_INVALID.descriptor
	))
		return os::STATUS_FAILED;
	return os::STATUS_FAILED;
	//return Registrar::enableSignal(descriptor);
}

// TODO
os::Status Registrar::disableSocket(SocketDescriptor descriptor) noexcept
{
	flame_ide::unused(descriptor);
	return os::STATUS_FAILED;
	//return Registrar::disableSignal(descriptor);
}

SocketDescriptor Registrar::popUdpServer() noexcept
{
	return anonymous::popFromQueue(
			udpServersQueue, os::SOCKET_INVALID.descriptor
	);
}

SocketDescriptor Registrar::popUdpCleint() noexcept
{
	return anonymous::popFromQueue(
			udpClientsQueue, os::SOCKET_INVALID.descriptor
	);
}

Registrar::AcceptedConnection Registrar::popTcpServerAcception() noexcept
{
	return anonymous::popFromQueue(
			tcpServerAcceptionsQueue, AcceptedConnection{}
	);
}

SocketDescriptor Registrar::popTcpServer() noexcept
{
	return anonymous::popFromQueue(
			tcpServersQueue, os::SOCKET_INVALID.descriptor
	);
}

SocketDescriptor Registrar::popTcpClient() noexcept
{
	return anonymous::popFromQueue(
			tcpClientsQueue, os::SOCKET_INVALID.descriptor
	);
}

// private - Constructor

Registrar::Registrar() noexcept
{}

// private - WSAAsync

// TODO
os::windows::OsWindow Registrar::makeWindow() noexcept
{
	return {};
}

// TODO
os::windows::OsResult Registrar::action(
	os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
		, os::windows::OsParam param
)
{
	flame_ide::unused(window);
	flame_ide::unused(message);
	flame_ide::unused(socket);
	flame_ide::unused(param);
	return {};
}

// TODO
os::windows::OsResult Registrar::handleUdp(
	os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
		, os::windows::OsParam param
)
{
	flame_ide::unused(window);
	flame_ide::unused(message);
	flame_ide::unused(socket);
	flame_ide::unused(param);
	return {};
}

// TODO
os::windows::OsResult Registrar::handleTcpAcceptor(
	os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
		, os::windows::OsParam param
)
{
	flame_ide::unused(window);
	flame_ide::unused(message);
	flame_ide::unused(socket);
	flame_ide::unused(param);
	return {};
}

// TODO
os::windows::OsResult Registrar::handleTcp(
	os::windows::OsWindow window, Types::uint_t message, os::SocketDescriptor socket
		, os::windows::OsParam param
)
{
	flame_ide::unused(window);
	flame_ide::unused(message);
	flame_ide::unused(socket);
	flame_ide::unused(param);
	return {};
}

// private - push sockets

bool Registrar::pushUdpServer(SocketDescriptor descriptor) noexcept
{
	return anonymous::pushToQueue(udpServersQueue, udpServers->capacity(), descriptor);
}

bool Registrar::pushUdpClient(SocketDescriptor descriptor) noexcept
{
	return anonymous::pushToQueue(udpClientsQueue, udpClients->capacity(), descriptor);
}

bool Registrar::pushTcpServerAcception(AcceptedConnection connection) noexcept
{
	return anonymous::pushToQueue(tcpServerAcceptionsQueue, tcpServerAcceptions->capacity(), connection);
}

bool Registrar::pushTcpServer(SocketDescriptor descriptor) noexcept
{
	return anonymous::pushToQueue(tcpServersQueue, tcpServers->capacity(), descriptor);
}

bool Registrar::pushTcpClient(SocketDescriptor descriptor) noexcept
{
	return anonymous::pushToQueue(tcpClientsQueue, tcpClients->capacity(), descriptor);
}

}}}}} // namespace flame_ide::os::windows::async::network
