#ifndef TEMPLATES_SIMPLEARRAY_ITERATORS
#define TEMPLATES_SIMPLEARRAY_ITERATORS

#include <Templates/BasicIterator.h>

//typedef unsigned long size_t;

namespace flame_ide
{namespace templates
{

template<typename T> class SimpleArrayIterator;
template<typename T> class SimpleArrayReverseIterator;
template<typename T> class SimpleArray;

template<typename T>
class SimpleArrayIterator : public BasicIterator<T*, T>
{
	using BasicIterator<T*,T>::operator ++;
	using BasicIterator<T*,T>::operator --;
	
public:
	SimpleArrayIterator();
	SimpleArrayIterator(SimpleArrayIterator<T> &&iterator);
	SimpleArrayIterator(const SimpleArrayIterator<T> &iterator);
	
	~SimpleArrayIterator() = default;
	
	friend class SimpleArray<T>;
	typedef SimpleArrayIterator<T> my_type;
	typedef SimpleArrayReverseIterator<T> friend_type;
	
	
	inline my_type& operator =(my_type &iterator)  noexcept;
	inline my_type& operator =(my_type &&iterator) noexcept;
	
	inline const my_type& operator =(const my_type &iterator) const noexcept;
	inline const my_type& operator =(my_type &&iterator)      const noexcept;
	
	
	inline my_type& operator =(friend_type &iterator)  noexcept;
	inline my_type& operator =(friend_type &&iterator) noexcept;
	
	inline const my_type& operator =(const friend_type &iterator) const noexcept;
	inline const my_type& operator =(friend_type &&iterator)      const noexcept;
	
	
	virtual T& operator *()  noexcept;
	virtual T* operator ->() noexcept;
	
	virtual const T& operator *()  const noexcept;
	virtual const T* operator ->() const noexcept;
	
	
	inline my_type& operator ++();
	inline my_type& operator --();
	
	inline const my_type& operator ++() const;
	inline const my_type& operator --() const;
	
	
	inline my_type& operator ++(int);
	inline my_type& operator --(int);
	
	inline const my_type& operator ++(int) const;
	inline const my_type& operator --(int) const;
	
	template<typename TSizeType>
	inline my_type& operator -(TSizeType dimer);
	template<typename TSizeType>
	inline const my_type& operator -(TSizeType dimer) const;
	
	template<typename TSizeType>
	inline my_type& operator +(TSizeType adder);
	template<typename TSizeType>
	inline const my_type& operator +(TSizeType adder) const;
	
	template<typename Tt> friend
	bool operator ==(const SimpleArrayIterator<Tt> &iter1,
	                 const SimpleArrayIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const SimpleArrayIterator<Tt> &iter1,
	                 const SimpleArrayIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const SimpleArrayIterator<Tt> &iter1,
	                 const SimpleArrayReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const SimpleArrayIterator<Tt> &iter1,
	                 const SimpleArrayReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const SimpleArrayReverseIterator<Tt> &iter1,
	                 const SimpleArrayIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const SimpleArrayReverseIterator<Tt> &iter1,
	                 const SimpleArrayIterator<Tt> &iter2);
};

template<typename T>
class SimpleArrayReverseIterator : public BasicReverseIterator<T*, T>
{
	using BasicReverseIterator<T*,T>::operator ++;
	using BasicReverseIterator<T*,T>::operator --;
	
public:
	SimpleArrayReverseIterator();
	SimpleArrayReverseIterator(SimpleArrayReverseIterator<T> &&iterator);
	SimpleArrayReverseIterator(const SimpleArrayReverseIterator<T> &iterator);
	
	~SimpleArrayReverseIterator() = default;
	
	friend class SimpleArray<T>;
	typedef SimpleArrayReverseIterator<T> my_type;
	typedef SimpleArrayIterator<T> friend_type;
	
	
	inline my_type& operator =(my_type &iterator) noexcept;
	inline my_type& operator =(my_type &&iterator) noexcept;
	
	inline const my_type& operator =(const my_type &iterator) const noexcept;
	inline const my_type& operator =(my_type &&iterator)      const noexcept;
	
	
	inline my_type& operator =(friend_type &iterator) noexcept;
	inline my_type& operator =(friend_type &&iterator) noexcept;
	
	inline const my_type& operator =(const friend_type &iterator) const noexcept;
	inline const my_type& operator =(friend_type &&iterator)      const noexcept;
	
	
	virtual T& operator *()  noexcept;
	virtual T* operator ->() noexcept;
	
	virtual const T& operator *()  const noexcept;
	virtual const T* operator ->() const noexcept;
	
	
	inline my_type& operator ++();
	inline my_type& operator --();
	
	inline const my_type& operator ++() const;
	inline const my_type& operator --() const;
	
	
	inline my_type& operator ++(int);
	inline my_type& operator --(int);
	
	inline const my_type& operator ++(int) const;
	inline const my_type& operator --(int) const;
	
	
	template<typename TSizeType>
	inline my_type& operator -(TSizeType dimer);
	template<typename TSizeType>
	inline const my_type& operator -(TSizeType dimer) const;
	
	template<typename TSizeType>
	inline my_type& operator +(TSizeType adder);
	template<typename TSizeType>
	inline const my_type& operator +(TSizeType adder) const;
	
	
	template<typename Tt> friend
	bool operator ==(const SimpleArrayReverseIterator<Tt> &iter1,
	                 const SimpleArrayReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const SimpleArrayReverseIterator<Tt> &iter1,
	                 const SimpleArrayReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const SimpleArrayIterator<Tt> &iter1,
	                 const SimpleArrayReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const SimpleArrayIterator<Tt> &iter1,
	                 const SimpleArrayReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const SimpleArrayReverseIterator<Tt> &iter1,
	                 const SimpleArrayIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const SimpleArrayReverseIterator<Tt> &iter1,
	                 const SimpleArrayIterator<Tt> &iter2);
};


template<typename T> inline
bool operator ==(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
template<typename T> inline
bool operator !=(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);


template<typename T> inline
bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
                 const SimpleArrayReverseIterator<T> &iter2);
template<typename T> inline
bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
                 const SimpleArrayReverseIterator<T> &iter2);


template<typename T> inline
bool operator ==(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);
template<typename T> inline
bool operator !=(const SimpleArrayIterator<T> &iter1,
				 const SimpleArrayReverseIterator<T> &iter2);


template<typename T> inline
bool operator ==(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);
template<typename T> inline
bool operator !=(const SimpleArrayReverseIterator<T> &iter1,
				 const SimpleArrayIterator<T> &iter2);

template<typename T, typename TSizeType> inline
SimpleArrayIterator<T>& operator +(SimpleArrayIterator<T> &it,
								   size_t adder);	
template<typename T, typename TSizeType> inline
SimpleArrayIterator<T>& operator +(size_t adder,
								   SimpleArrayIterator<T> &it);


template<typename T, typename TSizeType> inline
SimpleArrayIterator<T>& operator -(SimpleArrayIterator<T> &it,
								   size_t dimer);	
template<typename T, typename TSizeType> inline
SimpleArrayIterator<T>& operator -(size_t dimer,
								   SimpleArrayIterator<T> &it);


template<typename T, typename TSizeType> inline
SimpleArrayReverseIterator<T>& operator +(SimpleArrayIterator<T> &it,
										  size_t adder);	
template<typename T, typename TSizeType> inline
SimpleArrayReverseIterator<T>& operator +(size_t adder,
										  SimpleArrayReverseIterator<T> &it);


template<typename T, typename TSizeType> inline
SimpleArrayReverseIterator<T>& operator -(SimpleArrayReverseIterator<T> &it,
										  size_t dimer);	
template<typename T, typename TSizeType> inline
SimpleArrayReverseIterator<T>& operator -(size_t dimer,
										  SimpleArrayReverseIterator<T> &it);


// ============================================================================
// SimpleArrayIterator

template<typename T>
SimpleArrayIterator<T>::SimpleArrayIterator()
	: BasicIterator<T*, T>()
{}

template<typename T>
SimpleArrayIterator<T>
	::SimpleArrayIterator(SimpleArrayIterator<T> &&iterator)
		: BasicIterator<T*, T>(iterator)
{}

template<typename T>
SimpleArrayIterator<T>
	::SimpleArrayIterator(const SimpleArrayIterator<T> &iterator)
		: BasicIterator<T*, T>(iterator)
{}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(SimpleArrayIterator<T> &&iterator) noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(SimpleArrayIterator<T> &iterator) noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(SimpleArrayIterator<T> &&iterator) const noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(const SimpleArrayIterator<T> &iterator)
const noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(SimpleArrayReverseIterator<T> &&iterator)
noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(SimpleArrayReverseIterator<T> &iterator)
noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(SimpleArrayReverseIterator<T> &&iterator) const
noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator =(const SimpleArrayReverseIterator<T> &iterator) const
noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
T&
SimpleArrayIterator<T>::operator *() noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
T*
SimpleArrayIterator<T>::operator ->() noexcept
{
	return this->inc_data_iterator;
}

template<typename T>
const T&
SimpleArrayIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
const T*
SimpleArrayIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator;
}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++()
{
	this->__operator_inc();
	return *this;
}
template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++() const
{
	this->__operator_inc();
	return *this;
}

