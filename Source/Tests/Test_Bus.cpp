#include <iostream>
#include "Test.h"
#include "../Others/TextStyle.h"

// Bus
#include "../Bus/MsgInterface.h"

using namespace flame_ide;

void
Test::Bus::all()
{
	std::cout << "Test::Bus::all()" << '\n';
	count_success_tests = this->TMsgInterface();
	
	std::cout << '\n';
}

unsigned int
Test::Bus::TMsgInterface()
{
	std::cout << "Test::Bus::TMsgInterface()" << '\n';
	return 1;
}
