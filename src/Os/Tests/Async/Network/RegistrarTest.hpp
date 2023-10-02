#ifndef FLAMEIDE_OS_ASYNC_TESTS_REGISTRARTEST_HPP
#define FLAMEIDE_OS_ASYNC_TESTS_REGISTRARTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Os/Network/Ipv4.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{namespace tests
{

struct RegistrarTest: public ::AbstractTest
{
	RegistrarTest();
	~RegistrarTest() = default;

	virtual int vStart() override;

private:
	int udpServer();
	int udpClient();
	int tcpServerLitener();
	int tcpServer();
	int tcpClient();

private:
	const os::network::Ipv4::Port port = 65530;
	os::network::Ipv4 ipv4 = os::network::Ipv4::localhost(port);
};

}}}}} // flame_ide::os::async::network::tests

#endif // FLAMEIDE_OS_ASYNC_TESTS_REGISTRARTEST_HPP
