#include "CommandLine.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <stdio.h>

using namespace flame_ide;

CommandLine::CommandLine()
{
	//ctor
}

CommandLine::~CommandLine()
{
	//dtor
}

//std::string
//CommandLine::getOutput(std::string& command)
//{
//	FILE* pipe = popen(command.c_str(), "r");
//
//	if (!pipe)
//		return "ERROR";
//
//	char buffer[32];
//	std::string result = "";
//
//    while(!feof(pipe))
//	{
//		if(fgets(buffer, 32, pipe) != NULL)
//			result += buffer;
//    }
//
//    pclose(pipe);
//
//    return result;
//}

std::string
CommandLine::getOutput(const std::string& command)
{
	#ifdef DEBUG
	std::cout << "CommandLine::getOutput(const std::string command)\n";
	#endif // DEBUG

	FILE* pipe = popen(command.c_str(), "r");

	if (!pipe)
		return "ERROR";

	char buffer[32];
	std::string result = "";

    while(!feof(pipe))
	{
		if(fgets(buffer, 32, pipe) != NULL)
			result += buffer;
    }

    pclose(pipe);

    return result;
}


std::string
CommandLine::getOutput(char* command)
{
	#ifdef DEBUG
	std::cout << "CommandLine::getOutput(char* command)\n";
	#endif // DEBUG

	FILE* pipe = popen(command, "r");

	if (!pipe)
		return "ERROR";

	char buffer[32];
	std::string result = "";

    while(!feof(pipe))
	{
		if(fgets(buffer, 32, pipe) != NULL)
			result += buffer;
    }

    pclose(pipe);

    return result;
}

std::string
CommandLine::getOutput(const char* command)
{
	#ifdef DEBUG
	std::cout << "CommandLine::getOutput(const char* command)\n";
	#endif // DEBUG

	FILE* pipe = popen(command, "r");

	if (!pipe)
		return "ERROR";

	char buffer[1024];
	std::string result = "";

    while(!feof(pipe))
	{
		if(fgets(buffer, 32, pipe) != NULL)
			result += buffer;
    }

    pclose(pipe);

    return result;
}
