#include <iostream>
#include <Others/TextStyle.h>

// Bus
#include <Bus/MsgInterface.h>

#include <Tests/Test.h>

using namespace flame_ide;

void
Test::Bus::all()
{
	std::cout << "Test::Bus::all()" << '\n';
	count_success_tests = this->MsgInterface();
	
	std::cout << '\n';
}

unsigned int
Test::Bus::MsgInterface()
{
	std::cout << "Test::Bus::MsgInterface()" << '\n';
	return 1;
}
