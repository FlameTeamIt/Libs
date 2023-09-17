#include <FlameIDE/Os/Network/NetworkBase.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>

namespace flame_ide
{namespace os
{namespace network
{

// public

NetworkBase::~NetworkBase() noexcept
{
if (!operator bool())
		return;

	socket::destroy(socket);
}

NetworkBase::operator bool() const noexcept
{
	return (SOCKET_INVALID.descriptor != socket.descriptor) || (status >= 0);
}

Status NetworkBase::getStatus() const noexcept
{
	return status;
}

const Socket &NetworkBase::native() const
{
	return socket;
}

NetworkBase::NativeSocketControl NetworkBase::nativeControl() noexcept
{
	NativeSocketControl socketControl;
	socketControl.destroy = socket::destroy;
	socketControl.receivingBytesNumber = socket::receivingBytesNumber;
	socketControl.getIpv4 = socket::getIpv4;

	socketControl.type = reinterpret_cast<decltype(socketControl.type)>(socket::getType);
	socketControl.error = socket::getError;
	socketControl.isAcceptor = socket::isAcceptor;
	socketControl.isServer = socket::isServer;
	return socketControl;
}

// protected

NetworkBase::NetworkBase(Socket socket) noexcept : socket{ socket }
{
	if (!operator bool())
	{
		setStatus(STATUS_FAILED);
	}
}

NetworkBase::NetworkBase(NetworkBase &&base) noexcept : NetworkBase(base.socket)
{
	operator=(move(base));
}

NetworkBase &NetworkBase::operator=(NetworkBase &&base) noexcept
{
	status = base.status;
	socket = base.socket;

	base.status = os::STATUS_SUCCESS;
	base.socket = os::SOCKET_INITIALIZER;

	return *this;
}

void NetworkBase::setStatus(Status statusInit) noexcept
{
	this->status = statusInit;
}

Types::int_t NetworkBase::checkStatus(Status status) noexcept
{
	if (status < 0)
	{
		return os::STATUS_FAILED;
	}
	return os::STATUS_SUCCESS;
}

}}} // namespace flame_ide::os::network
