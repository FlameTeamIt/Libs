#ifndef UNIQUEPOITER_HPP
#define UNIQUEPOITER_HPP

#include <tests/Test.hpp>
#include <Templates/Pointers.hpp>

#include "TestClass.hpp"

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
};

}}

#endif // UNIQUEPOITER_HPP
