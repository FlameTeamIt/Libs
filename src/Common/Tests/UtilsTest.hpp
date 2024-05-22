#ifndef FLAMEIDE_COMMON_TESTS_UTILSTEST_HPP
#define FLAMEIDE_COMMON_TESTS_UTILSTEST_HPP

#include <FlameIDE/Common/Utils.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

class UtilsTest: public AbstractTest
{
public:
	UtilsTest();
	virtual ~UtilsTest();

private:
	virtual int vStart();

private:
	int length() noexcept;
};

}}}

#endif // FLAMEIDE_COMMON_TESTS_UTILSTEST_HPP
