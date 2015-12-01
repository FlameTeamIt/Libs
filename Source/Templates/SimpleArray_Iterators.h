#ifndef TEMPLATES_SIMPLEARRAY_ITERATORS
#define TEMPLATES_SIMPLEARRAY_ITERATORS

#include <Templates/BasicIterator.h>

typedef unsigned long size_t;

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
	
	friend class SimpleArray<T>;
	typedef SimpleArrayIterator<T> my_type;
	typedef SimpleArrayReverseIterator<T> friend_type;
	
	const T& operator *() const noexcept;
	      T& operator *()       noexcept;
		  
	const T* operator ->() const noexcept;
	      T* operator ->()       noexcept;
	
	
	template<T> friend
	bool operator ==(const my_type &iter1,
	                 const my_type &iter2);
	template<T> friend
	bool operator !=(const my_type &iter1,
	                 const my_type &iter2);
	
	
	template<T> friend
	bool operator ==(const my_type &iter1,
	                 const friend_type &iter2);
	template<T> friend
	bool operator !=(const my_type &iter1,
	                 const friend_type &iter2);
	
	template<T> friend
	bool operator== (const friend_type &iter1,
	                 const my_type &iter2);
	template<T> friend
	bool operator !=(const friend_type &iter1,
	                 const my_type &iter2);
	
	template<T> friend
	my_type& operator +(const my_type &it, size_t adder);	
	template<T> friend
	my_type& operator +(size_t adder, const my_type &it);
	
	template<T> friend
	my_type& operator -(const my_type &it, size_t adder);	
	template<T> friend
	my_type& operator -(size_t adder, const my_type &it);
};

template<class T>
class SimpleArrayReverseIterator : public BasicReverseIterator<T, T>
{
public:
	SimpleArrayReverseIterator();
	SimpleArrayReverseIterator(SimpleArrayReverseIterator<T> &&iterator);
	SimpleArrayReverseIterator(const SimpleArrayReverseIterator<T> &iterator);
	
	~SimpleArrayReverseIterator() = default;
	
	friend class SimpleArray<T>;
	typedef SimpleArrayReverseIterator<T> my_type;
	typedef SimpleArrayIterator<T> friend_type;
	
	virtual const inline T& operator *() const noexcept;
	virtual       inline T& operator *()       noexcept;
		  
	virtual const inline T* operator ->() const noexcept;
	virtual       inline T* operator ->()       noexcept;
	
	const SimpleArrayReverseIterator<T>& operator =
		(SimpleArrayReverseIterator<T> &&iterator);
  
	const SimpleArrayReverseIterator<T>& operator =
		(const SimpleArrayReverseIterator<T> &iterator);
	
	template<T> friend
	bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	template<T> friend
	bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
					 const SimpleArrayReverseIterator<T> &iter2);
	
	
	template<T> friend
	bool operator ==(const friend_type &iter1,
					 const my_type &iter2);
	template<T> friend
	bool operator !=(const friend_type &iter1,
					 const my_type &iter2);
	
	template<T> friend
	bool operator ==(const my_type &iter1,
					 const friend_type &iter2);
	template<T> friend
	bool operator !=(const my_type &iter1,
					 const friend_type &iter2);
	
	template<T> friend
	my_type& operator +(const my_type &it, size_t adder);	
	template<T> friend
	my_type& operator +(size_t adder, const my_type &it);
	
	template<T> friend
	my_type& operator -(const my_type &it, size_t adder);	
	template<T> friend
	my_type& operator -(size_t adder, const my_type &it);
	
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

template<class T>
SimpleArrayIterator<T>& operator +(const SimpleArrayIterator<T> &it,
								   size_t adder);	
template<class T>
SimpleArrayIterator<T>& operator +(size_t adder,
								   const SimpleArrayIterator<T> &it);


template<class T>
SimpleArrayIterator<T>& operator -(const SimpleArrayIterator<T> &it,
								   size_t dimer);	
template<class T>
SimpleArrayIterator<T>& operator -(size_t dimer,
								   const SimpleArrayIterator<T> &it);


template<class T>
SimpleArrayReverseIterator<T>& operator +(const SimpleArrayIterator<T> &it,
										  size_t adder);	
template<class T>
SimpleArrayReverseIterator<T>& operator +(size_t adder,
										  const SimpleArrayReverseIterator<T> &it);


template<class T>
SimpleArrayReverseIterator<T>& operator -(const SimpleArrayReverseIterator<T> &it,
										  size_t dimer);	
template<class T>
SimpleArrayReverseIterator<T>& operator -(size_t dimer,
										  const SimpleArrayReverseIterator<T> &it);


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

// ============================================================================
// Add and dim operators


template<class T>
SimpleArrayIterator<T>& flame_ide::templates::
operator +(const SimpleArrayIterator<T> &it,
		   size_t adder)
{
	SimpleArrayIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator + adder;
	
	return ret_it;
}
template<class T>
SimpleArrayIterator<T>& flame_ide::templates::
operator +(size_t adder,
		   const SimpleArrayIterator<T> &it)
{
	SimpleArrayIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator + adder;
	
	return ret_it;
}

template<class T>
SimpleArrayIterator<T>& flame_ide::templates::
operator -(const SimpleArrayIterator<T> &it,
		   size_t dimer)
{
	SimpleArrayIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator - dimer;
	
	return ret_it;
}
template<class T>
SimpleArrayIterator<T>& flame_ide::templates::
operator -(size_t dimer,
		   const SimpleArrayIterator<T> &it)
{
	SimpleArrayIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator - dimer;
	
	return ret_it;
}

template<class T>
SimpleArrayReverseIterator<T>& flame_ide::templates::
operator +(const SimpleArrayIterator<T> &it,
		   size_t adder)
{
	SimpleArrayReverseIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator - adder;
	
	return ret_it;
}
template<class T>
SimpleArrayReverseIterator<T>& flame_ide::templates::
operator +(size_t adder,
		   const SimpleArrayReverseIterator<T> &it)
{
	SimpleArrayReverseIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator - adder;
	
	return ret_it;
}

template<class T>
SimpleArrayReverseIterator<T>& flame_ide::templates::
operator -(const SimpleArrayReverseIterator<T> &it,
		   size_t dimer)
{
	SimpleArrayReverseIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator + dimer;
	
	return ret_it;
}
template<class T>
SimpleArrayReverseIterator<T>& flame_ide::templates::
operator -(size_t dimer,
		   const SimpleArrayReverseIterator<T> &it)
{
	SimpleArrayReverseIterator<T> ret_it;
	ret_it.inc_data_iterator = it.inc_data_iterator + dimer;
	
	return ret_it;
}

#endif // TEMPLATES_SIMPLEARRAY_ITERATORS

