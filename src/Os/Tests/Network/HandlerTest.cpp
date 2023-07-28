#include <FlameIDE/../../src/Os/Tests/Network/HandlerTest.hpp>

#include <FlameIDE/Os/Network/Handler.hpp>

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

	return ::AbstractTest::SUCCESS;
}

int HandlerTest::init()
{
	Handler handler;
	std::cout << handler.getInfo().udp.maxServers << std::endl;
	return ::AbstractTest::SUCCESS;
}

}}}} // namespace flame_ide::os::network::tests

