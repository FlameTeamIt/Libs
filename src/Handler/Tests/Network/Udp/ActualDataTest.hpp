#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_ACTUALDATATEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_ACTUALDATATEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class ActualDataTest: public ::AbstractTest
{
public:
	ActualDataTest();
	virtual ~ActualDataTest();

private:
	virtual int vStart();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDP_ACTUALDATATEST_HPP
