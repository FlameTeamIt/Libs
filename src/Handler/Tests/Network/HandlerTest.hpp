#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_HANDLER_TEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_HANDLER_TEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class HandlerTest: public ::AbstractTest
{
public:
	HandlerTest();
	virtual ~HandlerTest();

private:
	virtual int vStart();

	int init();

	int udpServerPushPop();
	int udpServerCommunicate();

	int udpClientPushPop();
	int udpClientCommunicate();

	int tcpServerPushPop();
	int tcpServerCommunicate();

	int tcpClientPushPop();
	int tcpClientCommunicate();
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_HANDLER_TEST_HPP
