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

	virtual bool isKeyword(std::string&);
	virtual bool isKeyword(char*);

	virtual bool isEarlyType(std::string&);
	virtual bool isEarlyType(char*);

	virtual bool isPreprocessor(std::string&);
	virtual bool isPreprocessor(char*);

	virtual bool isOperator(std::string&);
	virtual bool isOperator(char*);

	virtual std::list< std::string > getSemanticList (std::string&);
	virtual std::list< std::string > getSemanticList (char*);
};

class CodeParcer_C : public BasicCodeParcer
{
	using BasicCodeParcer::loadFile;

	std::list< std::string > semantics;


public:

};

}

#endif // CODEPARCER_H
