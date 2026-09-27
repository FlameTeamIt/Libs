#include <FlameIDE/../../src/Handler/Tests/Network/TcpTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

TcpTest::TcpTest() : ::AbstractTest("Tcp")
{}

TcpTest::~TcpTest() = default;

int TcpTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
