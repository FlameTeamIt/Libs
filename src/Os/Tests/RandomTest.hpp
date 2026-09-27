#ifndef FLAMEIDE_SRC_OS_TESTS_RANDOMTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_RANDOMTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class RandomTest: public ::AbstractTest
{
public:
	RandomTest();
	virtual ~RandomTest();

private:
	virtual int vStart();
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_RANDOMTEST_HPP
