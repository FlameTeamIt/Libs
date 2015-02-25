#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <string>

namespace flame_ide
{

class CommandLine
{

public:
	CommandLine();
	~CommandLine();

//	std::string getOutput(std::string&);
	static std::string getOutput(const std::string);

	static std::string getOutput(char*);
	static std::string getOutput(const char*);

};

}

#endif // COMMANDLINE_H
