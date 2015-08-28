#ifndef PROJECT_H
#define PROJECT_H

#include "../Store/BasicFile.h"

namespace flame_ide
{

class Project
{
public:
	Project();
	~Project();
	
	void
	createNew();
	
	void
	addFiles();
	
	void
	getFiles();
	
};

}


#endif // PROJECT_H
