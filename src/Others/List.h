#ifndef LIST
#define LIST

#include <cstdlib>
namespace flame_ide
{ namespace templates
{

template<typename T>
class BasicListIterator
{
	bool is_basic;
protected:
	BasicListIterator* next_elem;
	BasicListIterator* prev_elem;
	
public:
	BasicListIterator();
	BasicListIterator(const bool& is_basic_list_iterator);
	BasicListIterator(const BasicListIterator& basic_list_iterator);
	
	virtual bool isBasicIterator() = 0;
	
	bool toNext();
	bool toPrev();
	
	BasicListIterator* getNext();
	BasicListIterator* getPrev();
};

template<typename T>
class ListIterator : public BasicListIterator
{
	T* data;
	size_t number;
	
public:
	
	bool isBasicIterator();
	
	T* getData();
	T* getCopiedData();
};

template<typename T>
class List
{
	BasicListIterator head;
	BasicListIterator tail;
	BasicListIterator* run_pointer;
	
public:
	
	T& at(const size_t& index);
	T* operator[](const size_t& index);
};

}}

using namespace	flame_ide::templates;

template<typename T>
BasicListIterator<T>::BasicListIterator()
{
	this->is_basic = true;
	next_elem = nullptr;
	prev_elem = nullptr;
}

template<typename T>
BasicListIterator<T>::BasicListIterator(const bool& is_basic_list_iterator)
{this->is_basic = is_basic_list_iterator;}

template<typename T> bool
BasicListIterator<T>::isBasicIterator()
{return is_basic;}

template<typename T> bool
BasicListIterator<T>::toNext()
{
	if(next_elem != nullptr)
	{
		this = this->next_elem;
		return true;
	}
	
	return false;
}

template<typename T> bool
BasicListIterator<T>::toPrev()
{
	if(prev_elem != nullptr)
	{
		this = this->prev_elem;
		return true;
	}
	
	return false;
}

template<typename T> BasicListIterator*
BasicListIterator::getNext()
{return this->next_elem;}

template<typename T> BasicListIterator*
BasicListIterator::getPrev()
{return this->prev_elem;}

#endif // LIST

