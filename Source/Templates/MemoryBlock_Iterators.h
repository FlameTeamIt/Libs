#ifndef TEMPLATES_MEMORYBLOCK_ITERATORS
#define TEMPLATES_MEMORYBLOCK_ITERATORS

#include <Templates/BasicIterator.h>
#include <Templates/SimpleArray.h>

namespace flame_ide
{namespace templates
{

template<typename T> class MemoryBlock;
template<typename T> class MemoryBlockIterator;
template<typename T> class MemoryBlockReverseIterator;

template<typename T>
class MemoryBlockIterator
	: public BasicIterator<SimpleArrayIterator<T>, T>
{
protected:
	mutable MemoryBlock<T> *inc_block;
public:
	friend class MemoryBlock<T>;
	typedef MemoryBlockIterator<T> my_type;
	typedef MemoryBlockReverseIterator<T> friend_type;
	
	MemoryBlockIterator();
	MemoryBlockIterator(MemoryBlockIterator<T> &&iterator);
	MemoryBlockIterator(const MemoryBlockIterator<T> &iterator);
	
	~MemoryBlockIterator() = default;
	
	inline const my_type& operator =(const my_type &iterator);
	inline const my_type& operator =(my_type &&iterator);
	
	inline const my_type& operator =(const my_type &iterator) const;
	inline const my_type& operator =(my_type &&iterator)      const;
	
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
	bool operator ==(const MemoryBlockIterator<Tt> &iter1,
	                 const MemoryBlockIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const MemoryBlockIterator<Tt> &iter1,
	                 const MemoryBlockIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const MemoryBlockIterator<Tt> &iter1,
	                 const MemoryBlockReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const MemoryBlockIterator<Tt> &iter1,
	                 const MemoryBlockReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const MemoryBlockReverseIterator<Tt> &iter1,
	                 const MemoryBlockIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const MemoryBlockReverseIterator<Tt> &iter1,
	                 const MemoryBlockIterator<Tt> &iter2);
};

template<typename T>
class MemoryBlockReverseIterator
	: public BasicReverseIterator<SimpleArrayReverseIterator<T>, T>
{
protected:
	mutable MemoryBlock<T> *inc_block;
    
public:
	friend class MemoryBlock<T>;
	typedef MemoryBlockReverseIterator<T> my_type;
	typedef MemoryBlockIterator<T> friend_type;
	
	MemoryBlockReverseIterator();
	MemoryBlockReverseIterator(MemoryBlockReverseIterator<T> &&iterator);
	MemoryBlockReverseIterator(const MemoryBlockReverseIterator<T> &iterator);
	
	~MemoryBlockReverseIterator() = default;
	
	inline const my_type& operator =(const my_type &iterator);
	inline const my_type& operator =(my_type &&iterator);
	
	inline const my_type& operator =(const my_type &iterator) const;
	inline const my_type& operator =(my_type &&iterator)      const;
	
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
	bool operator ==(const MemoryBlockReverseIterator<Tt> &iter1,
	                 const MemoryBlockReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const MemoryBlockReverseIterator<Tt> &iter1,
	                 const MemoryBlockReverseIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const MemoryBlockReverseIterator<Tt> &iter1,
	                 const MemoryBlockIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const MemoryBlockReverseIterator<Tt> &iter1,
	                 const MemoryBlockIterator<Tt> &iter2);
	
	
	template<typename Tt> friend
	bool operator ==(const MemoryBlockIterator<Tt> &iter1,
	                 const MemoryBlockReverseIterator<Tt> &iter2);
	template<typename Tt> friend
	bool operator !=(const MemoryBlockIterator<Tt> &iter1,
	                 const MemoryBlockReverseIterator<Tt> &iter2);	
};

// MemoryBlockIterator

template<typename T>
MemoryBlockIterator<T>::MemoryBlockIterator()
	: BasicIterator<SimpleArrayIterator<T>, T>()
	,inc_block(nullptr)
{}

template<typename T>
MemoryBlockIterator<T>::MemoryBlockIterator(
	MemoryBlockIterator<T> &&iterator)
	: BasicIterator<SimpleArrayIterator<T>, T>(iterator)
	,inc_block(iterator.inc_block)
{}

template<typename T>
MemoryBlockIterator<T>::MemoryBlockIterator(
	const MemoryBlockIterator<T> &iterator)
	: BasicIterator<SimpleArrayIterator<T>, T>(iterator)
	,inc_block(iterator.inc_block)
{}

template<class T>
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator =(MemoryBlockIterator<T> &&iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator =(const MemoryBlockIterator<T> &iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator =(MemoryBlockIterator<T> &&iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator =(const MemoryBlockIterator<T> &iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<typename T>
T&
MemoryBlockIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
T*&
MemoryBlockIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator.operator ->();
}

template<typename T>
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator ++()
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator --()
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator ++() const
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator --() const
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator ++(int)
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator --(int)
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator ++(int) const
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
const MemoryBlockIterator<T>&
MemoryBlockIterator<T>::operator --(int) const
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


// MemoryBlockReverseIterator

template<typename T>
MemoryBlockReverseIterator<T>::MemoryBlockReverseIterator()
	: BasicReverseIterator<SimpleArrayReverseIterator<T>, T>()
	,inc_block(nullptr)
{}

template<typename T>
MemoryBlockReverseIterator<T>::MemoryBlockReverseIterator(
	MemoryBlockReverseIterator<T> &&iterator)
		: BasicReverseIterator<SimpleArrayReverseIterator<T>, T>(iterator)
		,inc_block(iterator.inc_block)
{}

template<typename T>
MemoryBlockReverseIterator<T>::MemoryBlockReverseIterator(
	const MemoryBlockReverseIterator<T> &iterator)
	: BasicReverseIterator<SimpleArrayReverseIterator<T>, T>(iterator)
	,inc_block(iterator.inc_block)
{}

template<class T>
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator =(
	MemoryBlockReverseIterator<T> &&iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator =(
	const MemoryBlockReverseIterator<T> &iterator)
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator =(
	MemoryBlockReverseIterator<T> &&iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<class T>
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator =(
	const MemoryBlockReverseIterator<T> &iterator) const
{
	this->inc_data_iterator = iterator.inc_data_iterator;
	this->inc_block = iterator.inc_block;
	return *this;
}

template<typename T>
T&
MemoryBlockReverseIterator<T>::operator *() const noexcept
{
	return *(this->inc_data_iterator);
}

template<typename T>
T*&
MemoryBlockReverseIterator<T>::operator ->() const noexcept
{
	return this->inc_data_iterator.operator ->();
}

template<typename T>
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator ++()
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator --()
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator ++() const
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator --() const
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator ++(int)
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator --(int)
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator ++(int) const
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
const MemoryBlockReverseIterator<T>&
MemoryBlockReverseIterator<T>::operator --(int) const
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
operator ==(const MemoryBlockIterator<T> &it1,
			const MemoryBlockIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const MemoryBlockIterator<T> &it1,
			const MemoryBlockIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

template<typename T> inline
bool
operator ==(const MemoryBlockReverseIterator<T> &it1,
			const MemoryBlockReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const MemoryBlockReverseIterator<T> &it1,
			const MemoryBlockReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

// hybrid operators

template<typename T> inline
bool
operator ==(const MemoryBlockIterator<T> &it1,
			const MemoryBlockReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const MemoryBlockIterator<T> &it1,
			const MemoryBlockReverseIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

template<typename T> inline
bool
operator ==(const MemoryBlockReverseIterator<T> &it1,
			const MemoryBlockIterator<T> &it2)
{
	return
		(it1.inc_data_iterator == it2.inc_data_iterator)
		 &&
		(it1.inc_block == it2.inc_block);
}

template<typename T> inline
bool
operator !=(const MemoryBlockReverseIterator<T> &it1,
			const MemoryBlockIterator<T> &it2)
{
	return
		(it1.inc_data_iterator != it2.inc_data_iterator)
		 ||
		(it1.inc_block != it2.inc_block);
}

}}

#endif // TEMPLATES_MEMORYBLOCK_ITERATORS
