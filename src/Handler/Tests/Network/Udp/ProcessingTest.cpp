#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ProcessingTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

ProcessingTest::ProcessingTest() : ::AbstractTest("udp::Processing")
{}

ProcessingTest::~ProcessingTest() = default;

int ProcessingTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
