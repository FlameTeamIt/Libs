#ifndef ARRAY_FUNCTIONS
#define ARRAY_FUNCTIONS

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
array_delete(Tt *array)
{
	delete[] array;
}


#endif // ARRAY_FUNCTIONS

