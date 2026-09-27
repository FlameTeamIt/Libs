#ifndef HANDLER_INTERNAL_UDP_WORKERS_HPP
#define HANDLER_INTERNAL_UDP_WORKERS_HPP

#include <FlameIDE/../../src/Handler/Network/WorkerBase.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Processing.hpp>

#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

//

class ServerWorker: public WorkerBase, private ServerProcessor
{
public:
	ServerWorker(Handler::Udp &udpInit) noexcept;

private:
	void processing() noexcept override;

private:
	Handler::Udp &udp;
};

//

class ClientWorker: public WorkerBase, private ClientProcessor
{
public:
	ClientWorker(Handler::Udp &udpInit) noexcept;

private:
	void processing() noexcept override;

private:
	Handler::Udp &udp;
};

//

class Workers
{
public:
	Workers(Handler::Udp &udpInit) noexcept;

	void start() noexcept;
	void stop() noexcept;

	WorkerBase::Notifier serverNotifier() noexcept;
	WorkerBase::Notifier clientNotifier() noexcept;

private:
	ServerWorker serverWorker;
	ClientWorker clientWorker;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_WORKERS_HPP
