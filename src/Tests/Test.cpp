#include "Test.h"

#include "../Actions/CommandLine.h"
#include "../Actions/CodeParcer.h"

#include "../Bus/MsgInterface.h"

#include "../Others/Array.h"
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
	std::cout << "Test::all()\n";
	
	actions.all();
	bus.all();
	store.all();
}

// Actions

void
Test::Actions::all()
{
	std::cout << "Test::Actions::all()\n";
	
	this->TCodeParcer();
	this->TCommandLine();	
}

void
Test::Actions::TCodeParcer()
{
	std::cout << '\t' << "Test::Actions::TCodeParcer()\n";
}

void
Test::Actions::TCommandLine()
{
	std::cout << '\t' << "Test::Actions::TCommandLine()\n";
	
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
	this->TMsgInterface();
}

void
Test::Bus::TMsgInterface()
{
	std::cout << '\t' << "Test::Bus::TMsgInterface()" << '\n';
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
	Array<unsigned long> array(1);
	
	std::cout << "Size: " << array.getLength() << '\n';
	
	for(unsigned int i = 0; i < array.getLength(); i++)
	{
		array[i] = i;
	}
	
	array.setLength(65536*32);
	
	std::cout << "Size: " << array.getLength() << '\n';
	
	for(unsigned long i = 0, size = array.getLength(); i < size; i++)
	{
		array[i] = i;
	}
	std::cout << '\n';
	
	array.setLength(8);
	
	std::cout << "Size: " << array.getLength() << '\n';
	for(unsigned int i = 0; i < array.getLength(); i++)
	{
		array[i] = i;
	}
	std::cout << '\n';
	
}

void
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
	
}

void
Test::Store::TProject()
{
	std::cout << '\t' << "Test::Store::TProject()" << '\n';
	
}

void
Test::Store::TSession()
{
	std::cout << '\t' << "Test::Store::TSession()" << '\n';
}
