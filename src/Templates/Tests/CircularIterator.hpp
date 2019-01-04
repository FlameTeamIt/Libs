#ifndef TEST_CIRCULARITERATOR_HPP
#define TEST_CIRCULARITERATOR_HPP

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

#endif // TEST_CIRCULARITERATOR_HPP
