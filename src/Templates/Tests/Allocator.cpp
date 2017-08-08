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

int ObjectAllocator::_start()
{
	TestClass *object = allocator.construct();
	object->getChar() = '1';
	object->getShort() = 10;
	object->getInt() = 100;
	object->getLong() = 1000;

	std::cout << object->getChar()
			<< ' ' << object->getShort()
			<< ' ' << object->getInt()
			<< ' ' << object->getLong()
			<< std::endl;

	allocator.destruct(object);

	return 0;
}

// ArrayAllocator

ArrayAllocator::ArrayAllocator() : AbstractTest("ArrayAllocator")
{}

ArrayAllocator::~ArrayAllocator()
{}

int ArrayAllocator::_start()
{
	using SizeType = flame_ide::templates::SizeTraits::SizeType;
	constexpr SizeType SIZE = 6;
	TestClass *array = allocator.construct(SIZE);

	for (SizeType i = 0; i < SIZE; ++i)
	{
		array[i].getChar() = '1' + i;
		array[i].getShort() = 10 + i;
		array[i].getInt() = i * 100;
		array[i].getLong() = i * 1000;
	}

	for (SizeType i = 0; i < SIZE; ++i)
	{
		std::cout << array[i].getChar()
				<< ' ' << array[i].getShort()
				<< ' ' << array[i].getInt()
				<< ' ' << array[i].getLong()
				<< std::endl;
	}

	allocator.destruct(array, SIZE);

	return 0;
}

}}

