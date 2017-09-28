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
{}

Array::~Array()
{}

int Array::vStart()
{
	constexpr size_t SIZE = 5;
	auto lambdaPrint = [] (const TestClass &testObject) {
		std::cout << testObject.getLong()
				<< ' ' << testObject.getInt()
				<< ' ' << testObject.getShort()
				<< ' ' << testObject.getChar() << std::endl;
	};
	auto printArray = [&lambdaPrint] (auto &array) {
		auto itEnd = array.end();
		auto it = array.begin();
		while (it != itEnd)
		{
			lambdaPrint(*it);
			++it;
		}
		std::cout << std::endl;
	};

	std::cout << "Test initializing size:" << std::endl;
	if (array.size() == SIZE)
		std::cout << array.size() << " == " << SIZE << std::endl;
	else
	{
		std::cout << array.size() << " != " << SIZE << std::endl;
		return 1;
	}
	std::cout << std::endl;

	std::cout << "Test initializing:" << std::endl;
	printArray(array);

	std::cout << "Test cloning:" << std::endl;
	decltype(array) arrayClone = array.clone();
	printArray(arrayClone);
	std::cout << std::endl;

	std::cout << "Test copying:" << std::endl;
	templates::Array<TestClass, 10> arrayCopy = array;

	printArray(arrayCopy);
	std::cout << std::endl;

	std::cout << "Test reverse:" << std::endl;
	typename flame_ide::templates::ContainerTraits<decltype(array)>::ConstReference crefArray = array;
	flame_ide::templates::Range<decltype(array)::ConstReverseIterator> range(crefArray.rbegin(), crefArray.rend());
	printArray(range);
	std::cout << std::endl;

	TestClass testLastObject;
	std::cout << "Test last():" << std::endl;
	testLastObject = array.last();
	lambdaPrint(testLastObject);
	std::cout << std::endl;

	TestClass testFirstObject;
	std::cout << "Test first():" << std::endl;
	testFirstObject = array.first();
	lambdaPrint(testFirstObject);
	std::cout << std::endl;

	std::cout << "Test popBack():" << std::endl;
	array.popBack();
	printArray(array);

	std::cout << "Test pushBack():" << std::endl;
	array.pushBack(testLastObject);
	printArray(array);

	std::cout << "Test insert()" << std::endl;
	TestClass testMiddleObject(-2500, -250, -25, 'M');

	testFirstObject.getChar() = 'F';
	testFirstObject.getShort() = -10;
	testFirstObject.getInt() = -100;
	testFirstObject.getLong() = -1000;

	testLastObject.getChar() = 'L';
	testLastObject.getShort() = -50;
	testLastObject.getInt() = -500;
	testLastObject.getLong() = -5000;

	array.insert(array.begin(), testFirstObject);
	array.insert(array.begin() + 3, testMiddleObject);
	array.insert(array.end(), testLastObject);

	printArray(array);

	std::cout << "Test erase()" << std::endl;
	array.erase(array.begin() + 3);
	array.erase(array.begin());
	array.erase(array.end() - 1);

	printArray(array);

	TestClass testArray[] = {
		testFirstObject, testMiddleObject, testLastObject
	};

	std::cout << "> Test insert(range)/erase(range) <" << std::endl;

	std::cout << "Insert to begin()" << std::endl;
	array.insert(array.begin(), testArray, testArray + 3);
	printArray(array);

	std::cout << "Erase from begin()" << std::endl;
	array.erase(array.begin(), array.begin() + 3);
	printArray(array);

	std::cout << "Insert to begin() + 3" << std::endl;
	array.insert(array.begin() + 3, testArray, testArray + 3);
	printArray(array);

	std::cout << "Erase from begin() + 3" << std::endl;
	array.erase(array.begin() + 3, array.begin() + 3 + 3);
	printArray(array);

	std::cout << "Insert to end()" << std::endl;
	array.insert(array.end(), testArray, testArray + 3);
	printArray(array);

	std::cout << "Erase from end()" << std::endl;
	array.erase(array.end() - 3, array.end());
	printArray(array);

	return 0;
}
