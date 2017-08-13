/*
 * file:       Array.hpp
 *
 * created:    21.07.2017
 * author:     kachsheev
 */
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <tests/Test.hpp>
#include <Templates/Array.hpp>

#include "TestClass.hpp"

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
};

}}

#endif // ARRAY_HPP
