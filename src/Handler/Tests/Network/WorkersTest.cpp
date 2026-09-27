#include <FlameIDE/../../src/Handler/Tests/Network/WorkersTest.hpp>
#include <FlameIDE/../../src/Handler/Network/Workers.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

WorkersTest::WorkersTest() : ::AbstractTest("Workers")
{}

WorkersTest::~WorkersTest() = default;

int WorkersTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
