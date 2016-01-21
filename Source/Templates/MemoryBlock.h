#ifndef TEMPLATES_MEMORYBLOCK
#define TEMPLATES_MEMORYBLOCK

#include <Templates/Pointers.h>
#include <Templates/SimpleArray.h>
#include <Templates/MemoryBlock_Iterators.h>

#define DEFAULT_CAPACITY size_t(32)

/*

Что нужно реализовать:
1. Конструкторы копирования/перемещения   -- not done
2. _block_at()                            -> done and tested
3. _block_getArrayCopy()                  -- not done

4. insert()/erase() (включая итераторы)   -- not done
5. begin()/end()                          -- not done
6. rbegin()/rend()                        -- not done

*/
namespace flame_ide
{namespace templates
{

typedef enum
{
	FROM_NULL = char(0),
	FROM_FRONT = char(1),
	FROM_BACK = char(2)
} FromBlock;

template<class T>
class MemoryBlock : public SimpleArray<T>
{
	inline void __block_setCopy(const MemoryBlock<T> &block);
	inline void __block_setMove(MemoryBlock<T> &block);
	
protected:
	typedef MemoryBlock<T> my_type;
	
	bool is_front_adding;
	
	size_t block_start_index; // start/end index in block list
	
	SharedPointer<my_type> prev_block;
	SharedPointer<my_type> next_block;
	
	inline void _block_init_spNextBlock();
	inline void _block_init_spPrevBlock();
	
	void _block_popFront(size_t count);
	void _block_popBack(size_t count);
	
	SharedPointer<my_type> _block_getNext();
	SharedPointer<my_type> _block_getPrev();
	
	template<typename TSize_Type> T& _block_at(TSize_Type index,
											   FromBlock from_back);
		  
	inline T* _block_getArrayCopy() const;
	
public:
	MemoryBlock();
	MemoryBlock(size_t init_size);
	template<typename TSize_Type> MemoryBlock(TSize_Type init_size);
	MemoryBlock(bool is_front_adding);
	MemoryBlock(bool is_front_adding, size_t init_size);
	template<typename TSize_Type> MemoryBlock(bool is_front_adding,
											  TSize_Type init_size);
	MemoryBlock(const MemoryBlock<T> &block);
	MemoryBlock(MemoryBlock<T> &&block);
	
	virtual ~MemoryBlock();
	
//	size_t size(); // new - not in plan
//	size_t capacity(); // new - not in plan
	
//	void resize(size_t count); // new - not in plan
//	void reserve(size_t count); // new - not in plan
	
	int pushFront(const T &obj);
	int pushFront(T &&obj);
	
	int pushBack(const T &obj);
	int pushBack(T &&obj);
	
	int insert(size_t pos_index, const T &obj);
	int insert(size_t pos_index, T &&obj);
	
	void popFront(size_t count = 1);
	void popBack(size_t count = 1);
	
	int erase(size_t pos_index, size_t count = 1);
	
	void clear();
	
	template<typename TSize_Type> const T& at(TSize_Type index) const;
	template<typename TSize_Type>       T& at(TSize_Type index);
	
	const T& operator [](size_t index) const noexcept;
	      T& operator [](size_t index)       noexcept;
	
	template<typename TSize_Type> 
	const T& operator [](TSize_Type index) const noexcept;
	template<typename TSize_Type> 
	      T& operator [](TSize_Type index)       noexcept;
	
	const my_type& operator =(const my_type &block);
	const my_type& operator =(my_type &&block);
};

}}

using namespace flame_ide::templates;

template<typename T>
MemoryBlock<T>::MemoryBlock()
	: SimpleArray<T>(DEFAULT_CAPACITY)
	,is_front_adding(false)
	,block_start_index(0)
{}

