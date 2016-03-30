#ifndef TEMPLATES_ArrayBlocks_ITERATORS
#define TEMPLATES_ArrayBlocks_ITERATORS

#include <Templates/BasicIterator.h>
#include <Templates/SimpleArray.h>

namespace flame_ide
{namespace templates
{

template<typename T> class ArrayBlocks;
template<typename T> class ArrayBlocksIterator;
template<typename T> class ArrayBlocksReverseIterator;

template<typename T>
class ArrayBlocksIterator
	: public BasicIterator<SimpleArrayIterator<T>, T>
{
protected:
	mutable ArrayBlocks<T> *inc_block;
public:
	friend class ArrayBlocks<T>;
	typedef ArrayBlocksIterator<T> my_type;
	typedef ArrayBlocksReverseIterator<T> friend_type;
	
	ArrayBlocksIterator();
	ArrayBlocksIterator(ArrayBlocksIterator<T> &&iterator);
	ArrayBlocksIterator(const ArrayBlocksIterator<T> &iterator);
	
	~ArrayBlocksIterator() = default;
	
	inline my_type& operator =(const my_type &iterator);
	inline my_type& operator =(my_type &&iterator);
	
	inline const my_type& operator =(const my_type &iterator) const;
	inline const my_type& operator =(my_type &&iterator)      const;
	
	virtual T& operator *()  const noexcept;
	virtual T* operator ->() const noexcept;
	
	inline my_type& operator ++();
	inline my_type& operator --();
	
	inline const my_type& operator ++() const;
	inline const my_type& operator --() const;
	
	
	inline my_type& operator ++(int);
	inline my_type& operator --(int);
	
	inline const my_type& operator ++(int) const;
	inline const my_type& operator --(int) const;
	
	// надо подумать, как с ними быть	
//	template<class TSizeType>
//	inline const my_type& operator -(TSizeType dimer);
//	template<class TSizeType>
//	inline const my_type& operator -(TSizeType dimer) const;
	
	
//	template<class TSizeType>
//	inline const my_type& operator +(TSizeType adder);
//	template<class TSizeType>
//	inline const my_type& operator +(TSizeType adder) const;
	
	template<typename Tt> friend
	bool operator ==(const ArrayBlocksIterator<Tt> &iter1,
	                 const ArrayBlocksIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const ArrayBlocksIterator<Tt> &iter1,
	                 const ArrayBlocksIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const ArrayBlocksIterator<Tt> &iter1,
	                 const ArrayBlocksReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const ArrayBlocksIterator<Tt> &iter1,
	                 const ArrayBlocksReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const ArrayBlocksReverseIterator<Tt> &iter1,
	                 const ArrayBlocksIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const ArrayBlocksReverseIterator<Tt> &iter1,
	                 const ArrayBlocksIterator<Tt> &iter2);
};

template<typename T>
class ArrayBlocksReverseIterator
	: public BasicReverseIterator<SimpleArrayReverseIterator<T>, T>
{
protected:
	mutable ArrayBlocks<T> *inc_block;
    
public:
	friend class ArrayBlocks<T>;
	typedef ArrayBlocksReverseIterator<T> my_type;
	typedef ArrayBlocksIterator<T> friend_type;
	
	ArrayBlocksReverseIterator();
	ArrayBlocksReverseIterator(ArrayBlocksReverseIterator<T> &&iterator);
	ArrayBlocksReverseIterator(const ArrayBlocksReverseIterator<T> &iterator);
	
	~ArrayBlocksReverseIterator() = default;
	
	inline const my_type& operator =(const my_type &iterator);
	inline const my_type& operator =(my_type &&iterator);
	
	inline const my_type& operator =(const my_type &iterator) const;
	inline const my_type& operator =(my_type &&iterator)      const;
	
	virtual T& operator *()  const noexcept;
	virtual T* operator ->() const noexcept;
	
	inline const my_type& operator ++();
	inline const my_type& operator --();
	
	inline const my_type& operator ++() const;
	inline const my_type& operator --() const;
	
	
	inline const my_type& operator ++(int);
	inline const my_type& operator --(int);
	
	inline const my_type& operator ++(int) const;
	inline const my_type& operator --(int) const;
	
	
	// надо подумать, как с ними быть	
//	template<class TSizeType>
//	inline const my_type& operator -(TSizeType dimer);
//	template<class TSizeType>
//	inline const my_type& operator -(TSizeType dimer) const;
	
	
//	template<class TSizeType>
//	inline const my_type& operator +(TSizeType adder);
//	template<class TSizeType>
//	inline const my_type& operator +(TSizeType adder) const;
	
	
	template<typename Tt> friend
	bool operator ==(const ArrayBlocksReverseIterator<Tt> &iter1,
	                 const ArrayBlocksReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const ArrayBlocksReverseIterator<Tt> &iter1,
	                 const ArrayBlocksReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const ArrayBlocksReverseIterator<Tt> &iter1,
	                 const ArrayBlocksIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const ArrayBlocksReverseIterator<Tt> &iter1,
	                 const ArrayBlocksIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const ArrayBlocksIterator<Tt> &iter1,
	                 const ArrayBlocksReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const ArrayBlocksIterator<Tt> &iter1,
	                 const ArrayBlocksReverseIterator<Tt> &iter2);	
};

// ArrayBlocksIterator

template<typename T>
ArrayBlocksIterator<T>::ArrayBlocksIterator()
	: BasicIterator<SimpleArrayIterator<T>, T>()
	,inc_block(nullptr)
{}

template<typename T>
ArrayBlocksIterator<T>::ArrayBlocksIterator(
	ArrayBlocksIterator<T> &&iterator)
	: BasicIterator<SimpleArrayIterator<T>, T>(iterator)
	,inc_block(iterator.inc_block)
{}

template<typename T>
ArrayBlocksIterator<T>::ArrayBlocksIterator(
	const ArrayBlocksIterator<T> &iterator)
	: BasicIterator<SimpleArrayIterator<T>, T>(iterator)
	,inc_block(iterator.inc_block)
{}

template<class T>
ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator =(ArrayBlocksIterator<T> &&iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator =(const ArrayBlocksIterator<T> &iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator =(ArrayBlocksIterator<T> &&iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator =(const ArrayBlocksIterator<T> &iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<typename T>
T&
ArrayBlocksIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
T*
ArrayBlocksIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator.operator ->();
}

template<typename T>
ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator ++()
{
	++(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()))
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_begin();
	}
	return *this;
}
template<typename T>
ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator --()
{
	--(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = --(inc_block->_block_simple_end());
	}
	return *this;
}

template<typename T>
const ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator ++() const
{
	++(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_begin();
	}
	return *this;
}
template<typename T>
const ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator --() const
{
	--(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = --(inc_block->_block_simple_end());
	}
	return *this;
}

template<typename T>
ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator ++(int)
{
	this->inc_data_iterator++;
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_begin();
	}
	return *this;
}
template<typename T>
ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator --(int)
{
	this->inc_data_iterator--;
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = (inc_block->_block_simple_end())--;
	}
	return *this;
}

template<typename T>
const ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator ++(int) const
{
	this->inc_data_iterator++;
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_begin();
	}
	return *this;
}
template<typename T>
const ArrayBlocksIterator<T>&
ArrayBlocksIterator<T>::operator --(int) const
{
	this->inc_data_iterator--;
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = (inc_block->_block_simple_end())--;
	}
	return *this;
}


