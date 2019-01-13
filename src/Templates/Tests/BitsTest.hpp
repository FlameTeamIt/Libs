#ifndef FLAMEIDE_TEMPLATES_TESTS_BITSTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_BITSTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Bits.hpp>

namespace flame_ide
{namespace test
{

class BitsTest: public AbstractTest
{
public:
	BitsTest();
	virtual ~BitsTest();

private:
	virtual int vStart();

	bool minimalType();
};

}}

#endif // FLAMEIDE_TEMPLATES_TESTS_BITSTEST_HPP
