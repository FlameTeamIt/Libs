/*
 * file:       Vector.cpp
 *
 * created:    16.08.2017
 * author:     kachsheev
 */
#include "Vector.hpp"

#define COMPARE_VECTORS(vector1, vector2) \
{ \
	auto vector1ItBegin = vector1.begin(); \
	auto vector1ItEnd = vector1.end(); \
	auto vector2ItBegin = vector2.begin(); \
	auto vector2ItEnd = vector2.end(); \
\
	auto vector1It = vector1ItBegin; \
	auto vector2It = vector2ItBegin; \
\
	for (; vector1It != vector1ItEnd || vector2It != vector2ItEnd; \
			++vector1It, ++vector2It) \
	{ \
		if (*vector1It != *vector2It) \
		{ \
			std::cout << "Failed"; \
\
			log << std::endl; \
			std::cout << "vector1It (" #vector1 ") = "; \
			lambdaPrint(*vector1It); \
			std::cout << std::endl; \
\
			std::cout << "vector2It (" #vector2 ") = "; \
			lambdaPrint(*vector2It); \
			std::cout << std::endl; \
\
			return -1; \
		} \
	} \
	std::cout << "Success" << std::endl; \
}

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
	constexpr size_t SIZE = 5;

	TestClass testFirstObject{ -1000, -100, -10, 'F' };
	TestClass testMiddleObject{ -2000, -200, -20, 'M' };
	TestClass testLastObject{ -3000, -300, -30, 'L' };

	auto lambdaPrint = [] (const TestClass &testObject) {
		std::cout << "{ "
				  << "long("<< testObject.getLong() << "), "
				  << "int(" << testObject.getInt() << "), "
				  << "short(" << testObject.getShort() << "), "
				  << "char('" << testObject.getChar() << "') "
				  << "}";
	};

	std::cout << "Test initializing size: ";
	{
		if (vector.size() != stdvector.size())
		{
			log << vector.size() << " != " << SIZE << std::endl;
			return -1;
		}
		else
		{
			std::cout << "Success" << std::endl;
		}
	}

	std::cout << "Test initializing: ";
	{
		COMPARE_VECTORS(vector, stdvector)
	}

	std::cout << "Test reverse: ";
	{
		auto stdVectorItBegin = stdvector.rbegin();
		auto stdVectorItEnd = stdvector.rend();
		auto vectorItBegin = vector.rbegin();
		auto vectorItEnd = vector.rend();

		auto stdVectorIt = stdVectorItBegin;
		auto vectorIt = vectorItBegin;

		for (; stdVectorIt != stdVectorItEnd || vectorIt != vectorItEnd;
				++stdVectorIt, ++vectorIt)
		{
			if (*stdVectorIt != *vectorIt)
			{
				std::cout << "Failed";

				log << std::endl;
				std::cout << "stdVectorIt = ";
				lambdaPrint(*stdVectorIt);
				std::cout << std::endl;

				std::cout << "vectorIt = ";
				lambdaPrint(*stdVectorIt);
				std::cout << std::endl;

				return -1;
			}
		}
		std::cout << "Success" << std::endl;
	}

	{
		TestClass tmp = *vector.rbegin();

		std::cout << "Test popBack(): ";
		{
			vector.popBack();
			stdvector.pop_back();

			COMPARE_VECTORS(stdvector, vector)
		}

		std::cout << "Test pushBack(): ";
		{
			vector.pushBack(tmp);
			stdvector.push_back(tmp);

			COMPARE_VECTORS(vector, stdvector)
		}
	}

	std::cout << "Test emplaceBack(): ";
	{
		vector.emplaceBack(6000, 600, 60, '6');
		stdvector.emplace_back(6000, 600, 60, '6');

		COMPARE_VECTORS(vector, stdvector)

		vector.popBack();
		stdvector.pop_back();
	}

	std::cout << "Test insert(): ";
	{
		vector.insert(vector.begin(), testFirstObject);
		vector.insert(vector.begin() + 3, testMiddleObject);
		vector.insert(vector.end(), testLastObject);

		stdvector.insert(stdvector.begin(), testFirstObject);
		stdvector.insert(stdvector.begin() + 3, testMiddleObject);
		stdvector.insert(stdvector.end(), testLastObject);

		COMPARE_VECTORS(vector, stdvector)
	}

	std::cout << "Test erase(): ";
	{
		vector.erase(vector.begin() + 3);
		vector.erase(vector.begin());
		vector.erase(vector.end() - 1);

		stdvector.erase(stdvector.begin() + 3);
		stdvector.erase(stdvector.begin());
		stdvector.erase(stdvector.end() - 1);

		COMPARE_VECTORS(vector, stdvector)
	}

	std::cout << "Test emplace: ";
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

		COMPARE_VECTORS(vector, stdvector)

		vector.erase(vector.begin() + 3);
		vector.erase(vector.begin());
		vector.erase(vector.end() - 1);

		stdvector.erase(stdvector.begin() + 3);
		stdvector.erase(stdvector.begin());
		stdvector.erase(stdvector.end() - 1);
	}

	// Test insert(range)/erase(range)
	{
		TestClass testArray[] = {
			testFirstObject, testMiddleObject, testLastObject
		};

		std::cout << "Insert range to begin(): ";
		{
			vector.insert(vector.begin(), testArray, testArray + 3);
			stdvector.insert(stdvector.begin(), testArray, testArray + 3);

			COMPARE_VECTORS(vector, stdvector)
		}

		std::cout << "Erase range from begin(): ";
		{
			vector.erase(vector.begin(), vector.begin() + 3);
			stdvector.erase(stdvector.begin(), stdvector.begin() + 3);

			COMPARE_VECTORS(vector, stdvector)
		}

		std::cout << "Insert range to begin() + 3: ";
		{
			vector.insert(vector.begin() + 3, testArray, testArray + 3);
			stdvector.insert(stdvector.begin() + 3, testArray, testArray + 3);

			COMPARE_VECTORS(vector, stdvector)
		}

		std::cout << "Erase range from begin() + 3: ";
		{
			vector.erase(vector.begin() + 3, vector.begin() + 3 + 3);
			stdvector.erase(stdvector.begin() + 3, stdvector.begin() + 3 + 3);

			COMPARE_VECTORS(vector, stdvector)
		}

		std::cout << "Insert range to end(): ";
		{
			vector.insert(vector.end(), testArray, testArray + 3);
			stdvector.insert(stdvector.end(), testArray, testArray + 3);

			COMPARE_VECTORS(vector, stdvector)
		}

		std::cout << "Erase from end(): ";
		{
			vector.erase(vector.end() - 3, vector.end());
			stdvector.erase(stdvector.end() - 3, stdvector.end());

			COMPARE_VECTORS(vector, stdvector)
		}
	}

	return 0;
}


