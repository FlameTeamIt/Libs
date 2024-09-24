#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_TCPTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_TCPTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class TcpQueueTest: public ::AbstractTest
{
public:
	TcpQueueTest();
	virtual ~TcpQueueTest();

private:
	virtual int vStart();

private:
	int init();
	int serverPushPop();
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_TCPTEST_HPP