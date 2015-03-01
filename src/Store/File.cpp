#include "File.h"

#include <fstream>

#ifdef DEBUG
#include <iostream>
#endif

using namespace flame_ide;

// constructors & destructor

File::File()
{
	#ifdef DEBUG  
	
	#endif // DEBUG
	
	// default values
	this->initialization();
}

File::File(std::string& filename, bool toLoad) : File()
{
	this->filename = filename;
	
	switch(toLoad)
	{
	case 0:
		// for save
		break;
		
	default:
		load();
		break;
	}
}


File::~File()
{}

// private methods

void File::initialization()
{
	this->eof = false;
	
	this->settings.loadAll = true;
	this->settings.loadWords = false;
	
	this->content_string = "";
}

void
File::load()
{
	unsigned short sets = 
		this->settings.loadAll*10
		+ this->settings.loadWords;
		
	switch(sets)
	{
		case 1:
		break;
		case 11:
		break;
		
		case 0:
		default: // 10
			this->loadAll();
		break;
	}
}

void
File::loadAll()
{
	std::ifstream file(this->filename.c_str());

	if(file.is_open())
	{
		char temp;
		while(!file.eof())
		{
			file.get(temp);
			this->content_string += temp;
		}
		
		this->eof = true;

		#ifdef DEBUG
		std::cout << content_string << '\n';
		#endif // DEBUG
	}
	#ifdef DEBUG
	else
	{
		std::cout << "Error to open file!\n";
	}
	#endif // DEBUG
}

// public methods

std::string
File::getLoaded()
{
	return this->content_string;
}