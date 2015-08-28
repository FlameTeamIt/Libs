#include <iostream>
#include "Test.h"
#include "../Others/TextStyle.h"

// Actions
#include "../Actions/CommandLine.h"
#include "../Actions/CodeParcer.h"

using namespace flame_ide;

void
Test::Actions::all()
{
	std::cout << "Test::Actions::all()\n";
	
	this->count_success_tests = this->TCodeParcer()
			                    + this->TCommandLine();
	
	std::cout << '\n';
}

unsigned int
Test::Actions::TCodeParcer()
{
	std::cout << "Test::Actions::TCodeParcer()\n";
	return 1;
}

unsigned int
Test::Actions::TCommandLine()
{
	std::cout << "Test::Actions::TCommandLine()\n";
	
	CommandLine commands;
	
#define c_comm "ls -a"
	
	char str[] = c_comm;
	std::string command(str);
	
	std::cout << commands.getOutput(str) << "\n";
	std::cout << commands.getOutput(std::string(str)) << "\n";
	std::cout << commands.getOutput(command) << '\n';
	std::cout << commands.getOutput(c_comm) << '\n';
	
#undef c_comm
	
	return 1;
}
