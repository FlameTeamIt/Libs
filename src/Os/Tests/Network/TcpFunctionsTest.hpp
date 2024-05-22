#ifndef FLAMEIDE_SRC_OS_TESTS_NETWORK_TCPFUNCTIONSTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_NETWORK_TCPFUNCTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

class TcpFunctionsTest: public ::AbstractTest
{
public:
	TcpFunctionsTest();
	virtual ~TcpFunctionsTest() override;

private:
	virtual int vStart() override;

private:
	int initSockets() noexcept;

	int withoutWait() noexcept;
	int wait() noexcept;

	int pingPong() noexcept;
};

}}}} // namespace flame_ide::os::network::tests

#endif // FLAMEIDE_SRC_OS_TESTS_NETWORK_TCPFUNCTIONSTEST_HPP
