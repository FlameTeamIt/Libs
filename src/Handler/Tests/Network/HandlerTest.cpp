#include <FlameIDE/../../src/Handler/Tests/Network/HandlerTest.hpp>
#include <FlameIDE/Handler/Network/Handler.hpp>

#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

HandlerTest::HandlerTest() : ::AbstractTest("Handler")
{}

HandlerTest::~HandlerTest() = default;

int HandlerTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"initialization"
			, [this]() { return init(); }
	));

	// UPD
	// Server
	CHECK_RESULT_SUCCESS(doTestCase(
			"UDP Server push-pop"
			, [this]() { return udpServerPushPop(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"UDP Server communication"
			, [this]() { return udpServerCommunicate(); }
	));
	// Client
	CHECK_RESULT_SUCCESS(doTestCase(
			"UDP Client push-pop"
			, [this]() { return udpClientPushPop(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"UDP Client communication"
			, [this]() { return udpClientCommunicate(); }
	));

	// TCP
	// Server
	CHECK_RESULT_SUCCESS(doTestCase(
			"TCP Server push-pop"
			, [this]() { return tcpServerPushPop(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"TCP Server communication"
			, [this]() { return tcpServerCommunicate(); }
	));
	// Client
	CHECK_RESULT_SUCCESS(doTestCase(
			"TCP Client push-pop"
			, [this]() { return tcpClientPushPop(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"TCP Client communication"
			, [this]() { return tcpClientCommunicate(); }
	));

	return ResultType::SUCCESS;
}

int HandlerTest::init()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

int HandlerTest::udpServerPushPop()
{
	flame_ide::os::network::UdpServer originalUdpServer{ 65001 };
	const flame_ide::os::Socket originalNativeSocket = originalUdpServer.native();

	Handler handler;
	Handler::ExpectedServerHandle updServerHandle =
			handler.pushUdp(::flame_ide::move(originalUdpServer));

	// Check valid handle
	{
		ResultType pushResult = ResultType::FAILED;
		updServerHandle.ifResultGet(
				[&pushResult](auto &)
				{
					pushResult = ResultType::SUCCESS;
				}
		);
		IN_CASE_CHECK(pushResult == ResultType::SUCCESS);
	}

	// Get handle
	Handler::ServerHandle serverHandle;
	updServerHandle.ifResult(
			[&serverHandle](Handler::ServerHandle &&inputHandle)
			{
				serverHandle = move(inputHandle);
			}
	);
	Handler::ExpectedUdpServer udpServer = handler.popUdp(serverHandle);

	// Check valid server
	{
		ResultType popResult = ResultType::FAILED;
		udpServer.ifResultGet(
				[&popResult](auto &)
				{
					popResult = ResultType::SUCCESS;
				}
		);
		IN_CASE_CHECK(popResult == ResultType::SUCCESS);
	}

	// Check valid descriptor
	flame_ide::os::network::UdpServer popedUdpServer;
	udpServer.ifResult(
			[&popedUdpServer](os::network::UdpServer &&inputServer)
			{
				popedUdpServer = move(inputServer);
			}
	);
	const flame_ide::os::Socket popedNativeSocket = popedUdpServer.native();
	IN_CASE_CHECK_END(popedNativeSocket.descriptor == originalNativeSocket.descriptor);
}

int HandlerTest::udpServerCommunicate()
{
	const auto port = ::flame_ide::os::network::Ipv4::Port{ 65001 };
	const auto ip = ::flame_ide::os::network::Ipv4::localhost(port);

	::flame_ide::os::network::UdpClient udpClient{ ip };

	::flame_ide::os::network::UdpServer originalUdpServer{ port };
	Handler handler;
	Handler::ExpectedServerHandle updServerHandle =
			handler.pushUdp(::flame_ide::move(originalUdpServer));

	// Check valid handle
	{
		ResultType pushResult = ResultType::FAILED;
		updServerHandle.ifResultGet(
				[&pushResult](auto &)
				{
					pushResult = ResultType::SUCCESS;
				}
		);
		IN_CASE_CHECK(pushResult == ResultType::SUCCESS);
	}

	Handler::ServerHandle serverHandle;
	updServerHandle.ifResult(
			[&serverHandle](Handler::ServerHandle &&inputHandle)
			{
				serverHandle = move(inputHandle);
			}
	);

	// TODO: communicate a-la pingPong test in UdpTest

	return ResultType::SUCCESS;
}

int HandlerTest::udpClientPushPop()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

int HandlerTest::udpClientCommunicate()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

int HandlerTest::tcpServerPushPop()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

int HandlerTest::tcpServerCommunicate()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

int HandlerTest::tcpClientPushPop()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

int HandlerTest::tcpClientCommunicate()
{
	Handler handler;
	flame_ide::unused(handler);

	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
