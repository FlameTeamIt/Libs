#include <FlameIDE/../../src/Os/Tests/Network/HandlerTest.hpp>

#include <FlameIDE/Os/Network/Handler.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{
namespace // anonymous
{

} // namespace anonymous
}}}} // namespace flame_ide::os::network::tests

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

HandlerTest::HandlerTest() : ::AbstractTest("Handler")
{}

HandlerTest::~HandlerTest() = default;

int HandlerTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"Init and destroy"
			, [this]()
			{
				return init();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Push UDP Server"
			, [this]()
			{
				return pushUdpServer();
			}
	));

	return ::AbstractTest::SUCCESS;
}

int HandlerTest::init()
{
	Handler handler;
	std::cout << handler.getInfo().udp.maxServers << std::endl;
	return ::AbstractTest::SUCCESS;
}

int HandlerTest::pushUdpServer()
{
	Handler handler;
	Handler::ServerHandle handle;
	{
		const auto port = Ipv4::Port{ 65001 };
		UdpServer server{ port };
		handle = handler.push(flame_ide::move(server));
	}
	IN_CASE_CHECK(handle.operator bool());
	return ::AbstractTest::SUCCESS;
}

}}}} // namespace flame_ide::os::network::tests

