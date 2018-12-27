#ifndef TEST_ALLOCATOR_HPP
#define TEST_ALLOCATOR_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Allocator.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class ObjectAllocator: public AbstractTest
{
public:
	ObjectAllocator();
	virtual ~ObjectAllocator();

private:
	virtual int vStart();

	flame_ide::templates::allocator::ObjectAllocator<TestClass> allocator;
};

class ArrayAllocator: public AbstractTest
{
public:
	ArrayAllocator();
	virtual ~ArrayAllocator();

private:
	virtual int vStart();

	flame_ide::templates::allocator::ArrayAllocator<TestClass> allocator;
};

}}

#endif // TEST_ALLOCATOR_HPP
