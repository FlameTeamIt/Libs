#include <FlameIDE/Os/Network/TcpServer.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/TcpSocketFunctions.hpp>

#include <Generated/Network/Config.hpp>

namespace flame_ide
{namespace os
{namespace network
{

TcpServer::TcpServer(TcpServer &&tcpServer) noexcept :
		NetworkBase(move(static_cast<NetworkBase &&>(tcpServer)))
{}

TcpServer::TcpServer(Ipv4::Port port) noexcept :
		NetworkBase(socket::createTcpServer(port))
{
	setStatus(socket::tcp::server::listen(
			socket, generated::network::Config::TCP_SERVER_BACKLOG
	));
}

TcpServer &TcpServer::operator=(TcpServer &&tcpServer) noexcept
{
	operator=(move(static_cast<NetworkBase &&>(tcpServer)));
	return *this;
}

TcpServer::WithClient TcpServer::accept() const noexcept
{
	if (getStatus() < 0)
	{
		return WithClient{ os::SOCKET_INVALID, getStatus() };
	}

	Status tmpStatus = os::STATUS_SUCCESS;
	auto client = socket::tcp::server::accept(socket, &tmpStatus);
	return WithClient{ client, tmpStatus };
}

const TcpServer::NativeCallbacks &TcpServer::callbacks() noexcept
{
	static const NativeCallbacks nativeCallbacks = []()
	{
		NativeCallbacks callbacks;
		callbacks = NetworkBase::callbacks();
		callbacks.create = socket::createTcpServer;
		callbacks.listen = socket::tcp::server::listen;
		callbacks.accept = socket::tcp::server::accept;
		callbacks.send = socket::tcp::send;
		callbacks.receive = socket::tcp::receive;
		callbacks.waitBytes = socket::tcp::waitBytes;
		callbacks.alive = socket::tcp::alive;
		return callbacks;
	} ();
	return nativeCallbacks;
}

}}} // namespace flame_ide::os::network

namespace flame_ide
{namespace os
{namespace network
{

TcpServer::WithClient::WithClient(WithClient &&client) noexcept
{
	operator=(move(client));
}

TcpServer::WithClient::WithClient(Socket socket, Status result) noexcept :
		socket{ socket }
		, status{ result }
{}

TcpServer::WithClient::~WithClient() noexcept
{
	if (socket.descriptor == os::SOCKET_INITIALIZER.descriptor)
	{
		return;
	}

	socket::destroy(socket);
}

TcpServer::WithClient &TcpServer::WithClient::operator=(WithClient &&client) noexcept
{
	socket = client.socket;
	status = client.status;

	client.socket = os::SOCKET_INITIALIZER;
	client.status = os::STATUS_SUCCESS;

	return *this;
}

Types::ssize_t TcpServer::WithClient::numberBytesToRead() const noexcept
{
	auto result = socket::receivingBytesNumber(socket);
	return result;
}

Status TcpServer::WithClient::getStatus() const noexcept
{
	return status;
}

const Socket &TcpServer::WithClient::native() const noexcept
{
	return socket;
}

Types::ssize_t TcpServer::WithClient::send(TcpServer::ConstRange range) noexcept
{
	auto result = socket::tcp::send(socket, range);
	if (result < 0)
	{
		status = static_cast<Status>(result);
		return os::STATUS_FAILED;
	}
	return result;
}

Types::ssize_t TcpServer::WithClient::receive(TcpServer::Range range) noexcept
{
	auto result = socket::tcp::receive(socket, range);
	if (result < 0)
	{
		status = static_cast<Status>(result);
		return os::STATUS_FAILED;
	}
	return result;
}

}}} // namespace flame_ide::os::network
