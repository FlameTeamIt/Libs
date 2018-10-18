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

	CHECK_RESULT_SUCCESS(doTestCase(
			"Constructing object"
			, [&]()
			{
				object = allocator.construct(
						mainObject.getLong()
						, mainObject.getInt()
						, mainObject.getShort()
						, mainObject.getChar()
				);
				if(object && *object == mainObject)
				{
					return ResultType::SUCCESS;
				}
				else
				{
					return ResultType::FAILED;
				}
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Destructing object"
			, [&]()
			{
				allocator.destroy(object);
				if (!object)
				{
					return ResultType::SUCCESS;
				}
				else
				{
					return ResultType::FAILED;
				}
			}
	));

	return 0;
}

// ArrayAllocator

ArrayAllocator::ArrayAllocator() : AbstractTest("ArrayAllocator")
{}

ArrayAllocator::~ArrayAllocator()
{}

int ArrayAllocator::vStart()
{
	struct
	{
		int current()
		{
			return index;
		}

		auto &add()
		{
			++index;
			return *this;
		}

		int index = 0;
	} idx;

	using SsizeType = flame_ide::SizeTraits::SsizeType;
	constexpr SsizeType SIZE = 6;
	TestClass array[SIZE] = {
			TestClass{
					long(idx.add().current() * 1000), int(idx.current() * 100)
					, short(idx.current() + 10), char(idx.current() + '1')
			}
			, TestClass{
					long((idx.add().current()) * 1000), int(idx.current() * 100)
					, short(idx.current() + 10), char(idx.current() + '1')
			}
			, TestClass{
					long((idx.add().current()) * 1000), int(idx.current() * 100)
					, short(idx.current() + 10), char(idx.current() + '1')
			}
			, TestClass{
					long((idx.add().current()) * 1000), int(idx.current() * 100)
					, short(idx.current() + 10), char(idx.current() + '1')
			}
			, TestClass{
					long((idx.add().current()) * 1000), int(idx.current() * 100)
					, short(idx.current() + 10), char(idx.current() + '1')
			}
			, TestClass{
					long((idx.add().current()) * 1000), int(idx.current() * 100)
					, short(idx.current() + 10), char(idx.current() + '1')
			}
	};
	TestClass *testArray;

	CHECK_RESULT_SUCCESS(doTestCase(
			"Check array pointer"
			, [&]()
			{
				testArray = allocator.construct(SIZE);
				if (!testArray)
				{
					return ResultType::FAILED;
				}
				else
				{
					return ResultType::SUCCESS;
				}
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Check intializing"
			, [&]()
			{
				for (SsizeType i = 0; i < SIZE; ++i)
				{
					testArray[i] = {
							array[i].getLong(), array[i].getInt()
							, array[i].getShort(), array[i].getChar()
					};
				}

				for (SsizeType i = 0; i < SIZE; ++i)
				{
					if (array[i] != testArray[i])
					{
						return ResultType::FAILED;
					}
				}

				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Destroying array"
			, [&]()
			{
				allocator.destroy(testArray, SIZE);
				{
					if (testArray)
					{
						return ResultType::FAILED;
					}
					else
					{
						return ResultType::SUCCESS;
					}
				}
			}
	));

	return 0;
}

}}
