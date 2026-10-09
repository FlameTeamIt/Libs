#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_WORKER_BASE_TEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_WORKER_BASE_TEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class WorkerBaseTest: public ::AbstractTest
{
public:
	WorkerBaseTest();
	virtual ~WorkerBaseTest();

private:
	virtual int vStart();
};


}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_WORKER_BASE_TEST_HPP
