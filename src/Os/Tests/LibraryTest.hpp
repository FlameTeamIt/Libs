#ifndef FLAMEIDE_SRC_OS_TESTS_LIBRARYTEST_HPP
#define FLAMEIDE_SRC_OS_TESTS_LIBRARYTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

class LibraryTest: public ::AbstractTest
{
public:
	LibraryTest();
	virtual ~LibraryTest();

private:
	virtual int vStart();
};

}}} // namespace flame_ide::os::tests

#endif // FLAMEIDE_SRC_OS_TESTS_LIBRARYTEST_HPP
