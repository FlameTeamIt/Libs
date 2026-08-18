#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ActualDataTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

ActualDataTest::ActualDataTest() : ::AbstractTest("udp::ActualData")
{}

ActualDataTest::~ActualDataTest() = default;

int ActualDataTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
