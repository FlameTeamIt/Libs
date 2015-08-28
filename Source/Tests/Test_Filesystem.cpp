#include <iostream>
#include <Others/TextStyle.h>

// Store
#include <Filesystem/BasicFile.h>
#include <Filesystem/Project.h>
#include <Filesystem/Session.h>

#include "Test.h"

using namespace flame_ide;

void
Test::Filesystem::all()
{
	std::cout << "Test::Filesystem::all()" << '\n';
	count_success_tests = this->TBasicFile()
						  + this->TProject()
						  + this->TSession();
	std::cout << '\n';
}

unsigned int
Test::Filesystem::TBasicFile()
{
	std::cout << "Test::Filesystem::TBasicFile()" << '\n';
	
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
Test::Filesystem::TProject()
{
	std::cout << "Test::Filesystem::TProject()" << '\n';
	return 1;
}

unsigned int
Test::Filesystem::TSession()
{
	std::cout << "Test::Filesystem::TSession()" << '\n';
	return 1;
}
