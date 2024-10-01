#ifndef FLAMEIDE_SRC_HANDLER_NETWORK_WORKERTEST_HPP
#define FLAMEIDE_SRC_HANDLER_NETWORK_WORKERTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

class WorkerTest: public ::AbstractTest
{
public:
	WorkerTest();
	virtual ~WorkerTest();

private:
	virtual int vStart();
};

}}}} // namespace flame_ide::handler::network::tests

#endif // FLAMEIDE_SRC_HANDLER_NETWORK_WORKERTEST_HPP
