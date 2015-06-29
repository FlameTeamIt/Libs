#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

namespace flame_ide
{namespace templates
{

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
	Container(const Container<T> &container);
	Container(PosType position_type);
	Container(T* init_data, PosType position_type);
	Container(Container<T> *init_next, Container<T> *init_prev,
			  T* init_data, PosType position_type);
	
	~Container();
	
	// noexcept - гарантия отсуствия исключений
	// нужно писать и в шапке перед реализациейб как и const
	inline const Container<T> & operator =(const Container<T> &Container);
	inline bool operator ==(const Container<T> &container) const;
	inline bool operator !=(const Container<T> &container) const;
};

}}


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
Container<T>::Container(const Container<T> &container) : Container()
{
	pos_type = container.pos_type;
	inc_data = new T(*(container.inc_data));
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
		break;
	}
	inc_data = nullptr;
	pos_type = position_type;
}
template<typename T>
flame_ide::templates::
Container<T>::Container(T *init_data, PosType position_type)
	: Container(position_type)
{
	inc_data = init_data;
}
template<typename T>
flame_ide::templates::
Container<T>::Container(flame_ide::templates::Container<T> *init_next,
						flame_ide::templates::Container<T> *init_prev,
						T *init_data, flame_ide::templates::PosType position_type)
	: Container(init_data, position_type)
{
	this->next = init_next;
	this->prev = init_prev;
}

template<typename T>
flame_ide::templates::
Container<T>::~Container()
{
	if(inc_data != nullptr)
	{ delete inc_data;}
}

template<typename T>
const flame_ide::templates::Container<T> &
flame_ide::templates::
Container<T>::operator =(const flame_ide::templates::Container<T> &container)
{
	if(inc_data != nullptr)
	{
		delete this->inc_data;
	}
	this->inc_data = new T(*(container.inc_data));
	
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

#endif // LIST_FUNCTIONS_H

