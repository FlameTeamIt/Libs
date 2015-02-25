#include "Actions/CodeParcer.h"
<<<<<<< HEAD
#include "Actions/CommandLine.h"

#include <iostream>
=======

#include <stdlib.h>
>>>>>>> 7c7dcb0a4ca6a2e74276280e0cd445b467bccefb

using namespace flame_ide;

int main()
{
<<<<<<< HEAD
	std::string file("src/main.cpp"), command("sleep 10");
//    BasicCodeParcer::loadFile(file);
	char c_command[] = "find src/ -type d";

	CommandLine comands;

	std::cout << comands.getOutput("find src/ -type d") << "\n\n";
	std::cout << comands.getOutput(std::string("find src/ -type d")) << "\n";
	std::cout << comands.getOutput(command) << '\n';
	std::cout << comands.getOutput(c_command) << '\n';

=======
	std::string file("src/main.cpp");
//    BasicCodeParcer::loadFile(file);

>>>>>>> 7c7dcb0a4ca6a2e74276280e0cd445b467bccefb
    return 0;
}
