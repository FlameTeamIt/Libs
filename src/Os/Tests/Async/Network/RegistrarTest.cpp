#include <FlameIDE/../../src/Os/Tests/Async/Network/RegistrarTest.hpp>

#include <FlameIDE/Os/Async/Network/Registrar.hpp>

#include <FlameIDE/Os/Network/UdpServer.hpp>
#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Network/TcpClient.hpp>

#include <FlameIDE/Os/Threads/ConditionVariable.hpp>
#include <FlameIDE/Os/Threads/Mutex.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

#include <FlameIDE/Templates/RaiiCaller.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{namespace tests
{
namespace anonymous
{namespace
{

class NotificatorTest: public NotificatorBase
{
public:
	threads::ConditionVariable &condition() noexcept
	{
		return condvar;
	}

private:
	virtual void operator()() const noexcept override
	{
		condvar.notify();
	}

private:
	mutable threads::Mutex mutex;
	mutable threads::ConditionVariable condvar{ mutex };
};

class NotificationTestThread: public threads::ThreadCrtp<NotificationTestThread>
{
public:
	NotificationTestThread(threads::ConditionVariable &initCondvar) :
			condvar{ &initCondvar }
	{}

	void body() noexcept
	{
		condvar->wait();
		{
			threads::Locker locker{ mutex };
			notified = true;
		}
	}

	bool isNotified() const
	{
		threads::Locker locker{ mutex };
		return notified;
	}

private:
	threads::ConditionVariable *condvar = nullptr;
	mutable threads::Mutex mutex;
	bool notified = false;
};

}} // namespace anonymous
}}}}} // flame_ide::os::async::network::tests

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
	CHECK_RESULT_SUCCESS(doTestCase(
			"UdpServer notify"
			, [this]
			{
				return udpNotify();
			}
	));
	return RegistrarTest::SUCCESS;
}

int RegistrarTest::udpServer()
{
	os::network::UdpServer server{ port };
	os::network::UdpClient client{ ipv4 };

	Registrar registar;
	{
		IN_CASE_CHECK(registar.add(server) == os::STATUS_SUCCESS);
		const auto message = MESSAGE_PING;
		{
			const auto result = client.send(templates::makeRange(
					reinterpret_cast<const byte_t *>(message)
					, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE_PING)
			));
			IN_CASE_CHECK(result == sizeof(MESSAGE_PING));
		}

		// Wait
		os::SocketDescriptor resultDescriptor = os::SOCKET_INVALID.descriptor;
		for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultDescriptor; --i)
		{
			resultDescriptor = registar.popUdpServer();
		}
		IN_CASE_CHECK(resultDescriptor != os::SOCKET_INVALID.descriptor);
		IN_CASE_CHECK(resultDescriptor == server.native().descriptor);

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
		IN_CASE_CHECK(registar.remove(server) == os::STATUS_SUCCESS);
	}
	auto raii = templates::makeRaiiCaller([&registar](){ registar.clear(); });

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
		auto raiiServer = templates::makeRaiiCaller(
				[&server, &registar]() { registar.add(server); }
				, [&server, &registar]() { registar.remove(server); }
		);

		const auto message = MESSAGE_PING;
		const auto result = client.send(templates::makeRange(
				reinterpret_cast<const byte_t *>(message)
				, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE_PING)
		));
		IN_CASE_CHECK(result == sizeof(MESSAGE_PING));

		// Wait
		os::SocketDescriptor resultDescriptor = os::SOCKET_INVALID.descriptor;
		for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultDescriptor; --i)
		{
			resultDescriptor = registar.popUdpServer();
		}
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

			IN_CASE_CHECK(
					sizeof(MESSAGE_PONG) == fromServer.send(templates::makeRange(
							reinterpret_cast<const byte_t *>(MESSAGE_PONG)
							, reinterpret_cast<const byte_t *>(MESSAGE_PONG)
									+ sizeof(MESSAGE_PONG)
					))
			);
			IN_CASE_CHECK(client.wait() == sizeof(MESSAGE_PONG));
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

			// Wait
			os::SocketDescriptor resultDescriptor = os::SOCKET_INVALID.descriptor;
			for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultDescriptor; --i)
			{
				resultDescriptor = registar.popUdpClient();
			}
			IN_CASE_CHECK(resultDescriptor == client.native().descriptor);
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

	// Wait
	decltype(registar.popTcpServerAcception()) resultConnection = {};
	for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultConnection.server; --i)
	{
		resultConnection = registar.popTcpServerAcception(); // FIXME: под MinGW периодически
	}
	IN_CASE_CHECK(resultConnection.server != os::SOCKET_INVALID.descriptor);
	IN_CASE_CHECK(resultConnection.server == server.native().descriptor);

	IN_CASE_CHECK(client.disconnect() == os::STATUS_SUCCESS);

	auto control = os::network::NetworkBase::callbacks();
	IN_CASE_CHECK(control.destroy(resultConnection.client) == os::STATUS_SUCCESS);

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

	// Wait
	decltype(registar.popTcpServerAcception()) resultConnection = {};
	for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultConnection.server; --i)
	{
		resultConnection = registar.popTcpServerAcception();
	}
	IN_CASE_CHECK(resultConnection.server == server.native().descriptor);

	os::network::TcpServer::WithClient serverConnection{
			resultConnection.client, os::STATUS_SUCCESS
	};
	IN_CASE_CHECK(registar.add(serverConnection) == os::STATUS_SUCCESS);
	IN_CASE_CHECK(client.disconnect() == os::STATUS_SUCCESS);

	// Wait
	os::SocketDescriptor resultDescriptor = os::SOCKET_INVALID.descriptor;
	for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultDescriptor; --i)
	{
		resultDescriptor = registar.popTcpServer();
	}
	IN_CASE_CHECK(resultDescriptor != os::SOCKET_INVALID.descriptor);
	IN_CASE_CHECK(resultDescriptor == serverConnection.native().descriptor);

	IN_CASE_CHECK(registar.remove(serverConnection) == os::STATUS_SUCCESS);

	return RegistrarTest::SUCCESS;
}

