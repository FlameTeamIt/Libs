#ifndef FLAMEIDE_TEMPLATES_TESTS_CIRCULARVECTORTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_CIRCULARVECTORTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/CircularVector.hpp>
#include "TestClass.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

class CircularVectorTest: public AbstractTest
{
public:
	CircularVectorTest();
	virtual ~CircularVectorTest();

private:
	virtual int vStart();

	templates::CircularVector<TestClass> circVector;
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_CIRCULARVECTORTEST_HPP
