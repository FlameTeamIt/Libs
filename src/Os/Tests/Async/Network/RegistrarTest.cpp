#include <FlameIDE/../../src/Os/Tests/Async/Network/RegistrarTest.hpp>

#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Network/TcpClient.hpp>

#include <FlameIDE/Templates/RaiiCaller.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{namespace tests
{

constexpr Types::uichar_t MESSAGE_PING[] = "ping";
constexpr Types::uichar_t MESSAGE_PONG[] = "pong";

RegistrarTest::RegistrarTest() : ::AbstractTest("AsyncNetworkRegistrar")
{}

int RegistrarTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"UdpServer receiving signal"
			, [this]
			{
				return udpServer();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"UdpClient receiving signal"
			, [this]
			{
				return udpClient();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"TcpServer listener receiving signal"
			, [this]
			{
				return tcpServerLitener();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"TcpServer receiving signal"
			, [this]
			{
				return tcpServer();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"TcpClient receiving signal"
			, [this]
			{
				return tcpClient();
			}
	));
	return RegistrarTest::SUCCESS;
}

int RegistrarTest::udpServer()
{
	os::network::UdpServer server{ port };
	os::network::UdpClient client{ ipv4 };

	Registrar registar;
	auto raii = templates::makeRaiiCaller([&registar](){ registar.clear(); });

	IN_CASE_CHECK(registar.add(server) == os::STATUS_SUCCESS);
	const auto message = MESSAGE_PING;
	{
		const auto result = client.send(templates::makeRange(
				reinterpret_cast<const byte_t *>(message)
				, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE_PING)
		));
		IN_CASE_CHECK(result == sizeof(MESSAGE_PING));
	}
	auto fromServer = server.wait();
	IN_CASE_CHECK(fromServer.getStatus() == sizeof(MESSAGE_PING));
	{
		char messageIn[sizeof(MESSAGE_PING)];
		const auto result = fromServer.receive(templates::makeRange(
				reinterpret_cast<byte_t *>(messageIn)
				, reinterpret_cast<byte_t *>(messageIn) + sizeof(messageIn)
		));
		IN_CASE_CHECK(result == sizeof(messageIn))
	}
	IN_CASE_CHECK(registar.popUdpServer() == server.native().descriptor);
	IN_CASE_CHECK(registar.remove(server) == os::STATUS_SUCCESS);

	return RegistrarTest::SUCCESS;
}

int RegistrarTest::udpClient()
{
	os::network::UdpServer server{ port };
	os::network::UdpClient client{ ipv4 };

	Registrar registar;
	auto raii = templates::makeRaiiCaller([&registar](){ registar.clear(); });

	// server
	{
		auto raii = templates::makeRaiiCaller(
				[&server, &registar]() { registar.add(server); }
				, [&server, &registar]() { registar.remove(server); }
		);

		const auto message = MESSAGE_PING;
		const auto result = client.send(templates::makeRange(
				reinterpret_cast<const byte_t *>(message)
				, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE_PING)
		));
		IN_CASE_CHECK(result == sizeof(MESSAGE_PING));
		registar.popUdpServer();
	}

	// client
	{
		IN_CASE_CHECK(registar.add(client) == os::STATUS_SUCCESS);

		auto fromServer = server.wait();
		{
			char messageIn[sizeof(MESSAGE_PING)];
			fromServer.receive(templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(messageIn)
			));

			const auto messageOut = MESSAGE_PONG;
			IN_CASE_CHECK(
					sizeof(messageOut) == fromServer.send(templates::makeRange(
							reinterpret_cast<const byte_t *>(messageOut)
							, reinterpret_cast<const byte_t *>(messageOut)
									+ sizeof(messageOut)
					))
			);
			IN_CASE_CHECK(client.wait() == sizeof(messageOut));
		}

		{
			char messageIn[sizeof(MESSAGE_PING)];
			IN_CASE_CHECK(
					sizeof(messageIn) == client.receive(templates::makeRange(
							reinterpret_cast<byte_t *>(messageIn)
							, reinterpret_cast<byte_t *>(messageIn)
									+ sizeof(messageIn)
					))
			);
			IN_CASE_CHECK(registar.popUdpClient() == client.native().descriptor);
		}
		IN_CASE_CHECK(registar.remove(client) == os::STATUS_SUCCESS);
	}
	return RegistrarTest::SUCCESS;
}

