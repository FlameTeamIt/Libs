#include "File.h"

#include <fstream>

using namespace flame_ide;

// constructor & destructor

File::File()
{
	#ifdef DEBUG  
	
	#endif // DEBUG
	
	// default values
	this->eof = false;
	
	this->settings.loadAll = true;
	this->settings.loadWords = false;
	
	this->content_string = "";
}

File::File(std::string& filename) : File()
{
	this->filename = filename;
	this->load();
}

File::~File()
{}

// private methods
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
		std::cout << buffer << '\n';
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
