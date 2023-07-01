#include <FlameIDE/../../src/Os/Tests/Network/UdpTest.hpp>

#include <FlameIDE/Os/Network/UdpClient.hpp>
#include <FlameIDE/Os/Network/UdpServer.hpp>
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
struct UdpSeverPong: public os::threads::ThreadCrtp<UdpSeverPong>
{
public:
	UdpSeverPong(Types::size_t count, UdpServer &server)
		: countReceiveSend(count)
		, server{ server }
	{}

	~UdpSeverPong() noexcept override
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
		for (const auto i : range)
		{
			unused(i);
			auto client = server.wait();
			if (client.getStatus() != sizeof(MESSAGE_PING))
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

			auto udpResult = client.receive(rangeIn);
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

			udpResult = client.send(rangeOut);
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
	UdpServer &server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

// client - send "ping" and receive "pong"
struct UdpClientPing: public os::threads::ThreadCrtp<UdpClientPing>
{
public:
	UdpClientPing(Types::size_t count, UdpClient &client)
			: countSendReceive(count)
			, client(client)
	{}

	~UdpClientPing() noexcept
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
		for (const auto i : range)
		{
			unused(i);

			const char messageOut[] = MESSAGE_PING;
			auto rangeOut = templates::makeRange(
					reinterpret_cast<const byte_t *>(messageOut)
					, reinterpret_cast<const byte_t *>(messageOut) + sizeof(messageOut)
			);

			auto udpResult = client.send(rangeOut);
			if (udpResult < 0)
			{
				std::cerr << "Ping (client): Invalid send 'ping'" << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			udpResult = client.wait();
			if (udpResult != sizeof(MESSAGE_PONG))
			{
				std::cerr << "Ping (client): Invalid sizeof receive 'pong':" << udpResult << std::endl;
				result = AbstractTest::FAILED;
				return;
			}

			char messageIn[sizeof(MESSAGE_PONG)];
			auto rangeIn = templates::makeRange(
					reinterpret_cast<byte_t *>(messageIn)
					, reinterpret_cast<byte_t *>(messageIn) + sizeof(messageIn)
			);
			udpResult = client.receive(rangeIn);
			if (udpResult < 0)
			{
				std::cerr << "Ping (client): Invalid receive 'pong': " << udpResult << std::endl;
				result = AbstractTest::FAILED;
				return;
			}
		}
	}

private:
	const Types::size_t countSendReceive;
	UdpClient &client;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;
};

}
}}}} // namespace flame_ide::os::tests::anonumous

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

UdpTest::UdpTest() : ::AbstractTest("UdpTest")
{}

UdpTest::~UdpTest() = default;

int UdpTest::vStart()
{
	CHECK_RESULT_SUCCESS_END(doTestCase(
			"Ping - pong"
			, [this]()
			{
				return pingPong();
			}
	));
}

int UdpTest::pingPong() noexcept
{
	const auto port = Ipv4::Port{ 65001 };
	const auto ip = Ipv4::localhost(port);

	UdpServer server{ port };
	UdpClient client{ ip };

	const Types::size_t count = 65536;
	UdpSeverPong pong{ count, server };
	UdpClientPing ping{ count, client };

	pong.run();
	ping.run();

	pong.join();
	ping.join();

	if (ping.threadResult() == AbstractTest::SUCCESS
			&& pong.threadResult() == AbstractTest::SUCCESS)
	{
		return AbstractTest::SUCCESS;
	}
	return AbstractTest::FAILED;
}

}}}} // namespace flame_ide::os::network::tests
