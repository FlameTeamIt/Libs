#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/../../src/Os/Posix/Async/Network/Registrar.hpp>
#include <FlameIDE/../../src/Os/Windows/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Network/TcpClient.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
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

os::Status Registrar::add(const os::network::TcpServer &socket) noexcept
{
	return PlatformRegistrar::get().enableTcpServerAcceptor(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::TcpServer::WithClient &socket) noexcept
{
	return PlatformRegistrar::get().enableTcpServer(socket.native().descriptor);
}

os::Status Registrar::add(const os::network::TcpClient &socket) noexcept
{
	return PlatformRegistrar::get().enableTcpClient(socket.native().descriptor);
}

// Registrar::remove

os::Status Registrar::remove(const os::network::UdpServer &socket) noexcept
{
	return PlatformRegistrar::get().disableSocket(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::UdpClient &socket) noexcept
{
	return PlatformRegistrar::get().disableSocket(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::TcpServer &socket) noexcept
{
	return PlatformRegistrar::get().disableSocket(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::TcpServer::WithClient &socket) noexcept
{
	return PlatformRegistrar::get().disableSocket(socket.native().descriptor);
}

os::Status Registrar::remove(const os::network::TcpClient &socket) noexcept
{
	return PlatformRegistrar::get().disableSocket(socket.native().descriptor);
}

// Registrar::pop*

os::SocketDescriptor Registrar::popUdpServer() noexcept
{
	return PlatformRegistrar::get().popUdpServer();
}

os::SocketDescriptor Registrar::popUdpClient() noexcept
{
	return PlatformRegistrar::get().popUdpCleint();
}

AcceptedConnection Registrar::popTcpServerAcception() noexcept
{
	return PlatformRegistrar::get().popTcpServerAcception();
}

os::SocketDescriptor Registrar::popTcpServer() noexcept
{
	return PlatformRegistrar::get().popTcpServer();
}

os::SocketDescriptor Registrar::popTcpClient() noexcept
{
	return PlatformRegistrar::get().popTcpClient();
}

void Registrar::clear() noexcept
{
	while (popUdpServer() != os::SOCKET_INVALID.descriptor);
	while (popUdpClient() != os::SOCKET_INVALID.descriptor);
	while (popTcpServerAcception());
	while (popTcpServer() != os::SOCKET_INVALID.descriptor);
	while (popTcpClient() != os::SOCKET_INVALID.descriptor);
}

}}}} // namespace flame_ide::os::async::network
