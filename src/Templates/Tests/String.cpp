#include "String.hpp"

#define TEST_STRING "Hello, world!"

using namespace flame_ide::test;

String::String() : AbstractTest("String")
		, string(TEST_STRING)
{}

String::~String()
{}

int String::vStart()
{
	auto printString = [] (auto &string, bool endl = false)
	{
		std::cout << '"';
		for (auto i : string)
		{
			std::cout << i;
		}
		std::cout << '"' << std::endl;

		if (endl)
			std::cout << std::endl;
	};

	std::cout << "Testing bufferSize from string_utils:" << std::endl;
	{
		int i = 100500;
		std::cout << '\'' << i << "' -> "
				<< templates::string_utils::bufferSize(i)
				<< std::endl;
		std::cout << '\'' << i * (-1) << "' -> "
				<< templates::string_utils::bufferSize(i * (-1))
				<< std::endl;
		std::cout << '\'' << unsigned(i) << "' -> "
				<< templates::string_utils::bufferSize(unsigned(i))
				<< std::endl;
		std::cout << '\'' << UINT64_MAX << "' -> "
				<< templates::string_utils::bufferSize(UINT64_MAX)
				<< std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing toString()" << std::endl;
	{
		int i = 100500;
		std::cout << i << " -> "
				<< templates::toString(i).data()
				<< std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing output:" << std::endl;
	{
		printString(string);
	}
	std::cout << std::endl;

	std::cout << "Testing output (reverse):" << std::endl;
	{
		auto range = templates::makeRange(string.rbegin(), string.rend());
		printString(range);
	}
	std::cout << std::endl;

	std::cout << "Testing pushBack()/popBack():" << std::endl;
	{
		std::cout << "---> pushBack(object):" << std::endl;
		{
			string.pushBack('_');
			printString(string);
		}

		std::cout << "---> popBack():" << std::endl;
		{
			string.popBack();
			printString(string);
		}

		std::cout << "---> pushBack(array):" << std::endl;
		{
			string.pushBack(" My name is John.");
			printString(string);
		}
	}
	std::cout << std::endl;

	std::cout << "Testing insert()/erase():" << std::endl;
	{
		std::cout << "---> erase(range)" << std::endl;
		{
			auto size = sizeof(TEST_STRING) - 1;
			string.erase(string.begin() + size, string.end());
			printString(string);
		}

		std::cout << "---> erase(iterator)" << std::endl;
		{
			auto size = sizeof("Hello") - 1;
			string.erase(string.begin() + size);
			printString(string);
		}

		std::cout << "---> insert(iterator)" << std::endl;
		{
			auto size = sizeof("Hello") - 1;
			string.insert(string.begin() + size, ',');
			printString(string);
		}
	}
	std::cout << std::endl;

	std::cout << "Testing operator=()" << std::endl;
	{
		std::cout << "---> operator=(ConstReference)" << std::endl;
		{
			templates::String copiedString = string;
			std::cout << copiedString.data() << std::endl;
		}
		std::cout << "---> operator=(MoveReference)" << std::endl;
		{
			templates::String movedString = templates::String();
			movedString = flame_ide::move(string);
			std::cout << "Moved: " << movedString.data() << std::endl;
			string = flame_ide::move(movedString);
			std::cout << "Original: " << string.data() << std::endl;
		}
		std::cout << "---> operator=(PointerToConst)" << std::endl;
		{
			templates::String stringFromArray = templates::String();
			stringFromArray = string.data();
			std::cout << stringFromArray.data() << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
