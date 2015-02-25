#include "Actions/CodeParcer.h"
#include "Actions/CommandLine.h"

#include <iostream>

using namespace flame_ide;

int main()
{
	std::string file("src/main.cpp"), command("sleep 10");
//    BasicCodeParcer::loadFile(file);
	char c_command[] = "find src/ -type d";

	CommandLine comands;

	std::cout << comands.getOutput("find src/ -type d") << "\n\n";
	std::cout << comands.getOutput(std::string("find src/ -type d")) << "\n";
	std::cout << comands.getOutput(command) << '\n';
	std::cout << comands.getOutput(c_command) << '\n';

    return 0;
}
