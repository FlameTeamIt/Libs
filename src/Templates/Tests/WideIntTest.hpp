#ifndef FLAMEIDE_TEMPLATES_TESTS_WIDEINTTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_WIDEINTTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/WideInt.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class WideIntTest: public AbstractTest
{
public:
	WideIntTest();
	virtual ~WideIntTest() = default;

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_WIDEINTTEST_HPP
