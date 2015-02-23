#include "CodeParcer.h"

#include <fstream>
#include <iostream>

using namespace flame_ide;

std::string
BasicCodeParcer::loadFile(std::string& code)
{
	std::string buffer(""), temp;
	std::ifstream file(code.c_str());

	if(file.is_open())
	{
		while(!file.eof())
		{
			file >> temp;
			buffer += " ";
			buffer += temp;
		}

		#ifdef DEBUG
		std::cout << buffer << '\n';
		#endif // DEBUG
	}
	else
	{
		std::cout << "Error to open file!\n";
	}

	return buffer;
}

std::list< std::string >
BasicCodeParcer::getSemanticList(std::string& buffer)
{
	std::list< std::string > semantics(0);

	return semantics;
}
