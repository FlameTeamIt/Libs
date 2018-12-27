#ifndef SESSION_H
#define SESSION_H

#include <FlameIDE/Filesystem/BasicFile.hpp>
#include <FlameIDE/Filesystem/Project.hpp>

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
