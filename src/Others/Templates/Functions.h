#ifndef FUNCTIONS
#define FUNCTIONS

#include <cstdlib>

namespace flame_ide
{namespace templates
{

template<typename Tt> inline
Tt** array_get_new(const size_t &length);

template<typename Tt> inline
Tt** array_get_copy(const size_t &length, Tt **array);

template<typename Tt> inline
void array_copying(const size_t &length, Tt **old_array, Tt **new_array);

template<typename Tt> inline
void array_delete(const size_t &length, Tt **array);

template<typename Tt> inline
Tt** array_resize(const size_t &old_size, const size_t &new_size, Tt **array);

// --------------------

typedef enum
{
	FIRST,
	CENTRAL,
	LAST
} PosType;

template<typename T>
struct Container
{
	mutable Container<T> *next;
	mutable Container<T> *prev;
	
	PosType pos_type;
	T *inc_data;
	
	Container();
	Container(PosType position_type);
	Container(Container<T> *init_next, Container<T> *init_prev,
			  T* init_data, PosType position_type);
	
	// noexcept - гарантия отсуствия исключений
	// нужно писать и в шапке перед реализацией
	inline Container<T> & operator =(const Container<T> &Container);
	inline bool operator ==(const Container<T> &container) const;
	inline bool operator !=(const Container<T> &container) const;
};

template<typename Tt> inline
void list_insert_default(Container<Tt> *start_container, size_t count);

template<typename Tt> inline
void list_insert_array(Container<Tt> *start_container, size_t count, Tt *array);

template<typename Tt> inline
void list_insert_elem_after(Container<Tt> *start_container, const Tt &element);

template<typename Tt> inline
void list_erase_elem(Container<Tt> *container);

template<typename Tt> inline
void list_erase_some_elements(Container<Tt> *start_container, size_t count);

template<typename Tt> inline
void list_erase_some_elements(Container<Tt> *start_container,
							  Container<Tt> *end_container);

}}

template<typename Tt>
Tt**
flame_ide::templates::
array_get_new(const size_t &length)
{
	Tt** pointer_array = new Tt*[length];
	for(size_t i = 0; i < length; i++)
	{	pointer_array[i] = new Tt;}
	
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
array_delete(const size_t &length, Tt **array)
{
	for(size_t i = 0; i < length; i++)
	{	delete array[i];}
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

// --------------------

template<typename T>
flame_ide::templates::
Container<T>::Container()
{
	next = nullptr;
	prev = nullptr;
	inc_data = nullptr;
	pos_type = CENTRAL;
}
template<typename T>
flame_ide::templates::
Container<T>::Container(flame_ide::templates::PosType position_type)
{
	switch (position_type)
	{
	case FIRST:
		prev = nullptr;
		break;
		
	case LAST:
		next = nullptr;
		break;
		
	default:
		next = nullptr;
		prev = nullptr;
		break;
	}
	inc_data = nullptr;
	pos_type = position_type;
}

template<typename T>
flame_ide::templates::
Container<T>::Container(flame_ide::templates::Container<T> *init_next,
						flame_ide::templates::Container<T> *init_prev,
						T *init_data, flame_ide::templates::PosType position_type)
{
	this->next = init_next;
	this->prev = init_prev;
	this->inc_data = init_data;
	this->pos_type = position_type;
}

template<typename T>
flame_ide::templates::Container<T> &
flame_ide::templates::
Container<T>::operator =(const flame_ide::templates::Container<T> &container)
{
	this->next = container.next;
	this->prev = container.prev;
	this->inc_data = container.inc_data;
	this->pos_type = container.pos_type;
	
	return *this;
}
template<typename T>
bool
flame_ide::templates::
Container<T>::operator ==(const flame_ide::templates::Container<T> &container) const
{
	return ((this->pos_type == container.pos_type)
			&& (this->next == container.next)
			&& (this->prev == container.prev)
			&& (this->inc_data == container.inc_data)
			);
}

template<typename T>
bool
flame_ide::templates::
Container<T>::operator !=(const flame_ide::templates::Container<T> &container) const
{
	return ((this->pos_type != container.pos_type)
			&& (this->next != container.next)
			&& (this->prev != container.prev)
			&& (this->inc_data != container.inc_data)
			);
}

template<typename Tt>
void
flame_ide::templates::
list_insert_default(Container<Tt> *start_container, size_t count)
{
	Container<Tt> *run_pointer = start_container;
	Container<Tt> *end_container = start_container->next;
	
	for(size_t i = 0; i < count; i++)
	{
		Container<Tt> *new_elem = new Container<Tt>;
		
		new_elem->pos_type = CENTRAL;
		new_elem->inc_data = new Tt;
		
		new_elem->prev = run_pointer;
		run_pointer->next = new_elem;
		
		run_pointer = run_pointer->next;
	}
	
	run_pointer->next = end_container;
	
	end_container->prev = run_pointer;
}

template<typename Tt>
void
flame_ide::templates::
list_insert_array(Container<Tt> *start_container, size_t count, Tt *array)
{
	Container<Tt> *run_pointer = start_container;
	Container<Tt> *end_container = start_container->next;
	
	for(size_t i = 0; i < count; i++)
	{
		Container<Tt> *new_elem = new Container<Tt>;
		
		new_elem->pos_type = CENTRAL;
		new_elem->inc_data = new Tt(array[i]);
		
		new_elem->prev = run_pointer;
		run_pointer->next = new_elem;
		
		run_pointer = run_pointer->next;
	}
	
	run_pointer->next = end_container;
	
	end_container->prev = run_pointer;
}

template<typename Tt>
void
flame_ide::templates::
list_insert_elem_after(Container<Tt> *start_container, const Tt &element)
{
	if(start_container->pos_type != LAST)
	{
		Container<Tt> *end_container = start_container->next;
		Container<Tt> *new_elem = new Container<Tt>(end_container, start_container,
													new Tt(element), CENTRAL);
		
		start_container->next = new_elem;
		end_container->prev = new_elem;
	}
}

template<typename Tt>
void
flame_ide::templates::
list_erase_elem(Container<Tt> *container)
{
	if(container->pos_type == CENTRAL)
	{
		Container<Tt> *prev_container = container->prev;
		Container<Tt> *next_container = container->next;
		
		prev_container->next = next_container;
		next_container->prev = prev_container;
		
		delete container->inc_data;
		delete container;
	}
}

template<typename Tt>
void
flame_ide::templates::
list_erase_some_elements(Container<Tt> *start_container, size_t count)
{
	Container<Tt> *end_container, *run_pointer = start_container;
	count++;
	
	for(size_t i = 0; i < count; i++)
	{
		run_pointer = run_pointer->next;
	}
	end_container = run_pointer;
	
	list_erase_some_elements<Tt>(start_container, end_container);
}

template<typename Tt>
void
flame_ide::templates::
list_erase_some_elements(Container<Tt> *start_container,
						 Container<Tt> *end_container)
{
	Container<Tt> *run_pointer = start_container->next;
	while(run_pointer != end_container)
	{
		run_pointer = run_pointer->next;
		delete run_pointer->prev->inc_data;
		delete run_pointer->prev;
	}
	
	if(start_container->next != end_container
	  && end_container->prev != start_container)
	{
		start_container->next = end_container;
		end_container->prev = start_container;
	}
}


#endif // FUNCTIONS

