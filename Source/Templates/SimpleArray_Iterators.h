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
	using BasicIterator<T,T>::operator ++;
	using BasicIterator<T,T>::operator --;
	
public:
	SimpleArrayIterator();
	SimpleArrayIterator(SimpleArrayIterator<T> &&iterator);
	SimpleArrayIterator(const SimpleArrayIterator<T> &iterator);
	
	~SimpleArrayIterator() = default;
	
	friend class SimpleArray<T>;
	typedef SimpleArrayIterator<T> my_type;
	typedef SimpleArrayReverseIterator<T> friend_type;
	
	virtual T&  operator *()  const noexcept;
	virtual T*& operator ->() const noexcept;
	
	inline const my_type& operator ++();
	inline const my_type& operator --();
	
	inline const my_type& operator ++() const;
	inline const my_type& operator --() const;
	
	
	inline const my_type& operator ++(int);
	inline const my_type& operator --(int);
	
	inline const my_type& operator ++(int) const;
	inline const my_type& operator --(int) const;
	
	template<class TSizeType>
	inline const my_type& operator -(TSizeType dimer);
	template<class TSizeType>
	inline const my_type& operator -(TSizeType dimer) const;
	
	template<class TSizeType>
	inline const my_type& operator +(TSizeType adder);
	template<class TSizeType>
	inline const my_type& operator +(TSizeType adder) const;
	
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
	bool operator ==(const friend_type &iter1,
	                 const my_type &iter2);
	template<T> friend
	bool operator !=(const friend_type &iter1,
	                 const my_type &iter2);
};

template<class T>
class SimpleArrayReverseIterator : public BasicReverseIterator<T, T>
{
	using BasicReverseIterator<T,T>::operator ++;
	using BasicReverseIterator<T,T>::operator --;
	
public:
	SimpleArrayReverseIterator();
	SimpleArrayReverseIterator(SimpleArrayReverseIterator<T> &&iterator);
	SimpleArrayReverseIterator(const SimpleArrayReverseIterator<T> &iterator);
	
	~SimpleArrayReverseIterator() = default;
	
	friend class SimpleArray<T>;
	typedef SimpleArrayReverseIterator<T> my_type;
	typedef SimpleArrayIterator<T> friend_type;
	
	virtual inline T&  operator *()  const noexcept;
	virtual inline T*& operator ->() const noexcept;
	
	const SimpleArrayReverseIterator<T>& operator =
	     (SimpleArrayReverseIterator<T> &&iterator);
  
	const SimpleArrayReverseIterator<T>& operator =
	     (const SimpleArrayReverseIterator<T> &iterator);
	
	inline const my_type& operator ++();
	inline const my_type& operator --();
	
	inline const my_type& operator ++() const;
	inline const my_type& operator --() const;
	
	
	inline const my_type& operator ++(int);
	inline const my_type& operator --(int);
	
	inline const my_type& operator ++(int) const;
	inline const my_type& operator --(int) const;
	
	
	template<class TSizeType>
	inline const my_type& operator -(TSizeType dimer);
	template<class TSizeType>
	inline const my_type& operator -(TSizeType dimer) const;
	
	template<class TSizeType>
	inline const my_type& operator +(TSizeType adder);
	template<class TSizeType>
	inline const my_type& operator +(TSizeType adder) const;
	
	
	template<T> friend
	bool operator ==(const my_type &iter1,
	                 const my_type &iter2);
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
};


template<class T> inline
bool operator ==(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
template<class T> inline
bool operator !=(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);


template<class T> inline
bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
                 const SimpleArrayReverseIterator<T> &iter2);
template<class T> inline
bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
                 const SimpleArrayReverseIterator<T> &iter2);


template<class T> inline
bool operator ==(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);
template<class T> inline
bool operator !=(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);


template<class T> inline
bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
template<class T> inline
bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);

template<class T, class TSizeType> inline
SimpleArrayIterator<T>& operator +(SimpleArrayIterator<T> &it,
								   size_t adder);	
template<class T, class TSizeType> inline
SimpleArrayIterator<T>& operator +(size_t adder,
								   SimpleArrayIterator<T> &it);


template<class T, class TSizeType> inline
SimpleArrayIterator<T>& operator -(SimpleArrayIterator<T> &it,
								   size_t dimer);	
template<class T, class TSizeType> inline
SimpleArrayIterator<T>& operator -(size_t dimer,
								   SimpleArrayIterator<T> &it);


template<class T, class TSizeType> inline
SimpleArrayReverseIterator<T>& operator +(SimpleArrayIterator<T> &it,
										  size_t adder);	
