#include <FlameIDE/../../src/Handler/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Handler/Tests/Network/Udp/TypeMappingTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ActualDataTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/EndpointTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/StorageTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ServerTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ClientTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ProcessingTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/WorkersTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/NotificatorsTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/Udp/UdpTest.hpp>

#include <FlameIDE/../../src/Handler/Tests/Network/Tcp/QueueTest.hpp>

#include <FlameIDE/../../src/Handler/Tests/Network/UdpTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/TcpTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/WorkerBaseTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/WorkersTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/NotificatorsTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/ServerHandleTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/SessionHandleTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/InternalTest.hpp>
#include <FlameIDE/../../src/Handler/Tests/Network/HandlerTest.hpp>

namespace flame_ide
{namespace handler
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Handler")
{
	// UDP
	pushBackTest(std::make_shared<network::udp::tests::TypeMappingTest>());
	pushBackTest(std::make_shared<network::udp::tests::ActualDataTest>());
	pushBackTest(std::make_shared<network::udp::tests::EndpointTest>());
	pushBackTest(std::make_shared<network::udp::tests::StorageTest>());
	pushBackTest(std::make_shared<network::udp::tests::ServerTest>());
	pushBackTest(std::make_shared<network::udp::tests::ClientTest>());
	pushBackTest(std::make_shared<network::udp::tests::ProcessingTest>());
	pushBackTest(std::make_shared<network::udp::tests::WorkersTest>());
	pushBackTest(std::make_shared<network::udp::tests::NotificatorsTest>());
	pushBackTest(std::make_shared<network::udp::tests::UdpTest>());

	// TCP
	pushBackTest(std::make_shared<network::tcp::tests::QueueTest>());

	// Handler
	pushBackTest(std::make_shared<network::tests::UdpTest>());
	pushBackTest(std::make_shared<network::tests::TcpTest>());
	pushBackTest(std::make_shared<network::tests::WorkerBaseTest>());
	pushBackTest(std::make_shared<network::tests::WorkersTest>());
	pushBackTest(std::make_shared<network::tests::NotificatorsTest>());
	pushBackTest(std::make_shared<network::tests::ServerHandleTest>());
	pushBackTest(std::make_shared<network::tests::SessionHandleTest>());
	pushBackTest(std::make_shared<network::tests::InternalTest>());
	pushBackTest(std::make_shared<network::tests::HandlerTest>());
}

}}} // namespace flame_ide::handler::tests
