#include <FlameIDE/../../src/Handler/Tests/Network/ServerHandleTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

ServerHandleTest::ServerHandleTest() : ::AbstractTest("ServerHandle")
{}

ServerHandleTest::~ServerHandleTest() = default;

int ServerHandleTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