int RegistrarTest::tcpServerLitener()
{
	Registrar registar;
	auto raii = templates::makeRaiiCaller([&registar](){ registar.clear(); });

	os::network::TcpServer server{ port };
	os::network::TcpClient client{ ipv4 };

	IN_CASE_CHECK(registar.add(server) == os::STATUS_SUCCESS);
	IN_CASE_CHECK(client.connect() == os::STATUS_SUCCESS);

	auto connection = registar.popTcpServerAcception();
	IN_CASE_CHECK(connection.server == server.native().descriptor);

	IN_CASE_CHECK(client.disconnect() == os::STATUS_SUCCESS);

	auto control = os::network::NetworkBase::nativeControl();
	IN_CASE_CHECK(control.destroy(connection.client) == os::STATUS_SUCCESS);

	IN_CASE_CHECK(registar.remove(server) == os::STATUS_SUCCESS);

	return RegistrarTest::SUCCESS;
}

int RegistrarTest::tcpServer()
{
	os::network::TcpServer server{ port };
	os::network::TcpClient client{ ipv4 };

	Registrar registar;
	auto raii = templates::makeRaiiCaller(
			[&registar, &server]() -> void
			{
				[&](){ IN_CASE_CHECK_END(
						registar.add(server) == os::STATUS_SUCCESS
				); }();
			}
			, [&registar, &server]() -> void
			{
				[&](){ IN_CASE_CHECK_END(
						registar.remove(server) == os::STATUS_SUCCESS
				); }();
				registar.clear();
			}
	);

	IN_CASE_CHECK(client.connect() == os::STATUS_SUCCESS);
	auto connection = registar.popTcpServerAcception();
	IN_CASE_CHECK(connection.server == server.native().descriptor);

	os::network::TcpServer::WithClient serverConnection{
			connection.client, os::STATUS_SUCCESS
	};
	IN_CASE_CHECK(registar.add(serverConnection) == os::STATUS_SUCCESS);
	IN_CASE_CHECK(client.disconnect() == os::STATUS_SUCCESS);
	IN_CASE_CHECK(registar.popTcpServer() == serverConnection.native().descriptor);
	IN_CASE_CHECK(registar.remove(serverConnection) == os::STATUS_SUCCESS);

	return RegistrarTest::SUCCESS;
}

int RegistrarTest::tcpClient()
{
	auto nativeControl = os::network::NetworkBase::nativeControl;

	os::network::TcpServer server{ port };
	os::network::TcpClient client{ ipv4 };

	Registrar registar;
	auto raii = templates::makeRaiiCaller(
			[&registar, &server]() -> void
			{
				[&](){ IN_CASE_CHECK_END(
						registar.add(server) == os::STATUS_SUCCESS
				); }();
			}
			, [&registar, &server]() -> void
			{
				[&](){ IN_CASE_CHECK_END(
						registar.remove(server) == os::STATUS_SUCCESS
				); }();
			}
	);

	IN_CASE_CHECK(client.connect() == os::STATUS_SUCCESS);
	IN_CASE_CHECK(registar.add(client) == os::STATUS_SUCCESS);
	auto connection = registar.popTcpServerAcception();
	IN_CASE_CHECK(
			nativeControl().destroy(connection.client) == os::STATUS_SUCCESS
	);
	auto descriptor = registar.popTcpClient();
	IN_CASE_CHECK(descriptor == client.native().descriptor);

	return RegistrarTest::SUCCESS;
}

}}}}} // flame_ide::os::async::network::tests
