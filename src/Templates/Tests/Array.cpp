/*
 * file:       Array.cpp
 *
 * created:    21.07.2017
 * author:     kachsheev
 */

#include "Array.hpp"

using namespace flame_ide;
using namespace flame_ide::test;

Array::Array() : AbstractTest("Array")
		, array{{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		}}
		, stdVector{{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		}}
{}

Array::~Array()
{}

int Array::vStart()
{
	TestClass testArray[] = {
			TestClass{-1000, -100, -10, 'F'}
			, TestClass{-2500, -250, -25, 'M'}
			, TestClass{-5000, -500, -50, 'L'}
	};
	constexpr size_t countObjects = sizeof(testArray) / sizeof(testArray[0]);
	constexpr size_t insertIndex = 3;

	CHECK_RESULT(doTestCase(
			"initializing size"
			, [&]()
			{
				return (array.size() == stdVector.size())
						? ResultType::SUCCESS
						: ResultType::FAILED;
			}
	));
	CHECK_RESULT(doTestCase(
			"initializing"
			, [&]()
			{
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"cloning"
			, [&]()
			{
				templates::Array<TestClass, 10> arrayClone = array.clone();
				return compareContainers(arrayClone, array);
			}
	));
	CHECK_RESULT(doTestCase(
			"copying"
			, [&]()
			{
				templates::Array<TestClass, 10> arrayCopy = array;
				return compareContainers(arrayCopy, array);
			}
	));
	CHECK_RESULT(doTestCase(
			"moving"
			, [&]()
			{
				templates::Array<TestClass, 10> arrayMove = flame_ide::move(array);
				CHECK_RESULT(compareContainers(arrayMove, stdVector));

				array = flame_ide::move(arrayMove);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"reverse"
			, [&]()
			{
				return compareContainers(
					templates::makeRange(array.rbegin(), array.rend())
					, templates::makeRange(stdVector.rbegin(), stdVector.rend())
				);
			}
	));
	CHECK_RESULT(doTestCase(
			"popBack()"
			, [&]()
			{
				array.popBack();
				stdVector.pop_back();
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"pushBack()"
			, [&]()
			{
				TestClass testLastObject = *array.rbegin();
				array.pushBack(testLastObject);
				stdVector.push_back(testLastObject);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"emplaceBack()"
			, [&]()
			{
				array.emplaceBack(-6000, -600, -60, '6');
				stdVector.emplace_back(-6000, -600, -60, '6');
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"insert()"
			, [&]()
			{
				TestClass testFirstObject = {-1000, -100, -10, 'F'};
				TestClass testMiddleObject = {-2500, -250, -25, 'M'};
				TestClass testLastObject = {-5000, -500, -50, 'L'};

				array.insert(array.begin(), testFirstObject);
				array.insert(array.begin() + 3, testMiddleObject);
				array.insert(array.end(), testLastObject);
				stdVector.insert(stdVector.begin(), testFirstObject);
				stdVector.insert(stdVector.begin() + 3, testMiddleObject);
				stdVector.insert(stdVector.end(), testLastObject);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"erase()"
			, [&]()
			{
				TestClass testFirstObject = {-1000, -100, -10, 'F'};
				TestClass testMiddleObject = {-2500, -250, -25, 'M'};
				TestClass testLastObject = {-5000, -500, -50, 'L'};

				array.erase(array.begin() + 3);
				array.erase(array.begin());
				array.erase(array.end() - 1);
				stdVector.erase(stdVector.begin() + 3);
				stdVector.erase(stdVector.begin());
				stdVector.erase(stdVector.end() - 1);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"emplace()"
			, [&]()
			{
				TestClass testFirstObject = {-1000, -100, -10, 'F'};
				TestClass testMiddleObject = {-2500, -250, -25, 'M'};
				TestClass testLastObject = {-5000, -500, -50, 'L'};

				array.emplace(array.begin(), testFirstObject);
				array.emplace(array.begin() + 3, testMiddleObject);
				array.emplace(array.end(), testLastObject);
				stdVector.emplace(stdVector.begin(), testFirstObject);
				stdVector.emplace(stdVector.begin() + 3, testMiddleObject);
				stdVector.emplace(stdVector.end(), testLastObject);
				CHECK_RESULT(compareContainers(array, stdVector));

				array.erase(array.begin() + 3);
				array.erase(array.begin());
				array.erase(array.end() - 1);
				stdVector.erase(stdVector.begin() + 3);
				stdVector.erase(stdVector.begin());
				stdVector.erase(stdVector.end() - 1);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator+=() copy"
			, [&]()
			{
				TestClass testObject {-6000, -600, -60, '6'};
				array += testObject;
				stdVector.push_back(testObject);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator-=(Iterator)"
			, [&]()
			{
				array -= --(array.end());
				stdVector.erase(--stdVector.end());
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator+=() move"
			, [&]()
			{
				TestClass testObject {-7000, -700, -70, '7'};
				array += flame_ide::move(testObject);
				stdVector.emplace_back(-7000, -700, -70, '7');
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator-=(ReverseIterator)"
			, [&]()
			{
				array -= array.rbegin();
				stdVector.erase(--stdVector.end());
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator+=(Range)"
			, [&]()
			{
				TestClass testObjects[] = {
						{6000, 600, 60, '6'}
						, {-7000, -700, -70, '7'}
						, {-8000, -800, -80, '8'}
						, {-8000, -800, -80, '8'}
				};
				constexpr size_t countObjects = sizeof(testObjects) / sizeof(testObjects[0]);

				array += templates::Range<TestClass *>{
						testObjects, testObjects + countObjects
				};
				stdVector.insert(stdVector.end(), testObjects, testObjects + countObjects);

				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator-=(Range)"
			, [&]()
			{
				constexpr size_t countObjects = 4;
				array -= templates::makeRange(array.end() - countObjects, array.end());
				stdVector.erase(stdVector.end() - countObjects, stdVector.end());
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator+=(Range)"
			, [&]()
			{
				TestClass testObjects[] = {
						{6000, 600, 60, '6'}
						, {-7000, -700, -70, '7'}
						, {-8000, -800, -80, '8'}
						, {-8000, -800, -80, '8'}
				};
				constexpr size_t countObjects = sizeof(testObjects) / sizeof(testObjects[0]);
				auto range = templates::Range<TestClass *>{
						 testObjects, testObjects + countObjects
				};

				array += range;
				stdVector.insert(stdVector.end(), range.begin(), range.end());

				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"operator-=(ReverseRange)"
			, [&]()
			{
				constexpr size_t countObjects = 4;
				array -= flame_ide::templates::Range<decltype(array)::ReverseIterator> {
						array.rbegin(), array.rbegin() + countObjects
				};
				stdVector.erase(stdVector.end() - countObjects, stdVector.end());
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"insert to begin(range)"
			, [&]()
			{
				array.insert(array.begin(), testArray, testArray + countObjects);
				stdVector.insert(stdVector.begin(), testArray, testArray + countObjects);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"erase from begin(range)"
			, [&]()
			{
				array.erase(array.begin(), array.begin() + countObjects);
				stdVector.erase(stdVector.begin(), stdVector.begin() + countObjects);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			std::string("insert to begin(range) + ") + std::to_string(insertIndex)
			, [&]()
			{
				array.insert(
						array.begin() + insertIndex
						, testArray
						, testArray + countObjects
				);
				stdVector.insert(
						stdVector.begin() + insertIndex
						, testArray
						, testArray + countObjects
				);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			std::string("erase from begin(range) + ") + std::to_string(insertIndex)
			, [&]()
			{
				array.erase(
						array.begin() + insertIndex
						, array.begin() + insertIndex + countObjects
				);
				stdVector.erase(
						stdVector.begin() + insertIndex
						, stdVector.begin() + insertIndex + countObjects
				);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"insert to end(range)"
			, [&]()
			{
				array.insert(array.end(), testArray, testArray + countObjects);
				stdVector.insert(stdVector.end(), testArray, testArray + countObjects);
				return compareContainers(array, stdVector);
			}
	));
	CHECK_RESULT(doTestCase(
			"erase from end(range)"
			, [&]()
			{
				array.erase(array.end() - countObjects, array.end());
				stdVector.erase(stdVector.end() - countObjects, stdVector.end());
				return compareContainers(array, stdVector);
			}
	));

	return 0;
}