template<typename T>
MemoryBlock<T>::MemoryBlock(size_t init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(false)
	,block_start_index(0)
{}

template<typename T>
template<typename TSize_Type>
MemoryBlock<T>::MemoryBlock(TSize_Type init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(false)
	,block_start_index(0)
{}

template<typename T>
MemoryBlock<T>::MemoryBlock(bool is_front_adding)
	: SimpleArray<T>(DEFAULT_CAPACITY)
	,is_front_adding(is_front_adding)
	,block_start_index(0)
{}

template<typename T>
MemoryBlock<T>::MemoryBlock(bool is_front_adding, size_t init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(is_front_adding)
	,block_start_index(0)
{
	this->first_index = is_front_adding ? init_size : 0;
	this->last_index = is_front_adding ? init_size : 0;
}

template<typename T>
template<typename TSize_Type>
MemoryBlock<T>::MemoryBlock(bool is_front_adding, TSize_Type init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(is_front_adding)
	,block_start_index(0)
{
	this->first_index = is_front_adding ? static_cast<size_t>(init_size) : 0;
	this->last_index = is_front_adding ? static_cast<size_t>(init_size) : 0;
}

template<typename T>
MemoryBlock<T>::MemoryBlock(MemoryBlock<T> &&block)
{
	this->__block_setMove(block);
}

template<typename T>
MemoryBlock<T>::MemoryBlock(const MemoryBlock<T> &block)
{
	this->__block_setCopy(block);
}

template<typename T>
MemoryBlock<T>::~MemoryBlock()
{
	if(prev_block.isInitialized())
	{
		prev_block.clear();
	}
	if(next_block.isInitialized())
	{
		next_block.clear();
	}
}

template<typename T>
void
MemoryBlock<T>::__block_setCopy(const MemoryBlock<T> &block)
{
	
}

template<typename T>
void
MemoryBlock<T>::__block_setMove(MemoryBlock<T> &block)
{
	
}

template<typename T>
void
MemoryBlock<T>::_block_init_spNextBlock()
{
	if(!this->next_block.isInitialized())
	{
		this->next_block = make_shared<MemoryBlock>(this->arr_capacity);
		this->next_block->prev_block = SharedPointer<MemoryBlock>(this);
		this->next_block->block_start_index = this->block_start_index + 1;
	}	
}

template<typename T>
void
MemoryBlock<T>::_block_init_spPrevBlock()
{
	if(!this->prev_block.isInitialized())
	{
		this->prev_block = make_shared<MemoryBlock>(true, this->arr_capacity);
		this->prev_block->next_block = SharedPointer<MemoryBlock>(this);
		
		SharedPointer<my_type> *p_sp_block = &(this->prev_block->next_block);
		while(p_sp_block->isInitialized())
		{
			(*p_sp_block)->block_start_index++;
			p_sp_block = &((*p_sp_block)->next_block);
		}
	}	
}

template<typename T>
void
MemoryBlock<T>::_block_popFront(size_t count)
{
	if(is_front_adding)
	{
		if(this->arr_size < count)
		{
			array_call_distructors(this->arr_size, this->inc_arr + this->first_index);
			if(this->next_block.isInitialized())
			{
				this->next_block->_block_popFront(count - this->arr_size);
			}
			this->arr_size = 0;
			this->first_index = this->last_index;
		}
		else
		{
			array_call_distructors(count, this->inc_arr + this->first_index);
			this->arr_size    -= count;
			this->first_index += count;
		}
	}
	else
	{
		if(this->arr_size < count)
		{
			if(this->next_block.isInitialized())
			{
				this->next_block->_block_popFront(count - this->arr_size);
			}
			this->SimpleArray<T>::erase(0, this->arr_size);
		}
		else
		{
			this->SimpleArray<T>::erase(0, count);
		}
		
	}
}

template<typename T>
void
MemoryBlock<T>::_block_popBack(size_t count)
{
	if(is_front_adding)
	{
		if(this->arr_size < count)
		{
			array_call_distructors(this->arr_size, this->inc_arr + this->first_index);
			if(this->prev_block.isInitialized())
			{
				this->prev_block->_block_popBack(count - this->arr_size);
			}
			this->arr_size = 0;
			this->first_index = this->last_index;
		}
		else
		{
			array_call_distructors(
				count,
				this->inc_arr + (this->last_index-1) - count
			);
			this->arr_size -= count;
			
			// move elements
			for(size_t i = 0; i < this->arr_size; ++i)
			{
				array_rewrite(this->inc_arr, this->arr_capacity - 1 - i,
					this->inc_arr[this->first_index + this->arr_size - 1 - i]);
				array_call_distructors(1,
					this->inc_arr + this->first_index + this->arr_size - 1 - i);
				
			}
			this->first_index += count;
		}
		
	}
	else
	{
		if(this->arr_size < count)
		{
			if(this->prev_block.isInitialized())
			{
				this->prev_block->_block_popBack(count - this->arr_size);
			}
			this->SimpleArray<T>::popBack(this->arr_size);
		}
		else
		{
			this->SimpleArray<T>::popBack(count);
		}
		
	}
}

template<typename T>
SharedPointer<MemoryBlock<T>>
MemoryBlock<T>::_block_getNext()
{
	return next_block;
}
template<typename T>
SharedPointer<MemoryBlock<T>>
MemoryBlock<T>::_block_getPrev()
{
	return prev_block;
}

template<typename T>
template<typename TSize_Type>
T&
MemoryBlock<T>::_block_at(TSize_Type index, FromBlock from_block)
{
	size_t local_index = static_cast<size_t>(index);
	switch (from_block)
	{
	case FROM_NULL:
	case FROM_BACK:
		if(prev_block.isInitialized())
		{
			return prev_block->_block_at(local_index, FROM_BACK);
		}
		else
		{
			if(local_index < this->arr_size)
			{
				return this->SimpleArray<T>::at(local_index);
			}
			else
			{
				if(next_block.isInitialized())
				{
					return next_block->_block_at(local_index - this->arr_size,
												 FROM_FRONT);
				}
				else
				{
					return this->SimpleArray<T>::at(size_t(0));
				}
			}
		}
	
	
	case FROM_FRONT:
	    if(local_index < this->arr_size)
	    {
		    return this->SimpleArray<T>::at(local_index);
	    }
	    else
	    {
		    if(next_block.isInitialized())
		    {
			    return next_block->_block_at(local_index - this->arr_size + 1,
										     FROM_FRONT);
		    }
		    else
		    {
			    return this->SimpleArray<T>::at(size_t(0));
		    }
	    }
	}
	
	return this->SimpleArray<T>::at(size_t(0));
}

template<typename T>
int
MemoryBlock<T>::pushFront(const T &obj)
{
	if(this->is_front_adding)
	{
		if(this->arr_size < this->arr_capacity)
		{
			--this->first_index;
			++this->arr_size;
			
			array_copying(1, &obj, this->inc_arr + this->first_index);
			
			return 1;
		}
	}
	else
	{
		int return_code = this->SimpleArray<T>::insert(0, obj);
		if(return_code > 0)
		{
			return return_code;
		}
	}
	
	_block_init_spPrevBlock();
	return prev_block->pushFront(obj);
	
}

template<typename T>
int
MemoryBlock<T>::pushFront(T &&obj)
{
	if(this->is_front_adding)
	{
		if(this->arr_size < this->arr_capacity)
		{
			--this->first_index;
			++this->arr_size;
			
			this->inc_arr[this->first_index] = T(obj);
			
			return 1;
		}
	}
	else
	{
		int return_code = this->SimpleArray<T>::insert(0, obj);
		if(return_code > 0)
		{
			return return_code;
		}
	}
	
	_block_init_spPrevBlock();
	return prev_block->pushFront(obj);
	
}

template<typename T>
int
MemoryBlock<T>::pushBack(const T &obj)
{
	if(this->is_front_adding)
	{
		// нужно сдвинуть массив на один элемент влево
		if(this->arr_size < this->arr_capacity)
		{
			std::copy(this->inc_arr + this->first_index,
					  this->inc_arr + this->arr_capacity,
					  this->inc_arr + this->first_index - 1);
			
			array_copying(1, &obj, this->inc_arr + this->arr_capacity - 1);
			
			--this->first_index;
			++this->arr_size;
			
			return 1;
		}
	}
	else
	{
		int return_code = this->SimpleArray<T>::pushBack(obj);
		if(return_code > 0)
		{
			return return_code;
		}
	}
	_block_init_spNextBlock();
	return next_block->pushBack(obj);
}

template<typename T>
int
MemoryBlock<T>::pushBack(T &&obj)
{
	if(this->is_front_adding)
	{
		if(this->arr_size < this->arr_capacity)
		{
			std::copy(this->inc_arr + this->first_index,
					  this->inc_arr + this->arr_capacity,
					  this->inc_arr + this->first_index - 1);
			
			this->inc_arr[this->arr_capacity - 1].~T();
			this->inc_arr[this->arr_capacity - 1] = T(obj);
			
			--this->first_index;
			++this->arr_size;
			
			return 1;
		}
	}
	else
	{
		int return_code = this->SimpleArray<T>::pushBack(obj);
		if(return_code > 0)
		{
			return return_code;
		}
	}
	_block_init_spNextBlock();
	return next_block->pushBack(obj);
}

template<typename T>
void
MemoryBlock<T>::popFront(size_t count)
{
	if(this->prev_block.isInitialized())
	{
		this->prev_block->popFront(count);
	}
	else
	{
		this->_block_popFront(count);
	}
}

template<typename T>
void
MemoryBlock<T>::popBack(size_t count)
{
	if(this->next_block.isInitialized())
	{
		this->next_block->popBack(count);
	}
	else
	{
		this->_block_popBack(count);
	}
}

template<typename T>
int
MemoryBlock<T>::erase(size_t pos_index, size_t count)
{
	if(this->arr_size < count)
	{
		return -1;
	}
	
	if(this->is_front_adding)
	{
		return 1;
	}
	else
	{
		return 1;
	}
}

template<typename T>
void
MemoryBlock<T>::clear()
{
	// don't know about pointers
	
	this->SimpleArray<T>::clear();
	if(is_front_adding)
	{
		
	}
	else
	{
		
	}
}

template<typename T>
template<typename TSize_Type>
const T&
MemoryBlock<T>::at(TSize_Type index) const
{
	return this->_block_at(index, FROM_NULL);
}
template<typename T>
template<typename TSize_Type>
T&
MemoryBlock<T>::at(TSize_Type index)
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
const T&
MemoryBlock<T>::operator [](size_t index) const noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
T&
MemoryBlock<T>::operator [](size_t index) noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
template<typename TSize_Type>
const T&
MemoryBlock<T>::operator [](TSize_Type index) const noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
template<typename TSize_Type>
T&
MemoryBlock<T>::operator [](TSize_Type index) noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
const MemoryBlock<T>&
MemoryBlock<T>::operator =(const MemoryBlock<T> &block)
{
	return *this;
}

template<typename T>
const MemoryBlock<T>&
MemoryBlock<T>::operator =(MemoryBlock<T> &&block)
{
	return *this;
}

#endif // TEMPLATES_MEMORYBLOCK
