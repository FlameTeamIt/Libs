#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_NOTIFICATORSTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_NOTIFICATORSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class NotificatorsTest: public ::AbstractTest
{
public:
	NotificatorsTest();
	virtual ~NotificatorsTest();

private:
	virtual int vStart();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDP_NOTIFICATORSTEST_HPP
