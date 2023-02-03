#include <FlameIDE/Os/NetworkBase.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

namespace flame_ide
{namespace os
{

NetworkBase::~NetworkBase() noexcept
{
	if (socket.descriptor == SOCKET_INVALID.descriptor)
		return;

	socket::destroy(socket);
}

NetworkBase::NetworkBase(Socket socket) noexcept : socket{ socket }
{}

NetworkBase::NetworkBase(NetworkBase &&udp) noexcept : NetworkBase(udp.socket)
{
	udp.socket = Socket{};
}

}} // namespace flame_ide::os
