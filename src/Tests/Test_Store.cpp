#include <iostream>
#include "Test.h"
#include "../Others/TextStyle.h"

// Store
#include "../Store/BasicFile.h"
#include "../Store/Project.h"
#include "../Store/Session.h"

using namespace flame_ide;

void
Test::Store::all()
{
	std::cout << "Test::Store::all()" << '\n';
	count_success_tests = this->TBasicFile()
						  + this->TProject()
						  + this->TSession();
	std::cout << '\n';
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
	return 1;
}

unsigned int
Test::Store::TSession()
{
	std::cout << '\t' << "Test::Store::TSession()" << '\n';
	return 1;
}
