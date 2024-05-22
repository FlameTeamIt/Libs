#ifndef FLAMEIDE_SRC_OS_TESTS_NETWORK_UDPFUNCTIONSTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_NETWORK_UDPFUNCTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

class UdpFunctionsTest: public ::AbstractTest
{
public:
	UdpFunctionsTest();
	virtual ~UdpFunctionsTest() override;

private:
	virtual int vStart() override;

private:
	int withoutWait() noexcept;
	int wait() noexcept;

	int pingPong() noexcept;
};

}}}} // namespace flame_ide::os::network::tests

#endif // FLAMEIDE_SRC_OS_TESTS_NETWORK_UDPFUNCTIONSTEST_HPP
