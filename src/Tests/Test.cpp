#include <iostream>
#include "Test.h"

#include "../Others/TextStyle.h"

struct Kilobyte
{
	char data[1024];
};

using namespace flame_ide;

Test::Test()
{}

Test::~Test()
{}

void
Test::all()
{
	std::cout << TEXT_STYLE_CYAN << TEXT_STYLE_BOLD
			  << "Test::all()" << TEXT_STYLE_NULL << '\n';
	
//	actions.all();
//	bus.all();
//	store.all();
	
	others.all();
	
	std::cout << '\n';
}


