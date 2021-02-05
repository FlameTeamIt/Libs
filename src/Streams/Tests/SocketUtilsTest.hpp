#ifndef FLAMEIDE_STREAMS_TESTS_SOCKETUTILSTEST_HPP
#define FLAMEIDE_STREAMS_TESTS_SOCKETUTILSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace streams
{namespace tests
{

class SocketUtilsTest : public ::AbstractTest
{
public:
	SocketUtilsTest();
	virtual ~SocketUtilsTest();

private:
	virtual int vStart();

private:
	int ipv4Test() noexcept;
	int ipv6Test() noexcept;
};

}}}

#endif // FLAMEIDE_STREAMS_TESTS_SOCKETUTILSTEST_HPP
