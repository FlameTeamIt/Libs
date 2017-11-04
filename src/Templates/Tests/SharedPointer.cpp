#include "SharedPointer.hpp"

using namespace flame_ide;
using namespace flame_ide::test;

SharedPointer::SharedPointer() : AbstractTest("SharedPointer")
		, pointer {{1000, 100, 10, 1}}
{}

SharedPointer::~SharedPointer()
{}

int SharedPointer::vStart()
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

	std::cout << "Test copying:" << std::endl;
	{
		auto copyPointer = pointer;
		lambdaPrint(*copyPointer);
	}

	std::cout << "Test moving:" << std::endl;
	{
		decltype(pointer) movePointer = templates::move(pointer);
		lambdaPrint(*movePointer);

		pointer = templates::move(movePointer);
	}

	return 0;
}
