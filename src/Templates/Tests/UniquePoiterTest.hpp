#ifndef FLAMEIDE_TEMPLATES_TESTS_UNIQUEPOITERTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_UNIQUEPOITERTEST_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include "TestClass.hpp"

#include <memory>

namespace flame_ide
{namespace templates
{namespace test
{

class UniquePointerTest: public AbstractTest
{
public:
	UniquePointerTest();
	virtual ~UniquePointerTest();

private:
	virtual int vStart();

	templates::UniquePointer<TestClass> pointer;
	std::unique_ptr<TestClass> stdpointer;
};

}}}

#endif // FLAMEIDE_TEMPLATES_TESTS_UNIQUEPOITERTEST_HPP
