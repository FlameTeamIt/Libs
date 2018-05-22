#ifndef TEST_SHAREDPOINTER_HPP
#define TEST_SHAREDPOINTER_HPP

#include <tests/Test.hpp>
#include <Templates/Pointers.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class SharedPointer: public AbstractTest
{
public:
	SharedPointer();
	virtual ~SharedPointer();

private:
	virtual int vStart();

	templates::SharedPointer<TestClass> pointer;
};

}}

#endif // TEST_SHAREDPOINTER_HPP
