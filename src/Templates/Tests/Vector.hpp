#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

#include <tests/Test.hpp>
#include <Templates/Vector.hpp>
#include <vector>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class Vector: public AbstractTest
{
public:
	Vector();
	virtual ~Vector();

	using TestVector = flame_ide::templates::Vector<TestClass>;

private:
	virtual int vStart();

	TestVector vector;
	std::vector<TestClass> stdvector;
};

}}

#endif // TEST_VECTOR_HPP
