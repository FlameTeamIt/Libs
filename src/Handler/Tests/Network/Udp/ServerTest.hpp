#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_SERVERTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_SERVERTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class ServerTest: public ::AbstractTest
{
public:
	ServerTest();
	virtual ~ServerTest();

private:
	virtual int vStart();

private:
	int init() noexcept;
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_SERVERTEST_HPP
