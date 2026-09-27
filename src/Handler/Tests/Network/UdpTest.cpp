#include <FlameIDE/../../src/Handler/Tests/Network/UdpTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

UdpTest::UdpTest() : ::AbstractTest("Udp")
{}

UdpTest::~UdpTest() = default;

int UdpTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
