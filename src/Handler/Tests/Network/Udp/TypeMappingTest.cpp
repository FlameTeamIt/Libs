#include <FlameIDE/../../src/Handler/Tests/Network/Udp/TypeMappingTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

TypeMappingTest::TypeMappingTest() : ::AbstractTest("udp::TypeMapping")
{}

TypeMappingTest::~TypeMappingTest() = default;

int TypeMappingTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
