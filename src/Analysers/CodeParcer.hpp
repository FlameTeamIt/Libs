#ifndef CODEPARCER_H
#define CODEPARCER_H

#include <list>
#include <string>

namespace flame_ide
{

class BasicCodeParcer
{
protected:
	std::string loadFile(std::string& file);
	std::string loadFile(char* file);

public:

	virtual std::list< std::string > parceSemantics(std::string&);
	virtual std::list< std::string > parceSemantics(char*);

	virtual bool isKeyword(std::string&) = 0;
	virtual bool isKeyword(char*) = 0;

	virtual bool isEarlyType(std::string&) = 0;
	virtual bool isEarlyType(char*) = 0;

	virtual bool isPreprocessor(std::string&) = 0;
	virtual bool isPreprocessor(char*) = 0;

	virtual bool isOperator(std::string&) = 0;
	virtual bool isOperator(char*) = 0;

	virtual std::list< std::string > getSemanticList (std::string&) = 0;
	virtual std::list< std::string > getSemanticList (char*) = 0;
};

class CodeParcer_C : public BasicCodeParcer
{
	using BasicCodeParcer::loadFile;

	std::list< std::string > semantics;


public:

};



class CodeParcer_CPP : public BasicCodeParcer
{
};

}
#endif // CODEPARCER_H
