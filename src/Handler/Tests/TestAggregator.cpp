#include <FlameIDE/../../src/Handler/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Handler/Tests/Network/UdpQueueTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/TcpQueueTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/WorkerTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/InternalTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/HandlerTest.hpp>

namespace flame_ide
{namespace handler
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Handler")
{
	pushBackTest(std::make_shared<network::tests::UdpQueueTest>());
	pushBackTest(std::make_shared<network::tests::TcpQueueTest>());
	pushBackTest(std::make_shared<network::tests::WorkerTest>());
	pushBackTest(std::make_shared<network::tests::InternalTest>());
	pushBackTest(std::make_shared<network::tests::HandlerTest>());
}

}}} // namespace flame_ide::handler::tests
