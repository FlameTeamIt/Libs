#include "Actions/CommandLine.h"
#include "Store/File.h"

#include <iostream>
using namespace flame_ide;

int main()
{
	std::string str_file("../src/main.cpp"), command("find ../src/ -type d");
	char c_command[] = "find ../src/ -type d";
	File file(str_file, true);
	
	CommandLine comands;

	std::cout << comands.getOutput("find ../src/ -type d") << "\n\n";
	std::cout << comands.getOutput(std::string("find ../src/ -type d")) << "\n";
	std::cout << comands.getOutput(command) << '\n';
	std::cout << comands.getOutput(c_command) << '\n';
	
	std::cout << '\n' << file.getLoaded() << '\n';
	
    return 0;
}
