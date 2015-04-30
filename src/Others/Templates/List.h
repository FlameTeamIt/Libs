#ifndef LIST
#define LIST

#include "Functions.h"

namespace flame_ide
{ namespace templates
{

class MainIterator;
class ListIterator;

class MainIterator
{
	MainIterator *next, *prev;
	bool is_main;
	
public:
	MainIterator() {}
	~MainIterator() {}
	
	virtual bool isContainer();
};

template<typename T>
class ListIterator : MainIterator
{
	T *inc_data;
public:
	ListIterator();
	ListIterator(const ListIterator &iterator);
	ListIterator(const ListIterator *init_next, const ListIterator *init_prev,
				 const T *init_data);
	
	bool isContainer();
	
	T* data();
	
	ListIterator & operator =(const ListIterator &iterator);
};

template<typename T>
class List
{
	typedef MainIterator main_iterator;
public:
	typedef ListIterator<T> iterator;
	
private:
	size_t size;
	
	main_iterator head;
	main_iterator tail;
	
public:
	
	List();
	List(const size_t &new_size);
	List(const List &list);
	
	void pushBack(const T &data);
	void pushFront(const T &data);
	
	void erase(const iterator &pos);
	void erase(const iterator &pos, const size_t &count);
	
	void insert(const iterator &pos, const T &elem);
	void insert(const iterator &pos, const size_t &count, const T *array);
	
	void popBack();
	void popFront();
	
	T* operator[] (const size_t &index);
};

}}

using namespace	flame_ide::templates;

#endif // LIST

