#include <FlameIDE/../../src/Handler/Tests/Network/InternalTest.hpp>
#include <FlameIDE/../../src/Handler/Network/Internal.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

InternalTest::InternalTest() : ::AbstractTest("Internal")
{}

InternalTest::~InternalTest() = default;

int InternalTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
