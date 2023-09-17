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

const NetworkBase::NativeControl &NetworkBase::nativeControl() noexcept
{
	static const NativeControl socketControl{
			socket::destroy
			, socket::receivingBytesNumber
			, socket::getIpv4
			, reinterpret_cast<decltype(socketControl.type)>(socket::getType)
			, socket::getError
			, socket::isAcceptor
			, socket::isServer
	};
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

NetworkBase::SocketType NetworkBase::getType() const
{
	auto type = static_cast<NetworkBase::SocketType>(socket::getType(socket));
	switch (type) {
		case SocketType::STREAM:
		case SocketType::DATAGRAM:
			return type;

		case SocketType::UNKNOWN:
		default:
			return SocketType::UNKNOWN;
			break;
	}
}

os::Status NetworkBase::getError() const
{
	os::Status status = socket::getError(socket);
	return status;
}

bool NetworkBase::isServer() const
{
	return socket::isServer(socket);
}

bool NetworkBase::isAcceptor() const
{
	return socket::isAcceptor(socket);
}

// private

Types::int_t NetworkBase::checkStatus(Status status) noexcept
{
	if (status < 0)
	{
		return os::STATUS_FAILED;
	}
	return os::STATUS_SUCCESS;
}

}}} // namespace flame_ide::os::network
