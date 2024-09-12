#ifndef FLAMEIDE_COMMON_TESTS_VOIDTYPETEST_HPP
#define FLAMEIDE_COMMON_TESTS_VOIDTYPETEST_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>

#include <tests/Test.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

class VoidTypeTest: public AbstractTest
{
public:
	VoidTypeTest();
	virtual ~VoidTypeTest();

private:
	virtual int vStart();
};

}}} // flame_ide::common::tests

#endif // FLAMEIDE_COMMON_TESTS_VOIDTYPETEST_HPP
