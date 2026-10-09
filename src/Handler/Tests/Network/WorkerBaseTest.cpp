#include <FlameIDE/../../src/Handler/Tests/Network/WorkerBaseTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

WorkerBaseTest::WorkerBaseTest() : ::AbstractTest("NOT_IMPLEMENTED WorkerBase")
{}

WorkerBaseTest::~WorkerBaseTest() = default;

int WorkerBaseTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
