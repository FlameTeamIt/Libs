#include <FlameIDE/Os/TcpServer.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/TcpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{

TcpServer::TcpServer(TcpServer &&tcpServer) noexcept :
		NetworkBase(move(static_cast<NetworkBase &&>(tcpServer)))
{}

TcpServer::TcpServer(Ipv4::Port port, Types::size_t backlog) noexcept :
		NetworkBase(socket::createTcpServer(port))
{
	setStatus(socket::tcp::server::listen(socket, backlog));
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

	Status status = os::STATUS_SUCCESS;
	auto client = socket::tcp::server::accept(socket, &status);
	return WithClient{ client, status };
}

}} // namespace flame_ide::os

namespace flame_ide
{namespace os
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

Types::ssize_t TcpServer::WithClient::send(TcpServer::ConstRange range) noexcept
{
	auto result = socket::tcp::send(socket, range);
	if (result < 0)
	{
		status = result;
		return os::STATUS_FAILED;
	}
	return result;
}

Types::ssize_t TcpServer::WithClient::receive(TcpServer::Range range) noexcept
{
	auto result = socket::tcp::receive(socket, range);
	if (result < 0)
	{
		status = result;
		return os::STATUS_FAILED;
	}
	return result;
}

}} // namespace flame_ide::os
