#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_CLIENTTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_CLIENTTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class ClientTest: public ::AbstractTest
{
public:
	ClientTest();
	virtual ~ClientTest();

private:
	virtual int vStart();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_CLIENTTEST_HPP
