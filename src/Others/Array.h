#ifndef ARRAY_H
#define ARRAY_H

// Пока не уверен, что нужно, но пусть пока будет

#include <cstdlib>

namespace flame_ide
{

template<typename T>
class Array
{
	T** inc_arr;
	
	size_t length;
	bool initialised;
	
	// operators
	
	Array<T>& operator=(const Array<T>&); // не нужно присваивание
	
	// static
	
	template<typename Tt> static inline
	Tt**
	get_new_array(const size_t& length);
	
	template<typename Tt> static inline
	Tt**
	get_copy_array(const size_t& length, Tt** array);
	
	template<typename Tt> static inline
	void
	copy_array(const size_t& length, Tt** old_array, Tt** new_array);
	
	template<typename Tt> static inline
	void
	delete_array(const size_t& length, Tt** array);
	
	template<typename Tt> static inline
	Tt**
	resize_array(const size_t& old_size, const size_t& new_size, Tt** array);
	
	// normal
	
	// избавился от функции измнения массива
	
public:
	Array();
	Array(Array<T>& array);
	Array(const size_t& length);
	
	// future
	// пока не знаю, как работать с функциями с произвольным количеством аргументов	
//	template<typename ... cunstructor_args>
//	Array(const size_t& length, ...);
	
	~Array();
	
	// virtual
	
	// normal
	
	void
	setLength(const size_t& new_length);
	
	size_t
	getLength();
	
	T**
	getArray_c();
	
	T**
	getCopyArray_c();
	
	T&
	at(const size_t& index);
	
	// operators
	
	T&
	operator[](const size_t& index);
};

}

using namespace flame_ide;

// constructors & distructor

template<typename T>
Array<T>::Array()
{
	inc_arr = nullptr;
	length = 0;
	initialised = false;
}
template<typename T>
Array<T>::Array(Array<T> &array)
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
	delete_array<T>(this->length, this->inc_arr);
}

// private

template<typename T>
template<typename Tt>
Tt**
Array<T>::get_new_array(const size_t& length)
{
	
//	T** array = (T**)malloc(sizeof(T*) * length);
	T** array = new T*[length];
	
	for(size_t i = 0; i < length; i++)
	{
//		array[i] = (T*)malloc(sizeof(T));
		array[i] = new T;
	}
	
	return array;
}

template<typename T>
template<typename Tt>
Tt**
Array<T>::get_copy_array(const size_t& length, Tt** array)
{
	
//	T** copy_array = std::malloc(sizeof(T*) * length);
	T** copy_array = new T*[length];
	
	for(size_t i = 0; i < length; i++)
	{
//		copy_array[i] = (T*)malloc(sizeof(T));
		copy_array[i] = new T;
		copy_array[i][0] = array[i][0];
	}
	
	return copy_array;
}

template<typename T>
template<typename Tt>
void
Array<T>::copy_array(const size_t& length, Tt** old_array, Tt** new_array)
{
	for(size_t i = 0; i < length; i++)
	{
		new_array[i][0] = old_array[i][0];
	}
}

template<typename T>
template<typename Tt>
void
Array<T>::delete_array(const size_t& length, Tt** array)
{
	for(size_t i = 0; i < length; i++)
	{
//		free(array[i]);
		delete array[i];
	}
//	free(array);
	delete[] array;
}


template<typename T>
template<typename Tt>
Tt**
Array<T>::resize_array(const size_t& old_size, const size_t& new_size, Tt** array)
{
	Tt** resized_arr;
	
	if(old_size != new_size)
	{
		resized_arr = get_new_array<Tt>(new_size);
		
		if(old_size < new_size)
		{
			copy_array<Tt>(old_size, array, resized_arr);
		}
		else
		{
			copy_array<Tt>(new_size, array, resized_arr);
		}
		
		delete_array<Tt>(old_size, array);
	}
	else
	{
		resized_arr	= array;
	}
	
	return resized_arr;
}

// public

template<typename T>
void
Array<T>::setLength(const size_t &new_length)
{
	if(!initialised)
	{
		inc_arr = get_new_array<T>(new_length);
	}
	else
	{
		inc_arr = resize_array<T>(this->length, new_length, this->inc_arr);
	}
	
	this->length = new_length;
}

template<typename T>
size_t
Array<T>::getLength()
{	return this->length;}

template<typename T>
T**
Array<T>::getArray_c()
{	return inc_arr;}

template<typename T>
T**
Array<T>::getCopyArray_c()
{
	return
		(initialised) 
		?
			get_copy_array<T>(this->length, this->inc_arr)
		:
			nullptr;	
}

// "защиты от дурака" нет, так что страдайте.
template<typename T>
T&
Array<T>::at(const size_t& index)
{
	if(index < this->length)
	{	return inc_arr[index][0];}
		
	return nullptr;
}

// сделал "защиту от дурака", чтобы народ не выходил за границы массива
// идиотская идея, т.к. доп действие. Зато типа защищено
template<typename T>
T&
Array<T>::operator [](const size_t& index)
{	return inc_arr[index % this->length][0];}

#endif // ARRAY_H
