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
	virtual ~ActualDataTest() override;

private:
	virtual int vStart() override;

	ResultType init();

	// getEmptyMessage() test cases
	ResultType getEmptyMessage_One();
	ResultType getEmptyMessage_All();
	ResultType getEmptyMessage_AllOne();


	ResultType getFilledMessage_NoMessages();
	ResultType getFilledMessage_OneMessage();
	ResultType getFilledMessage_AllMessages();

	ResultType getFilledMessageSize();

	ResultType pingPong();
};

}}}}} // namespace flame_ide::handler::network::udp::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_UDP_ACTUALDATATEST_HPP
