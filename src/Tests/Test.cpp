#include "Test.h"

#include <../Actions/CodeParcer.h>
#include <../Actions/CommandLine.h>

#include <../Bus/MsgInterface.h>

#include <../Store/File.h>
#include <../Store/Project.h>
#include <../Store/Session.h>

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
	
	std::cout << comands.getOutput("find ../src/ -type d") << "\n\n";
	std::cout << comands.getOutput(std::string("find ../src/ -type d")) << "\n";
	std::cout << comands.getOutput(command) << '\n';
	std::cout << comands.getOutput(c_command) << '\n';
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
