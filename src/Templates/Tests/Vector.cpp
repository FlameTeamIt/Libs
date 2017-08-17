/*
 * file:       Vector.cpp
 *
 * created:    16.08.2017
 * author:     kachsheev
 */
#include "Vector.hpp"

using namespace flame_ide::test;

Vector::Vector() : AbstractTest("Vector")
		, vector{
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
	auto lambdaPrint = [] (const TestClass &testObject) {
		std::cout << testObject.getLong()
				<< ' ' << testObject.getInt()
				<< ' ' << testObject.getShort()
				<< ' ' << testObject.getChar() << std::endl;
	};
	auto printArray = [&lambdaPrint] (auto &vector) {
		for (auto &i : vector)
			lambdaPrint(i);
		std::cout << std::endl;
	};

	std::cout << "Test initializing size:" << std::endl;
	if (vector.size() == SIZE)
		std::cout << vector.size() << " == " << SIZE << std::endl;
	else
	{
		std::cout << vector.size() << " != " << SIZE << std::endl;
		return 1;
	}
	std::cout << std::endl;

	std::cout << "Test initializing:" << std::endl;
	printArray(vector);

	std::cout << "Test reverse:" << std::endl;
	for (auto it = vector.rbegin(); it != vector.rend(); ++it)
		lambdaPrint(*it);
	std::cout << std::endl;

	TestClass testLastObject;
	std::cout << "Test last():" << std::endl;
	testLastObject = vector.last();
	lambdaPrint(testLastObject);
	std::cout << std::endl;

	TestClass testFirstObject;
	std::cout << "Test first():" << std::endl;
	testFirstObject = vector.first();
	lambdaPrint(testFirstObject);
	std::cout << std::endl;

	std::cout << "Test popBack():" << std::endl;
	vector.popBack();
	printArray(vector);

	std::cout << "Test pushBack():" << std::endl;
	vector.pushBack(testLastObject);
	printArray(vector);

//	std::cout << "Test insert()" << std::endl;
//	TestClass testMiddleObject(-2500, -250, -25, 'M');

//	testFirstObject.getChar() = 'F';
//	testFirstObject.getShort() = -10;
//	testFirstObject.getInt() = -100;
//	testFirstObject.getLong() = -1000;

//	testLastObject.getChar() = 'L';
//	testLastObject.getShort() = -50;
//	testLastObject.getInt() = -500;
//	testLastObject.getLong() = -5000;

//	vector.insert(vector.begin(), testFirstObject);
//	vector.insert(vector.begin() + 3, testMiddleObject);
//	vector.insert(vector.end(), testLastObject);

//	printArray(vector);

//	std::cout << "Test erase()" << std::endl;
//	vector.erase(vector.begin() + 3);
//	vector.erase(vector.begin());
//	vector.erase(vector.end() - 1);

//	printArray(vector);

//	TestClass testArray[] = {
//		testFirstObject, testMiddleObject, testLastObject
//	};

//	//
//	std::cout << "> Test insert(range)/erase(range) <" << std::endl;

//	std::cout << "Insert to begin()" << std::endl;
//	vector.insert(vector.begin(), testArray, testArray + 3);
//	printArray(vector);

//	std::cout << "Erase from begin()" << std::endl;
//	vector.erase(vector.begin(), vector.begin() + 3);
//	printArray(vector);

//	std::cout << "Insert to begin() + 3" << std::endl;
//	vector.insert(vector.begin() + 3, testArray, testArray + 3);
//	printArray(vector);

//	std::cout << "Erase from begin() + 3" << std::endl;
//	vector.erase(vector.begin() + 3, vector.begin() + 3 + 3);
//	printArray(vector);

//	std::cout << "Insert to end()" << std::endl;
//	vector.insert(vector.end(), testArray, testArray + 3);
//	printArray(vector);

//	std::cout << "Erase from end()" << std::endl;
//	vector.erase(vector.end() - 3, vector.end());
//	printArray(vector);

	return 0;
}