template<class T, class TSizeType> inline
SimpleArrayReverseIterator<T>& operator +(size_t adder,
										  SimpleArrayReverseIterator<T> &it);


template<class T, class TSizeType> inline
SimpleArrayReverseIterator<T>& operator -(SimpleArrayReverseIterator<T> &it,
										  size_t dimer);	
template<class T, class TSizeType> inline
SimpleArrayReverseIterator<T>& operator -(size_t dimer,
										  SimpleArrayReverseIterator<T> &it);


// ============================================================================
// SimpleArrayIterator

template<class T>
SimpleArrayIterator<T>::SimpleArrayIterator()
	: BasicIterator<T, T>()
{}

template<class T>
SimpleArrayIterator<T>
	::SimpleArrayIterator(SimpleArrayIterator<T> &&iterator)
		: BasicIterator<T, T>(iterator)
{}

template<class T>
SimpleArrayIterator<T>
	::SimpleArrayIterator(const SimpleArrayIterator<T> &iterator)
		: BasicIterator<T, T>(iterator)
{}

template<class T>
T&
SimpleArrayIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<class T>
T*&
SimpleArrayIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator;
}

template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++()
{
	this->BasicIterator<T,T>::operator ++();
	return *this;
}
template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++() const
{
	this->BasicIterator<T,T>::operator ++();
	return *this;
}

template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --() const
{
	this->BasicIterator<T,T>::operator --();
	return *this;
}
template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --()
{
	this->BasicIterator<T,T>::operator --();
	return *this;
}

template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++(int)
{
	this->BasicIterator<T,T>::operator ++();
	return *this;
}
template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++(int) const
{
	this->BasicIterator<T,T>::operator ++();
	return *this;
}

template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --(int)
{
	this->BasicIterator<T,T>::operator --();
	return *this;
}
template<class T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --(int) const
{
	this->BasicIterator<T,T>::operator --();
	return *this;
}

template<class T>
bool
operator ==(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool
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
T&
SimpleArrayReverseIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<class T>
T*&
SimpleArrayReverseIterator<T>::operator ->() const noexcept
{
	return (this->inc_data_iterator);
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++()
{
	this->BasicReverseIterator<T,T>::operator ++();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --()
{
	this->BasicReverseIterator<T,T>::operator --();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++() const
{
	this->BasicReverseIterator<T,T>::operator ++();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --() const
{
	this->BasicReverseIterator<T,T>::operator --();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++(int)
{
	this->BasicReverseIterator<T,T>::operator ++();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --(int)
{
	this->BasicReverseIterator<T,T>::operator --();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++(int) const
{
	this->BasicReverseIterator<T,T>::operator ++();
	return *this;
}

template<class T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --(int) const
{
	this->BasicReverseIterator<T,T>::operator --();
	return *this;
}

template<class T>
bool
operator ==(const SimpleArrayReverseIterator<T> &iter1,
            const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.operator ->() == iter2.operator ->());
}

template<class T>
bool
operator !=(const SimpleArrayReverseIterator<T> &iter1,
            const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.operator ->() != iter2.operator ->());
}


// ============================================================================
// Hibrid compare operators

template<class T>
bool
operator ==(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool
operator !=(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}

template<class T>
bool
operator ==(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<class T>
bool
operator !=(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}

// ============================================================================
// Add and dim operators


template<class T>
template<class TSizeType>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator +(TSizeType adder)
{
	this->inc_data_iterator += adder;
	
	return *this;
}
template<class T>
template<class TSizeType>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator +(TSizeType adder) const
{
	this->inc_data_iterator += adder;
	
	return *this;
}

template<class T>
template<class TSizeType>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator -(TSizeType dimer)
{
	this->inc_data_iterator -= dimer;
	
	return *this;
}
template<class T>
template<class TSizeType>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator -(TSizeType dimer) const
{
	this->inc_data_iterator -= dimer;
	
	return *this;
}


template<class T>
template<class TSizeType>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator +(TSizeType adder)
{
	this->inc_data_iterator -= adder;
	
	return *this;
}
template<class T>
template<class TSizeType>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator +(TSizeType adder) const
{
	this->inc_data_iterator -= adder;
	
	return *this;
}

template<class T>
template<class TSizeType>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator -(TSizeType dimer)
{
	this->inc_data_iterator += dimer;
	
	return *this;
}
template<class T>
template<class TSizeType>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator -(TSizeType dimer) const
{
	this->inc_data_iterator += dimer;
	
	return *this;
}

}}

#endif // TEMPLATES_SIMPLEARRAY_ITERATORS

