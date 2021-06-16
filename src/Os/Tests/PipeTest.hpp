#ifndef FLAMEIDE_SRC_OS_TESTS_PIPETEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_PIPETEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class PipeTest: public ::AbstractTest
{
public:
	PipeTest();
	virtual ~PipeTest();

private:
	virtual int vStart();
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_PIPETEST_HPP
