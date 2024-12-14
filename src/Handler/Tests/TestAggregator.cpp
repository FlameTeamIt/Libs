#include <FlameIDE/../../src/Handler/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Handler/Tests/Network/Udp/StorageTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Tcp/QueueTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/WorkerTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/InternalTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/HandlerTest.hpp>

namespace flame_ide
{namespace handler
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Handler")
{
	// UDP
	pushBackTest(std::make_shared<network::udp::tests::StorageTest>());

	// TCP
	pushBackTest(std::make_shared<network::tcp::tests::QueueTest>());

	pushBackTest(std::make_shared<network::tests::WorkerTest>());
	pushBackTest(std::make_shared<network::tests::InternalTest>());
	pushBackTest(std::make_shared<network::tests::HandlerTest>());
}

}}} // namespace flame_ide::handler::tests
