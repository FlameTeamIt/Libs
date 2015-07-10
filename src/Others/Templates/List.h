#ifndef TEMPLATES_LIST
#define TEMPLATES_LIST

#include "List_Functions.h"

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
	List<T> *parent;
	
#ifdef FUTURE
	T** inc_arr_elements; // fast getting data
#endif
	
public:
	ListIterator();
	ListIterator(const ListIterator<T> &iterator);
	
	inline T& getData();
	
	bool inline toNext() const;
	bool inline toPrev() const;
	
	bool isReverse();
	
	const inline ListIterator<T>& operator=(const ListIterator<T> &iterator) const;
	
	bool inline operator==(const ListIterator<T> &iterator) const;
	bool inline operator!=(const ListIterator<T> &iterator) const;
	
	const inline ListIterator<T>& operator++() const;
	const inline ListIterator<T>& operator++(int) const;
	
	const inline ListIterator<T>& operator--() const;
	const inline ListIterator<T>& operator--(int) const;
	
	friend class List<T>;
};

template<typename T>
class List
{
public:
	typedef Container<T> container;
	typedef ListIterator<T> iterator;
	
private:
	bool is_opimize;
	
	mutable bool is_temporary;
	
	size_t size;
	
	container head;
	container tail;
	
	iterator begin_iterator;
	iterator end_iterator;
	
	iterator revers_begin_iterator;
	iterator revers_end_iterator;
	
	void updateIterators();
	
public:
	List();
	List(size_t new_size);
	List(const List &list);
	
	~List();
	
	void pushBack(const T &data); // вставка элемента в конец
	void pushFront(const T &data); // вставка элемента в начало

	void pushBack(size_t count, const T *array); // вставка массива в конец
	void pushFront(size_t count, const T *array); // вставка массива в начало
	
	void insert(const ListIterator<T> &pos, const T &elem); // вставка элементов после итератора
	void insert(const ListIterator<T> &pos, const size_t &count, const T *array); // вставка вектора после итератора
	
	void popBack(); // удаление элемента с конца
	void popFront(); // удаление элемента с начала
	
	void popBack(size_t count); // удаление опр. кол-ва элементов с конца
	void popFront(size_t count); // удаление опр. кол-ва элементов с начала
	
	void erase(const ListIterator<T> &pos); // удаление элемента, на который указывает итератор
	void erase(const ListIterator<T> &pos, const size_t &count); // удаление опр. количества элементов после итератора
	
	void clear(); // tested
	
	size_t getSize() const; // tested
	
	ListIterator<T> begin() const; // head.next
	ListIterator<T> end() const; // tail
	
	ListIterator<T> beginReverse() const; // tested
	ListIterator<T> endReverse() const; // tested
	
	ListIterator<T> first() const; // tested
	ListIterator<T> last() const; // tested
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;
	
	// дополнительные функции -- преобразование к динамическому массиву.
	// будут отдельно реализованы
	
	T& operator[] (size_t index) const;
	const List<T>& operator=(const List<T>& arg);
};

}}

using namespace	flame_ide::templates;

// ListIterator

template<typename T>
ListIterator<T>::ListIterator()
{
	
}
template<typename T>
ListIterator<T>::ListIterator(const ListIterator<T> &iterator)
{
	this->pointer = iterator.pointer;
	this->is_reverse = iterator.is_reverse;
	this->parent = iterator.parent;
}

template<typename T>
T&
ListIterator<T>::getData()
{
	return *(pointer->inc_data);
}

