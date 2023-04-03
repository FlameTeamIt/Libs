#include <FlameIDE/../../src/Os/Tests/UdpTest.hpp>

#include <FlameIDE/Os/UdpClient.hpp>
#include <FlameIDE/Os/UdpServer.hpp>

#define MESSAGE_PING "ping"
#define MESSAGE_PONG "pong"

namespace flame_ide
{namespace os
{namespace tests
{

UdpTest::UdpTest() : ::AbstractTest("UdpTest")
{}

UdpTest::~UdpTest() = default;

int UdpTest::vStart()
{
	const auto port = Ipv4::Port{ 65001 };
	const auto ip = Ipv4::localhost(port);

	UdpClient client{ ip };
	UdpServer server{ port };

	return AbstractTest::SUCCESS;
}

}}} // namespace flame_ide::os::tests
