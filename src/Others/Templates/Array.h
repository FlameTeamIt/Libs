#ifndef TEMPLATES_ARRAY_H
#define TEMPLATES_ARRAY_H

#include "Array_Functions.h"

namespace flame_ide
{ namespace templates
{

template<class T>
class Array
{
	mutable T *inc_arr;
	size_t arr_size;
	size_t type_size;
	
	mutable bool initialised;
	
	void set();
	T* getPCopy() const;
	
protected:
	// static
	
public:
	Array();
	Array(const Array<T> &array);
	Array(const size_t &arr_size);
	
	~Array();
	
	bool isInitialised() const;
	
	void pushBack(const T &data);
	void pushFront(const T &data);
	
	void insert(const size_t &index, const T &data);
	void insert(const size_t &index, const size_t &count, const T *array);
	
	void popBack();
	void popFront();
	
	void popBack(const size_t &count);
	void popFront(const size_t &count);
	
	void erase(const size_t &index); // удаляет элемент, находящийся под этим интексом
	void erase(const size_t &index, const size_t &count); // удаляет элементы после индекса
	
	void clear();
	
	void   setSize(const size_t &new_length);
	void   setCopy(const Array<T> &copying_array);
	size_t getSize() const;
	
	inline T& at(const size_t &index) const;
	inline T& operator[](const size_t &index) const;
	
	const Array<T> &operator=(const Array<T> &);
};

}}


using namespace flame_ide::templates;

// constructors & distructor

template<class T>
Array<T>::Array()
{
	set();
}
template<class T>
Array<T>::Array(const Array<T> &array)
{
	if(array.arr_size && array.initialised)
	{
		this->inc_arr = array_get_copy<T>(array.arr_size, array.inc_arr);
		this->arr_size = array.arr_size;
		this->initialised = true;
	}
	else set();
}
template<class T>
Array<T>::Array(const size_t& array_length)
{
	if(array_length)
	{
		this->arr_size = array_length;
		this->initialised = true;
		inc_arr = array_get_new<T>(this->arr_size);
	}
	else set();
}

template<class T>
Array<T>::~Array()
{
	if(initialised)
	{
		array_delete<T>(this->inc_arr);
	}
}

// private

template<class T>
void
Array<T>::set()
{
	inc_arr = nullptr;
	arr_size = 0;
	type_size = sizeof(T);
	initialised = false;	
}

template<class T>
T*
Array<T>::getPCopy() const
{
	return array_get_copy<T>(this->arr_size, this->inc_arr);
}

// public

template<class T>
bool
Array<T>::isInitialised() const
{	return initialised;}

template<class T>
void
Array<T>::pushBack(const T &data)
{
	size_t new_length = arr_size + 1;
	
	if(!initialised)
	{
		array_insert_element<T>(arr_size, inc_arr, arr_size, data);
		initialised	= true;
	}
	else
	{
//		array_insert_element<T>(arr_size, inc_arr, arr_size-1, data);
		array_insert_element<T>(arr_size, inc_arr, arr_size, data);
	}
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::pushFront(const T &data)
{
	size_t new_length = arr_size + 1;
	
	array_insert_element<T>(arr_size, inc_arr, 0, data);
	
	if(!initialised)
	{
		initialised	= true;
	}
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::insert(const size_t &index, const T &data)
{
	if(index > arr_size) return;
	
	size_t new_length = arr_size + 1;
	
	array_insert_element<T>(arr_size, inc_arr,
							index, data);
	
	if(!initialised)
	{
		initialised = true;
	}
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::insert(const size_t &index, const size_t &count, const T *array)
{
	if(index > arr_size) return;
	
	size_t new_length = arr_size + count;
	
	array_insert_array<T>(arr_size, inc_arr,
						  index, count, array);
	
	if(!initialised)
	{
		initialised = true;
	}
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::popBack()
{
	if(!initialised) return;
	
	size_t new_length = arr_size - 1;
	T *tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T *new_arr = array_get_new<T>(new_length);
		
		// копируем все данные кроме последнего
		array_copying<T>(new_length, inc_arr, 0, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}

	// удаляем старый массив
	array_delete<T>(tmp_inc_arr);
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::popFront()
{
	if(!initialised) return;
	
	size_t new_length = arr_size - 1;
	T *tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T *new_arr = array_get_new<T>(new_length);
		
		// копируем все данные кроме первого
		array_copying<T>(new_length, inc_arr, 1, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}

	// удаляем старый массив
	array_delete<T>(tmp_inc_arr);
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::popBack(const size_t &count)
{
	if(!initialised || (count > arr_size)) return;
	
	size_t new_length = arr_size - count;
	T *tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T *new_arr = array_get_new<T>(new_length);
		
		// копируем все данные кроме последнего
		array_copying<T>(new_length, inc_arr, 0, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}
	
	// удаляем старый массив
	array_delete<T>(tmp_inc_arr);
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::popFront(const size_t &count)
{
	if(!initialised || (count > arr_size)) return;
	
	size_t new_length = arr_size - count;
	T *tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T *new_arr = array_get_new<T>(new_length);
		
		// копируем все данные кроме первого
		array_copying<T>(new_length, inc_arr, count-1, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}
	
	// удаляем старый массив
	array_delete<T>(tmp_inc_arr);
	
	arr_size = new_length;
}

template<class T>
void
Array<T>::erase(const size_t &index)
{
	if(!initialised || (index >= arr_size)) return;
	
	array_erase<T>(arr_size, inc_arr, index);
	
	if(!arr_size)
	{
		initialised = false;
	}
}

template<class T>
void
Array<T>::erase(const size_t &index, const size_t &count)
{
	if(!initialised || ( (index + count - 1) >= arr_size) || !count) return;
	
	array_erase<T>(arr_size, inc_arr, index, count);
	
	if(!arr_size)
	{
		initialised = false;
	}
}

template<class T>
void
Array<T>::clear()
{
	if(initialised)
	{
		array_delete<T>(this->inc_arr);
		this->inc_arr = nullptr;
		this->initialised = false;
		this->arr_size = 0;
	}
}

template<class T>
void
Array<T>::setSize(const size_t &new_length)
{
	if(initialised)
	{
		array_delete<T>(this->inc_arr);
	}
	
	this->initialised = true;
	this->inc_arr = array_get_new<T>(new_length);
	this->arr_size = new_length;
	
}

template<class T>
void
Array<T>::setCopy(const Array<T> &copying_array)
{
	array_delete<T>(this->inc_arr);
	
	this->arr_size = copying_array.getSize();
	this->inc_arr = copying_array.getPCopy();
}

template<class T>
size_t
Array<T>::getSize() const
{
	return this->arr_size;
}

// сделал "защиту от дурака", чтобы народ не выходил за границы массива
// идиотская идея, т.к. доп действие. Зато типа защищено
template<class T>
T&
Array<T>::at(const size_t &index) const
{
	return inc_arr[index % this->arr_size];
}

// "защита от дурака" х2
template<class T>
T&
Array<T>::operator [](const size_t &index) const
{
	return inc_arr[index % this->arr_size];
}

template<class T>
const Array<T>&
Array<T>::operator =(const Array<T> &arg)
{
	if(arg.initialised)
	{
		array_delete<T>(this->inc_arr);
		this->arr_size = arg.arr_size;
		this->inc_arr = arg.getPCopy();
		this->initialised = true;
	}
	
	return *this;
}

#endif // TEMPLATES_ARRAY_H
