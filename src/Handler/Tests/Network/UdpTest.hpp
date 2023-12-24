#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDPTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDPTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class UdpTest: public ::AbstractTest
{
public:
	UdpTest();
	virtual ~UdpTest();

private:
	virtual int vStart();

private:
	int init();
	int serverPushPop();
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDPTEST_HPP
