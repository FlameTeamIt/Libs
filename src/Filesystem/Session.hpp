#ifndef SESSION_H
#define SESSION_H

#include <Filesystem/BasicFile.h>
#include <Filesystem/Project.h>

#include <vector>

namespace flame_ide
{

class Session
{
	std::vector <Project> projets;

public:
	Session();
	~Session();
	
	void
	createNew();
		
};

}

#endif // SESSION_H