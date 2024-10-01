#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

void Worker::notify()
{
	condvar.notify();
}

void Worker::body() noexcept
{
	while (!condvar.tryWait())
	{}
}

}}} // namespace flame_ide::handler::network

namespace flame_ide
{namespace handler
{namespace network
{

Workers::Workers() noexcept
{}

Workers::~Workers() noexcept
{
	stop();
}

os::Status Workers::start()
{
	return os::STATUS_FAILED;
}

os::Status Workers::stop()
{
	return os::STATUS_FAILED;
}

}}} // namespace flame_ide::handler::network
