#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ServerTest.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Server.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

ServerTest::ServerTest() : ::AbstractTest("udp::Server")
{}

ServerTest::~ServerTest() = default;

int ServerTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"initialization"
			, [this]() { return init(); }

	));
	return ResultType::SUCCESS;
}

int ServerTest::init() noexcept
{
	ServerCommunicationData server;
	flame_ide::unused(server);

	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
