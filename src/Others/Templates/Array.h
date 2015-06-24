#ifndef TEMPLATES_ARRAY_H
#define TEMPLATES_ARRAY_H

#include "Functions.h"

namespace flame_ide
{ namespace templates
{

template<typename T>
class Array
{
	mutable T **inc_arr;
	
	size_t arr_size;
	mutable bool initialised;
	
	T** getPCopy() const;
	
protected:
	// static
	
public:
	Array();
	Array(const Array<T> &array);
	Array(const size_t &arr_size);
	
	~Array();
	
	// future
	// пока не знаю, как работать с функциями с произвольным количеством аргументов	
//	template<typename ... cunstructor_args>
//	Array(const size_t& length, ...);
	
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
	
	T*  getPointer(const size_t &index) const;
	
	inline T& at(const size_t &index) const;
	inline T& operator[](const size_t &index) const;
	
	const Array<T> &operator=(const Array<T> &);
};

}}


using namespace flame_ide::templates;

// constructors & distructor

template<typename T>
Array<T>::Array()
{
	inc_arr = nullptr;
	arr_size = 0;
	initialised = false;
}
template<typename T>
Array<T>::Array(const Array<T> &array)
{
	if(array.arr_size && array.initialised)
	{
		this->inc_arr = array_get_copy<T>(array.arr_size, array.inc_arr);
		this->arr_size = array.arr_size;
		this->initialised = true;
	}
	else Array();
}
template<typename T>
Array<T>::Array(const size_t& array_length)
{
	if(array_length)
	{
		this->arr_size = array_length;
		this->initialised = true;
		inc_arr = array_get_new<T>(this->arr_size);
	}
	else Array();
}

template<typename T>
Array<T>::~Array()
{
	if(initialised)
	{ array_delete<T>(this->arr_size, this->inc_arr);}
}

// private

template<typename T>
T**
Array<T>::getPCopy() const
{
	return array_get_copy<T>(this->arr_size, this->inc_arr);
}

// public

template<typename T>
bool
Array<T>::isInitialised() const
{	return initialised;}

template<typename T>
void
Array<T>::pushBack(const T &data)
{
	// создаём новый массив нового размера
	size_t new_length = arr_size + 1;
	T **new_arr = array_get_new<T>(new_length, false);
	
	// копируем элементы
	array_copying_with_new<T>(arr_size, inc_arr, 0, new_arr, 0);
	
	// выделяем память на последний элемент
	new_arr[arr_size] = new T(data);
	
	// удаляем старый массив
	if(initialised)
	{
		array_delete<T>(arr_size, inc_arr);
	}
	else
	{
		initialised	= true;
	}
	
	inc_arr = new_arr;
	arr_size = new_length;
	
}

template<typename T>
void
Array<T>::pushFront(const T &data)
{
	// создаём новый массив нового размера
	size_t new_length = arr_size + 1;
	T **new_arr = array_get_new<T>(new_length, false);
	
	// выделяем память на первый элемент
	new_arr[0] = new T(data);
	
	// копируем элементы
	array_copying_with_new<T>(arr_size, inc_arr, 0, new_arr, 1);
	
	// удаляем старый массив
	if(initialised)
	{
		array_delete<T>(arr_size, inc_arr);
	}
	else
	{
		initialised	= true;
	}
	
	inc_arr = new_arr;
	arr_size = new_length;
}

template<typename T>
void
Array<T>::insert(const size_t &index, const T &data)
{
	if(index > arr_size) return;
	
	size_t new_length = arr_size + 1;
	// создаём новый массив нового размера
	T** new_arr = array_get_new<T>(new_length, false);
	
	// копируем данные до индекса
	array_copying_with_new<T>(index, inc_arr, 0, new_arr, 0);
	
	new_arr[index] = new T(data);
	
	// копируем данные после индекса
	array_copying_with_new<T>(arr_size - index, inc_arr, index, new_arr, index+1);
	
	if(initialised)
	{ array_delete<T>(arr_size, inc_arr); }
	
	inc_arr = new_arr;
	arr_size = new_length;
}

template<typename T>
void
Array<T>::insert(const size_t &index, const size_t &count, const T *array)
{
	if(index > arr_size) return;
	
	size_t new_length = arr_size + count;
	// создаём новый массив нового размера
	T** new_arr = array_get_new<T>(new_length, false);
	
	// копируем данные до индекса
	array_copying_with_new<T>(index, inc_arr, 0, new_arr, 0);
	
	// копируем данные из массива
	for(size_t i = 0; i < count; i++)
	{ new_arr[index + i] = new T(array[i]); }
	
	// копируем данные после индекса
	array_copying_with_new<T>(arr_size - index, inc_arr, index, new_arr, index+count);
	
	// удаляем старый массив
	if(initialised)
	{ array_delete<T>(arr_size, inc_arr); }
	else
	{ initialised = true; }
	
	inc_arr = new_arr;
	arr_size = new_length;
}

