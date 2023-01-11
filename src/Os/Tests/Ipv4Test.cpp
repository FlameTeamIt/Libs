#include <FlameIDE/../../src/Os/Tests/Ipv4Test.hpp>

#include <cstring>
#include <FlameIDE/Os/Ipv4.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

bool operator==(const Ipv4::Address &address1, const Ipv4::Address &address2)
{
	const bool strcmpResult = !strcmp(address1.ip, address2.ip);
	return address1.port == address2.port && strcmpResult;
}

Ipv4Test::Ipv4Test() : ::AbstractTest("Ipv4")
{}

Ipv4Test::~Ipv4Test() = default;

int Ipv4Test::vStart()
{
	const Ipv4::Address expectedAddress = {"128.0.0.1", 1234};

	Ipv4 ipv4{"128.0.0.1", 1234};
	IN_CASE_CHECK((ipv4))

	Ipv4::Address address = ipv4;
	IN_CASE_CHECK_END((address == expectedAddress))
}

}}} // namespace flame_ide::os::tests
