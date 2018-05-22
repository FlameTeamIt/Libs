#ifndef TEST_TUPLE_HPP
#define TEST_TUPLE_HPP

#include <tests/Test.hpp>

#include <Templates/Tuple.hpp>

namespace flame_ide
{namespace test
{

class Tuple: public AbstractTest
{
public:
	Tuple();
	virtual ~Tuple();

private:
	virtual int vStart();

	flame_ide::templates::Tuple<char, short, int, long> tuple;
};


}}

#endif // TEST_TUPLE_HPP
