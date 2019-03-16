#ifndef FLAMEIDE_TEMPLATES_TESTS_ASINTEGRALTYPETEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_ASINTEGRALTYPETEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/AsIntegralType.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class AsIntegralTypeTest: public AbstractTest
{
public:
	AsIntegralTypeTest();
	virtual ~AsIntegralTypeTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_ASINTEGRALTYPETEST_HPP
