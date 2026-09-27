#include <FlameIDE/../../src/Handler/Tests/Network/Udp/EndpointTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

EndpointTest::EndpointTest() : ::AbstractTest("udp::Endpoint")
{}

EndpointTest::~EndpointTest() = default;

int EndpointTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