// ArrayBlocksReverseIterator

template<typename T>
ArrayBlocksReverseIterator<T>::ArrayBlocksReverseIterator()
	: BasicReverseIterator<SimpleArrayReverseIterator<T>, T>()
	,inc_block(nullptr)
{}

template<typename T>
ArrayBlocksReverseIterator<T>::ArrayBlocksReverseIterator(
	ArrayBlocksReverseIterator<T> &&iterator)
		: BasicReverseIterator<SimpleArrayReverseIterator<T>, T>(iterator)
		,inc_block(iterator.inc_block)
{}

template<typename T>
ArrayBlocksReverseIterator<T>::ArrayBlocksReverseIterator(
	const ArrayBlocksReverseIterator<T> &iterator)
	: BasicReverseIterator<SimpleArrayReverseIterator<T>, T>(iterator)
	,inc_block(iterator.inc_block)
{}

template<class T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator =(
	ArrayBlocksReverseIterator<T> &&iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator =(
	const ArrayBlocksReverseIterator<T> &iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator =(
	ArrayBlocksReverseIterator<T> &&iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator =(
	const ArrayBlocksReverseIterator<T> &iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<typename T>
T&
ArrayBlocksReverseIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
T*
ArrayBlocksReverseIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator.operator ->();
}

template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator ++()
{
	++(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_rbegin();
	}
	return *this;
}
template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator --()
{
	--(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = --(inc_block->_block_simple_rend());
	}
	return *this;
}

template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator ++() const
{
	++(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_rbegin();
	}
	return *this;
}
template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator --() const
{
	--(this->inc_data_iterator);
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = --(inc_block->_block_simple_end());
	}
	return *this;
}

template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator ++(int)
{
	this->inc_data_iterator++;
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_rbegin();
	}
	return *this;
}
template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator --(int)
{
	this->inc_data_iterator--;
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = (inc_block->_block_simple_rend())--;
	}
	return *this;
}

template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator ++(int) const
{
	this->inc_data_iterator++;
	if(this->inc_data_iterator == inc_block->_block_simple_rend()
	   && inc_block->prev_block.isInitialized()
	   && !(inc_block->prev_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getPrev().operator ->();
		this->inc_data_iterator = inc_block->_block_simple_rbegin();
	}
	return *this;
}
template<typename T>
const ArrayBlocksReverseIterator<T>&
ArrayBlocksReverseIterator<T>::operator --(int) const
{
	this->inc_data_iterator--;
	if(this->inc_data_iterator == inc_block->_block_simple_end()
	   && inc_block->next_block.isInitialized()
	   && !(inc_block->next_block->_block_simple_isEmpty()) )
	{
		inc_block = inc_block->_block_getNext().operator ->();
		this->inc_data_iterator = (inc_block->_block_simple_end())--;
	}
	return *this;
}

// operators

template<typename T> inline
bool
operator ==(const ArrayBlocksIterator<T> &it1,
			const ArrayBlocksIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const ArrayBlocksIterator<T> &it1,
			const ArrayBlocksIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

template<typename T> inline
bool
operator ==(const ArrayBlocksReverseIterator<T> &it1,
			const ArrayBlocksReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const ArrayBlocksReverseIterator<T> &it1,
			const ArrayBlocksReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

// hybrid operators

template<typename T> inline
bool
operator ==(const ArrayBlocksIterator<T> &it1,
			const ArrayBlocksReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const ArrayBlocksIterator<T> &it1,
			const ArrayBlocksReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

template<typename T> inline
bool
operator ==(const ArrayBlocksReverseIterator<T> &it1,
			const ArrayBlocksIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const ArrayBlocksReverseIterator<T> &it1,
			const ArrayBlocksIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

}}

#endif // TEMPLATES_ArrayBlocks_ITERATORS
