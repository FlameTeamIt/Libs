#ifndef FLAMEIDE_TEMPLATES_TESTS_ALLOCATORTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_ALLOCATORTEST_HPP

#include <tests/Test.hpp>

#include <FlameIDE/Templates/Allocator.hpp>

#include "TestClass.hpp"

namespace flame_ide
{namespace test
{

class ObjectAllocatorTest: public AbstractTest
{
public:
	ObjectAllocatorTest();
	virtual ~ObjectAllocatorTest();

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

#endif // FLAMEIDE_TEMPLATES_TESTS_ALLOCATORTEST_HPP
