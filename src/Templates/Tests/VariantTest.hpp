#ifndef FLAMEIDE_TEMPLATES_TESTS_VARIANTTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_VARIANTTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Variant.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

class VariantTest: public AbstractTest
{
public:
	VariantTest();
	virtual ~VariantTest();

private:
	virtual int vStart();
	bool testVariantStruct();
	bool testVariant();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_VARIANTTEST_HPP
