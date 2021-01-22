#ifndef FLAMEIDE_TEMPLATES_TESTS_FUTURE_HPP
#define FLAMEIDE_TEMPLATES_TESTS_FUTURE_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/Future.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class FutureTest: public AbstractTest
{
public:
	FutureTest();
	virtual ~FutureTest();

private:
	virtual int vStart();
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_FUTURE_HPP
