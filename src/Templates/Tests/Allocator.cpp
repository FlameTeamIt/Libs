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
	using SsizeType = flame_ide::SizeTraits::SsizeType;
	constexpr SsizeType SIZE = 6;
	TestClass *array = allocator.construct(SIZE);

	for (SsizeType i = 0; i < SIZE; ++i)
	{
		array[i] = {long(i * 1000), int(i * 100), short(10 + i), char('1' + i)};
	}

	for (SsizeType i = 0; i < SIZE; ++i)
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

