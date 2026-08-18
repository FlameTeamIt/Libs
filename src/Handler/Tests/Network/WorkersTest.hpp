#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_WORKERS_TEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_WORKERS_TEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class WorkersTest: public ::AbstractTest
{
public:
	WorkersTest();
	virtual ~WorkersTest();

private:
	virtual int vStart();
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_WORKERS_TEST_HPP
