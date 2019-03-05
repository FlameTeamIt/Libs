#ifndef FLAMEIDE_TEMPLATES_TESTS_ARRAYTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_ARRAYTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/Array.hpp>

#include "TestClass.hpp"

#include <vector>

namespace flame_ide
{namespace test
{

class ArrayTest: public AbstractTest
{
public:
	ArrayTest();
	virtual ~ArrayTest();

private:
	virtual int vStart();

	flame_ide::templates::Array<TestClass, 10> array;
	std::vector<TestClass> stdvector;
};

}}

#endif // FLAMEIDE_TEMPLATES_TESTS_ARRAYTEST_HPP
