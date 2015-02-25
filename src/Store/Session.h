#ifndef SESSION_H
#define SESSION_H

#include "File.h"
#include "Project.h"

#include <vector>

namespace flame_ide
{

class Session
{
	std::vector <Project> projets;

	protected:
	public:
		Session();
		~Session();
};

}

#endif // SESSION_H