template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --() const
{
	this->__operator_dec();
	return *this;
}
template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --()
{
	this->__operator_dec();
	return *this;
}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++(int)
{
	this->__operator_inc();
	return *this;
}
template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator ++(int) const
{
	this->__operator_inc();
	return *this;
}

template<typename T>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --(int)
{
	this->__operator_dec();
	return *this;
}
template<typename T>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator --(int) const
{
	this->__operator_dec();
	return *this;
}

template<typename T>
bool
operator ==(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<typename T>
bool
operator !=(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}

// ============================================================================
// SimpleArrayReverseIterator

template<typename T>
SimpleArrayReverseIterator<T>::SimpleArrayReverseIterator()
	: BasicReverseIterator<T*, T>()
{}

template<typename T>
SimpleArrayReverseIterator<T>
	::SimpleArrayReverseIterator(SimpleArrayReverseIterator<T> &&iterator)
		: BasicReverseIterator<T*, T>(iterator)
{}

template<typename T>
SimpleArrayReverseIterator<T>
	::SimpleArrayReverseIterator(const SimpleArrayReverseIterator<T> &iterator)
		: BasicReverseIterator<T*, T>(iterator)
{}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
	SimpleArrayReverseIterator<T> &&iterator) noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
	SimpleArrayReverseIterator<T> &iterator) noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
		SimpleArrayReverseIterator<T> &&iterator) const noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
	const SimpleArrayReverseIterator &iterator) const noexcept
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	return *this;
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
		SimpleArrayIterator<T> &&iterator) noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
		SimpleArrayIterator<T> &iterator) noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
		SimpleArrayIterator<T> &&iterator) const noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator =(
		const SimpleArrayIterator<T> &iterator) const noexcept
{
	this->inc_data_iterator = iterator.operator ->();
	return *this;
}

