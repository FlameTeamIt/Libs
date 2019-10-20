#ifndef FLAMEIDE_TEMPLATES_TESTS_EXPECTEDTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_EXPECTEDTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Expected.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class ExpectedTest: public AbstractTest
{
public:
	ExpectedTest();
	virtual ~ExpectedTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_EXPECTEDTEST_HPP
