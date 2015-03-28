#include "BasicFile.h"

#include <fstream>

//#ifdef DEBUG
#include <iostream>
//#endif

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

// static

std::string
BasicFile::getPath(std::string &filename)
{
	// разделяем на куски путь + имя файла
}

// virtual

void
BasicFile::initialization()
{
	eof = false;
	error = 0;
}

// public methods

// virtual

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

void
BasicFile::save(const std::string &text)
{
	std::ofstream file(filename.c_str());
	
	if(file.is_open())
	{
		file << text;
	}
	
	file.close();
	
}

// static

unsigned int
BasicFile::getSize(const std::string &)
{
	// нужно погуглить
	return 0;
}

unsigned int
BasicFile::getSize(const char *)
{
	// нужно погуглить
	return 0;
}

// normal

void
BasicFile::setName(std::string &filename)
{
	this->filename = filename;
	
}

void
BasicFile::setName(std::string &path, std::string &filename)
{
	
}

void
BasicFile::setName(const char *&filename)
{
	
}

void
BasicFile::setName(const char *&path, const char *&filename)
{
	
}