template<typename T>
T&
SimpleArrayReverseIterator<T>::operator *() noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
T*
SimpleArrayReverseIterator<T>::operator ->() noexcept
{
	return (this->inc_data_iterator);
} 

template<typename T>
const T&
SimpleArrayReverseIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
const T*
SimpleArrayReverseIterator<T>::operator ->() const noexcept
{
	return (this->inc_data_iterator);
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++()
{
	this->__operator_inc();
	return *this;
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --()
{
	this->__operator_dec();
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++() const
{
	this->__operator_inc();
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --() const
{
	this->__operator_dec();
	return *this;
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++(int)
{
	this->__operator_inc();
	return *this;
}

template<typename T>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --(int)
{
	this->__operator_dec();
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator ++(int) const
{
	this->__operator_inc();
	return *this;
}

template<typename T>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator --(int) const
{
	this->__operator_dec();
	return *this;
}

template<typename T>
bool
operator ==(const SimpleArrayReverseIterator<T> &iter1,
            const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<typename T>
bool
operator !=(const SimpleArrayReverseIterator<T> &iter1,
            const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}


// ============================================================================
// Hibrid compare operators

template<typename T>
bool
operator ==(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<typename T>
bool
operator !=(const SimpleArrayIterator<T> &iter1,
			const SimpleArrayReverseIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}

template<typename T>
bool
operator ==(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator == iter2.inc_data_iterator);
}

template<typename T>
bool
operator !=(const SimpleArrayReverseIterator<T> &iter1,
			const SimpleArrayIterator<T> &iter2)
{
	return (iter1.inc_data_iterator != iter2.inc_data_iterator);
}

// ============================================================================
// Add and dim operators


template<typename T>
template<typename TSizeType>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator +(TSizeType adder)
{
	this->inc_data_iterator += adder;
	
	return *this;
}
template<typename T>
template<typename TSizeType>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator +(TSizeType adder) const
{
	this->inc_data_iterator += adder;
	
	return *this;
}

template<typename T>
template<typename TSizeType>
SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator -(TSizeType dimer)
{
	this->inc_data_iterator -= dimer;
	
	return *this;
}
template<typename T>
template<typename TSizeType>
const SimpleArrayIterator<T>&
SimpleArrayIterator<T>::operator -(TSizeType dimer) const
{
	this->inc_data_iterator -= dimer;
	
	return *this;
}


template<typename T>
template<typename TSizeType>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator +(TSizeType adder)
{
	this->inc_data_iterator -= adder;
	
	return *this;
}
template<typename T>
template<typename TSizeType>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator +(TSizeType adder) const
{
	this->inc_data_iterator -= adder;
	
	return *this;
}

template<typename T>
template<typename TSizeType>
SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator -(TSizeType dimer)
{
	this->inc_data_iterator += dimer;
	
	return *this;
}
template<typename T>
template<typename TSizeType>
const SimpleArrayReverseIterator<T>&
SimpleArrayReverseIterator<T>::operator -(TSizeType dimer) const
{
	this->inc_data_iterator += dimer;
	
	return *this;
}

}}

#endif // TEMPLATES_SIMPLEARRAY_ITERATORS

