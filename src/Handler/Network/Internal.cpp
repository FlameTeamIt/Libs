#include <FlameIDE/../../src/Handler/Network/Internal.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp/InternalData.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/InternalData.hpp>

#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Handler::Internal::Internal() noexcept
{}

Handler::Internal::~Internal() noexcept = default;

Handler::Udp &Handler::Internal::udp() noexcept
{
	return udpData;
}

Handler::Tcp &Handler::Internal::tcp() noexcept
{
	return tcpData;
}

os::async::network::Registrar &Handler::Internal::registrar() noexcept
{
	return registration;
}

os::Status Handler::Internal::start() noexcept
{
	return workers.start();
}

os::Status Handler::Internal::stop() noexcept
{
	return workers.stop();
}

}}} // namespace flame_ide::os::network
