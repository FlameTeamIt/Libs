#ifndef ARRAY_H
#define ARRAY_H

// Пока не уверен, что нужно, но пусть пока будет
#include "Functions.h"

namespace flame_ide
{ namespace templates
{

template<typename T>
class Array
{
	mutable T **inc_arr;
	
	size_t length;
	mutable bool initialised;
	
protected:
	// static
	
public:
	Array();
	Array(const Array<T> &array);
	Array(const size_t &length);
	
	// future
	// пока не знаю, как работать с функциями с произвольным количеством аргументов	
//	template<typename ... cunstructor_args>
//	Array(const size_t& length, ...);
	
	~Array();
	
	bool isInitialised() const;
	void clear();
	
	void   setLength(const size_t &new_length);
	void   setCopy(const Array<T> &copying_array);
	void   setPCopy(const size_t &array_length, const T **copying_array);
	size_t getLength() const;
	
	T** getPCopy() const;
	T*  getPointer(const size_t &index) const;
	
	T& at(const size_t &index) const;
	T& operator[](const size_t &ndex) const;
	
	Array<T> &operator=(const Array<T>&);
};

}}


using namespace flame_ide::templates;

// constructors & distructor

template<typename T>
Array<T>::Array()
{
	inc_arr = nullptr;
	length = 0;
	initialised = false;
}
template<typename T>
Array<T>::Array(const Array<T> &array)
{
	this->length = array.length;
	this->initialised = true;
	this->inc_arr = get_copy_array<T>(array.length, array.inc_arr);
}
template<typename T>
Array<T>::Array(const size_t& array_length)
{
	this->length = array_length;
	this->initialised = true;
	
	inc_arr = get_new_array<T>(this->length);
}

template<typename T>
Array<T>::~Array()
{
	if(initialised)
	{	delete_array<T>(this->length, this->inc_arr);}
}

// public

template<typename T>
bool
Array<T>::isInitialised() const
{	return initialised;}

template<typename T>
void
Array<T>::clear()
{
	if(initialised)
	{
		delete_array<T>(this->length, this->inc_arr);
		this->initialised = false;
	}
}

template<typename T>
void
Array<T>::setLength(const size_t &new_length)
{
	if(!initialised)
	{	inc_arr = get_new_array<T>(new_length);}
	else
	{	inc_arr = resize_array<T>(this->length, new_length, this->inc_arr);}
	
	this->length = new_length;
}

template<typename T>
void
Array<T>::setCopy(const Array<T> &copying_array)
{
	delete_array<T>(this->length, this->inc_arr);
	
	this->length = copying_array.getLength();
	this->inc_arr = copying_array.getPCopy();
}

template<typename T>
void
Array<T>::setPCopy(const size_t& array_length, const T **copying_array)
{
	this->length = array_length;
	this->inc_arr = copying_array; // или брать от него копию?
}

template<typename T>
size_t
Array<T>::getLength() const
{	return this->length;}

template<typename T>
T**
Array<T>::getPCopy() const
{
	return
		(initialised) 
		?	get_copy_array<T>(this->length, this->inc_arr)
		:	nullptr;
}

template<typename T>
T*
Array<T>::getPointer(const size_t &index) const
{	return inc_arr[index];}

// сделал "защиту от дурака", чтобы народ не выходил за границы массива
// идиотская идея, т.к. доп действие. Зато типа защищено
template<typename T>
T&
Array<T>::at(const size_t& index) const
{	return inc_arr[index % this->length][0];}

// "защита от дурака" х2
template<typename T>
T&
Array<T>::operator [](const size_t& index) const
{	return inc_arr[index % this->length][0];}

template<typename T>
Array<T>&
Array<T>::operator =(const Array<T> &arg)
{
	if(arg.initialised)
	{
		delete_array<T>(this->length, this->inc_arr);
		this->length = arg.length;
		this->inc_arr = arg.getPCopy();
	}
}

#endif // ARRAY_H
