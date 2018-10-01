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
	auto printArray = [&lambdaPrint] (auto &array, bool endl = true) {
		auto itEnd = array.end();
		auto it = array.begin();
		while (it != itEnd)
		{
			lambdaPrint(*it);
			++it;
		}
		if (endl)
			std::cout << std::endl;
	};

	std::cout << "Test initializing size:" << std::endl;
	{
		if (array.size() == SIZE)
			std::cout << array.size() << " == " << SIZE << std::endl;
		else
		{
			std::cout << array.size() << " != " << SIZE << std::endl;
			return 1;
		}
	}

	std::cout << "Test initializing:" << std::endl;
	{
		printArray(array);
	}

	std::cout << "Test cloning:" << std::endl;
	{
		templates::Array<TestClass, 10> arrayClone = array.clone();
		printArray(arrayClone);
	}

	std::cout << "Test copying:" << std::endl;
	{
		templates::Array<TestClass, 10> arrayCopy = array;
		printArray(arrayCopy);
	}

	std::cout << "Test moving:" << std::endl;
	{
		templates::Array<TestClass, 10> arrayMove = flame_ide::move(array);
		std::cout << "--> Moved: " << std::endl;
		printArray(arrayMove, false);

		array = flame_ide::move(arrayMove);
		std::cout << "--> Original: " << std::endl;
		printArray(array);
	}
	std::cout << std::endl;

	std::cout << "Test reverse:" << std::endl;
	{
		templates::Range<
			decltype(array.crbegin())
		> range(array.crbegin(), array.crend());
		printArray(range);
	}
	std::cout << std::endl;

	std::cout << "Test popBack():" << std::endl;
	{
		array.popBack();
		printArray(array);
	}

	TestClass testLastObject = *array.rbegin();
	std::cout << "Test pushBack():" << std::endl;
	{
		array.pushBack(testLastObject);
		printArray(array);
	}

	std::cout << "Test emplaceBack():" << std::endl;
	{
		array.emplaceBack(-6000, -600, -60, '6');
		printArray(array);
		array.popBack();
	}

	TestClass testMiddleObject = {-2500, -250, -25, 'M'};
	TestClass testFirstObject = {-1000, -100, -10, 'F'};
	testLastObject = {-5000, -500, -50, 'L'};

	std::cout << "Test insert()" << std::endl;
	{
		array.insert(array.begin(), testFirstObject);
		array.insert(array.begin() + 3, testMiddleObject);
		array.insert(array.end(), testLastObject);

		printArray(array);
	}

	std::cout << "Test erase()" << std::endl;
	{
		array.erase(array.begin() + 3);
		array.erase(array.begin());
		array.erase(array.end() - 1);

		printArray(array);
	}

	std::cout << "Test emplace:" << std::endl;
	{
		array.emplace(array.begin(), testFirstObject);
		array.emplace(array.begin() + 3, testMiddleObject);
		array.emplace(array.end(), testLastObject);

		printArray(array);

		array.erase(array.begin() + 3);
		array.erase(array.begin());
		array.erase(array.end() - 1);
	}

	std::cout << "Test operator+=() copy" << std::endl;
	{
		TestClass testObject {-6000, -600, -60, '6'};
		array += testObject;

		printArray(array);
	}

	std::cout << "Test operator-=(Iterator)" << std::endl;
	{
		array -= --(array.end());

		printArray(array);
	}

	std::cout << "Test operator+=() move" << std::endl;
	{
		TestClass testObject {-7000, -700, -70, '7'};
		array += flame_ide::move(testObject);

		printArray(array);
	}

	std::cout << "Test operator-=(ReverseIterator)" << std::endl;
	{
		array -= array.rbegin();

		printArray(array);
	}

	std::cout << "Test operator+=(Range)" << std::endl;
	{
		TestClass testObjects[] = {{6000, 600, 60, '6'}
				, {-7000, -700, -70, '7'}
				, {-8000, -800, -80, '8'}
				, {-8000, -800, -80, '8'}};

		array += flame_ide::templates::Range<TestClass *>{
				testObjects, testObjects + 4
		};

		printArray(array);
	}

	std::cout << "Test operator-=(ForwardRange)" << std::endl;
	{
		array -= flame_ide::templates::Range<decltype(array)::Iterator> {
				array.end() - 4, array.end()
		};

		printArray(array);
	}

	std::cout << "Test operator+=(Range)" << std::endl;
	{
		TestClass testObjects[] = {{6000, 600, 60, '6'}
				, {-7000, -700, -70, '7'}
				, {-8000, -800, -80, '8'}
				, {-8000, -800, -80, '8'}};

		array += flame_ide::templates::Range<TestClass *>{
				testObjects, testObjects + 4
		};

		printArray(array);
	}

	std::cout << "Test operator-=(ReverseRange)" << std::endl;
	{
		array -= flame_ide::templates::Range<decltype(array)::ReverseIterator> {
				array.rbegin(), array.rbegin() + 4
		};

		printArray(array);
	}

	std::cout << ">--- Test insert(range)/erase(range) ---<" << std::endl << std::endl;
	{
		TestClass testArray[] = {
			testFirstObject, testMiddleObject, testLastObject
		};

		std::cout << "Insert to begin()" << std::endl;
		{
			array.insert(array.begin(), testArray, testArray + 3);
			printArray(array);
		}

		std::cout << "Erase from begin()" << std::endl;
		{
			array.erase(array.begin(), array.begin() + 3);
			printArray(array);
		}

		std::cout << "Insert to begin() + 3" << std::endl;
		{
			array.insert(array.begin() + 3, testArray, testArray + 3);
			printArray(array);
		}

		std::cout << "Erase from begin() + 3" << std::endl;
		{
			array.erase(array.begin() + 3, array.begin() + 3 + 3);
			printArray(array);
		}

		std::cout << "Insert to end()" << std::endl;
		{
			array.insert(array.end(), testArray, testArray + 3);
			printArray(array);
		}

		std::cout << "Erase from end()" << std::endl;
		{
			array.erase(array.end() - 3, array.end());
			printArray(array);
		}
	}
	std::cout << ">--- End test insert(range)/erase(range) ---<" << std::endl << std::endl;
	/**/

	return 0;
}

