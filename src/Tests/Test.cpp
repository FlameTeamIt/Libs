#include "Test.h"

#include "../Actions/CommandLine.h"
#include "../Actions/CodeParcer.h"

#include "../Bus/MsgInterface.h"


#include "../Store/Array.h"
#include "../Store/BasicFile.h"
#include "../Store/Project.h"
#include "../Store/Session.h"

#include <iostream>


using namespace flame_ide;

Test::Test()
{
}

Test::~Test()
{
}

void
Test::all()
{
#ifdef DEBUG
	std::cout << "Test::all()\n";
#endif
	actions.all();
	bus.all();
	store.all();
}

// Actions

void
Test::Actions::all()
{
#ifdef DEBUG
	std::cout << "Test::Actions::all()\n";
#endif
	
	this->TCodeParcer();
	this->TCommandLine();	
}

void
Test::Actions::TCodeParcer()
{
#ifdef DEBUG
	std::cout << "Test::Actions::TCodeParcer()\n";
#endif
	
}

void
Test::Actions::TCommandLine()
{
#ifdef DEBUG
	std::cout << "Test::Actions::TCommandLine()\n";
#endif
	
	
//	std::string str_file("../src/main.cpp"), command("find ../src/ -type d");
//	char c_command[] = "find ../src/ -type d";
	CommandLine commands;
	
//	std::cout << commands.getOutput("find ../src/ -type d") << "\n\n";
//	std::cout << commands.getOutput(std::string("find ../src/ -type d")) << "\n";
//	std::cout << commands.getOutput(command) << '\n';
//	std::cout << commands.getOutput(c_command) << '\n';
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
	this->TMsgInterface();
}

void
Test::Bus::TMsgInterface()
{
	
}

// Store

void
Test::Store::all()
{
	this->TArray();
	
	this->TBasicFile();
	this->TProject();
	this->TSession();
}

void
Test::Store::TArray()
{
	Array<int> array(32);
	
	for(unsigned int i = 0; i < array.getLength(); i++)
	{
		array[i] = (int)i;
		
		std::cout << array[i] << ' ' << i << '\n';
	}
}

void
Test::Store::TBasicFile()
{
	BasicFile basic_file("test.txt");
	std::string text("This is test file\n");
	
	basic_file.save(text);
}

void
Test::Store::TProject()
{
	
}

void
Test::Store::TSession()
{
	
}
