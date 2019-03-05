#ifndef FLAMEIDE_TEMPLATES_TESTS_TUPLETEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_TUPLETEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Tuple.hpp>

namespace flame_ide
{namespace test
{

class TupleTest: public AbstractTest
{
public:
	TupleTest();
	virtual ~TupleTest();

private:
	virtual int vStart();

	flame_ide::templates::Tuple<char, short, int, long> tuple;
};


}}

#endif // FLAMEIDE_TEMPLATES_TESTS_TUPLETEST_HPP
