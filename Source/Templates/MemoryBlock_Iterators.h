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
		: public BasicReverseIterator<SimpleArrayIterator<T>, T>
{
private:
	MemoryBlock<T> *inc_block;
public:
	friend class MemoryBlock<T>;
	typedef MemoryBlockIterator<T> my_type;
	typedef MemoryBlockReverseIterator<T> friend_type;
	
	MemoryBlockIterator();
	MemoryBlockIterator(MemoryBlockIterator<T> &&iterator);
	MemoryBlockIterator(const MemoryBlockIterator<T> &iterator);
	
	~MemoryBlockIterator() = default;
	
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

template<typename T>
class MemoryBlockReverseIterator
		: public BasicReverseIterator<SimpleArrayReverseIterator<T>, T>
{
private:
	MemoryBlock<T> *inc_block;
    
public:
	friend class MemoryBlock<T>;
	typedef MemoryBlockReverseIterator<T> my_type;
	typedef MemoryBlockIterator<T> friend_type;
	
	MemoryBlockReverseIterator();
	MemoryBlockReverseIterator(MemoryBlockReverseIterator<T> &&iterator);
	MemoryBlockReverseIterator(const MemoryBlockReverseIterator<T> &iterator);
	
	~MemoryBlockReverseIterator() = default;
	
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



}}

#endif // TEMPLATES_MEMORYBLOCK_ITERATORS
