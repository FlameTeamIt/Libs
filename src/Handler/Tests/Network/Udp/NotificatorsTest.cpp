#include <FlameIDE/../../src/Handler/Tests/Network/Udp/NotificatorsTest.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

NotificatorsTest::NotificatorsTest() : ::AbstractTest("udp::Notificators")
{}

NotificatorsTest::~NotificatorsTest() = default;

int NotificatorsTest::vStart()
{
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
