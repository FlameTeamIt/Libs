#include <FlameIDE/Os/NetworkBase.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

namespace flame_ide
{namespace os
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
	return (SOCKET_INVALID.descriptor != socket.descriptor) || (status > 0);
}

Status NetworkBase::getStatus() const noexcept
{
	return status;
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

	base.status = STATUS_SUCCESS;
	base.socket = Socket{};

	return *this;
}

void NetworkBase::setStatus(Status status) noexcept
{
	this->status = status;
}

Types::int_t NetworkBase::checkStatus(Status status) noexcept
{
	if (status < 0)
	{
		return STATUS_FAILED;
	}
	return STATUS_SUCCESS;
}

}} // namespace flame_ide::os
