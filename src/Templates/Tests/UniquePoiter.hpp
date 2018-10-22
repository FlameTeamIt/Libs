#ifndef TEST_UNIQUEPOITER_HPP
#define TEST_UNIQUEPOITER_HPP

#include <tests/Test.hpp>
#include <Templates/Pointers.hpp>

#include "TestClass.hpp"

#include <memory>

namespace flame_ide
{namespace test
{

class UniquePointer: public AbstractTest
{
public:
	UniquePointer();
	virtual ~UniquePointer();

private:
	virtual int vStart();

	templates::UniquePointer<TestClass> pointer;
	std::unique_ptr<TestClass> stdpointer;
};

}}

#endif // TEST_UNIQUEPOITER_HPP
