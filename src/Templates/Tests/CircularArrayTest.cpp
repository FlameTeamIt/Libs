#include "CircularArrayTest.hpp"
#include "TestClass.hpp"

#include <FlameIDE/Templates/IntegerIterator.hpp>

namespace flame_ide
{namespace test
{

using CircularArray = templates::CircularArray<TestClass, 4>;

CircularArrayTest::CircularArrayTest() : AbstractTest("CircularArray")
{}

int CircularArrayTest::vStart()
{
	CircularArray circularArray;

	// pushBack
	const TestClass testObject{
			long{ 1000 }
			, int{ 100 }
			, short{ 10 }
			, char{ '1' }
	};

	auto range = templates::makeRange(
			templates::SizeTypeIterator(0)
			, templates::SizeTypeIterator(10));
	for (auto i : range)
	{
		(void)i;
		TestClass tmp = testObject;
		auto itBegin = circularArray.begin();
		auto itEnd = circularArray.end();

		if (itBegin != itEnd)
		{
			return -1;
		}
		circularArray.pushBack(move(tmp));
		if (circularArray.size() != 1)
		{
			return -1;
		}

		itBegin = circularArray.begin();
		itEnd = circularArray.end();

		if (itBegin == itEnd)
		{
			return -1;
		}
		for (auto it = circularArray.begin(); it != circularArray.end(); ++it)
		{
			TestClass &obj = *it;
			if (obj != testObject)
			{
				return -1;
			}
		}

		circularArray.popFront();
		if (circularArray.size() != 0)
		{
			return -1;
		}
	}

	circularArray.clean();

	for (auto i : range)
	{
		(void)i;
		TestClass tmp = testObject;
		auto itBegin = circularArray.begin();
		auto itEnd = circularArray.end();
		if (itBegin != itEnd)
		{
			return -1;
		}
		circularArray.pushBack(move(tmp));
		if (circularArray.size() != 1)
		{
			return -1;
		}
		itBegin = circularArray.begin();
		itEnd = circularArray.end();
		if (itBegin == itEnd)
		{
			return -1;
		}
		for (auto it = circularArray.begin(); it != circularArray.end(); ++it)
		{
			TestClass &obj = *it;
			if (obj != testObject)
			{
				return -1;
			}
		}

		circularArray.popFront();
		if (circularArray.size() != 0)
		{
			return -1;
		}
	}

	circularArray.clean();

	for (auto i : range)
	{
		(void)i;
		circularArray.pushBack(testObject);
		if (circularArray.size() != 1)
		{
			return -1;
		}
		auto itBegin = circularArray.rbegin();
		auto itEnd = circularArray.rend();
		if (itBegin == itEnd)
		{
			return -1;
		}
		for (auto it = circularArray.rbegin(); it != circularArray.rend(); ++it)
		{
			TestClass &obj = *it;
			if (obj != testObject)
			{
				return -1;
			}
		}

		circularArray.popFront();
		if (circularArray.size() != 0)
		{
			return -1;
		}
	}

	return 0;
}

}}
