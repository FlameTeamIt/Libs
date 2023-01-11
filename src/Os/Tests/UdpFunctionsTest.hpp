#ifndef FLAMEIDE_SRC_OS_TESTS_UDPFUNCTIONSTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_UDPFUNCTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class UdpFunctionsTest: public ::AbstractTest
{
public:
	UdpFunctionsTest();
	virtual ~UdpFunctionsTest();

private:
	virtual int vStart();
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_UDPFUNCTIONSTEST_HPP
