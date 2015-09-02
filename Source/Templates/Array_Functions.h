#ifndef TEMPLATES_ARRAY_FUNCTIONS
#define TEMPLATES_ARRAY_FUNCTIONS

#include <cstdlib>
#include <algorithm>

namespace flame_ide
{namespace templates
{

template<typename Tt> inline
Tt* array_get_new(const size_t &length);

template<typename Tt> inline
Tt* array_get_copy(const size_t &length, const Tt *array);

template<typename Tt> inline
void array_copying(const size_t &length, const Tt *old_array, Tt *new_array);

template<typename Tt> inline
void array_copying(const size_t &length
				   ,const Tt *old_array, const size_t &start_index_old
				   ,Tt *new_array, const size_t &start_index_new);

template<typename Tt> inline
void array_insert_element(const size_t &length, Tt *&array
						  ,const size_t &index
						  ,const Tt &insert_elem);

// no implementation
template<typename Tt> inline
void array_insert_array(const size_t &length, Tt *&array
						,const size_t &index
						,const size_t &length_insert, const Tt *insert_array);

// no implementation
template<typename Tt> inline
void array_erase(size_t &length, Tt *&array
				 ,const size_t &index
				 ,const size_t &count = 1);

template<typename Tt> inline
void array_delete(Tt *array);

}}

template<typename Tt>
Tt*
flame_ide::templates::
array_get_new(const size_t &length)
{
	Tt* pointer_array = new Tt[length];
	return pointer_array;
}

template<typename Tt>
Tt*
flame_ide::templates::
array_get_copy(const size_t &length, const Tt *array)
{
	Tt* copy_array = new Tt[length];
	std::copy(array, array+length, copy_array);
	
	return copy_array;
}

template<typename Tt>
void
flame_ide::templates::
array_copying(const size_t &length, const Tt *old_array, Tt *new_array)
{
	std::copy(old_array, old_array+length, new_array);
}

// копирование с заданным смещением
template<typename Tt>
void
flame_ide::templates::
array_copying(const size_t &length
			  ,const Tt *old_array, const size_t &start_index_old
			  ,Tt *new_array, const size_t &start_index_new)
{
	std::copy(old_array + start_index_old
			  ,old_array + start_index_old + length
			  ,new_array + start_index_new);
}

template<typename Tt>
void
flame_ide::templates::
array_insert_element(const size_t &length, Tt *&array
					 ,const size_t &index
					 ,const Tt &insert_elem)
{
	// создаём новый массив нового размера
	Tt* new_arr = array_get_new<Tt>(length+1);
	
	// копируем данные до индекса
	if(index > 0)
	{
		array_copying<Tt>(index, array, 0, new_arr, 0);
	}
	
	// выделяем память на нужный элемент
	std::copy_n(&insert_elem, 1, new_arr+index);
	
	// копируем данные после индекса
	if(index < length)
	{
		array_copying<Tt>(length - index, array, index, new_arr, index+1);
	}
	
	if(length)
	{
		array_delete<Tt>(array);
	}
	
	array = new_arr;
}

// no implementation
template<typename Tt>
void
flame_ide::templates::
array_insert_array(const size_t &length, Tt *&array
				   ,const size_t &index
				   ,const size_t &length_insert, const Tt *insert_array)
{
	// создаём новый массив нового размера
	Tt* new_arr = array_get_new<Tt>(length+length_insert);
	
	// копируем данные до индекса
	if(index > 0)
	{
		array_copying<Tt>(index, array, 0, new_arr, 0);
	}
	
	// копируем данные из массива
	std::copy_n(insert_array, length_insert, new_arr+index);
	
	// копируем данные после индекса
	if(index < length)
	{
		array_copying<Tt>(length - index, array, index, new_arr, index+length_insert);
	}
	
	// удаляем старый массив
	if(length)
	{
		array_delete<Tt>(array);
	}
	
	array = new_arr;
}

// no implementation
template<typename Tt>
void
flame_ide::templates::
array_erase(size_t &length, Tt *&array
			,const size_t &index
			,const size_t &count)
{
	size_t new_length = length - count;
	Tt* tmp_arr = array;
	
	if(new_length)
	{
		// содаем новый массив
		Tt *new_arr = array_get_new<Tt>(new_length);
		
		// копируем элементы до индекса
		array_copying<Tt>(index, array, 0, new_arr, 0);
		
		// копируем после индекса + количество удяляемых элементов
		array_copying<Tt>(length - index - count,
								  array, index + count,
								  new_arr, index);
		
		array = new_arr;
	}
	else
	{
		array = nullptr;
	}
		
	// удаляем старый массив
	array_delete<Tt>(tmp_arr);
	length = new_length;
}


template<typename Tt>
void
flame_ide::templates::
array_delete(Tt *array)
{
	delete[] array;
}


#endif // ARRAY_FUNCTIONS

