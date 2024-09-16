#include <FlameIDE/../../src/Handler/Tests/Network/TcpTest.hpp>
#include <FlameIDE/../../src/Handler/Network/Tcp/Tcp.hpp>

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

int TcpTest::init()
{
	tcp::Tcp tcp;
	return ResultType::SUCCESS;
}

int TcpTest::serverPushPop()
{
	tcp::Tcp tcp;
	os::network::TcpServer server{ 65001 };

	const os::Socket expectedSocket = server.native();

	auto handle = tcp.push(flame_ide::move(server));
	IN_CASE_CHECK(handle != nullptr);

	auto resultServer = tcp.pop(handle);
	IN_CASE_CHECK(expectedSocket.descriptor == resultServer.native().descriptor);

	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
