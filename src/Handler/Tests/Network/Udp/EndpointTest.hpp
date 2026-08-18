#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_ENDPOINTTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_ENDPOINTTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class EndpointTest: public ::AbstractTest
{
public:
	EndpointTest();
	virtual ~EndpointTest();

private:
	virtual int vStart();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_ENDPOINTUDP_TEST_HPP
