#ifndef FLAMEIDE_SRC_OS_TESTS_TCPTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_TCPTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class TcpTest: public ::AbstractTest
{
public:
	TcpTest();
	virtual ~TcpTest() override;

private:
	virtual int vStart() override;

	//private:
	//	int withoutWait() noexcept;
	//	int wait() noexcept;

	//	int pingPong() noexcept;
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_TCPTEST_HPP
