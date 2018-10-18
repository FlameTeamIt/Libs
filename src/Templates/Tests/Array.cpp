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
		, stdvector{{
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

	CHECK_RESULT_SUCCESS(doTestCase(
			"initializing size"
			, [&]()
			{
				IN_CASE_CHECK_END(array.size() == stdvector.size());
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"initializing"
			, [&]()
			{
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"cloning"
			, [&]()
			{
				templates::Array<TestClass, 10> arrayClone = array.clone();
				return compareContainers(arrayClone, array);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"copying"
			, [&]()
			{
				templates::Array<TestClass, 10> arrayCopy = array;
				return compareContainers(arrayCopy, array);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"moving"
			, [&]()
			{
				templates::Array<TestClass, 10> arrayMove = flame_ide::move(array);
				CHECK_RESULT_SUCCESS(compareContainers(arrayMove, stdvector));

				array = flame_ide::move(arrayMove);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"reverse"
			, [&]()
			{
				return compareContainers(
					templates::makeRange(array.rbegin(), array.rend())
					, templates::makeRange(stdvector.rbegin(), stdvector.rend())
				);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"popBack()"
			, [&]()
			{
				array.popBack();
				stdvector.pop_back();
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack()"
			, [&]()
			{
				TestClass testLastObject = *array.rbegin();
				array.pushBack(testLastObject);
				stdvector.push_back(testLastObject);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"emplaceBack()"
			, [&]()
			{
				array.emplaceBack(-6000, -600, -60, '6');
				stdvector.emplace_back(-6000, -600, -60, '6');
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"insert()"
			, [&]()
			{
				TestClass testFirstObject = {-1000, -100, -10, 'F'};
				TestClass testMiddleObject = {-2500, -250, -25, 'M'};
				TestClass testLastObject = {-5000, -500, -50, 'L'};

				array.insert(array.begin(), testFirstObject);
				array.insert(array.begin() + 3, testMiddleObject);
				array.insert(array.end(), testLastObject);
				stdvector.insert(stdvector.begin(), testFirstObject);
				stdvector.insert(stdvector.begin() + 3, testMiddleObject);
				stdvector.insert(stdvector.end(), testLastObject);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"erase()"
			, [&]()
			{
				TestClass testFirstObject = {-1000, -100, -10, 'F'};
				TestClass testMiddleObject = {-2500, -250, -25, 'M'};
				TestClass testLastObject = {-5000, -500, -50, 'L'};

				array.erase(array.begin() + 3);
				array.erase(array.begin());
				array.erase(array.end() - 1);
				stdvector.erase(stdvector.begin() + 3);
				stdvector.erase(stdvector.begin());
				stdvector.erase(stdvector.end() - 1);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"emplace()"
			, [&]()
			{
				TestClass testFirstObject = {-1000, -100, -10, 'F'};
				TestClass testMiddleObject = {-2500, -250, -25, 'M'};
				TestClass testLastObject = {-5000, -500, -50, 'L'};

				array.emplace(array.begin(), testFirstObject);
				array.emplace(array.begin() + 3, testMiddleObject);
				array.emplace(array.end(), testLastObject);
				stdvector.emplace(stdvector.begin(), testFirstObject);
				stdvector.emplace(stdvector.begin() + 3, testMiddleObject);
				stdvector.emplace(stdvector.end(), testLastObject);
				CHECK_RESULT_SUCCESS(compareContainers(array, stdvector));

				array.erase(array.begin() + 3);
				array.erase(array.begin());
				array.erase(array.end() - 1);
				stdvector.erase(stdvector.begin() + 3);
				stdvector.erase(stdvector.begin());
				stdvector.erase(stdvector.end() - 1);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"operator+=() copy"
			, [&]()
			{
				TestClass testObject {-6000, -600, -60, '6'};
				array += testObject;
				stdvector.push_back(testObject);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"operator-=(Iterator)"
			, [&]()
			{
				array -= --(array.end());
				stdvector.erase(--stdvector.end());
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"operator+=() move"
			, [&]()
			{
				TestClass testObject {-7000, -700, -70, '7'};
				array += flame_ide::move(testObject);
				stdvector.emplace_back(-7000, -700, -70, '7');
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"operator-=(ReverseIterator)"
			, [&]()
			{
				array -= array.rbegin();
				stdvector.erase(--stdvector.end());
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
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
				stdvector.insert(stdvector.end(), testObjects, testObjects + countObjects);

				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"operator-=(Range)"
			, [&]()
			{
				constexpr size_t countObjects = 4;
				array -= templates::makeRange(array.end() - countObjects, array.end());
				stdvector.erase(stdvector.end() - countObjects, stdvector.end());
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
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
				stdvector.insert(stdvector.end(), range.begin(), range.end());

				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"operator-=(ReverseRange)"
			, [&]()
			{
				constexpr size_t countObjects = 4;
				array -= flame_ide::templates::Range<decltype(array)::ReverseIterator> {
						array.rbegin(), array.rbegin() + countObjects
				};
				stdvector.erase(stdvector.end() - countObjects, stdvector.end());
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"insert to begin(range)"
			, [&]()
			{
				array.insert(array.begin(), testArray, testArray + countObjects);
				stdvector.insert(stdvector.begin(), testArray, testArray + countObjects);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"erase from begin(range)"
			, [&]()
			{
				array.erase(array.begin(), array.begin() + countObjects);
				stdvector.erase(stdvector.begin(), stdvector.begin() + countObjects);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			std::string("insert to begin(range) + ") + std::to_string(insertIndex)
			, [&]()
			{
				array.insert(
						array.begin() + insertIndex
						, testArray
						, testArray + countObjects
				);
				stdvector.insert(
						stdvector.begin() + insertIndex
						, testArray
						, testArray + countObjects
				);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			std::string("erase from begin(range) + ") + std::to_string(insertIndex)
			, [&]()
			{
				array.erase(
						array.begin() + insertIndex
						, array.begin() + insertIndex + countObjects
				);
				stdvector.erase(
						stdvector.begin() + insertIndex
						, stdvector.begin() + insertIndex + countObjects
				);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"insert to end(range)"
			, [&]()
			{
				array.insert(array.end(), testArray, testArray + countObjects);
				stdvector.insert(stdvector.end(), testArray, testArray + countObjects);
				return compareContainers(array, stdvector);
			}
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"erase from end(range)"
			, [&]()
			{
				array.erase(array.end() - countObjects, array.end());
				stdvector.erase(stdvector.end() - countObjects, stdvector.end());
				return compareContainers(array, stdvector);
			}
	));

	return 0;
}

