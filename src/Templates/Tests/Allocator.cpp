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

	TestClass mainObject{ 1000, 10, 1, '1' };
	TestClass *object;

	std::cout << "Constructing object: ";
	{
		object = allocator.construct(
				mainObject.getLong()
				, mainObject.getInt()
				, mainObject.getShort()
				, mainObject.getChar()
		);
		if (object && *object == mainObject)
		{
			std::cout << "Success" << std::endl;
		}
		else
		{
			std::cout << "Failed" << std::endl;
			return -1;
		}
	}

	std::cout << "Destructing object: ";
	{
		allocator.destroy(object);
		if (!object)
		{
			std::cout << "Success" << std::endl;
		}
		else
		{
			std::cout << "Failed" << std::endl;
			return -1;
		}
	}

	return 0;
}

// ArrayAllocator

ArrayAllocator::ArrayAllocator() : AbstractTest("ArrayAllocator")
{}

ArrayAllocator::~ArrayAllocator()
{}

int ArrayAllocator::vStart()
{
	auto lambdaPrint = [] (const TestClass &testObject) {
		std::cout << "{ "
				<< "long("<< testObject.getLong() << "), "
				<< "int(" << testObject.getInt() << "), "
				<< "short(" << testObject.getShort() << "), "
				<< "char('" << testObject.getChar() << "') "
				<< "}";
	};

	using SsizeType = flame_ide::SizeTraits::SsizeType;
	int index = 0;
	constexpr SsizeType SIZE = 6;
	TestClass array[6] = {
			TestClass{
					long((index += 1) * 1000), int(index * 100)
					, short(10 + index), char('1' + index)
			}
			, TestClass{
					long((index += 1) * 1000), int(index * 100)
					, short(10 + index), char('1' + index)
			}
			, TestClass{
					long((index += 1) * 1000), int(index * 100)
					, short(10 + index), char('1' + index)
			}
			, TestClass{
					long((index += 1) * 1000), int(index * 100)
					, short(10 + index), char('1' + index)
			}
			, TestClass{
					long((index += 1) * 1000), int(index * 100)
					, short(10 + index), char('1' + index)
			}
			, TestClass{
					long((index += 1) * 1000), int(index * 100)
					, short(10 + index), char('1' + index)
			}
	};

	TestClass *testArray = allocator.construct(SIZE);
	std::cout << "Check array pointer: ";
	if (!testArray)
	{
		std::cout << "Failed." << std::endl;
		return -1;
	}
	else
	{
		std::cout << "Success." << std::endl;
	}

	for (SsizeType i = 0; i < SIZE; ++i)
	{
		testArray[i] = {
				array[i].getLong(), array[i].getInt()
				, array[i].getShort(), array[i].getChar()
		};
	}

	std::cout << "Check intializing: ";
	{
		for (SsizeType i = 0; i < SIZE; ++i)
		{
			if (array[i] != testArray[i])
			{
				std::cout << "Failed." << std::endl;
				std::cout << "array[" << i << "]:" << std::endl;
				lambdaPrint(array[i]);
				std::cout << std::endl
						<< "testArray[" << i << "]:" << std::endl;
				lambdaPrint(testArray[i]);
				std::cout << std::endl;

				return -1;
			}
		}
		std::cout << "Success." << std::endl;
	}

	std::cout << "Destroying array: ";
	allocator.destroy(testArray, SIZE);
	{
		if (testArray)
		{
			std::cout << "Failed." << std::endl;
			return -1;
		}
		else
		{
			std::cout << "Success." << std::endl;
		}
	}

	return 0;
}

}}

