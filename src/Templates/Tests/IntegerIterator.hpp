#ifndef TEST_INTEGERITERATOR_HPP
#define TEST_INTEGERITERATOR_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/IntegerIterator.hpp>

namespace flame_ide
{namespace test
{

class IntegerIterator: public AbstractTest
{
public:
	IntegerIterator();
	~IntegerIterator();

private:
	virtual int vStart();
};

}}

#endif // TEST_INTEGERITERATOR_HPP
