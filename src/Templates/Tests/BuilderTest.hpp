#ifndef FLAMEIDE_TEMPLATES_TESTS_BUILDERTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_BUILDERTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Builder.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class BuilderTest: public AbstractTest
{
public:
	BuilderTest();
	virtual ~BuilderTest();

private:
	virtual int vStart();

	int createBuildStep();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_BUILDERTEST_HPP
