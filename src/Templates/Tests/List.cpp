#include "List.hpp"

using namespace flame_ide;
using namespace flame_ide::test;

List::List() : AbstractTest("List")
		, list {{
				TestClass{1000, 100, 10, '1'}
				, TestClass{2000, 200, 20, '2'}
				, TestClass{3000, 300, 30, '3'}
				, TestClass{4000, 400, 40, '4'}
				, TestClass{5000, 500, 50, '5'}
		}}
{}

List::~List()
{}

int List::vStart()
{
	constexpr size_t SIZE = 5;
	auto lambdaPrint = [] (const TestClass &testObject) {
		std::cout << testObject.getLong()
				<< ' ' << testObject.getInt()
				<< ' ' << testObject.getShort()
				<< ' ' << testObject.getChar() << std::endl;
	};
	auto printList = [&lambdaPrint] (auto &list, bool endl = true) {
		auto itEnd = list.end();
		auto it = list.begin();
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
		if (list.size() == SIZE)
			std::cout << list.size() << " == " << SIZE << std::endl;
		else
		{
			std::cout << list.size() << " != " << SIZE << std::endl;
			return 1;
		}
	}

	std::cout << "Test initializing:" << std::endl;
	{
		printList(list);
	}

	std::cout << "Test cloning:" << std::endl;
	{
		templates::List<TestClass> listClone = list.clone();
		printList(listClone);
	}

	std::cout << "Test copying:" << std::endl;
	{
		templates::List<TestClass> listCopy = list;
		printList(listCopy);
	}

	std::cout << "Test moving:" << std::endl;
	{
		templates::List<TestClass> listMove = templates::move(list);
		std::cout << "--> Moved: " << std::endl;
		printList(listMove, false);

		list = templates::move(listMove);
		std::cout << "--> Original: " << std::endl;
		printList(list);
	}

	std::cout << "Test reverse:" << std::endl;
	{
		templates::ContainerTraits<decltype(list)>::ConstReference crlist = list;
		templates::Range<
			decltype(crlist.crbegin())
		> range(crlist.crbegin(), crlist.crend());
		printList(range);
	}

	TestClass testLastObject;
	std::cout << "Test last():" << std::endl;
	{
		testLastObject = list.last();
		lambdaPrint(testLastObject);
	}
	std::cout << std::endl;

	TestClass testFirstObject;
	std::cout << "Test first():" << std::endl;
	{
		testFirstObject = list.first();
		lambdaPrint(testFirstObject);
	}
	std::cout << std::endl;

	std::cout << "Test popBack():" << std::endl;
	{
		list.popBack();
		printList(list);
	}

	std::cout << "Test pushBack():" << std::endl;
	{
		list.pushBack(testLastObject);
		printList(list);
	}

	std::cout << "Test emplaceBack():" << std::endl;
	{
		list.emplaceBack(-6000, -600, -60, '6');
		printList(list);
		list.popBack();
	}

	std::cout << "Test popFront():" << std::endl;
	{
		list.popFront();
		printList(list);
	}

	std::cout << "Test pushFront():" << std::endl;
	{
		list.pushFront(testFirstObject);
		printList(list);
	}

	std::cout << "Test emplaceFront():" << std::endl;
	{
		list.emplaceFront(-6000, -600, -60, '6');
		printList(list);
		list.popFront();
	}

	TestClass testMiddleObject = {-2500, -250, -25, 'M'};
	testFirstObject = {-1000, -100, -10, 'F'};
	testLastObject = {-5000, -500, -50, 'L'};

	std::cout << "Test insert()" << std::endl;
	{
		list.insert(list.begin(), testFirstObject);
		list.insert(++(++(++list.begin())), testMiddleObject);
		list.insert(list.end(), testLastObject);

		printList(list);
	}

	std::cout << "Test erase()" << std::endl;
	{
		list.erase(list.begin());
		list.erase(++(++list.begin()));
		list.erase(list.end());

		printList(list);
	}

	std::cout << "Test emplace:" << std::endl;
	{
		list.emplace(list.begin(), testFirstObject);
		list.emplace(++(++(++list.begin())), testMiddleObject);
		list.emplace(list.end(), testLastObject);

		printList(list, false);

		list.erase(list.begin());
		list.erase(++(++list.begin()));
		list.erase(list.end());

		std::cout << "--> revert" << std::endl;
		printList(list);
	}

	std::cout << ">--- Test insert(range)/erase(range) ---<" << std::endl << std::endl;
	{
		TestClass testlist[] = {
			testFirstObject, testMiddleObject, testLastObject
		};

		std::cout << "Insert to begin()" << std::endl;
		{
			list.insert(list.begin(), testlist, testlist + 3);
			printList(list);
		}

		std::cout << "Erase from begin()" << std::endl;
		{
			list.erase(list.begin(), ++(++(++list.begin())));
			printList(list);
		}

		std::cout << "Insert to begin() + 3" << std::endl;
		{
			list.insert(++(++(++list.begin())), testlist, testlist + 3);
			printList(list);
		}

		std::cout << "Erase from begin() + 3" << std::endl;
		{
			list.erase(++(++(++list.begin()))
					, ++(++(++(++(++(++list.begin()))))) );
			printList(list);
		}

		std::cout << "Insert to end()" << std::endl;
		{
			list.insert(list.end(), testlist, testlist + 3);
			printList(list);
		}

		std::cout << "Erase from end()" << std::endl;
		{
			list.erase(--(--(--list.end())), list.end());
			printList(list);
		}
	}

	return 0;
}
