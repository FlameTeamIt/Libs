#include <FlameIDE/Process/CommandLine.hpp>

#include <cstdio>

using namespace flame_ide;

CommandLine::CommandLine()
{
}

CommandLine::~CommandLine()
{
}

std::string
CommandLine::getOutput(const std::string& command)
{
	FILE* pipe = popen(command.c_str(), "r");

	if (!pipe)
		return "ERROR";

	char buffer[_BUFFER_SIZE];
	std::string result = "";

	while(!feof(pipe))
	{
		if(fgets(buffer, _BUFFER_SIZE, pipe) != NULL)
			result += buffer;
	}

	pclose(pipe);

	return result;
}


std::string
CommandLine::getOutput(char* command)
{
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
