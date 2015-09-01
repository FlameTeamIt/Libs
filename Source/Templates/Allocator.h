#ifndef ALLOCATOR
#define ALLOCATOR

// 16K
#include <Templates/For_All.h>

namespace flame_ide
{namespace templates
{

struct Node
{
	const unsigned long size = 1024*16 - (2*sizeof(void*) + sizeof(unsigned long));
	char data[size];
	
	Node *next;
	Node *prev;
};

class Allocator
{
	Node *head;
//	Node *tail;
	
public:
	Allocator();
	
	void* newPointer(unsigned long size);
	void  deletePointer(void* pointer, unsigned long size);
	
	~Allocator();
};

}}

using namespace flame_ide::templates;

Allocator::Allocator()
{
	head = new Node;
	head->next = nullptr;
}

Allocator::~Allocator()
{
	while(head != nullptr)
	{
		auto tmp_head = head->next;
		delete head;
		
		head = tmp_head;
	}
}

void*
Allocator::newPointer(unsigned long size)
{
	
}

void
Allocator::deletePointer(void *pointer, unsigned long size)
{
	
}

/*

Есть несколько вещей, с которыми хотел бы разобраться:

1. Сдвиг указателя -- как нужно хранить информацию о том, где расположено начало объекта?
2. Стоит ли для всех типов делать один общий аллокатор?
3. Выделили, а нужно еще очистить. Как? + еще и сдвиги нужно делать.

Пиздец это, в общем.

*/
#endif // ALLOCATOR

