#include <FlameIDE/../../src/Handler/Network/Workers.hpp>

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

Workers::Workers(Handler::Udp &udp) noexcept : udpWorkers{ udp }
{}

Workers::~Workers() noexcept
{
	stop();
}

void Workers::start() noexcept
{
	udpWorkers.start();
}

void Workers::stop() noexcept
{
	udpWorkers.stop();
}

udp::Workers &Workers::udp() noexcept
{
	return udpWorkers;
}

}}} // namespace flame_ide::handler::network
