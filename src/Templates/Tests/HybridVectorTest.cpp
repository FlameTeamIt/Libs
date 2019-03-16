#include <FlameIDE/Templates/Range.hpp>

#include "HybridVectorTest.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

namespace hybridvector_utils
{

using HybridVector = flame_ide::templates::HybridVector<TestClass, test::HybridVectorTest::ARRAY_SIZE>;
using StdVector = std::vector<TestClass>;
using StdArray = std::array<TestClass, test::HybridVectorTest::ARRAY_SIZE>;

}

HybridVectorTest::HybridVectorTest() : AbstractTest("HybridVector")
{}

HybridVectorTest::~HybridVectorTest()
{}

int HybridVectorTest::vStart()
{
	IN_TEST_CHECK(!iterators())
	IN_TEST_CHECK(!container());
	IN_TEST_CHECK(!fullTestAsArray());
	IN_TEST_CHECK(!fullTestAsVector());
	IN_TEST_CHECK_END(!hybridTest());
}

bool HybridVectorTest::iterators()
{
	constexpr Types::size_t SIZE = ARRAY_SIZE;
	Vector vector;
	vector.reserve(SIZE);
	for (Types::size_t i = 0; i < SIZE; ++i)
	{
		vector.pushBack(Vector::Type(i));
	}

	CHECK_RESULT_SUCCESS_END(doTestCase(
		"As vector iterator"
		, [&]()
		{
			//
			{
				HybVectorIterator itBeign = vector.begin();
				HybVectorIterator itEnd = vector.end();
				auto range = templates::makeRange(itBeign, itEnd);
				IN_CASE_CHECK(ResultType::SUCCESS
						== compareContainers(range, vector));
			}

			//
			{
				ContainerTraits<Vector>::ConstReference cvector = vector;
				HybConstVectorIterator constItBeign = cvector.begin();
				HybConstVectorIterator constItEnd = cvector.end();
				auto constRange = templates::makeRange(constItBeign, constItEnd);
				IN_CASE_CHECK_END(ResultType::SUCCESS
						== compareContainers(constRange, vector));
			}
		}
	));
}

bool HybridVectorTest::container()
{
	IN_CASE_CHECK(!containerAsArray());
	IN_CASE_CHECK_END(!containerAsVector());
}

bool HybridVectorTest::containerAsArray()
{
	Array array{{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }};
	HybVector hybVector{ array };
	array_t stdarray{{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }};

	CHECK_RESULT_SUCCESS_END(doTestCase(
		"Creating by array"
		, [&]()
		{
			IN_CASE_CHECK(ResultType::SUCCESS
					== compareContainers(array, hybVector));
			IN_CASE_CHECK_END(ResultType::SUCCESS
					== compareContainers(stdarray, hybVector));
		}
	));
}

bool HybridVectorTest::containerAsVector()
{
	Vector vector{{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }};
	HybVector hybVector{ vector };
	vector_t stdvector{{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }};

	CHECK_RESULT_SUCCESS_END(doTestCase(
		"Creating by vector"
		, [&]()
		{
			IN_CASE_CHECK(ResultType::SUCCESS
					== compareContainers(vector, hybVector));
			IN_CASE_CHECK_END(ResultType::SUCCESS
					== compareContainers(stdvector, hybVector));
		}
	));
}

bool HybridVectorTest::fullTestAsArray()
{
	hybridvector_utils::HybridVector array;
	hybridvector_utils::StdArray stdarray;

	return false;
}

bool HybridVectorTest::fullTestAsVector()
{
	hybridvector_utils::HybridVector vector{
			hybridvector_utils::HybridVector::Vector{{
					TestClass{1000, 100, 10, '1'}
					, TestClass{2000, 200, 20, '2'}
					, TestClass{3000, 300, 30, '3'}
					, TestClass{4000, 400, 40, '4'}
					, TestClass{5000, 500, 50, '5'}
			}}
	};

	hybridvector_utils::StdVector stdvector{
		TestClass{1000, 100, 10, '1'}
		, TestClass{2000, 200, 20, '2'}
		, TestClass{3000, 300, 30, '3'}
		, TestClass{4000, 400, 40, '4'}
		, TestClass{5000, 500, 50, '5'}
	};

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

	auto caseEmplace = [&]()
	{
		TestClass tempFirstObject = testFirstObject;
		TestClass tempMiddleObject = testMiddleObject;
		TestClass tempLastObject = testLastObject;

		vector.emplace(vector.begin(), tempFirstObject);
		vector.emplace(vector.begin() + 3, tempMiddleObject);
		vector.emplace(vector.end(), tempLastObject);

		tempFirstObject = testFirstObject;
		tempMiddleObject = testMiddleObject;
		tempLastObject = testLastObject;

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
	};
	CHECK_RESULT_SUCCESS(doTestCase(
		"emplace"
		, caseEmplace
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

		CHECK_RESULT_SUCCESS_END(doTestCase(
			"erase from end()"
			, [&]()
			{
				vector.erase(vector.end() - countObjects, vector.end());
				stdvector.erase(stdvector.end() - countObjects, stdvector.end());

				return compareContainers(vector, stdvector);
			}
		));
	}
}

bool HybridVectorTest::hybridTest()
{
	hybridvector_utils::HybridVector hybridVector;
	return false;
}

}}}
