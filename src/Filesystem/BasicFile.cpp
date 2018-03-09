#include <Filesystem/BasicFile.hpp>

#include <fstream>
#include <list>

//#ifdef DEBUG
#include <iostream>
//#endif

// =======================================================

using namespace flame_ide;

// constructors & destructor

BasicFile::BasicFile() : filename(""), path("")
{
	// default values
	this->initialization();
}

BasicFile::BasicFile(std::string& str_filename)
	: BasicFile()
{
	parceFullFilename(str_filename, this->path, this->filename);
}

BasicFile::BasicFile(const char *str_filename)
	: BasicFile()
{
	parceFullFilename(std::string(str_filename), this->path, this->filename);
}

BasicFile::~BasicFile()
{}

// protected methods

// static

bool
BasicFile::parceFullFilename(const std::string &fullfilename,
							 std::string &str_path,
							 std::string &str_filename)
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

	if(str_path.length())
		str_path.clear();

	if(str_filename.length())
		str_filename.clear();

	if(is_find)
	{
		// использовать лябды и std::bind
		for(std::string::const_iterator
				it = it_end_path,
				it_end = fullfilename.end();
			it != it_end; ++it)
		{
			str_filename += *it;
		}

		for(std::string::const_iterator
				it = fullfilename.begin(),
				it_end = it_end_path;
			it != it_end; ++it)
		{
			str_path += *it;
		}

		return true;
	}

	str_filename = fullfilename;

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

		file.get(temp_char);

		while(!file.eof())
		{
			out += temp_char;
			file.get(temp_char);
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
	{	file << text;}

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
BasicFile::remove()
{
	std::string fullfilename = filename + path;
	std::ifstream file(fullfilename.c_str());

	if(file.is_open())
	{
		file.close();

		std::remove(fullfilename.c_str());
	}

	file.close();

}

void
BasicFile::setName(const std::string &str_filename)
{
	parceFullFilename(str_filename, this->path, this->filename);
}

void
BasicFile::setName(const std::string &str_path, const std::string &str_filename)
{
	this->path = str_path;
	this->filename = str_filename;
}

void
BasicFile::setName(const char *str_filename)
{
	std::string fullfilename(str_filename);
	parceFullFilename(fullfilename, this->path, this->filename);
}

void
BasicFile::setName(const char *str_path, const char *str_filename)
{
	this->path = str_path;
	this->filename = str_filename;
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
