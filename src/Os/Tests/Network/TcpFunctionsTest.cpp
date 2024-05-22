#include <FlameIDE/../../src/Os/Tests/Network/TcpFunctionsTest.hpp>

#include <FlameIDE/../../src/Os/Network/SocketFunctions.hpp>
#include <FlameIDE/../../src/Os/Network/TcpSocketFunctions.hpp>

#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Os/Constants.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

#include <FlameIDE/Templates/IntegerIterator.hpp>
#include <FlameIDE/Templates/RaiiCaller.hpp>
#include <FlameIDE/Templates/Range.hpp>

#define MESSAGE "hello"

#define MESSAGE_PING "ping"
#define MESSAGE_PONG "pong"

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{
namespace // anonymous
{

static constexpr flame_ide::Types::size_t MESSAGE_SIZE = sizeof(MESSAGE);
static const Ipv4 ip = Ipv4::localhost(65001);

struct TcpServerNoWaitThread: public os::threads::ThreadCrtp<TcpServerNoWaitThread>
{
public:
	TcpServerNoWaitThread(Socket &socket) : server{ socket }
	{
		if (server.descriptor == os::SOCKET_INVALID.descriptor)
		{
			result = AbstractTest::FAILED;
			return;
		}

		result = (socket::tcp::server::listen(server, 1) < 0)
				? AbstractTest::FAILED
				: AbstractTest::SUCCESS;
	}

	~TcpServerNoWaitThread()
	{}

	auto threadResult() const noexcept
	{
		return result;
	}

	void body() noexcept
	{
		if (result == AbstractTest::FAILED)
		{
			return;
		}

		Socket client = socket::tcp::server::accept(server);
		auto raii = templates::makeRaiiCaller(
				[&client]()
				{
					if (client.descriptor == os::SOCKET_INVALID.descriptor)
						return;
					socket::destroy(client);
				}
		);

		byte_t messageBuffer[MESSAGE_SIZE];
		auto range = templates::makeRange(messageBuffer);

		const auto countBytes = socket::tcp::receive(client, range);
		if (countBytes < 0)
		{
			result = AbstractTest::FAILED;
			std::cerr << "server error = " << countBytes << std::endl;
			return;
		}
	}

private:
	Socket &server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

struct TcpServerWaitThread: public os::threads::ThreadCrtp<TcpServerWaitThread>
{
public:
	TcpServerWaitThread(Socket &socket) : server{ socket }
	{
		if (server.descriptor == os::SOCKET_INVALID.descriptor)
		{
			result = AbstractTest::FAILED;
			return;
		}

		result = (socket::tcp::server::listen(server, 1) < 0)
				? AbstractTest::FAILED
				: AbstractTest::SUCCESS;
	}

	~TcpServerWaitThread()
	{}

	auto threadResult() const noexcept
	{
		return result;
	}

	void body() noexcept
	{
		if (result == AbstractTest::FAILED)
		{
			return;
		}

		Socket client = socket::tcp::server::accept(server);
		auto raii = templates::makeRaiiCaller(
				[&client]()
				{
					if (client.descriptor == os::SOCKET_INVALID.descriptor)
						return;
					socket::destroy(client);
				}
		);

		byte_t messageBuffer[MESSAGE_SIZE];
		auto range = templates::makeRange(messageBuffer);

		const auto countNotReadBytes = socket::tcp::waitBytes(client, sizeof(MESSAGE));
		if (countNotReadBytes < static_cast<Types::ssize_t>(sizeof(MESSAGE)))
		{
			result = AbstractTest::FAILED;
			std::cerr << "wait server error = " << countNotReadBytes << std::endl;
			return;
		}

		const auto countBytes = socket::tcp::receive(client, range);
		if (countBytes != sizeof(MESSAGE))
		{
			result = AbstractTest::FAILED;
			std::cerr << "receive server error = " << countBytes << std::endl;
			return;
		}
	}

private:
	Socket& server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

// server - receive "ping" and send "pong"
struct TcpPong: public os::threads::ThreadCrtp<TcpPong>
{
public:
	TcpPong(Types::size_t count)
		: countReceiveSend(count)
		, server{ socket::createTcpServer(ip.operator Ipv4::Address().port) }
	{
		result = (socket::tcp::server::listen(server, 1))
				? AbstractTest::FAILED
				: AbstractTest::SUCCESS;
	}

	~TcpPong() noexcept
	{
		socket::destroy(server);
	}

	auto threadResult() const noexcept
	{
		return result;
	}

	void body() noexcept
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

		auto client = socket::tcp::server::accept(server);
		for (const auto i : range)
		{
			unused(i);

			auto tcpResult = socket::tcp::waitBytes(client, sizeof(MESSAGE_PING));
			if (tcpResult != sizeof(MESSAGE_PING))
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
			tcpResult = socket::tcp::receive(client, rangeIn);
			if (tcpResult < 0)
			{
				std::cerr << "Pong (server): Invalid receive 'ping': " << tcpResult << std::endl;
				result = AbstractTest::FAILED;
				return;

			}

			const char messageOut[] = MESSAGE_PONG;
			auto rangeOut = templates::makeRange(
					reinterpret_cast<const byte_t *>(messageOut)
					, reinterpret_cast<const byte_t *>(messageOut) + sizeof(MESSAGE_PONG)
			);
			tcpResult = socket::tcp::send(client, rangeOut);
			if (tcpResult < 0)
			{
				std::cerr << "Pong (server): Invalid send 'pong' " << tcpResult << std::endl;
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
struct TcpPing: public os::threads::ThreadCrtp<TcpPing>
{
public:
	TcpPing(Types::size_t count)
		: numberSendReceive(count)
		, client(socket::createTcpClient(ip))
	{}

	~TcpPing() noexcept
	{
		socket::destroy(client);
	}

	auto threadResult() const noexcept
	{
		return result;
	}

	void body() noexcept
	{
		if (client.descriptor == SOCKET_INVALID.descriptor)
		{
			std::cerr << "Ping (client): Invalid client socket" << std::endl;
			result = AbstractTest::FAILED;
			return;
		}

		auto range = templates::makeRange(
				templates::SizeTypeIterator(0)
				, templates::SizeTypeIterator(numberSendReceive)
		);

		auto tcpResult = socket::tcp::client::connect(client);
		if (tcpResult != static_cast<os::Status>(::AbstractTest::SUCCESS))
		{
			std::cerr << "Ping (client): Invalid connect(): " << tcpResult << std::endl;
			result = AbstractTest::FAILED;
			return;
		}

		for (const auto i : range)
		{
			unused(i);

			const char messageOut[] = MESSAGE_PING;
			socket::tcp::ConstByteRange rangeOut = templates::makeRange(
					reinterpret_cast<const byte_t *>(messageOut)
					, reinterpret_cast<const byte_t *>(messageOut) + sizeof(messageOut)
			);

			auto tcpSizeResult = socket::tcp::send(client, rangeOut);
			if (tcpSizeResult < 0)
			{
				std::cerr << "Ping (client): Invalid send 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			tcpSizeResult = socket::tcp::waitBytes(client, sizeof(MESSAGE_PONG));
			if (tcpSizeResult != sizeof(MESSAGE_PONG))
			{
				std::cerr << "Ping (client): Invalid sizeof receive 'pong'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			char messageIn[sizeof(MESSAGE_PONG)];
			socket::tcp::ByteRange rangeIn = templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(messageIn)
			);
			tcpSizeResult = socket::tcp::receive(client, rangeIn);
			if (tcpSizeResult < 0)
			{
				std::cerr << "Ping (client): Invalid receive 'pong'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
	}

private:
	const Types::size_t numberSendReceive;
	Socket client;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

} // namespace anonymous
}}}} // namespace flame_ide::os::network::tests

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

TcpFunctionsTest::TcpFunctionsTest() : ::AbstractTest("TcpFunctions")
{}

TcpFunctionsTest::~TcpFunctionsTest() = default;

int TcpFunctionsTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"Create client and server"
			, [this]()
			{
				return initSockets();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Read without waiting"
			, [this]()
			{
				return withoutWait();
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Read with waiting"
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

int TcpFunctionsTest::initSockets() noexcept
{
	auto server = socket::createTcpServer(ip.operator Ipv4::Address().port);
	IN_CASE_CHECK(server.descriptor != os::SOCKET_INVALID.descriptor);
	{
		os::Status status = os::STATUS_SUCCESS;
		{
			auto raiiServer = templates::makeRaiiCaller([&]() {
					status = socket::destroy(server);
			});
		}
		IN_CASE_CHECK(status == os::STATUS_SUCCESS);
	}

	auto client = socket::createTcpClient(ip);
	IN_CASE_CHECK(client.descriptor != os::SOCKET_INVALID.descriptor);
	{
		os::Status status = os::STATUS_SUCCESS;
		{
			auto raiiClient = templates::makeRaiiCaller([&]() {
					status = socket::destroy(client);
			});
		}
		IN_CASE_CHECK(status == os::STATUS_SUCCESS);
	}

	return AbstractTest::SUCCESS;
}

int TcpFunctionsTest::withoutWait() noexcept
{
	const char message[] = MESSAGE;

	Socket server = socket::createTcpServer(ip.operator Ipv4::Address().port);
	IN_CASE_CHECK(server.descriptor != os::SOCKET_INVALID.descriptor);
	auto raiiServer = templates::makeRaiiCaller(
			[&server](){ socket::destroy(server); }
	);

	TcpServerNoWaitThread thread{ server };
	IN_CASE_CHECK(thread.threadResult() == AbstractTest::SUCCESS);

	thread.run();

	Socket client = socket::createTcpClient(ip);
	auto raiiClient = templates::makeRaiiCaller(
			[&client](){ socket::destroy(client); }
	);
	auto range = templates::makeRange(
			reinterpret_cast<const byte_t *>(message)
			, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE)
	);

	auto result = socket::tcp::client::connect(client);
	IN_CASE_CHECK(result == AbstractTest::SUCCESS);

	auto sizeResult = socket::tcp::send(client, range);
	if (sizeResult != sizeof(MESSAGE))
	{
		std::cerr << "client error = " << result << std::endl;
	}

	thread.join();
	return thread.threadResult();
}

int TcpFunctionsTest::wait() noexcept
{
	const char message[] = MESSAGE;

	Socket server = socket::createTcpServer(ip.operator Ipv4::Address().port);
	IN_CASE_CHECK(server.descriptor != os::SOCKET_INVALID.descriptor);
	auto raiiServer = templates::makeRaiiCaller(
			[&server](){ socket::destroy(server); }
	);

	TcpServerWaitThread thread{ server };
	IN_CASE_CHECK(thread.threadResult() == AbstractTest::SUCCESS);

	thread.run();

	Socket client;
	auto raii = templates::makeRaiiCaller(
			[&client](){ client = socket::createTcpClient(ip); }
			, [&client](){ socket::destroy(client); }
	);
	auto range = templates::makeRange(
			reinterpret_cast<const byte_t *>(message)
			, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE)
	);

	auto result = socket::tcp::client::connect(client);
	IN_CASE_CHECK(result == AbstractTest::SUCCESS);

	auto sizeResult = socket::tcp::send(client, range);
	if (sizeResult != sizeof(MESSAGE))
	{
		std::cerr << "client error = " << result << std::endl;
	}

	thread.join();
	return thread.threadResult();
}

int TcpFunctionsTest::pingPong() noexcept
{
	const Types::size_t count = 65536;
	TcpPong pong{ count };
	IN_CASE_CHECK(pong.threadResult() == AbstractTest::SUCCESS);

	TcpPing ping{ count };
	IN_CASE_CHECK(ping.threadResult() == AbstractTest::SUCCESS);

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

}}}} // namespace flame_ide::os::network::tests
