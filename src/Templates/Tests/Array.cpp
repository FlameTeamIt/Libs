/*
 * file:       Array.cpp
 *
 * created:    21.07.2017
 * author:     kachsheev
 */
#include "Array.hpp"

using namespace flame_ide::test;

Array::Array() : AbstractTest("Array")
		, array({
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		})
{}

Array::~Array()
{}

int Array::vStart()
{
	constexpr size_t SIZE = 5;
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
	for (TestClass &i : array)
		std::cout << i.getLong()
				<< ' ' << i.getInt()
				<< ' ' << i.getShort()
				<< ' ' << i.getChar() << std::endl;
	std::cout << std::endl;

	std::cout << "Test reverse:" << std::endl;
	for (auto it = array.rbegin(); it != array.rend(); ++it)
		std::cout << it->getLong()
				<< ' ' << it->getInt()
				<< ' ' << it->getShort()
				<< ' ' << it->getChar() << std::endl;
	std::cout << std::endl;

	TestClass testLastObject;
	std::cout << "Test last():" << std::endl;
	testLastObject = array.last();
	std::cout << testLastObject.getLong()
			<< ' ' << testLastObject.getInt()
			<< ' ' << testLastObject.getShort()
			<< ' ' << testLastObject.getChar() << std::endl;
	std::cout << std::endl;

	TestClass testFirstObject;
	std::cout << "Test first():" << std::endl;
	testFirstObject = array.first();
	std::cout << testFirstObject.getLong()
			<< ' ' << testFirstObject.getInt()
			<< ' ' << testFirstObject.getShort()
			<< ' ' << testFirstObject.getChar() << std::endl;
	std::cout << std::endl;

	std::cout << "Test popBack():" << std::endl;
	array.popBack();
	for (TestClass &i : array)
		std::cout << i.getLong()
				<< ' ' << i.getInt()
				<< ' ' << i.getShort()
				<< ' ' << i.getChar() << std::endl;
	std::cout << std::endl;

	std::cout << "Test pushBack():" << std::endl;
	array.pushBack(testLastObject);
	for (TestClass &i : array)
		std::cout << i.getLong()
				<< ' ' << i.getInt()
				<< ' ' << i.getShort()
				<< ' ' << i.getChar() << std::endl;
	std::cout << std::endl;

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

	for (TestClass &i : array)
		std::cout << i.getLong()
				<< ' ' << i.getInt()
				<< ' ' << i.getShort()
				<< ' ' << i.getChar() << std::endl;
	std::cout << std::endl;

	return 0;
}
