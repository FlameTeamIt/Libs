#include "BasicFile.h"

#include <fstream>
#include <list>

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
	: BasicFile()
{
	this->filename = filename;
}

BasicFile::~BasicFile()
{}

// protected methods

// static

bool
BasicFile::parceFullFilename(const std::string &fullfilename,
							 std::string &path,
							 std::string &filename)
{
	// разделяем на куски путь + имя файла
	std::string::const_iterator it_end_path;
	bool is_find = false;
	
	for(std::string::const_iterator
			it = fullfilename.begin(),
			it_end = fullfilename.end();
		it != it_end; ++it)
	{
		if(*it == '/')
		{
			it_end_path = it;
			is_find = true;
		}
	}
	it_end_path++;
	
	if(path.length())
		path.clear();
	
	if(filename.length())
		filename.clear();
	
	if(is_find)
	{
		// использовать лябды и std::bind
		for(std::string::const_iterator
				it = it_end_path,
				it_end = fullfilename.end();
			it != it_end; ++it)
		{
			filename += *it;
		}
		
		for(std::string::const_iterator
				it = fullfilename.begin(),
				it_end = it_end_path;
			it != it_end; ++it)
		{
			path += *it;
		}
		
		return true;
	}
	
	filename = fullfilename;
	
	return false;
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
	// по умолчанию, грузим все посимвольно
	
	std::ifstream file(this->filename.c_str());
	std::string out("");
	
	if(file.is_open())
	{
		char temp_char;
		
		while(!file.eof())
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

unsigned long // std::ios::pos_type
BasicFile::getSize(const std::string &filename)
{
	std::ifstream in(filename.c_str(), std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

unsigned long // std::ios::pos_type
BasicFile::getSize(const char *filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

// normal

void
BasicFile::setName(const std::string &filename)
{
	parceFullFilename(filename, this->path, this->filename);
}

void
BasicFile::setName(const std::string &path, const std::string &filename)
{
	this->path = path;
	this->filename = filename;
}

void
BasicFile::setName(const char *filename)
{
	std::string fullfilename(filename);
	parceFullFilename(fullfilename, this->path, this->filename);
}

void
BasicFile::setName(const char *path, const char *filename)
{
	this->path = path;
	this->filename = filename;
}

std::string
BasicFile::getName()
{
	return this->filename;
}

std::string
BasicFile::getPath()
{
	return this->path;
}

std::string
BasicFile::getFullName()
{
	return (this->path + this->filename);
}

int
BasicFile::getError()
{
	return error;
}
