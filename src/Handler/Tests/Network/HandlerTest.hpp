#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_HANDLERTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_HANDLERTEST_HPP

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
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_HANDLERTEST_HPP