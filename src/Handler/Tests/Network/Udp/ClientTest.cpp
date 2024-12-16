#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ClientTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

ClientTest::ClientTest() : ::AbstractTest("udp::Client")
{}

ClientTest::~ClientTest() = default;

int ClientTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
