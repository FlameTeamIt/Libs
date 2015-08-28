#include <iostream>
#include <Others/TextStyle.h>

#include "Test.h"

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
	
	analyzers.all();
	bus.all();
	filesystem.all();
	templates.all();
	
	others.all();
	
	std::cout << '\n';
}


