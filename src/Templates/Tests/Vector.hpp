/*
 * file:       Vector.hpp
 *
 * created:    16.08.2017
 * author:     kachsheev
 */
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <tests/Test.hpp>
#include <Templates/Vector.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class Vector: public AbstractTest
{
public:
	Vector();
	virtual ~Vector();

private:
	virtual int vStart();

	flame_ide::templates::Vector<TestClass> vector;
};

}}

#endif // VECTOR_HPP
