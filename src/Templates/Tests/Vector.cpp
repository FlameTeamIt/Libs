/*
 * file:       Vector.cpp
 *
 * created:    16.08.2017
 * author:     kachsheev
 */
#include "Vector.hpp"

using namespace flame_ide::test;

Vector::Vector() : AbstractTest("Vector")
		, vector{{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		}}
		, stdvector{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		}
{}

Vector::~Vector()
{}

int Vector::vStart()
{
	TestClass testFirstObject{ -1000, -100, -10, 'F' };
	TestClass testMiddleObject{ -2000, -200, -20, 'M' };
	TestClass testLastObject{ -3000, -300, -30, 'L' };

	CHECK_RESULT_SUCCESS(doTestCase(
			"initializing size"
			, [&]()
			{
				IN_CASE_CHECK_END(vector.size() == stdvector.size());
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"initializing"
		, [&]()
		{
			return compareContainers(vector, stdvector);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"reverse"
		, [&]()
		{
			auto vectorRange = templates::makeRange(
					vector.rbegin(), vector.rend()
			);
			auto stdVectorRange = templates::makeRange(
					stdvector.rbegin(), stdvector.rend()
			);

			CHECK_RESULT_SUCCESS_END(compareContainers(vectorRange, stdVectorRange));
		}
	));

	{
		TestClass tmp = *vector.rbegin();

		CHECK_RESULT_SUCCESS(doTestCase(
			"popBack()"
			, [&]()
			{
				vector.popBack();
				stdvector.pop_back();
				return compareContainers(vector, stdvector);
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"pushBack()"
			, [&]()
			{
				vector.pushBack(tmp);
				stdvector.push_back(tmp);
				return compareContainers(vector, stdvector);
			}
		));
	}

	CHECK_RESULT_SUCCESS(doTestCase(
		"emplaceBack()"
		, [&]()
		{
			vector.emplaceBack(6000, 600, 60, '6');
			stdvector.emplace_back(6000, 600, 60, '6');

			CHECK_RESULT_SUCCESS(compareContainers(vector, stdvector));

			vector.popBack();
			stdvector.pop_back();

			CHECK_RESULT_SUCCESS_END(compareContainers(vector, stdvector));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"insert()"
		, [&]()
		{
			vector.insert(vector.begin(), testFirstObject);
			vector.insert(vector.begin() + 3, testMiddleObject);
			vector.insert(vector.end(), testLastObject);

			stdvector.insert(stdvector.begin(), testFirstObject);
			stdvector.insert(stdvector.begin() + 3, testMiddleObject);
			stdvector.insert(stdvector.end(), testLastObject);

			return compareContainers(vector, stdvector);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"erase()"
		, [&]()
		{
			vector.erase(vector.begin() + 3);
			vector.erase(vector.begin());
			vector.erase(vector.end() - 1);

			stdvector.erase(stdvector.begin() + 3);
			stdvector.erase(stdvector.begin());
			stdvector.erase(stdvector.end() - 1);

			return compareContainers(vector, stdvector);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"emplace"
		, [&]()
		{
			TestClass tempFirstObject = testFirstObject;
			TestClass tempMiddleObject = testMiddleObject;
			TestClass tempLastObject = testLastObject;

			vector.emplace(vector.begin(), tempFirstObject);
			vector.emplace(vector.begin() + 3, tempMiddleObject);
			vector.emplace(vector.end(), tempLastObject);

			stdvector.emplace(stdvector.begin(), tempFirstObject);
			stdvector.emplace(stdvector.begin() + 3, tempMiddleObject);
			stdvector.emplace(stdvector.end(), tempLastObject);

			CHECK_RESULT_SUCCESS(compareContainers(vector, stdvector));

			vector.erase(vector.begin() + 3);
			vector.erase(vector.begin());
			vector.erase(vector.end() - 1);

			stdvector.erase(stdvector.begin() + 3);
			stdvector.erase(stdvector.begin());
			stdvector.erase(stdvector.end() - 1);

			CHECK_RESULT_SUCCESS_END(compareContainers(vector, stdvector));
		}
	));

	// Test insert(range)/erase(range)
	{
		TestClass testArray[] = {
			testFirstObject, testMiddleObject, testLastObject
		};
		constexpr size_t countObjects = sizeof(testArray) / sizeof(testArray[0]);
		constexpr size_t offset = countObjects;

		CHECK_RESULT_SUCCESS(doTestCase(
			"insert range to begin()"
			, [&]()
			{
				vector.insert(vector.begin(), testArray, testArray + countObjects);
				stdvector.insert(stdvector.begin(), testArray, testArray + countObjects);

				return compareContainers(vector, stdvector);
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"erase range from begin()"
			, [&]()
			{
				vector.erase(vector.begin(), vector.begin() + countObjects);
				stdvector.erase(stdvector.begin(), stdvector.begin() + countObjects);

				return compareContainers(vector, stdvector);
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			std::string("insert range to begin() + offset(") + std::to_string(countObjects) + ")"
			, [&]()
			{
				vector.insert(vector.begin() + countObjects
						, testArray, testArray + countObjects);
				stdvector.insert(stdvector.begin() + countObjects
						, testArray, testArray + countObjects);

				return compareContainers(vector, stdvector);
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			std::string("erase range from begin() + offset(") + std::to_string(countObjects) + ")"
			, [&]()
			{
				vector.erase(
						vector.begin() + offset
						, vector.begin() + offset + countObjects
				);
				stdvector.erase(
						stdvector.begin() + offset
						, stdvector.begin() + offset + countObjects
				);

				return compareContainers(vector, stdvector);
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"insert range to end()"
			, [&]()
			{
				vector.insert(vector.end(), testArray, testArray + countObjects);
				stdvector.insert(stdvector.end(), testArray, testArray + countObjects);

				return compareContainers(vector, stdvector);
			}
		));

		CHECK_RESULT_SUCCESS(doTestCase(
			"erase from end()"
			, [&]()
			{
				vector.erase(vector.end() - countObjects, vector.end());
				stdvector.erase(stdvector.end() - countObjects, stdvector.end());

				return compareContainers(vector, stdvector);
			}
		));
	}

	return 0;
}


