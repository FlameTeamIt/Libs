#include "Test.h"

#include "../Actions/CommandLine.h"
#include "../Actions/CodeParcer.h"

#include "../Bus/MsgInterface.h"

#include "../Store/BasicFile.h"
#include "../Store/Project.h"
#include "../Store/Session.h"

#include "../Others/Templates/Array.h"
#include "../Others/Templates/List.h"
#include "../Others/JSON/JSON.h"

#include <iostream>

using namespace flame_ide;

Test::Test()
{}

Test::~Test()
{}

void
Test::all()
{
	std::cout << "Test::all()\n";
	
//	actions.all();
//	bus.all();
//	store.all();
	
	others.all();
}

// Actions

void
Test::Actions::all()
{
	std::cout << "Test::Actions::all()\n";
	
	this->TCodeParcer();
	this->TCommandLine();	
}

unsigned int
Test::Actions::TCodeParcer()
{
	std::cout << "Test::Actions::TCodeParcer()\n";
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
}

// Bus

void
Test::Bus::all()
{
	count_success_tests = this->TMsgInterface();
}

unsigned int
Test::Bus::TMsgInterface()
{
	std::cout << '\t' << "Test::Bus::TMsgInterface()" << '\n';
}

// Store

void
Test::Store::all()
{
	count_success_tests = this->TBasicFile()
						  + this->TProject()
						  + this->TSession();
}

unsigned int
Test::Store::TBasicFile()
{
	std::cout << '\t' << "Test::Store::TBasicFile()" << '\n';
	
	BasicFile basic_file("test.txt");
	std::string text("This is test file\n"), out_text;
	
	basic_file.save(text);
	out_text = basic_file.load();
	std::cout << out_text;// << '\n';
	
	basic_file.remove();
	
	basic_file.setName(std::string("/usr/bin/qtcreator.txt"));
	std::cout << basic_file.getFullName() << " | "
			  << basic_file.getPath() << " | "
			  << basic_file.getName() << '\n';
	
	basic_file.setName(std::string("qtcreator.txt"));
	std::cout << basic_file.getFullName() << " | "
			  << basic_file.getPath() << " | "
			  << basic_file.getName() << '\n';
	
	return 1;
}

unsigned int
Test::Store::TProject()
{
	std::cout << "Test::Store::TProject()" << '\n';
}

unsigned int
Test::Store::TSession()
{
	std::cout << "Test::Store::TSession()" << '\n';
}

// Others
void
Test::Others::all()
{
	this->count_success_tests = this->TList();
}

unsigned int
Test::Others::TList()
{
	List<int> list(4);
	
	return 1;
}