int RegistrarTest::tcpClient()
{
	const auto &callbacks = os::network::NetworkBase::callbacks();

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

	// Wait
	decltype(registar.popTcpServerAcception()) resultConnection = {};
	for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultConnection.server; --i)
	{
		resultConnection = registar.popTcpServerAcception();
	}
	IN_CASE_CHECK(
			callbacks.destroy(resultConnection.client) == os::STATUS_SUCCESS
	);

	// Wait
	os::SocketDescriptor resultDescriptor = os::SOCKET_INVALID.descriptor;
	for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultDescriptor; --i)
	{
		resultDescriptor = registar.popTcpClient();
	}
	IN_CASE_CHECK(resultDescriptor != os::SOCKET_INVALID.descriptor);
	IN_CASE_CHECK(resultDescriptor == client.native().descriptor);

	return RegistrarTest::SUCCESS;
}

int RegistrarTest::udpNotify()
{
	os::network::UdpServer server{ port };
	os::network::UdpClient client{ ipv4 };

	anonymous::NotificatorTest notificator;

	anonymous::NotificationTestThread thread{ notificator.condition() };
	thread.run();

	Registrar registar;
	registar.setNotificator(notificator);

	{
		IN_CASE_CHECK(registar.add(server) == os::STATUS_SUCCESS);
		const auto message = MESSAGE_PING;
		{
			const auto result = client.send(templates::makeRange(
					reinterpret_cast<const byte_t *>(message)
					, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE_PING)
			));
			IN_CASE_CHECK(result == sizeof(MESSAGE_PING));
		}

		// Wait
		os::SocketDescriptor resultDescriptor = os::SOCKET_INVALID.descriptor;
		for (auto i = numberOfTries; i != 0 && os::SOCKET_INVALID.descriptor == resultDescriptor; --i)
		{
			resultDescriptor = registar.popUdpServer();
		}
		IN_CASE_CHECK(resultDescriptor != os::SOCKET_INVALID.descriptor);
		IN_CASE_CHECK(resultDescriptor == server.native().descriptor);

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
		IN_CASE_CHECK(registar.remove(server) == os::STATUS_SUCCESS);
	}

	auto raii = templates::makeRaiiCaller(
			[&registar]()
			{
				registar.clear();
				registar.unsetNotificator();
			}
	);

	thread.join();
	IN_CASE_CHECK(thread.isNotified() == true);

	return RegistrarTest::SUCCESS;
}

}}}}} // flame_ide::os::async::network::tests
