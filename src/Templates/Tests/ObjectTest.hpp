#ifndef FLAMEIDE_TEMPLATES_TESTS_OBJECTTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_OBJECTTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class ObjectTest: public ::AbstractTest
{
public:
	ObjectTest();
	virtual ~ObjectTest() override;

private:
	virtual int vStart() override;

private:
	int init();
	int moving();

};

}}} // flame_ide::templates::test

#endif // FLAMEIDE_TEMPLATES_TESTS_OBJECTTEST_HPP
