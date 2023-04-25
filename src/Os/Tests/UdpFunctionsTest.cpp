#include <FlameIDE/../../src/Os/Tests/UdpFunctionsTest.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/UdpSocketFunctions.hpp>

#include <FlameIDE/Common/Byte.hpp>

#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Templates/IntegerIterator.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/RaiiCaller.hpp>
#include <FlameIDE/Threads/Thread.hpp>

#include <iostream>

#define MESSAGE "hello"

#define MESSAGE_PING "ping"
#define MESSAGE_PONG "pong"

namespace flame_ide
{namespace os
{namespace tests
{

static constexpr flame_ide::Types::size_t MESSAGE_SIZE = sizeof(MESSAGE);
const Ipv4 ip = Ipv4::localhost(65001);

struct UdpServerNoWaitThread: public threads::Thread
{
public:
	UdpServerNoWaitThread() : server{ socket::createUdpServer(ip.operator Ipv4::Address().port) }
	{}

	~UdpServerNoWaitThread()
	{
		socket::destroy(server);
	}

	auto threadResult() const noexcept
	{
		return result;
	}
private:
	void vRun() override
	{
		byte_t messageBuffer[MESSAGE_SIZE];
		auto range = templates::makeRange(messageBuffer);

		SocketReceive client;
		const auto countBytes = socket::udp::receiveServer(server, range, {}, client);
		if (countBytes != sizeof(MESSAGE))
		{
			result = AbstractTest::FAILED;
			std::cerr << "server error = " << countBytes << std::endl;
			return;
		}
	}

private:
	Socket server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

struct UdpServerWaitThread: public threads::Thread
{
public:
	UdpServerWaitThread()
	{
		server = socket::createUdpServer(ip.operator Ipv4::Address().port);
	}

	~UdpServerWaitThread()
	{
		socket::destroy(server);
	}

	auto threadResult() const noexcept
	{
		return result;
	}
private:
	void vRun() override
	{
		byte_t messageBuffer[MESSAGE_SIZE];
		auto range = templates::makeRange(messageBuffer);

		SocketReceive client;
		const auto countNotReadBytes = socket::udp::waitServer(server, client);
		if (countNotReadBytes != sizeof(MESSAGE))
		{
			result = AbstractTest::FAILED;
			std::cerr << "wait server error = " << countNotReadBytes << std::endl;
			return;
		}

		const auto countReadBytes = socket::udp::receiveServer(server, range, {}, client);
		if (countReadBytes != sizeof(MESSAGE))
		{
			result = AbstractTest::FAILED;
			std::cerr << "receive server error = " << countReadBytes << std::endl;
			return;
		}
	}

private:
	Socket server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;

};

// server - receive "ping" and send "pong"
struct UdpPong: public threads::Thread
{
public:
	UdpPong(Types::size_t count)
		: countReceiveSend(count)
		, server(socket::createUdpServer(ip.operator Ipv4::Address().port))
	{}

	~UdpPong() noexcept
	{
		socket::destroy(server);
	}

	auto threadResult() const noexcept
	{
		return result;
	}
private:
	void vRun() override
	{
		if (server.descriptor == SOCKET_INVALID.descriptor)
		{
			std::cerr << "Pong (server): Invalid server socket" << std::endl;
			result = AbstractTest::FAILED;
			return;
		}

		auto range = templates::makeRange(
				templates::SizeTypeIterator(0)
				, templates::SizeTypeIterator(countReceiveSend)
		);
		for (const auto i : range)
		{
			unused(i);
			SocketReceive client;
			auto udpResult = socket::udp::waitServer(server, client);
			if (udpResult != sizeof(MESSAGE_PING))
			{
				std::cerr << "Pong (server): Invalid sizeof receive 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			char messageIn[sizeof(MESSAGE_PING)];
			auto rangeIn = templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(MESSAGE_PING)
			);
			udpResult = socket::udp::receiveServer(server, rangeIn, {}, client);
			if (udpResult < 0)
			{
				std::cerr << "Pong (server): Invalid receive 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;

			}

			const char messageOut[] = MESSAGE_PONG;
			auto rangeOut = templates::makeRange(
					reinterpret_cast<const byte_t *>(messageOut)
					, reinterpret_cast<const byte_t *>(messageOut) + sizeof(MESSAGE_PONG)
			);
			udpResult = socket::udp::send(client, rangeOut);
			if (udpResult < 0)
			{
				std::cerr << "Pong (server): Invalid send 'pong'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
	}

private:
	const Types::size_t countReceiveSend;
	Socket server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

// client - send "ping" and receive "pong"
struct UdpPing: public threads::Thread
{
public:
	UdpPing(Types::size_t count)
			: countSendReceive(count)
			, client(socket::createUdpClient(ip))
	{}

	~UdpPing() noexcept
	{
		socket::destroy(client);
	}

	auto threadResult() const noexcept
	{
		return result;
	}
private:
	void vRun() override
	{
		if (client.descriptor == SOCKET_INVALID.descriptor)
		{
			std::cerr << "Ping (client): Invalid client socket" << std::endl;
			result = AbstractTest::FAILED;
			return;
		}

		auto range = templates::makeRange(
				templates::SizeTypeIterator(0)
				, templates::SizeTypeIterator(countSendReceive)
		);
		for (const auto i : range)
		{
			unused(i);

			const char messageOut[] = MESSAGE_PING;
			socket::udp::ConstByteRange rangeOut = templates::makeRange(
					reinterpret_cast<const byte_t *>(messageOut)
					, reinterpret_cast<const byte_t *>(messageOut) + sizeof(messageOut)
			);

			auto udpResult = socket::udp::send(client, rangeOut);
			if (udpResult < 0)
			{
				std::cerr << "Ping (client): Invalid send 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			udpResult = socket::udp::waitClient(client);
			if (udpResult != sizeof(MESSAGE_PONG))
			{
				std::cerr << "Ping (client): Invalid sizeof receive 'pong'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			char messageIn[sizeof(MESSAGE_PONG)];
			socket::udp::ByteRange rangeIn = templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(messageIn)
			);
			udpResult = socket::udp::receiveClient(client, rangeIn, {});
			if (udpResult < 0)
			{
				std::cerr << "Ping (client): Invalid receive 'pong'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
	}

private:
	const Types::size_t countSendReceive;
	Socket client;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

}}} // namespace flame_ide::os::tests

namespace flame_ide
{namespace os
{namespace tests
{

UdpFunctionsTest::UdpFunctionsTest() : ::AbstractTest("UdpFunctions")
{}

UdpFunctionsTest::~UdpFunctionsTest() = default;

int UdpFunctionsTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"Read without waiting"
			, [this]()
			{
				return withoutWait();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Wait and read"
			, [this]()
			{
				return wait();
			}
	));
	CHECK_RESULT_SUCCESS_END(doTestCase(
			"Ping - pong"
			, [this]()
			{
				return pingPong();
			}
	));
}

int UdpFunctionsTest::withoutWait() noexcept
{
	const char message[] = MESSAGE;

	UdpServerNoWaitThread thread;
	thread.run();

	Socket client = socket::createUdpClient(ip);
	auto raii = templates::makeRaiiCaller(
			[&client](){ client = socket::createUdpClient(ip); }
			, [&client](){ socket::destroy(client); }
	);
	auto range = templates::makeRange(
			reinterpret_cast<const byte_t *>(message)
			, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE)
	);

	const auto result = socket::udp::send(client, range);
	thread.join();

	if (result != sizeof(MESSAGE))
	{
		std::cerr << "client error = " << result << std::endl;
	}

	return thread.threadResult();
}

int UdpFunctionsTest::wait() noexcept
{
	const char message[] = MESSAGE;

	UdpServerWaitThread thread;
	thread.run();

	Socket client;
	auto raii = templates::makeRaiiCaller(
			[&client](){ client = socket::createUdpClient(ip); }
			, [&client](){ socket::destroy(client); }
	);
	auto range = templates::makeRange(
			reinterpret_cast<const byte_t *>(message)
			, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE)
	);

	const auto result = socket::udp::send(client, range);
	thread.join();

	if (result != sizeof(MESSAGE))
	{
		std::cerr << "client error = " << result << std::endl;
	}

	return thread.threadResult();
}

int UdpFunctionsTest::pingPong() noexcept
{
	const Types::size_t count = 65536;
	UdpPong pong{ count };
	UdpPing ping{ count };

	pong.run();
	ping.run();

	pong.join();
	ping.join();

	if (pong.threadResult() != AbstractTest::SUCCESS)
	{
		return pong.threadResult();
	}
	return ping.threadResult();
}

}}} // namespace flame_ide::os::tests
