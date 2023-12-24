#include <FlameIDE/../../src/Handler/Tests/Network/HandlerTest.hpp>
#include <FlameIDE/Handler/Network/Handler.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

HandlerTest::HandlerTest() : ::AbstractTest("Handler")
{}

HandlerTest::~HandlerTest() = default;

int HandlerTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