template<typename T>
bool
ListIterator<T>::toNext() const
{
	switch (this->is_reverse)
	{
	case true: // to first
		if(pointer->pos_type != FIRST)
		{
			pointer = pointer->prev;
			return true;
		}
		break;
		
	default: // to last
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
ListIterator<T>::toPrev() const
{
	switch (this->is_reverse)
	{
	case true: // to last
		if(pointer->pos_type != LAST)
		{
			pointer = pointer->next;
			return true;
		}
		break;
		
	default: // to first
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
{
	return this->is_reverse;
}

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator=(const ListIterator<T> &iterator) const
{
	this->pointer = iterator.pointer;
	this->is_reverse = iterator.is_reverse;
	this->parent = iterator.parent;
	
	return (*this);
}

template<typename T>
bool
ListIterator<T>::operator==(const ListIterator<T> &iterator) const
{
	return ((this->parent == iterator.parent)
			&& (this->pointer == iterator.pointer)
			&& (this->is_reverse == iterator.is_reverse)
			);
}
template<typename T>
bool
ListIterator<T>::operator!=(const ListIterator<T> &iterator) const
{
	return ((this->parent != iterator.parent)
			&& (this->pointer != iterator.pointer)
			&& (this->is_reverse != iterator.is_reverse)
			);
}

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator++() const
{
	this->toNext();
	return *this;
}

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator++(int) const
{
	this->toNext();
	return *this;
}

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator--() const
{
	this->toPrev();
	return *this;
}

template<typename T>
const ListIterator<T>&
ListIterator<T>::operator--(int) const
{
	this->toPrev();
	return *this;
}

// List

template<typename T>
List<T>::List()
	: head(&tail, nullptr, nullptr, FIRST),
	  tail(nullptr, &head, nullptr, LAST)
{
	size = 0;
	
	begin_iterator.is_reverse = false;
	end_iterator.is_reverse = false;
	
	begin_iterator.pointer = head.next;
	end_iterator.pointer = &tail;
	
	begin_iterator.parent = this;
	end_iterator.parent = this;
	
	revers_begin_iterator.is_reverse = true;
	revers_end_iterator.is_reverse = true;
	
	revers_begin_iterator.pointer = tail.prev;
	revers_end_iterator.pointer = &head;
	
	revers_begin_iterator.parent = this;
	revers_end_iterator.parent = this;
	
	is_temporary = false;
}
template<typename T>
List<T>::List(size_t new_size)
	: List()
{
	size = new_size;
	list_insert_default<T>(&head, size);
	
	updateIterators();
}
template<typename T>
List<T>::List(const List<T> &list)
	: List()
{
	list_copy<T>(&(list.head), &(list.tail), // откуда
				 &(this->head), &(this->tail)); // и куда
	
	this->size = list.size;
}

template<typename T>
List<T>::~List()
{
	if(!is_temporary)
	{
		list_erase_some_elements<T>(&head, &tail);
	}
	else
	{
		is_temporary = false;
	}
}

template<typename T>
void
List<T>::updateIterators()
{
	begin_iterator.pointer = head.next;
	revers_begin_iterator.pointer = tail.prev;
}

template<typename T>
void
List<T>::pushBack(const T &data)
{
	list_insert_elem_before<T>(&this->tail, data);
	this->size++;
	
	updateIterators();	
}

template<typename T>
void
List<T>::pushFront(const T &data)
{
	list_insert_elem_after<T>(&head, data);
	this->size++;
	
	updateIterators();
}

template<typename T>
void
List<T>::pushBack(size_t count, const T *array)
{
	list_insert_array_before<T>(&this->tail, count, array);
	this->size += count;
	
	updateIterators();
}

template<typename T>
void
List<T>::pushFront(size_t count, const T *array)
{
	list_insert_array_after<T>(&this->head, count, array);
	this->size += count;
	
	updateIterators();
}

template<typename T>
void
List<T>::insert(const iterator &pos, const T &elem)
{
	if((pos.pointer->pos_type == LAST) 
		&& (pos.parent != this))
	{
		return;
	}
	
	list_insert_elem_after<T>(pos.pointer, elem);	
	this->size++;
	
	updateIterators();
}
template<typename T>
void
List<T>::insert(const iterator &pos, const size_t &count, const T *array)
{
	if((pos.pointer->pos_type == LAST) 
		&& (pos.parent != this))
	{
		return;
	}
	
	list_insert_array_after<T>(pos.pointer, count, array);
	this->size += count;
	
	updateIterators();
}

template<typename T>
void
List<T>::popBack()
{
	if(!size) return;
	
	list_erase_elem<T>(tail.prev);
	size--;
	
	updateIterators();
}

template<typename T>
void
List<T>::popFront()
{
	if(!size) return;
	
	list_erase_elem<T>(head.next);
	size--;
	
	updateIterators();
}

template<typename T>
void
List<T>::popBack(size_t count)
{
	if(!this->size) return;
	
	if(this->size > count)
	{
		size -= list_erase_some_elements_end<T>(&tail, count);
		updateIterators();
	}
	else
	{
		clear();
	}
}

template<typename T>
void
List<T>::popFront(size_t count)
{
	if(!size) return;
	
	if(size > count)
	{
		size -= list_erase_some_elements<T>(&head, count);
		updateIterators();
	}
	else
	{
		clear();
	}
}

template<typename T>
void
List<T>::erase(const iterator &pos)
{
	if(!this->size) return;
	
	if(pos.pointer->pos_type == LAST) return;
	
	if(pos.pointer->next != nullptr
		|| pos.pointer->prev != nullptr)
	{
		list_erase_elem<T>(pos.pointer);
		size--;
		
		updateIterators();
	}
}
template<typename T>
void
List<T>::erase(const iterator &pos, const size_t &count)
{
	if(!this->size) return;
	if(pos.pointer->pos_type == LAST) return;
	
	(this->size > count)
			? this->size -= list_erase_some_elements<T>(pos.pointer, count)
			: this->size = 0;
	
	updateIterators();
}

template<typename T>
void
List<T>::clear()
{
	list_erase_some_elements<T>(&head, &tail);
	size = 0;
	
	updateIterators();
}

template<typename T>
size_t
List<T>::getSize() const
{
	return size;
}

template<typename T>
ListIterator<T>
List<T>::begin() const
{
	return begin_iterator;
}

template<typename T>
ListIterator<T>
List<T>::end() const
{
	return end_iterator;
}

template<typename T>
ListIterator<T>
List<T>::beginReverse() const
{
	return revers_begin_iterator;
}

template<typename T>
ListIterator<T>
List<T>::endReverse() const
{
	return revers_end_iterator;
}

template<typename T>
ListIterator<T>
List<T>::first() const
{
	return begin_iterator;
}

template<typename T>
ListIterator<T>
List<T>::last() const
{
	return (end()--);
}

template<typename T>
void
List<T>::setTemporary(bool is_temp) const
{
	this->is_temporary = is_temp;
}

template<typename T>
bool
List<T>::isTemporary() const
{
	return is_temporary;
}

template<typename T>
T& List<T>::operator [](size_t index) const
{
	container *run_pointer = head.next;
	index = index % size;
	
	for(size_t i = 0; i < index; i++)
	{ run_pointer = run_pointer->next; }
		
	return *(run_pointer->inc_data);
}

template<typename T>
const List<T>&
List<T>::operator =(const List<T> &arg)
{
	if(this->size) this->clear();
	
	if(arg.is_temporary)
	{
		this->head = arg.head;
		this->tail = arg.tail;
		
		if(this->is_temporary)
		{
			is_temporary = false;
		}
	}
	else
	{
		list_copy<T>(&(arg.head), &(arg.tail), // from
					 &(this->head), &(this->tail)); // to
	}
	updateIterators();
	
	this->size = arg.size;
	
	return *this;
}

#endif // TEMPLATES_LIST

