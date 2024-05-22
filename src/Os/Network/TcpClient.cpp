#include <FlameIDE/Os/Network/TcpClient.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/TcpSocketFunctions.hpp>

namespace flame_ide
{namespace os
{namespace network
{

TcpClient::TcpClient(TcpClient &&client) noexcept :
		NetworkBase(move(static_cast<NetworkBase &&>(client)))
{}

TcpClient::TcpClient(Ipv4 ip) noexcept :
		NetworkBase(socket::createTcpClient(ip))
{}

TcpClient &TcpClient::operator=(TcpClient &&client) noexcept
{
	operator=(move(static_cast<NetworkBase &&>(client)));
	return *this;
}

Status TcpClient::connect() noexcept
{
	setStatus(socket::tcp::client::connect(socket));
	return getStatus();
}

Status TcpClient::disconnect() noexcept
{
	setStatus(socket::destroy(socket));
	return getStatus();
}

Status TcpClient::reconnect() noexcept
{
	if (native().descriptor != os::SOCKET_INVALID.descriptor && disconnect() < 0)
		return getStatus();

	auto ip = socket::getIpv4(socket);
	socket = socket::createTcpClient(ip);

	return connect();
}

Types::ssize_t TcpClient::numberBytesToRead() const noexcept
{
	auto result = socket::receivingBytesNumber(socket);
	return result;
}

Types::ssize_t TcpClient::send(ConstRange range) noexcept
{
	auto result = socket::tcp::send(socket, range);
	if (result < 0)
	{
		setStatus(static_cast<Status>(result));
		return os::STATUS_FAILED;
	}
	return result;
}

Types::ssize_t TcpClient::receive(Range range) noexcept
{
	auto result = socket::tcp::receive(socket, range);
	if (result < 0)
	{
		setStatus(static_cast<Status>(result));
		return os::STATUS_FAILED;
	}
	return result;
}

const TcpClient::NativeCallbacks &TcpClient::callbacks() noexcept
{
	static const NativeCallbacks nativeCallbacks = []()
	{
		NativeCallbacks callbacks;
		callbacks = NetworkBase::callbacks();
		callbacks.create = socket::createTcpClient;
		callbacks.connect = socket::tcp::client::connect;
		callbacks.send = socket::tcp::send;
		callbacks.receive = socket::tcp::receive;
		callbacks.waitBytes = socket::tcp::waitBytes;
		callbacks.alive = socket::tcp::alive;
		return callbacks;
	} ();
	return nativeCallbacks;
}


}}} // namespace flame_ide::os::network
