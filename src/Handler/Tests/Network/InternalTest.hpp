#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_INTERNALTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_INTERNALTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class InternalTest: public ::AbstractTest
{
public:
	InternalTest();
	virtual ~InternalTest();

private:
	virtual int vStart();
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_INTERNALTEST_HPP
