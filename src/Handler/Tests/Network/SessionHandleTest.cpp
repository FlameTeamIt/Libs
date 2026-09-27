#include <FlameIDE/../../src/Handler/Tests/Network/SessionHandleTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

SessionHandleTest::SessionHandleTest() : ::AbstractTest("SessionHandle")
{}

SessionHandleTest::~SessionHandleTest() = default;

int SessionHandleTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
