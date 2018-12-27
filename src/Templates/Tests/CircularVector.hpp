#ifndef TEST_CIRCULARVECTOR_HPP
#define TEST_CIRCULARVECTOR_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/CircularVector.hpp>
#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class CircularVector: public AbstractTest
{
public:
	CircularVector();
	virtual ~CircularVector();

private:
	virtual int vStart();

	templates::CircularVector<TestClass> circVector;
};

}}

#endif // TEST_CIRCULARVECTOR_HPP
