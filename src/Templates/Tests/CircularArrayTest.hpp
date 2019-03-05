#ifndef FLAMEIDE_TEMPLATES_TESTS_CIRCULARARRAYTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_CIRCULARARRAYTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/CircularArray.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class CircularArrayTest: public AbstractTest
{
public:
	CircularArrayTest();
	~CircularArrayTest() = default;

private:
	virtual int vStart();
};

}}

#endif // CIRCULARARRAYTEST_HPP
