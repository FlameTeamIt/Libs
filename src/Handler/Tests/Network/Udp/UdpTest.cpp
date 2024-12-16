#include <FlameIDE/../../src/Handler/Tests/Network/Udp/UdpTest.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

using Udp = Handler::Udp;

UdpTest::UdpTest() : ::AbstractTest("udp::Udp")
{}

UdpTest::~UdpTest() = default;

int UdpTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"Initialization"
			, [this]() { return init(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Push & pop server"
			, [this]() { return pushPopServer(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Push server"
			, [this]() { return pushServer(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Push & pop client"
			, [this]() { return pushPopClient(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Push client"
			, [this]() { return pushClient(); }
	));

	return ResultType::SUCCESS;
}

int UdpTest::init() noexcept
{
	Udp storage;
	flame_ide::unused(storage);

	return ResultType::SUCCESS;
}

int UdpTest::pushPopServer() noexcept
{
	os::network::UdpServer server{ 65001 };
	const os::Socket expectedSocket = server.native();
	IN_CASE_CHECK(expectedSocket.descriptor != os::SOCKET_INVALID.descriptor);

	Udp storage;
	Handler::ExpectedServerHandle expectedHandle = storage.push(flame_ide::move(server));
	Handler::ServerHandle handle;
	bool isError = false;
	expectedHandle.ifResult(
			[&handle](Handler::ServerHandle &&result)
			{
				handle = flame_ide::move(result);
			}
	).ifError(
			[&isError](os::Status &&)
			{
				isError = true;
			}
	);
	IN_CASE_CHECK(isError == false);
	IN_CASE_CHECK(handle.operator bool())

	Handler::ExpectedUdpServer expectedServer = storage.pop(handle);
	os::network::UdpServer resultServer;
	expectedServer.ifResult(
			[&resultServer](os::network::UdpServer &&server)
			{
				resultServer = flame_ide::move(server);
			}
	).ifError(
			[&isError](os::Status &&)
			{
				isError = true;
			}
	);
	IN_CASE_CHECK(isError == false);
	IN_CASE_CHECK(expectedSocket.descriptor == resultServer.native().descriptor);

	return ResultType::SUCCESS;
}

int UdpTest::pushServer() noexcept
{
	os::network::UdpServer server{ 65001 };
	IN_CASE_CHECK(server.native().descriptor != os::SOCKET_INVALID.descriptor);

	Udp storage;
	Handler::ExpectedServerHandle expectedHandle = storage.push(flame_ide::move(server));
	Handler::ServerHandle handle;
	bool isError = false;
	expectedHandle.ifResult(
			[&handle](Handler::ServerHandle &&result)
			{
				handle = flame_ide::move(result);
			}
	).ifError(
			[&isError](os::Status &&)
			{
				isError = true;
			}
	);
	IN_CASE_CHECK(isError == false);
	IN_CASE_CHECK(handle.operator bool())

	return ResultType::SUCCESS;
}

int UdpTest::pushPopClient() noexcept
{
	const os::network::Ipv4 ip{ { 127, 0, 0, 1 }, 65001 };
	os::network::UdpClient client{ ip };
	const os::Socket expectedSocket = client.native();
	IN_CASE_CHECK(expectedSocket.descriptor != os::SOCKET_INVALID.descriptor);

	Udp storage;
	Handler::ExpectedSessionHandle expectedHandle = storage.push(flame_ide::move(client));
	Handler::SessionHandle handle;
	bool isError = false;
	expectedHandle.ifResult(
			[&handle](Handler::SessionHandle &&result)
			{
				handle = flame_ide::move(result);
			}
	).ifError(
			[&isError](os::Status &&)
			{
				isError = true;
			}
	);
	IN_CASE_CHECK(isError == false);
	IN_CASE_CHECK(handle.operator bool())

	Handler::ExpectedUdpClient expectedClient = storage.pop(handle);
	os::network::UdpClient resultClient;
	expectedClient.ifResult(
			[&resultClient](os::network::UdpClient &&server)
			{
				resultClient = flame_ide::move(server);
			}
	).ifError(
			[&isError](os::Status &&)
			{
				isError = true;
			}
	);
	IN_CASE_CHECK(isError == false);
	IN_CASE_CHECK(expectedSocket.descriptor == resultClient.native().descriptor);

	return ResultType::SUCCESS;
}

int UdpTest::pushClient() noexcept
{
	const os::network::Ipv4 ip{ { 127, 0, 0, 1 }, 65001 };
	os::network::UdpClient client{ ip };
	IN_CASE_CHECK(client.native().descriptor != os::SOCKET_INVALID.descriptor);

	Udp storage;
	Handler::ExpectedSessionHandle expectedHandle = storage.push(flame_ide::move(client));
	Handler::SessionHandle handle;
	bool isError = false;
	expectedHandle.ifResult(
			[&handle](Handler::SessionHandle &&result)
			{
				handle = flame_ide::move(result);
			}
	).ifError(
			[&isError](os::Status &&)
			{
				isError = true;
			}
	);
	IN_CASE_CHECK(isError == false);
	IN_CASE_CHECK(handle.operator bool())

	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
