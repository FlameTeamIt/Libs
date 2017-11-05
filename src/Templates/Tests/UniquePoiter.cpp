#include "UniquePoiter.hpp"

using namespace flame_ide;
using namespace flame_ide::test;

UniquePointer::UniquePointer() : AbstractTest("UniquePointer")
		, pointer {{1000, 100, 10, '1'}}
{}

UniquePointer::~UniquePointer()
{}

int UniquePointer::vStart()
{
	auto lambdaPrint = [] (const TestClass &testObject, bool endl = true) {
		std::cout << testObject.getLong()
				<< ' ' << testObject.getInt()
				<< ' ' << testObject.getShort()
				<< ' ' << testObject.getChar() << std::endl;
		if (endl)
			std::cout << std::endl;
	};

	std::cout << "Test initializing:" << std::endl;
	{
		lambdaPrint(*pointer);
	}

	std::cout << "Test moving:" << std::endl;
	{
		decltype(pointer) movePointer = templates::move(pointer);
		lambdaPrint(*movePointer);

		pointer = templates::move(movePointer);
	}

	return 0;
}
