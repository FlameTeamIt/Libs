/*
 * file:       Allocator.cpp
 *
 * created:    17.07.2017
 * author:     kachsheev
 */
#include "Allocator.hpp"

namespace flame_ide
{namespace test
{

// ObjectAllocator

ObjectAllocator::ObjectAllocator() : AbstractTest("ObjectAllocator")
{}

ObjectAllocator::~ObjectAllocator()
{}

int ObjectAllocator::vStart()
{
	TestClass *object = allocator.construct(1000, 10, 1, '1');

	std::cout << object->getChar()
			<< ' ' << object->getShort()
			<< ' ' << object->getInt()
			<< ' ' << object->getLong()
			<< std::endl;

	allocator.destroy(object);

	return 0;
}

// ArrayAllocator

ArrayAllocator::ArrayAllocator() : AbstractTest("ArrayAllocator")
{}

ArrayAllocator::~ArrayAllocator()
{}

int ArrayAllocator::vStart()
{
	using SizeType = flame_ide::templates::SizeTraits::SizeType;
	constexpr SizeType SIZE = 6;
	TestClass *array = allocator.construct(SIZE);

	for (SizeType i = 0; i < SIZE; ++i)
	{
		array[i] = {i * 1000, i * 100, 10 + i, '1' + i};
	}

	for (SizeType i = 0; i < SIZE; ++i)
	{
		std::cout << array[i].getChar()
				<< ' ' << array[i].getShort()
				<< ' ' << array[i].getInt()
				<< ' ' << array[i].getLong()
				<< std::endl;
	}

	allocator.destroy(array, SIZE);

	return 0;
}

}}

