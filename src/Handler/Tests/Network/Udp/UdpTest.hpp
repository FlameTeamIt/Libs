#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_UDPTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_UDPTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class UdpTest: public ::AbstractTest
{
public:
	UdpTest();
	virtual ~UdpTest();

private:
	virtual int vStart();

	int init() noexcept;

	int pushPopServer() noexcept;
	int pushServer() noexcept;

	int pushPopClient() noexcept;
	int pushClient() noexcept;
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDPTEST_HPP
