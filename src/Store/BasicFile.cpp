#include "BasicFile.h"

#include <fstream>

//#ifdef DEBUG
#include <iostream>
//#endif

struct Container
{
	char data;
	Container *next;
};

class MiniList
{
	unsigned int length;
	Container *head, *end;
	
public:
	MiniList();
	~MiniList();
	
	void push_back();
	void pop_front();
	
	char* toArray();
};

// =======================================================

using namespace flame_ide;

// constructors & destructor

BasicFile::BasicFile()
{
#ifdef DEBUG  

#endif // DEBUG
	
	// default values
	this->initialization();
}

BasicFile::BasicFile(std::string& filename)
	: BasicFile()
{
	this->filename = filename;
}


BasicFile::~BasicFile()
{}

// private methods

void
BasicFile::initialization()
{
}

// public methods

std::string
BasicFile::load()
{
	// по умолчанию, грузим все
	
	std::ifstream file(this->filename.c_str());
	std::string out("");
	
	if(file.is_open())
	{
		char temp_char;
		
		while(!file)
		{
			file.get(temp_char);
			
			out += temp_char;
		}
	}
	
	return out;
}

char*
BasicFile::load_c()
{
}

void
BasicFile::save(std::string &)
{
	
}

void
BasicFile::save_c(char *)
{
	
}

unsigned int
BasicFile::getSize(std::string &)
{
	return 0;
}

unsigned int
BasicFile::getSize(char *)
{
	return 0;
}
