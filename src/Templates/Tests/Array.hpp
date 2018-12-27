#ifndef TEST_ARRAY_HPP
#define TEST_ARRAY_HPP

#include <tests/Test.hpp>
#include <FlameIDE/Templates/Array.hpp>

#include "TestClass.hpp"

#include <vector>

namespace flame_ide
{namespace test
{

class Array: public AbstractTest
{
public:
	Array();
	virtual ~Array();

private:
	virtual int vStart();

	flame_ide::templates::Array<TestClass, 10> array;
	std::vector<TestClass> stdvector;
};

}}

#endif // TEST_ARRAY_HPP
