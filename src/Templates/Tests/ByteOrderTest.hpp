#ifndef FLAMEIDE_TEMPLATES_TESTS_BYTEORDERTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_BYTEORDERTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/ByteOrder.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class ByteOrderTest: public AbstractTest
{
public:
	ByteOrderTest() : AbstractTest("ByteOrder")
	{}
	~ByteOrderTest() = default;

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_BYTEORDERTEST_HPP
