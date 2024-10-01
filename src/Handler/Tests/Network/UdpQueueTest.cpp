#include <FlameIDE/../../src/Handler/Tests/Network/UdpQueueTest.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Udp.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

UdpQueueTest::UdpQueueTest() : ::AbstractTest("UdpQueue")
{}

UdpQueueTest::~UdpQueueTest() = default;

int UdpQueueTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"initialization"
			, [this]() { return init(); }

	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"server push-pop"
			, [this]() { return serverPushPop(); }

	));
	return ResultType::SUCCESS;
}

int UdpQueueTest::init()
{
	udp::Udp udp;
	return ResultType::SUCCESS;
}

int UdpQueueTest::serverPushPop()
{
	udp::Udp udp;
	os::network::UdpServer server{ 65001 };

	const os::Socket expectedSocket = server.native();

	auto handle = udp.push(flame_ide::move(server));
	IN_CASE_CHECK(handle != nullptr);

	auto resultServer = udp.pop(handle);
	IN_CASE_CHECK(expectedSocket.descriptor == resultServer.native().descriptor);

	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
