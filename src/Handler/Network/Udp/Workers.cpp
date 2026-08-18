#include <FlameIDE/../../src/Handler/Network/Udp/Workers.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp.hpp>

#include <FlameIDE/Os/Async/Network/Registrar.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

//

ServerWorker::ServerWorker(Handler::Udp &udpInit) noexcept
		: udp{ udpInit }
{}

void ServerWorker::processing() noexcept
{
	auto event = os::async::network::Registrar{}.popUdpServer();
	if (event == decltype(event){})
		return;
	udp.process(*this, event);
}

//

ClientWorker::ClientWorker(Handler::Udp &udpInit) noexcept
		: udp{ udpInit }
{}

void ClientWorker::processing() noexcept
{
	auto event = os::async::network::Registrar{}.popUdpClient();
	if (event == decltype(event){})
		return;
	udp.process(*this, event);
}

//

Workers::Workers(Handler::Udp &udpInit) noexcept
		: serverWorker{ udpInit }, clientWorker{ udpInit }
{}

void Workers::start() noexcept
{
	serverWorker.start();
	clientWorker.start();
}

void Workers::stop() noexcept
{
	serverWorker.stop();
	clientWorker.stop();
}

WorkerBase::Notifier Workers::serverNotifier() noexcept
{
	return serverWorker.notifier();
}
WorkerBase::Notifier Workers::clientNotifier() noexcept
{
	return clientWorker.notifier();
}


}}}} // namespace flame_ide::handler::network::udp
