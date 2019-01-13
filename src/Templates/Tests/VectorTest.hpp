#ifndef FLAMEIDE_TEMPLATES_TESTS_VECTORTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_VECTORTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/Vector.hpp>
#include <vector>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class VectorTest: public AbstractTest
{
public:
	VectorTest();
	virtual ~VectorTest();

	using TestVector = flame_ide::templates::Vector<TestClass>;

private:
	virtual int vStart();

	TestVector vector;
	std::vector<TestClass> stdvector;
};

}}

#endif // FLAMEIDE_TEMPLATES_TESTS_VECTORTEST_HPP
