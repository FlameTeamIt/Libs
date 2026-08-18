#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_UDP_PROCESSINGTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_UDP_PROCESSINGTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

class ProcessingTest: public ::AbstractTest
{
public:
	ProcessingTest();
	virtual ~ProcessingTest();

private:
	virtual int vStart();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDP_PROCESSINGTEST_HPP
