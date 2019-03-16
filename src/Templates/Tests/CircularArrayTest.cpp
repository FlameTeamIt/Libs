#include "CircularArrayTest.hpp"
#include "TestClass.hpp"

#include <FlameIDE/Templates/IntegerIterator.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

using CircularArray = templates::CircularArray<TestClass, 4>;

CircularArrayTest::CircularArrayTest() : AbstractTest("CircularArray")
{}

int CircularArrayTest::vStart()
{
	CircularArray circularArray;

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(move) and popFront() : 1 elem"
			, [&]()
			{
				const TestClass testObject{
						long{ 1000 }
						, int{ 100 }
						, short{ 10 }
						, char{ '1' }
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp = testObject;
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(move(tmp));
					if (circularArray.size() != 1)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();

					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}
					for (auto &obj : circularArray)
					{
						if (obj != testObject)
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(move) and popFront() : 2 elem"
			, [&]()
			{
				const TestClass testObjects [] = {
					{
						long{ 1000 }
						, int{ 100 }
						, short{ 10 }
						, char{ '1' }
					}
					, {
						long{ 2000 }
						, int{ 200 }
						, short{ 20 }
						, char{ '2' }
					}
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp[] = { testObjects[0], testObjects[1] };
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(move(tmp[0]));
					circularArray.pushBack(move(tmp[1]));
					if (circularArray.size() != 2)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();
					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}

					auto index = 0;
					for (auto &obj : circularArray)
					{
						if (obj != testObjects[index++])
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(move) and popFront() : 3 elem"
			, [&]()
			{
				const TestClass testObjects [] = {
					{
						long{ 1000 }
						, int{ 100 }
						, short{ 10 }
						, char{ '1' }
					}
					, {
						long{ 2000 }
						, int{ 200 }
						, short{ 20 }
						, char{ '2' }
					}
					, {
						long{ 3000 }
						, int{ 300 }
						, short{ 30 }
						, char{ '3' }
					}
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp[] = {
							testObjects[0]
							, testObjects[1]
							, testObjects[2]
					};
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(move(tmp[0]));
					circularArray.pushBack(move(tmp[1]));
					circularArray.pushBack(move(tmp[2]));
					if (circularArray.size() != 3)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();
					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}

					auto index = 0;
					for (auto &obj : circularArray)
					{
						if (obj != testObjects[index++])
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					circularArray.popFront();
					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(move) and popFront() : 4 elem"
			, [&]()
			{
				const TestClass testObjects [] = {
					{ long{ 1000 }, int{ 100 }, short{ 10 }, char{ '1' } }
					, { long{ 2000 }, int{ 200 }, short{ 20 }, char{ '2' } }
					, { long{ 3000 }, int{ 300 }, short{ 30 }, char{ '3' } }
					, { long{ 4000 }, int{ 400 }, short{ 40 }, char{ '4' } }
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp[] = {
						testObjects[0], testObjects[1]
						, testObjects[2], testObjects[3]
					};
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(move(tmp[0]));
					circularArray.pushBack(move(tmp[1]));
					circularArray.pushBack(move(tmp[2]));
					circularArray.pushBack(move(tmp[3]));
					if (circularArray.size() != 4)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();
					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}

					auto index = 0;
					for (auto &obj : circularArray)
					{
						if (obj != testObjects[index++])
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					circularArray.popFront();
					circularArray.popFront();
					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(copy) and popFront() : 1 elem"
			, [&]()
			{
				const TestClass testObject[] = {
						{ long{ 1000 }, int{ 100 }, short{ 10 }, char{ '1' } }
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(*testObject);
					if (circularArray.size() != 1)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();

					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}
					for (auto &obj : circularArray)
					{
						if (obj != *testObject)
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(copy) and popFront() : 2 elem"
			, [&]()
			{
				const TestClass testObjects [] = {
					{
						long{ 1000 }
						, int{ 100 }
						, short{ 10 }
						, char{ '1' }
					}
					, {
						long{ 2000 }
						, int{ 200 }
						, short{ 20 }
						, char{ '2' }
					}
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp[] = { testObjects[0], testObjects[1] };
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(tmp[0]);
					circularArray.pushBack(tmp[1]);
					if (circularArray.size() != 2)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();
					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}

					auto index = 0;
					for (auto &obj : circularArray)
					{
						if (obj != testObjects[index++])
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(copy) and popFront() : 3 elem"
			, [&]()
			{
				const TestClass testObjects [] = {
					{
						long{ 1000 }
						, int{ 100 }
						, short{ 10 }
						, char{ '1' }
					}
					, {
						long{ 2000 }
						, int{ 200 }
						, short{ 20 }
						, char{ '2' }
					}
					, {
						long{ 3000 }
						, int{ 300 }
						, short{ 30 }
						, char{ '3' }
					}
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp[] = {
							testObjects[0]
							, testObjects[1]
							, testObjects[2]
					};
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(tmp[0]);
					circularArray.pushBack(tmp[1]);
					circularArray.pushBack(tmp[2]);
					if (circularArray.size() != 3)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();
					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}

					auto index = 0;
					for (auto &obj : circularArray)
					{
						if (obj != testObjects[index++])
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					circularArray.popFront();
					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack(copy) and popFront() : 4 elem"
			, [&]()
			{
				const TestClass testObjects [] = {
					{ long{ 1000 }, int{ 100 }, short{ 10 }, char{ '1' } }
					, { long{ 2000 }, int{ 200 }, short{ 20 }, char{ '2' } }
					, { long{ 3000 }, int{ 300 }, short{ 30 }, char{ '3' } }
					, { long{ 4000 }, int{ 400 }, short{ 40 }, char{ '4' } }
				};
				auto range = templates::makeRange(
						templates::SizeTypeIterator(0)
						, templates::SizeTypeIterator(10)
				);

				for (auto i : range)
				{
					(void)i;
					TestClass tmp[] = {
						testObjects[0], testObjects[1]
						, testObjects[2], testObjects[3]
					};
					auto itBegin = circularArray.begin();
					auto itEnd = circularArray.end();

					if (itBegin != itEnd)
					{
						return ResultType::FAILED;
					}
					circularArray.pushBack(tmp[0]);
					circularArray.pushBack(tmp[1]);
					circularArray.pushBack(tmp[2]);
					circularArray.pushBack(tmp[3]);
					if (circularArray.size() != 4)
					{
						return ResultType::FAILED;
					}

					itBegin = circularArray.begin();
					itEnd = circularArray.end();
					if (itBegin == itEnd)
					{
						return ResultType::FAILED;
					}

					auto index = 0;
					for (auto &obj : circularArray)
					{
						if (obj != testObjects[index++])
						{
							return ResultType::FAILED;
						}
					}

					circularArray.popFront();
					circularArray.popFront();
					circularArray.popFront();
					circularArray.popFront();
					if (circularArray.size() != 0)
					{
						return ResultType::FAILED;
					}
				}

				circularArray.clean();
				return ResultType::SUCCESS;
			}
	));

	CHECK_RESULT_SUCCESS_END(doTestCase(
			"reverse itererating"
			, [&]()
			{
				const TestClass testObjects [] = {
					{ long{ 1000 }, int{ 100 }, short{ 10 }, char{ '1' } }
					, { long{ 2000 }, int{ 200 }, short{ 20 }, char{ '2' } }
					, { long{ 3000 }, int{ 300 }, short{ 30 }, char{ '3' } }
					, { long{ 4000 }, int{ 400 }, short{ 40 }, char{ '4' } }
				};
				const Types::size_t countObjects = sizeof(testObjects)
						/ sizeof(*testObjects);

				auto objectsRange = templates::makeRange(testObjects
						, testObjects + countObjects);
				for (auto &i : objectsRange)
				{
					circularArray.pushBack(i);
				}
				if (circularArray.size() != countObjects)
				{
					return ResultType::FAILED;
				}

				auto reverseRange = templates::makeRange(
						circularArray.rbegin(), circularArray.rend()
				);
				auto range = templates::makeRange(circularArray);

				auto reverseIt = reverseRange.begin();
				auto it = --range.end();
				while (reverseIt != reverseRange.end() || it != range.end())
				{
					if (*reverseIt != *it)
					{
						return ResultType::FAILED;
					}
					++reverseIt;
					--it;
				}

				return ResultType::SUCCESS;
			}
	));

}

}}}
