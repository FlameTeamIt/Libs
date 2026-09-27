#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_TEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_TEST_HPP

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
};


}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDP_TEST_HPP
