#include "Test.h"

#include "../Actions/CommandLine.h"
#include "../Actions/CodeParcer.h"

#include "../Bus/MsgInterface.h"

#include "../Store/File.h"
#include "../Store/Project.h"
#include "../Store/Session.h"

#include <iostream>


using namespace flame_ide;

Test::Test()
{
	//ctor
}

Test::~Test()
{
	//dtor
}

// Actions

void
Test::Actions::all()
{
	
}

void
Test::Actions::TCodeParcer()
{
	
}

void
Test::Actions::TCommandLine()
{
	std::string str_file("../src/main.cpp"), command("find ../src/ -type d");
	char c_command[] = "find ../src/ -type d";
	CommandLine commands;
	
	std::cout << commands.getOutput("find ../src/ -type d") << "\n\n";
	std::cout << commands.getOutput(std::string("find ../src/ -type d")) << "\n";
	std::cout << commands.getOutput(command) << '\n';
	std::cout << commands.getOutput(c_command) << '\n';
}

// Bus

void
Test::Bus::all()
{
	
}

void
Test::Bus::TMsgInterface()
{
	
}

// Store

void
Test::Store::all()
{
	
}

void
Test::Store::TFile()
{
	
}

void
Test::Store::TProject()
{
	
}

void
Test::Store::TSession()
{
	
}
