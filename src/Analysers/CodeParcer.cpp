#include <Filesystem/BasicFile.hpp>
#include <Analysers/CodeParcer.hpp>

#include <iostream>

using namespace flame_ide;

std::string
BasicCodeParcer::loadFile(std::string&)
{
	std::string buffer;
	return buffer;
}

std::list<std::string>
BasicCodeParcer::getSemanticList(std::string&)
{
	std::list< std::string > semantics(0);

	return semantics;
}
