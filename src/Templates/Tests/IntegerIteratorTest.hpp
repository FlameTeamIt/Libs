#ifndef FLAMEIDE_TEMPLATES_TESTS_INTEGERITERATORTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_INTEGERITERATORTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/IntegerIterator.hpp>

namespace flame_ide
{namespace test
{

class IntegerIteratorTest: public AbstractTest
{
public:
	IntegerIteratorTest();
	~IntegerIteratorTest();

private:
	virtual int vStart();
};

}}

#endif // FLAMEIDE_TEMPLATES_TESTS_INTEGERITERATORTEST_HPP
