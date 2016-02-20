#ifndef TEMPLATES_ARRAY_FUNCTIONS
#define TEMPLATES_ARRAY_FUNCTIONS

#include <cstdlib>
#include <algorithm>

#include <Templates/For_All.h>

namespace flame_ide
{namespace templates
{

template<class Tt> inline
Tt* array_get_new(const size_t &length);

template<class Tt> inline
Tt* array_get_copy(const size_t &length, const Tt *array);

template<class Tt> inline
void array_copying(const size_t &length, const Tt *old_array, Tt *new_array);

template<class Tt> inline
void array_copying(const size_t &length
				   ,const Tt *old_array, const size_t &start_index_old
				   ,Tt *new_array, const size_t &start_index_new);

template<class Tt> inline
void array_insert_element(const size_t &length, Tt *&array
						  ,const size_t &index
						  ,const Tt &insert_elem);

template<class Tt> inline
void array_rewrite(Tt *array, size_t pos, const Tt &object);

// no implementation
template<class Tt> inline
void array_insert_array(const size_t &length, Tt *&array
						,const size_t &index
						,const size_t &length_insert, const Tt *insert_array);

// no implementation
template<class Tt> inline
void array_erase(size_t &length, Tt *&array
				 ,const size_t &index
				 ,const size_t &count = 1);

template<class Tt> inline
void array_call_distructors(size_t length, Tt *array);

template<class Tt> inline
void array_delete(Tt *array);

/* ========================================================================= */

template<class Tt>
Tt*
array_get_new(const size_t &length)
{
	Tt* pointer_array = nullptr;
	if(length)
	{
		size_t real_size = sizeof(Tt)*length;
		char *ch_arr = (char*)malloc(real_size);
		if(ch_arr)
		{
			for(size_t i = 0; i < real_size; ++i)
			{
				ch_arr[i] = 0;
			}
		}
		pointer_array = (Tt*)ch_arr;
	}
	return pointer_array;
}

template<class Tt>
Tt*
array_get_copy(const size_t &length, const Tt *array)
{
	Tt* copy_array = nullptr;
	if(length)
	{
		copy_array = (Tt*)malloc(length * sizeof(Tt));
		if(copy_array != NULL)
		{
			std::copy_n(array, length, copy_array);
		}
	}
	return copy_array;
}

template<class Tt>
void
array_copying(const size_t &length, const Tt *old_array, Tt *new_array)
{
	if(length)
	{
		std::copy_n(old_array, length, new_array);
	}
}

// копирование с заданным смещением
template<class Tt>
void
array_copying(const size_t &length
			  ,const Tt *old_array, const size_t &start_index_old
			  ,Tt *new_array, const size_t &start_index_new)
{
}

template<class Tt>
void
array_rewrite(Tt *array, size_t pos, const Tt &object)
{
	std::copy_n(&object, 1, array+pos);
}

template<class Tt>
void
array_insert_element(const size_t &length, Tt *&array
					 ,const size_t &index
					 ,const Tt &insert_elem)
{
}

// no implementation
template<class Tt>
void
array_insert_array(const size_t &length, Tt *&array
				   ,const size_t &index
				   ,const size_t &length_insert, const Tt *insert_array)
{
}

// no implementation
template<class Tt> inline
void array_erase(size_t &length, Tt *&array
				 ,const size_t &index
				 ,const size_t &count)
{
}

template<typename Tt>
void
array_call_distructors(size_t length, Tt *array)
{
	for(size_t i = 0; i < length; ++i)
	{
		array[i].~Tt();
	}
}

template<class Tt>
void
array_delete(Tt *array)
{
	free(array);
}

}}

#endif // ARRAY_FUNCTIONS

