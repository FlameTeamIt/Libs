#ifndef MSGINTERFACE_H
#define MSGINTERFACE_H

// класс для работы с библиотекой

#include <list>

namespace flame_ide
{

class MsgInterface
{
protected:
public:
	MsgInterface();
	~MsgInterface();
	
	static
	bool
	isFurst();
	
	static
	std::list<int>
	getSessionList();
};

}


#endif // MSGINTERFACE_H
