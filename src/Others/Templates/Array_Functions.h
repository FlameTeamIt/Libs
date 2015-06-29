#ifndef ARRAY_FUNCTIONS
#define ARRAY_FUNCTIONS

#include "List_Functions.h"

namespace flame_ide
{namespace templates
{

template<typename Tt> inline
Tt** array_get_new(const size_t &length, bool initialize_pointers = true);

template<typename Tt> inline
Tt** array_get_copy(const size_t &length, Tt **array);

template<typename Tt> inline
void array_copying(const size_t &length, Tt **old_array, Tt **new_array);

template<typename Tt> inline
void array_copying_with_new(const size_t &length,
				   Tt **old_array, const size_t &start_index_old, 
				   Tt **new_array, const size_t &start_index_new);

template<typename Tt> inline
void array_copying_without_new(const size_t &length,
							Tt **old_array, const size_t &start_index_old, 
							Tt **new_array, const size_t &start_index_new);

template<typename Tt> inline
void array_delete(const size_t &length, Tt **array);

template<typename Tt> inline
Tt** array_resize(const size_t &old_size, const size_t &new_size, Tt **array);

}}

template<typename Tt>
Tt**
flame_ide::templates::
array_get_new(const size_t &length, bool initialize_pointers)
{
	Tt** pointer_array = new Tt*[length];
	
	if(initialize_pointers)
	{
		for(size_t i = 0; i < length; i++)
		{	pointer_array[i] = new Tt;}
	}
	else
	{
		for(size_t i = 0; i < length; i++)
		{	pointer_array[i] = nullptr;}
	}
	
	return pointer_array;
}

template<typename Tt>
Tt**
flame_ide::templates::
array_get_copy(const size_t &length, Tt **array)
{
	Tt** copy_array = new Tt*[length];
	
	for(size_t i = 0; i < length; i++)
	{	copy_array[i] = new Tt(array[i][0]);}
	
	return copy_array;
}

template<typename Tt>
void
flame_ide::templates::
array_copying(const size_t &length, Tt **old_array, Tt **new_array)
{
	for(size_t i = 0; i < length; i++)
	{	new_array[i][0] = old_array[i][0];}
}

template<typename Tt>
void
flame_ide::templates::
array_copying_with_new(const size_t &length,
			  Tt **old_array, const size_t &start_index_old, 
			  Tt **new_array, const size_t &start_index_new)
{
	for(size_t i = 0; i < length; i++)
	{	new_array[start_index_new + i] = new Tt(old_array[start_index_old + i][0]);}
}

template<typename Tt>
void
flame_ide::templates::
array_copying_without_new(const size_t &length,
					   Tt **old_array, const size_t &start_index_old, 
					   Tt **new_array, const size_t &start_index_new)
{
	for(size_t i = 0; i < length; i++)
	{	new_array[start_index_new + i] = old_array[start_index_old + i];}
}

template<typename Tt>
void
flame_ide::templates::
array_delete(const size_t &length, Tt **array)
{
	for(size_t i = 0; i < length; i++)
	{
		if(array[i] != nullptr)
		{ delete array[i]; }
	}
	delete[] array;
}


template<typename Tt>
Tt**
flame_ide::templates::
array_resize(const size_t& old_size, const size_t& new_size, Tt** array)
{
	Tt** resized_arr;
	
	if(old_size != new_size)
	{
		resized_arr = array_get_new<Tt>(new_size);
		
		if(old_size < new_size)
		{	array_copying<Tt>(old_size, array, resized_arr);}
		else
		{	array_copying<Tt>(new_size, array, resized_arr);}
		
		array_delete<Tt>(old_size, array);
	}
	else
	{	resized_arr	= array;}
	
	return resized_arr;
}


#endif // ARRAY_FUNCTIONS

