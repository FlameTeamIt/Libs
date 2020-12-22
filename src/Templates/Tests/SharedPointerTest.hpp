#ifndef FLAMEIDE_TEMPLATES_TESTS_SHAREDPOINTERTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_SHAREDPOINTERTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include "TestClass.hpp"

#include <memory>

namespace flame_ide
{namespace templates
{namespace test
{

class SharedPointerTest: public AbstractTest
{
public:
	SharedPointerTest();
	virtual ~SharedPointerTest();

private:
	virtual int vStart();

	templates::SharedPointer<TestClass> pointer;
	std::shared_ptr<TestClass> stdpointer;
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_SHAREDPOINTERTEST_HPP
