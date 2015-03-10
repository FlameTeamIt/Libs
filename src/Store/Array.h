#ifndef ARRAY_H
#define ARRAY_H

// Пока не уверен, что нужно, но пусть пока будет

namespace flame_ide
{

template<typename T>
class Array
{
	T** inc_arr;
	
	unsigned int length;
	bool initialised;
	
	// operators
	
	Array<T>& operator=(const Array<T>&); // не нужно присваивание
	
	// static
	
	template<typename Tt> static inline
	Tt**
	get_new_array(const unsigned int& length);
	
	template<typename Tt> static inline
	Tt**
	get_copy_array(const unsigned int& length, Tt** array);
	
	template<typename Tt> static inline
	void
	copy_array(unsigned int& length, Tt** old_array, Tt** new_array);
	
	template<typename Tt> static inline
	void
	delete_array(unsigned int& length, Tt** array);
	
	// normal
	
	// избавился от функции измнения массива
	
public:
	Array();
	Array(Array<T>& array);
	Array(const unsigned int& length);
	
	// future
	// пока не знаю, как работать с функциями с произвольным количеством аргументов	
//	template<typename ... cunstructor_args>
//	Array(const unsigned int& length, ...);
	
	~Array();
	
	// virtual
	
	// normal
	
	unsigned int
	getLength();
	
	T**
	getArray_c();
	
	T**
	getCopyArray_c();
	
	T&
	at(unsigned int& index);
	
	// operators
	
	T&
	operator[](const unsigned int& index);
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
	T** arg_arr = array.inc_arr;
	
	this->length = array.length;
	this->initialised = true;
	this->inc_arr = get_copy_array<T>(this->length, arg_arr);
}
template<typename T>
Array<T>::Array(const unsigned int& length)
{
	this->length = length;
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
Array<T>::get_new_array(const unsigned int& length)
{
	
	T** array = new T*[length];
	
	for(unsigned int i = 0; i < length; i++)
	{
		array[i] = new T;
	}
	
	return array;
}

template<typename T>
template<typename Tt>
Tt**
Array<T>::get_copy_array(const unsigned int& length, Tt** array)
{
	
	T** copy_array = new T*[length];
	
	for(unsigned int i = 0; i < length; i++)
	{
		copy_array[i] = new T;
		copy_array[i][0] = array[i][0];
	}
	
	return copy_array;
}

template<typename T>
template<typename Tt>
void
Array<T>::copy_array(unsigned int& length, Tt** old_array, Tt** new_array)
{
	for(unsigned int i = 0; i < length; i++)
	{
		new_array[i][0] = old_array[i][0];
	}
}

template<typename T>
template<typename Tt>
void
Array<T>::delete_array(unsigned int& length, Tt** array)
{
	for(unsigned int i = 0; i < length; i++)
	{
		delete array[i];
	}
	delete[] array;
}


// public

template<typename T>
unsigned int
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

template<typename T>
T&
Array<T>::at(unsigned int& index)
{
	if(index < this->length)
	{
		return inc_arr[index][0];
	}
		
	return nullptr;
}

// сделал "защиту от дурака", чтобы народ не выходил за границы массива
// идиотская идея, т.к. доп действие. Зато типа защищено
template<typename T>
T&
Array<T>::operator [](const unsigned int& index)
{	return inc_arr[index % this->length][0];}

#endif // ARRAY_H
