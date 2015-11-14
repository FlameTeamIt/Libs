#ifndef TEMPLATES_SIMPLEARRAY_ITERATORS
#define TEMPLATES_SIMPLEARRAY_ITERATORS

#include <Templates/BasicIterator.h>

namespace flame_ide
{namespace templates
{

template<class T> class SimpleArrayIterator;
template<class T> class SimpleArrayReverseIterator;
template<class T> class SimpleArray;

template<class T>
class SimpleArrayIterator : public BasicIterator<T, T>
{
public:
	SimpleArrayIterator();
	SimpleArrayIterator(SimpleArrayIterator &&iterator);
	SimpleArrayIterator(const SimpleArrayIterator &iterator);
	
	~SimpleArrayIterator() = default;
	
	const T& operator *() const noexcept;
	      T& operator *()       noexcept;
		  
	const T* operator ->() const noexcept;
	      T* operator ->()       noexcept;
	
	friend class SimpleArray<T>;
	
	template<T> friend
	bool operator ==(const SimpleArrayIterator<T> &iter1,
					 const SimpleArrayIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayIterator<T> &iter1,
					 const SimpleArrayIterator<T> &iter2);
	
	
	template<T> friend
	bool operator ==(const SimpleArrayIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	
	template<T> friend
	bool operator== (const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayIterator<T> &iter2);
};

template<class T>
class SimpleArrayReverseIterator : public BasicReverseIterator<T, T>
{
	SimpleArrayReverseIterator();
	SimpleArrayReverseIterator(SimpleArrayReverseIterator<T> &&iterator);
	SimpleArrayReverseIterator(const SimpleArrayReverseIterator<T> &iterator);
	
	~SimpleArrayReverseIterator() = default;
	
	const inline T& operator *() const noexcept;
	      inline T& operator *()       noexcept;
		  
	const inline T* operator ->() const noexcept;
	      inline T* operator ->()       noexcept;
	
	const SimpleArrayReverseIterator<T>& operator =
		(SimpleArrayReverseIterator<T> &&iterator);
  
	const SimpleArrayReverseIterator<T>& operator =
		(const SimpleArrayReverseIterator<T> &iterator);
	
	friend class SimpleArray<T>;
	
	template<T> friend
	bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	
	
	template<T> friend
	bool operator ==(const SimpleArrayIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	
	
	template<T> friend
	bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayIterator<T> &iter2);
};


template<class T>
bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);
template<class T>
bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);


template<class T>
bool operator ==(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
template<class T>
bool operator !=(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);


template<class T>
bool operator ==(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);
template<class T>
bool operator !=(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);


template<class T>
bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
template<class T>
bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
}}

using flame_ide::templates::BasicIterator;
using flame_ide::templates::BasicReverseIterator;

using flame_ide::templates::SimpleArrayIterator;
using flame_ide::templates::SimpleArrayReverseIterator;

// ============================================================================
// SimpleArrayIterator

template<class T>
SimpleArrayIterator<T>::SimpleArrayIterator()
	: BasicIterator<T, T>()
{}

template<class T>
SimpleArrayIterator<T>
	::SimpleArrayIterator(SimpleArrayIterator &&iterator)
		: BasicIterator<T, T>(iterator)
{}

template<class T>
SimpleArrayIterator<T>
	::SimpleArrayIterator(const SimpleArrayIterator &iterator)
		: BasicIterator<T, T>(iterator)
{}

template<class T>
const T&
SimpleArrayIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}
template<class T>
T&
SimpleArrayIterator<T>::operator *() noexcept
{
	return *(this->inc_data_iterator);
}

template<class T>
const T*
SimpleArrayIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator;
}
template<class T>
T*
SimpleArrayIterator<T>::operator ->() noexcept
{
	return this->inc_data_iterator;
}

template<class T>
bool flame_ide::templates::
operator ==(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool flame_ide::templates::
operator !=(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.operator ->() != iter2.operator ->());
}

// ============================================================================
// SimpleArrayReverseIterator

template<class T>
SimpleArrayReverseIterator<T>::SimpleArrayReverseIterator()
	: BasicReverseIterator<T, T>()
{}

template<class T>
SimpleArrayReverseIterator<T>
	::SimpleArrayReverseIterator(SimpleArrayReverseIterator &&iterator)
		: BasicReverseIterator<T, T>(iterator)
{}

template<class T>
SimpleArrayReverseIterator<T>
	::SimpleArrayReverseIterator(const SimpleArrayReverseIterator &iterator)
		: BasicReverseIterator<T, T>(iterator)
{}

template<class T>
const T&
SimpleArrayReverseIterator<T>::operator *() const noexcept
{
	return this->inc_data_iterator;
}
template<class T>
T&
SimpleArrayReverseIterator<T>::operator *() noexcept
{
	return this->inc_data_iterator;
}

template<class T>
const T*
SimpleArrayReverseIterator<T>::operator ->() const noexcept
{
	return *(this->inc_data_iterator);
}
template<class T>
T*
SimpleArrayReverseIterator<T>::operator ->() noexcept
{
	return *(this->inc_data_iterator);
}


template<class T>
bool flame_ide::templates::
operator ==(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool flame_ide::templates::
operator !=(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}


// ============================================================================
// Hibrid compare operators

template<class T>
bool flame_ide::templates::
operator ==(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool flame_ide::templates::
operator !=(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}

template<class T>
bool flame_ide::templates::
operator ==(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool flame_ide::templates::
operator !=(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}


#endif // TEMPLATES_SIMPLEARRAY_ITERATORS

