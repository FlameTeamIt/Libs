#include <FlameIDE/../../src/Handler/Tests/Network/WorkerTest.hpp>
#include <FlameIDE/../../src/Handler/Network/Worker.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

WorkerTest::WorkerTest() : ::AbstractTest("Worker")
{}

WorkerTest::~WorkerTest() = default;

int WorkerTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
