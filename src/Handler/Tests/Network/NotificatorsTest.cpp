#include <FlameIDE/../../src/Handler/Tests/Network/NotificatorsTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace tests
{

NotificatorsTest::NotificatorsTest() : ::AbstractTest("Notificators")
{}

NotificatorsTest::~NotificatorsTest() = default;

int NotificatorsTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}} // namespace flame_ide::handler::network::tests
