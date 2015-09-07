#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#define BUFFER_SIZE 1024

#include <string>

namespace flame_ide
{

class CommandLine
{
	static const unsigned long _BUFFER_SIZE = BUFFER_SIZE;
public:
	CommandLine();
	~CommandLine();

	static std::string getOutput(const std::string&);
	static std::string getOutput(const char*);
	static std::string getOutput(char*);
};

}

#undef BUFFER_SIZE

#endif // COMMANDLINE_H
