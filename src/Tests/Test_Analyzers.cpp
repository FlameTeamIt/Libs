#include <iostream>
#include <Others/TextStyle.h>

// Actions
#include <Process/CommandLine.h>
#include <Analysers/CodeParcer.h>

#include <Tests/Test.h>

using namespace flame_ide;

void
Test::Analyzers::all()
{
	std::cout << "Test::Analyzers::all()\n";
	
	this->count_success_tests = this->CodeParcer()
			                    + this->CommandLine();
	
	std::cout << '\n';
	
	json_lib.all();
}

unsigned int
Test::Analyzers::CodeParcer()
{
	std::cout << "Test::Analyzers::CodeParcer()\n";
	return 1;
}

unsigned int
Test::Analyzers::CommandLine()
{
	std::cout << "Test::Analyzers::CommandLine()\n";
	
	flame_ide::CommandLine commands;
	
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
