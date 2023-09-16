#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Os/Posix/Async/Network/Registrar.hpp>
#include <FlameIDE/../../src/Os/Windows/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

using PlatformRegistrar = FLAMEIDE_REGISTAR_NAMESPACE::Registrar;

Registrar::Registrar() noexcept = default;

Registrar::~Registrar() noexcept = default;

// Registrar::add

os::Status Registrar::add(const os::network::UdpServer &socket) noexcept
{
	return PlatformRegistrar::get().enableUdpServer(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::UdpClient &socket) noexcept
{
	return PlatformRegistrar::get().enableUdpCleint(socket.native().descriptor);
}

// TODO
os::Status Registrar::add(const os::network::TcpServer &socket) noexcept
{
	flame_ide::unused(socket);
	return false;
}

// TODO
os::Status Registrar::add(const os::network::TcpClient &socket) noexcept
{
	flame_ide::unused(socket);
	return false;
}

// Registrar::remove

os::Status Registrar::remove(const os::network::UdpServer &socket) noexcept
{
	return PlatformRegistrar::get().disableSocket(socket.native().descriptor);
}

// TODO
os::Status Registrar::remove(const os::network::UdpClient &socket) noexcept
{
	flame_ide::unused(socket);
	return false;
}

// TODO
os::Status Registrar::remove(const os::network::TcpServer &socket) noexcept
{
	flame_ide::unused(socket);
	return false;
}

// TODO
os::Status Registrar::remove(const os::network::TcpClient &socket) noexcept
{
	flame_ide::unused(socket);
	return false;
}

// Registrar::pop*

os::SocketDescriptor Registrar::popUdpServer() noexcept
{
	return PlatformRegistrar::get().popUdpServer();
}

// TODO
os::SocketDescriptor Registrar::popUdpClient() noexcept
{
	return PlatformRegistrar::get().popUdpCleint();
}

// TODO
AcceptedConnection Registrar::popTcpServer() noexcept
{
	return {};
}

// TODO
os::SocketDescriptor Registrar::popTcpClient() noexcept
{
	return os::SOCKET_INVALID.descriptor;
}

}}}} // namespace flame_ide::os::async::network
