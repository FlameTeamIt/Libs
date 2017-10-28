#include "List.hpp"

using flame_ide::test::List;

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
	auto printList = [&lambdaPrint] (auto &array, bool endl = true) {
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

	return 0;
}
