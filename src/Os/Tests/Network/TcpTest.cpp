#include <FlameIDE/../../src/Os/Tests/Network/TcpTest.hpp>

#include <FlameIDE/Os/Network/TcpClient.hpp>
#include <FlameIDE/Os/Network/TcpServer.hpp>
#include <FlameIDE/Os/Threads/Thread.hpp>

#include <FlameIDE/Templates/IntegerIterator.hpp>
#include <FlameIDE/Templates/Range.hpp>

#define MESSAGE_PING "ping"
#define MESSAGE_PONG "pong"

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{
namespace // anonumous
{

// server - receive "ping" and send "pong"
struct TcpSeverPong: public os::threads::ThreadCrtp<TcpSeverPong>
{
public:
	TcpSeverPong(Types::size_t count, TcpServer &server)
			: countReceiveSend(count)
			, server{ server }
	{}

	~TcpSeverPong() noexcept override
	{}

	auto threadResult() const noexcept
	{
		return result;
	}

	void body() noexcept
	{
		if (!server)
		{
			std::cerr << "Pong (server): Invalid server socket" << std::endl;
			result = AbstractTest::FAILED;
			return;
		}

		auto range = templates::makeRange(
				templates::SizeTypeIterator(0)
				, templates::SizeTypeIterator(countReceiveSend)
		);

		auto client = server.accept();
		if (client.getStatus() < 0)
		{
			std::cerr << "Server: acception error: " << client.getStatus() << std::endl;
			result = ::AbstractTest::FAILED;
			return;
		}
		for (const auto i : range)
		{
			unused(i);

			char messageIn[sizeof(MESSAGE_PING)];
			auto rangeIn = templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(MESSAGE_PING)
			);

			auto tcpResult = client.numberBytesToRead();
			while (
					0 <= tcpResult
					&& tcpResult < static_cast<decltype(tcpResult)>(sizeof(MESSAGE_PONG))
			)
			{
				tcpResult = client.numberBytesToRead();
			}
			if (tcpResult < 0)
			{
				std::cerr << "Pong (server): Invalid sizeof receive 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			tcpResult = client.receive(rangeIn);
			if (tcpResult < 0)
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

			tcpResult = client.send(rangeOut);
			if (tcpResult < 0)
			{
				std::cerr << "Pong (server): Invalid send 'pong'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
	}

private:
	const Types::size_t countReceiveSend;
	TcpServer &server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

// client - send "ping" and receive "pong"
struct TcpClientPing: public os::threads::ThreadCrtp<TcpClientPing>
{
public:
	TcpClientPing(Types::size_t count, TcpClient &client)
		: countSendReceive(count)
		, client{ client }
	{}

	~TcpClientPing() noexcept
	{}

	auto threadResult() const noexcept
	{
		return result;
	}

	void body() noexcept
	{
		if (!client)
		{
			std::cerr << "Ping (client): Invalid client socket" << std::endl;
			result = AbstractTest::FAILED;
			return;
		}

		auto range = templates::makeRange(
				templates::SizeTypeIterator(0)
				, templates::SizeTypeIterator(countSendReceive)
		);

		{
			auto connectResult = client.connect();
			if (connectResult < 0)
			{
				std::cerr << "Client: connection error: " << connectResult << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
		for (const auto i : range)
		{
			unused(i);

			const char messageOut[] = MESSAGE_PING;
			auto rangeOut = templates::makeRange(
					reinterpret_cast<const byte_t *>(messageOut)
					, reinterpret_cast<const byte_t *>(messageOut) + sizeof(messageOut)
			);

			auto tcpResult = client.send(rangeOut);
			if (tcpResult < 0)
			{
				std::cerr << "Ping (client): Invalid send 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			tcpResult = client.numberBytesToRead();
			while (
					0 <= tcpResult
					&& tcpResult < static_cast<decltype(tcpResult)>(sizeof(MESSAGE_PONG))
			)
			{
				tcpResult = client.numberBytesToRead();
			}
			if (tcpResult != sizeof(MESSAGE_PONG))
			{
				std::cerr << "Ping (client): Invalid sizeof receive 'pong':" << tcpResult << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			char messageIn[sizeof(MESSAGE_PONG)];
			auto rangeIn = templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(messageIn)
			);
			tcpResult = client.receive(rangeIn);
			if (tcpResult < 0)
			{
				std::cerr << "Ping (client): Invalid receive 'pong': " << tcpResult << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
	}

private:
	const Types::size_t countSendReceive;
	TcpClient &client;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

} // namespace::anonumous
}}}} // namespace flame_ide::os::network::tests

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

TcpTest::TcpTest() : ::AbstractTest("TcpTest")
{}

TcpTest::~TcpTest() = default;

int TcpTest::vStart()
{
	CHECK_RESULT_SUCCESS_END(doTestCase(
			"Ping - pong"
			, [this]()
			{
				return pingPong();
			}
	));
}

int TcpTest::pingPong() noexcept
{
	const auto port = Ipv4::Port{ 65001 };
	const auto ip = Ipv4::localhost(port);

	TcpServer server{ port };
	TcpClient client{ ip };

	const Types::size_t count = 65536;
	TcpSeverPong pong{ count, server };
	TcpClientPing ping{ count, client };

	pong.run();
	ping.run();

	pong.join();
	ping.join();

	return (ping.getStatus() == AbstractTest::SUCCESS
			&& pong.getStatus() == AbstractTest::SUCCESS)
		? AbstractTest::SUCCESS
		: AbstractTest::FAILED;
}

}}}} // namespace flame_ide::os::network::tests
