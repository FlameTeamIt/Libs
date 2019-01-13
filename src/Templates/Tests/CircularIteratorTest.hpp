#ifndef FLAMEIDE_TEMPLATES_TESTS_CIRCULARITERATORTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_CIRCULARITERATORTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>

namespace flame_ide
{namespace test
{

class CircularIteratorTest: public AbstractTest
{
public:
	CircularIteratorTest() : AbstractTest("CircularIterator")
	{}
	~CircularIteratorTest() = default;

private:
	virtual int vStart();
};


}}

#endif // FLAMEIDE_TEMPLATES_TESTS_CIRCULARITERATORTEST_HPP