template<typename T>
void
Array<T>::popBack()
{
	if(!initialised) return;
	
	size_t new_length = arr_size - 1;
	T** tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T **new_arr = array_get_new<T>(new_length, false);
		
		// копируем все данные кроме последнего
		array_copying_with_new<T>(new_length, inc_arr, 0, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}

	// удаляем старый массив
	array_delete<T>(arr_size, tmp_inc_arr);
	
	arr_size = new_length;
}

template<typename T>
void
Array<T>::popFront()
{
	if(!initialised) return;
	
	size_t new_length = arr_size - 1;
	T** tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T **new_arr = array_get_new<T>(new_length, false);
		
		// копируем все данные кроме первого
		array_copying_with_new<T>(new_length, inc_arr, 1, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}

	// удаляем старый массив
	array_delete<T>(arr_size, tmp_inc_arr);
	
	arr_size = new_length;
}

template<typename T>
void
Array<T>::popBack(const size_t &count)
{
	if(!initialised || (count > arr_size)) return;
	
	size_t new_length = arr_size - count;
	T** tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T **new_arr = array_get_new<T>(new_length, false);
		
		// копируем все данные кроме последнего
		array_copying_with_new<T>(new_length, inc_arr, 0, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}
	
	// удаляем старый массив
	array_delete<T>(arr_size, tmp_inc_arr);
	
	arr_size = new_length;
}

template<typename T>
void
Array<T>::popFront(const size_t &count)
{
	if(!initialised || (count > arr_size)) return;
	
	size_t new_length = arr_size - count;
	T** tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// создаем новый массив нового размера
		T **new_arr = array_get_new<T>(new_length, false);
		
		// копируем все данные кроме первого
		array_copying_with_new<T>(new_length, inc_arr, 1, new_arr, 0);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}
	
	// удаляем старый массив
	array_delete<T>(arr_size, tmp_inc_arr);
	
	arr_size = new_length;
}

template<typename T>
void
Array<T>::erase(const size_t &index)
{
	if(!initialised || (index >= arr_size)) return;
	
	size_t new_length = arr_size - 1;
	T** tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// содаем новый массив
		T **new_arr = array_get_new<T>(new_length, false);
		
		// копируем элементы до индекса
		array_copying_with_new<T>(index, inc_arr, 0, new_arr, 0);
		
		// копируем после индекса
		array_copying_with_new<T>(arr_size - index - 1,
								  inc_arr, index+1,
								  new_arr, index);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}
		
	// удаляем старый массив
	array_delete<T>(arr_size, tmp_inc_arr);
	arr_size = new_length;
}

template<typename T>
void
Array<T>::erase(const size_t &index, const size_t &count)
{
	if(!initialised || ( (index + count - 1) >= arr_size)) return;
	
	size_t new_length = arr_size - count;
	T** tmp_inc_arr = inc_arr;
	
	if(new_length)
	{
		// содаем новый массив
		T **new_arr = array_get_new<T>(new_length, false);
		
		// тут нужно подумать. Что-то тут не так
		
		// копируем элементы до индекса
		array_copying_with_new<T>(index, inc_arr, 0, new_arr, 0);
		
		// копируем после индекса + количество удяляемых элементов
		array_copying_with_new<T>(arr_size - index - count,
								  inc_arr, index + count,
								  new_arr, index);
		
		inc_arr = new_arr;
	}
	else
	{
		inc_arr = nullptr;
		initialised = false;
	}
		
	// удаляем старый массив
	array_delete<T>(arr_size, tmp_inc_arr);
	arr_size = new_length;
}

template<typename T>
void
Array<T>::clear()
{
	if(initialised)
	{
		array_delete<T>(this->arr_size, this->inc_arr);
		this->initialised = false;
		this->arr_size = 0;
	}
}

template<typename T>
void
Array<T>::setSize(const size_t &new_length)
{
	if(initialised)
	{
		clear();
	}
	
	this->initialised = true;
	inc_arr = array_get_new<T>(new_length);
	this->arr_size = new_length;
	
}

template<typename T>
void
Array<T>::setCopy(const Array<T> &copying_array)
{
	array_delete<T>(this->arr_size, this->inc_arr);
	
	this->arr_size = copying_array.getSize();
	this->inc_arr = copying_array.getPCopy();
}

template<typename T>
size_t
Array<T>::getSize() const
{	return this->arr_size;}

template<typename T>
T*
Array<T>::getPointer(const size_t &index) const
{	return inc_arr[index];}

// сделал "защиту от дурака", чтобы народ не выходил за границы массива
// идиотская идея, т.к. доп действие. Зато типа защищено
template<typename T>
T&
Array<T>::at(const size_t &index) const
{	return inc_arr[index % this->arr_size][0];}

// "защита от дурака" х2
template<typename T>
T&
Array<T>::operator [](const size_t &index) const
{	return inc_arr[index % this->arr_size][0];}

template<typename T>
const Array<T>&
Array<T>::operator =(const Array<T> &arg)
{
	if(arg.initialised)
	{
		array_delete<T>(this->arr_size, this->inc_arr);
		this->arr_size = arg.arr_size;
		this->inc_arr = arg.getPCopy();
		this->initialised = true;
	}
	
	return *this;
}

#endif // TEMPLATES_ARRAY_H
