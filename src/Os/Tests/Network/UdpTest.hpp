#ifndef FLAMEIDE_SRC_OS_TESTS_NETWORK_UDPTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_NETWORK_UDPTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

class UdpTest: public ::AbstractTest
{
public:
	UdpTest();
	virtual ~UdpTest() override;

private:
	virtual int vStart() override;

private:
//	int withoutWait() noexcept;
//	int wait() noexcept;

	int pingPong() noexcept;
};

}}}} // namespace flame_ide::os::network::tests

#endif // FLAMEIDE_SRC_OS_TESTS_NETWORK_UDPTEST_HPP
