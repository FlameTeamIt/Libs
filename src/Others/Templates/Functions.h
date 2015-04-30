#ifndef FUNCTIONS
#define FUNCTIONS

#include <cstdlib>

namespace flame_ide
{namespace templates
{

template<typename Tt> static inline
Tt** get_new_array(const size_t& length);

template<typename Tt> static inline
Tt** get_copy_array(const size_t& length, Tt** array);

template<typename Tt> static inline
void copy_array(const size_t& length, Tt** old_array, Tt** new_array);

template<typename Tt> static inline
void delete_array(const size_t& length, Tt** array);

template<typename Tt> static inline
Tt** resize_array(const size_t& old_size, const size_t& new_size, Tt** array);

class Array;
class List;

}}

template<typename Tt>
Tt**
flame_ide::templates::
get_new_array(const size_t &length)
{
	Tt** pointer_array = new Tt*[length];
	for(size_t i = 0; i < length; i++)
	{	pointer_array[i] = new Tt;}
	
	return pointer_array;
}

template<typename Tt>
Tt**
flame_ide::templates::
get_copy_array(const size_t &length, Tt **array)
{
	Tt** copy_array = new Tt*[length];
	
	for(size_t i = 0; i < length; i++)
	{	copy_array[i] = new Tt(array[i][0]);}
	
	return copy_array;
}

template<typename Tt>
void
flame_ide::templates::
copy_array(const size_t &length, Tt **old_array, Tt **new_array)
{
	for(size_t i = 0; i < length; i++)
	{	new_array[i][0] = old_array[i][0];}
}

template<typename Tt>
void
flame_ide::templates::
delete_array(const size_t &length, Tt **array)
{
	for(size_t i = 0; i < length; i++)
	{	delete array[i];}
	delete[] array;
}


template<typename Tt>
Tt**
flame_ide::templates::
resize_array(const size_t& old_size, const size_t& new_size, Tt** array)
{
	Tt** resized_arr;
	
	if(old_size != new_size)
	{
		resized_arr = get_new_array<Tt>(new_size);
		
		if(old_size < new_size)
		{	copy_array<Tt>(old_size, array, resized_arr);}
		else
		{	copy_array<Tt>(new_size, array, resized_arr);}
		
		delete_array<Tt>(old_size, array);
	}
	else
	{	resized_arr	= array;}
	
	return resized_arr;
}

#endif // FUNCTIONS

