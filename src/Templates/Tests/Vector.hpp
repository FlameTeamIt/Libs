#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <tests/Test.hpp>
#include <Templates/Vector.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class Vector: public AbstractTest
{
public:
	Vector();
	virtual ~Vector();

private:
	virtual int vStart();

	flame_ide::templates::Vector<TestClass> vector;
};

}}

#endif // TEST_VECTOR_HPP
