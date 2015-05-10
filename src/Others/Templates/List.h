#ifndef LIST
#define LIST

#include "Functions.h"

namespace flame_ide
{ namespace templates
{

template<typename T>
class List;

template<typename T>
class ListIterator
{
	mutable Container<T> *pointer;
	bool is_reverse;
public:
	ListIterator();
	ListIterator(Container<T> *container);
	
	T&   get();
	
	bool toNext();
	bool toPrev();
	
	bool isReverse();
	
	ListIterator<T>& operator=(const ListIterator<T> &iterator) const;
	
	const ListIterator<T>& operator++();
	const ListIterator<T>& operator++(int);
	
	const ListIterator<T>& operator--();
	const ListIterator<T>& operator--(int);
	
	friend class List<T>;
};

template<typename T>
class List
{
	typedef Container<T> container;
public:
	typedef ListIterator<T> iterator;
	
private:
	size_t size;
	
	container head;
	container tail;
	
public:
	
	List();
	List(size_t new_size);
	List(const List &list);
	
	~List();
	
	void pushBack(const T &data);
	void pushFront(const T &data);
	
	void popBack();
	void popFront();
	
	void insert(const iterator &pos, const T &elem);
	void insert(const iterator &pos, const size_t &count, T *array);
	
	void erase(const iterator &pos);
	void erase(const iterator &pos, const size_t &count);
	
	void clear();
	
	size_t getSize();
	
	iterator begin() const; // head.next
	iterator end() const; // tail
	
	// итератор дб реверсным
	iterator beginReverse() const; // tail.prev
	iterator endReverse() const; // head
	
	iterator first() const; // head.next
	iterator last() const; // tail.prev
	
	// дополнительные функции -- преобразование к динамическому массиву.
	
	// и что на счет константности?
	
	T* operator[] (const size_t &index);
	
	// нужны дополнительные операторы -- присваивание, сравнение (?)
};

}}

using namespace	flame_ide::templates;

// ListIterator

template<typename T>
T&
ListIterator<T>::get()
{
	return *(pointer->inc_data);
}

template<typename T>
bool
ListIterator<T>::toNext()
{
	switch (this->is_reverse)
	{
	case true: // идем назад
		if(pointer->pos_type != FIRST)
		{
			pointer = pointer->prev;
			return true;
		}
		break;
		
	default:
		if(pointer->pos_type != LAST)
		{
			pointer = pointer->next;
			return true;
		}
		break;
	}
	
	return false;
}

template<typename T>
bool
ListIterator<T>::toPrev()
{
	switch (this->is_reverse)
	{
	case true: // идем вперед
		if(pointer->pos_type != LAST)
		{
			pointer = pointer->next;
			return true;
		}
		break;
		
	default:
		if(pointer->pos_type != FIRST)
		{
			pointer = pointer->prev;
			return true;
		}
		break;
	}
	
	return false;
}

template<typename T>
bool
ListIterator<T>::isReverse()
{ return this->is_reverse; }

template<typename T>
ListIterator<T>&
ListIterator<T>::operator=(const ListIterator<T> &iterator) const
{
	this->pointer = iterator.pointer;
}

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator++()
{ this->toNext(); return *this; }

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator++(int)
{ this->toNext(); return *this; }

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator--()
{ this->toPrev(); return *this; }

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator--(int)
{ this->toPrev(); return *this; }

// List

template<typename T>
List<T>::List()
	: head(&tail, nullptr, nullptr, FIRST),
	  tail(nullptr, &head, nullptr, LAST)
{ size = 0; }
template<typename T>
List<T>::List(size_t new_size)
	: List()
{
	size = new_size;
	list_insert_default<T>(&head, size);
}

template<typename T>
void
List<T>::pushBack(const T &data)
{
	list_insert_elem_before<T>(&tail, data);
}

template<typename T>
void
List<T>::pushFront(const T &data)
{
	
}

template<typename T>
void
List<T>::insert(const iterator &pos, const T &elem)
{
	
}
template<typename T>
void
List<T>::insert(const iterator &pos, const size_t &count, T *array)
{
	
}

template<typename T>
void
List<T>::popBack()
{
	
}

template<typename T>
void
List<T>::popFront()
{
	
}

template<typename T>
void
List<T>::erase(const iterator &pos)
{
	
}
template<typename T>
void
List<T>::erase(const iterator &pos, const size_t &count)
{
	
}

template<typename T>
void
List<T>::clear()
{
	list_erase_some_elements<T>(&head, &tail);
}

template<typename T>
List<T>::~List()
{
	clear();
}

#endif // LIST

