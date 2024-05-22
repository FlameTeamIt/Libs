#include "SocketUtilsTest.hpp"

#include <FlameIDE/Streams/SocketUtils.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

SocketUtilsTest::SocketUtilsTest() : ::AbstractTest("SocketUtilsTest")
{}

SocketUtilsTest::~SocketUtilsTest() = default;

int SocketUtilsTest::vStart()
{
	IN_CASE_CHECK(!ipv4Test());
	IN_CASE_CHECK_END(!ipv6Test());
}

int SocketUtilsTest::ipv4Test() noexcept
{
	return 0;
}

int SocketUtilsTest::ipv6Test() noexcept
{
	return 0;
}


}}} // flame_ide::streams::tests
