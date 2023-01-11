#include <FlameIDE/../../src/Os/Tests/UdpFunctionsTest.hpp>

#include <FlameIDE/../../src/Os/SocketFunctions.hpp>

#include <FlameIDE/Os/Ipv4.hpp>
#include <FlameIDE/Common/Byte.hpp>

#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Threads/Thread.hpp>

#include <iostream>

#define MESSAGE "hello"

static constexpr flame_ide::Types::size_t MESSAGE_SIZE = sizeof(MESSAGE);

namespace flame_ide
{namespace os
{namespace tests
{

struct UdpServerThread: public threads::Thread
{
	Socket server;
	AbstractTest::ResultType result = AbstractTest::SUCCESS;

private:
	void vRun() override
	{
		byte_t messageBuffer[::MESSAGE_SIZE];
		auto range = templates::makeRange(messageBuffer);

		SocketReceive client;
		const auto countBytes = socket::udpReceive(server, range, client);
		if (countBytes != sizeof(MESSAGE))
		{
			result = AbstractTest::FAILED;
			std::cerr << "server error = " << countBytes << std::endl;
			return;
		}
	}
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
	const char message[] = MESSAGE;

	const Ipv4 ip = Ipv4::localhost(65001);
	UdpServerThread thread;

	thread.server = socket::udpCreateServerSocket(ip.operator Ipv4::Address().port);
	thread.run();

	Socket client = socket::udpCreateClientSocket(ip);

	auto range = templates::makeRange(
			reinterpret_cast<const byte_t *>(message)
			, reinterpret_cast<const byte_t *>(message) + sizeof(MESSAGE)
	);

	const auto countBytes = socket::udpSend(client, range);
	thread.join();

	if (countBytes != sizeof(MESSAGE))
	{
		std::cerr << "client error = " << countBytes << std::endl;
	}

	return thread.result;
}


}}} // namespace flame_ide::os::tests
