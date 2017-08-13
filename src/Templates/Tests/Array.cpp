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
	std::cout << "Test initializing size:" << std::endl;
	if (array.size() == array.capacity())
		std::cout << array.size() << " == " << array.capacity() << std::endl;
	else
	{
		std::cout << array.size() << " != " << array.capacity() << std::endl;
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

	TestClass testObject;
//	std::cout << "Test last():" << std::endl;
//	testObject = array.last();
//	std::cout << testObject.getLong()
//			<< ' ' << testObject.getInt()
//			<< ' ' << testObject.getShort()
//			<< ' ' << testObject.getChar() << std::endl;
//	std::cout << std::endl;

	std::cout << "Test first():" << std::endl;
	testObject = array.first();
	std::cout << testObject.getLong()
			<< ' ' << testObject.getInt()
			<< ' ' << testObject.getShort()
			<< ' ' << testObject.getChar() << std::endl;
	std::cout << std::endl;

	std::cout << "Test popBack():" << std::endl;
	array.popBack();
	for (TestClass &i : array)
		std::cout << i.getLong()
				<< ' ' << i.getInt()
				<< ' ' << i.getShort()
				<< ' ' << i.getChar() << std::endl;
	std::cout << std::endl;

	return 0;
}
