#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

#include <FlameIDE/Templates/SimpleAlgorithms.hpp>

namespace flame_ide
{namespace handler
{namespace network
{

void Worker::init(os::threads::ConditionVariable &initCondvar) noexcept
{
	condvar = &initCondvar;
}

void Worker::body() noexcept
{
	while (!condvar->tryWait())
	{}
}

}}} // namespace flame_ide::handler::network

namespace flame_ide
{namespace handler
{namespace network
{

Workers::Workers() noexcept
{
	flame_ide::templates::foreachChangable(
			workers
			, [this](Worker &i) { i.init(condvar); }
	);
}

Workers::~Workers() noexcept
{
	stop();
}

void Workers::start()
{
	flame_ide::templates::foreachChangable(
			workers
			, [](Worker &i) { i.run(); }
	);
}

void Workers::stop()
{
	condvar.notify();
	flame_ide::templates::foreachChangable(
			workers
			, [](Worker &i) { i.join(); }
	);
}

}}} // namespace flame_ide::handler::network
