#ifndef FLAMEIDE_SRC_OS_TESTS_NETWORK_HANDLERTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_NETWORK_HANDLERTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace tests
{

class HandlerTest: public ::AbstractTest
{
public:
	HandlerTest();
	virtual ~HandlerTest();

private:
	virtual int vStart() override;

private:
	int init();
	int pushUdpServer();
};

}}}} // namespace flame_ide::os::network::tests

#endif // FLAMEIDE_SRC_OS_TESTS_NETWORK_HANDLERTEST_HPP
