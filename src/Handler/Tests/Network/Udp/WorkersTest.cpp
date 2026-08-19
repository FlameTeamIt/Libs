#include <FlameIDE/../../src/Handler/Tests/Network/Udp/WorkersTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

WorkersTest::WorkersTest() : ::AbstractTest("udp::Workers")
{}

WorkersTest::~WorkersTest() = default;

int WorkersTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
