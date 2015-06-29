#ifndef TEMPLATES_FUNCTIONS
#define TEMPLATES_FUNCTIONS

#include "List_Container.h"

namespace flame_ide
{namespace templates
{

template<typename Tt> inline
void list_insert_default(Container<Tt> *start_container, size_t count);

template<typename Tt> inline
void list_insert_array_after(Container<Tt> *start_container, size_t count, const Tt *array);

template<typename Tt> inline
void list_insert_array_before(Container<Tt> *start_container, size_t count, const Tt *array);

template<typename Tt> inline
void list_insert_elem_after(Container<Tt> *container, const Tt &element);

template<typename Tt> inline
void list_insert_elem_before(Container<Tt> *container, const Tt &element);

template<typename Tt> inline
void list_erase_elem(Container<Tt> *container);

template<typename Tt> inline // предлагаю возвращать количество удаленных элементов
size_t list_erase_some_elements(Container<Tt> *start_container, size_t count);

template<typename Tt> inline // предлагаю возвращать количество удаленных элементов
size_t list_erase_some_elements_end(Container<Tt> *end_container, size_t count);

template<typename Tt> inline // удаление между 2-мя элементами
size_t list_erase_some_elements(Container<Tt> *start_container,
							  Container<Tt> *end_container);

template<typename Tt> inline // нужно подумать
void list_copy(const Container<Tt> *start_from, const Container<Tt> *end_from,
			   Container<Tt> *start_to, Container<Tt> *end_to);

template<typename Tt> inline
void list_link_containers(Container<Tt> *container_prev, Container<Tt> *container_next);

}}


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
		
		run_pointer->next = new_elem;
		new_elem->prev = run_pointer;
		
		run_pointer = run_pointer->next;
	}
	
	run_pointer->next = end_container;
	end_container->prev = run_pointer;
}

template<typename Tt>
void
flame_ide::templates::
list_insert_array_after(Container<Tt> *start_container, size_t count, const Tt *array)
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
list_insert_array_before(Container<Tt> *start_container, size_t count, const Tt *array)
{
	Container<Tt> *run_pointer = start_container->prev;
	Container<Tt> *end_container = start_container;
	
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

// добавление после указанного контейнера
template<typename Tt>
void
flame_ide::templates::
list_insert_elem_after(Container<Tt> *container, const Tt &element)
{
	Container<Tt> *old_next_container = container->next;
	Container<Tt> *new_elem = new Container<Tt>(old_next_container, container,
												new Tt(element), CENTRAL);
	
	container->next = new_elem;
	old_next_container->prev = new_elem;
}

// добавление перед указанном контейнером
template<typename Tt>
void
flame_ide::templates::
list_insert_elem_before(Container<Tt> *container, const Tt &element)
{
	Container<Tt> *old_prev_container = container->prev;
	Container<Tt> *new_elem = new Container<Tt>(container, old_prev_container,
												new Tt(element), CENTRAL);
	
	container->prev = new_elem;
	old_prev_container->next = new_elem;
}

template<typename Tt>
void
flame_ide::templates::
list_erase_elem(Container<Tt> *container)
{
	Container<Tt> *prev_container = container->prev;
	Container<Tt> *next_container = container->next;
	
	list_link_containers<Tt>(prev_container, next_container);
	
	delete container;
}

template<typename Tt>
size_t
flame_ide::templates::
list_erase_some_elements(Container<Tt> *start_container, size_t count)
{
	Container<Tt> *end_container, *run_pointer = start_container;
	count++;
	
	for(size_t i = 0; (i < count) && (run_pointer->pos_type != LAST); i++)
	{
		run_pointer = run_pointer->next;
	}
	end_container = run_pointer;
	
	return list_erase_some_elements<Tt>(start_container, end_container);
}

template<typename Tt>
size_t
flame_ide::templates::
list_erase_some_elements_end(Container<Tt> *end_container, size_t count)
{
	Container<Tt> *start_container, *run_pointer = end_container;
	count++;
	
	for(size_t i = 0; (i < count) && (run_pointer->pos_type != FIRST); i++)
	{
		run_pointer = run_pointer->prev;
	}
	start_container = run_pointer;
	
	return list_erase_some_elements<Tt>(start_container, end_container);
}

template<typename Tt>
size_t
flame_ide::templates::
list_erase_some_elements(Container<Tt> *start_container,
						 Container<Tt> *end_container)
{
	size_t count_deleted = 0;
	Container<Tt> *run_pointer = start_container->next;
	while(run_pointer != end_container)
	{
		run_pointer = run_pointer->next;
		delete run_pointer->prev;
		
		count_deleted++;
	}
	
	if(start_container->next != end_container
	  && end_container->prev != start_container)
	{
		list_link_containers<Tt>(start_container, end_container);
	}
	return count_deleted;
}

template<typename Tt> inline // только вот откуда куда копируем?
void
flame_ide::templates::
list_copy(const Container<Tt> *start_from, const Container<Tt> *end_from,
		  Container<Tt> *start_to, Container<Tt> *end_to)
{
	Container<Tt> *run_pointer_from = start_from->next,
			*run_pointer_to = start_to;
	
	while(run_pointer_from != end_from)
	{
		Container<Tt> *new_elem = new Container<Tt>(*run_pointer_from);
		
		list_link_containers<Tt>(run_pointer_to, new_elem);
		
		run_pointer_to = run_pointer_to->next;
		run_pointer_from = run_pointer_from->next;
	}
	
	list_link_containers<Tt>(run_pointer_to, end_to);
}

template<typename Tt>
void
flame_ide::templates::
list_link_containers(Container<Tt> *container_prev, Container<Tt> *container_next)
{
	container_prev->next = container_next;
	container_next->prev = container_prev;
}

#endif // TEMPLATES_FUNCTIONS

