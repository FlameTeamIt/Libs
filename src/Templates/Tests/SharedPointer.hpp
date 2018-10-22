#ifndef TEST_SHAREDPOINTER_HPP
#define TEST_SHAREDPOINTER_HPP

#include <tests/Test.hpp>
#include <Templates/Pointers.hpp>

#include "TestClass.hpp"

#include <memory>

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
	std::shared_ptr<TestClass> stdpointer;
};

}}

#endif // TEST_SHAREDPOINTER_HPP
