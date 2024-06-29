#ifndef FLAMEIDE_SRC_OS_TESTS_FILEFUNCTIONSTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_FILEFUNCTIONSTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class FileFunctionsTest: public ::AbstractTest
{
public:
	FileFunctionsTest();
	virtual ~FileFunctionsTest();

private:
	virtual int vStart();
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_FILEFUNCTIONSTEST_HPP
