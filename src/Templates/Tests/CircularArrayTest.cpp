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
		std::cout << i << std::endl;
		TestClass tmp = testObject;
		auto itBegin = circularArray.begin();
		auto itEnd = circularArray.end();

		auto pointerBegin = flame_ide::getPointer(itBegin);
		auto pointerEnd = flame_ide::getPointer(itEnd);

		if (itBegin != itEnd)
		{
			return -1;
		}
		circularArray.pushBack(move(tmp));
		log << "circularArray.size() = " << circularArray.size() << std::endl;
		itBegin = circularArray.begin();
		itEnd = circularArray.end();

		pointerBegin = flame_ide::getPointer(itBegin);
		pointerEnd = flame_ide::getPointer(itEnd);

		if (itBegin == itEnd)
		{
			return -1;
		}
		for (auto it = circularArray.begin(); it != circularArray.end(); ++it)
		{
			TestClass &obj = *it;
			log << "{ long(" << obj.getLong() << "),"
					" int(" << obj.getInt() << "),"
					" short(" << obj.getShort() << ")"
					" char('" << obj.getChar() << ") }"
					<< std::endl;
		}

		circularArray.popFront();
		log << "circularArray.size() = " << circularArray.size() << '\n' << std::endl;
	}

	circularArray.clean();

	for (auto i : range)
	{
		std::cout << i << std::endl;
		TestClass tmp = testObject;
		auto itBegin = circularArray.begin();
		auto itEnd = circularArray.end();
		if (itBegin != itEnd)
		{
			return -1;
		}
		circularArray.pushBack(move(tmp));
		log << "circularArray.size() = " << circularArray.size() << std::endl;
		itBegin = circularArray.begin();
		itEnd = circularArray.end();
		if (itBegin == itEnd)
		{
			return -1;
		}
		for (auto it = circularArray.begin(); it != circularArray.end(); ++it)
		{
			TestClass &obj = *it;
			log << "{ long(" << obj.getLong() << "),"
					" int(" << obj.getInt() << "),"
					" short(" << obj.getShort() << ")"
					" char('" << obj.getChar() << ") }"
					<< std::endl;
		}

		circularArray.popFront();
		log << "circularArray.size() = " << circularArray.size() << '\n' << std::endl;
	}

	circularArray.clean();

	for (auto i : range)
	{
		std::cout << i << std::endl;
		circularArray.pushBack(testObject);
		log << "circularArray.size() = " << circularArray.size() << std::endl;
		auto itBegin = circularArray.rbegin();
		auto itEnd = circularArray.rend();
		if (itBegin == itEnd)
		{
			return -1;
		}
		for (auto it = circularArray.rbegin(); it != circularArray.rend(); ++it)
		{
			TestClass &obj = *it;
			log << "{ long(" << obj.getLong() << "),"
					" int(" << obj.getInt() << "),"
					" short(" << obj.getShort() << ")"
					" char('" << obj.getChar() << ") }"
					<< std::endl;
		}

		circularArray.popFront();
		log << "circularArray.size() = " << circularArray.size() << '\n' << std::endl;
	}

	return 0;
}

}}
