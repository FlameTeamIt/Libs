#include <FlameIDE/../../src/Os/Posix/Network/Handler/Worker.hpp>

#include <FlameIDE/../../src/Os/Posix/Network/Handler/Registration.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace posix
{

Worker::Worker() noexcept
{}

Worker::~Worker() noexcept
{}

void Worker::start() noexcept
{
	stopWorker = false;
	run();
}

void Worker::stop() noexcept
{
	stopWorker = true;
}

void Worker::set(udp::Udp &udpData, tcp::Tcp &tcpData) noexcept
{
	udp = makeReferenceWrapper(udpData);
	tcp = makeReferenceWrapper(tcpData);
}

void Worker::body() noexcept
{
	while (!needStop())
	{
		processUdp();
		processTcp();
	}
}

void Worker::processUdp() noexcept
{
	auto descriptor = GlobalRegistration::get()->popUdp();
	if (descriptor == os::INVALID_DESCRIPTOR)
		return;

	// find class with need descriptor
}

void Worker::processTcp() noexcept
{
	auto descriptor = GlobalRegistration::get()->popUdp();
	if (descriptor == os::INVALID_DESCRIPTOR)
		return;

	// find object with need descriptor
}

bool Worker::needStop() noexcept
{
	return stopWorker || !GlobalRegistration::get();
}

}}}} // flame_ide::os::network::posix
