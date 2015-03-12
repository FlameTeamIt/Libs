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
	// default values
	this->initialization();
}

BasicFile::BasicFile(std::string& filename)
	: BasicFile()
{
	this->filename = filename;
}

BasicFile::BasicFile(const char *filename)
{
	this->filename = filename;
}


BasicFile::~BasicFile()
{}

// private methods

void
BasicFile::initialization()
{
	eof = false;
	error = 0;
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
	
	file.close();
	
	return out;
}

char*
BasicFile::load_c()
{
	// пока алгоритм такой
	// узнаем размер файла
	// выделяем память на массив соотвествующего размера
	// грузим, используя get_line()
}

void
BasicFile::save(std::string &text)
{
	std::ofstream file(filename.c_str());
	
	if(file.is_open())
	{
		file << text;
	}
	
	file.close();
	
}

void
BasicFile::save_c(char *text)
{
	std::ofstream file(filename.c_str());
	
	if(file.is_open())
	{
		file << text;
	}
	
	file.close();
	
}

unsigned int
BasicFile::getSize(std::string &)
{
	// нужно погуглить
	return 0;
}

unsigned int
BasicFile::getSize(char *)
{
	// нужно погуглить
	return 0;
}
