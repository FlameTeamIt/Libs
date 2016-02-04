#ifndef TEMPLATES_ArrayBlocks
#define TEMPLATES_ArrayBlocks

#include <Templates/Pointers.h>
#include <Templates/SimpleArray.h>
#include <Templates/ArrayBlocks_Iterators.h>

/*


Что нужно реализовать:
1. Конструкторы копирования/перемещения   -> done and tested
2. _block_at()                            -> done and tested
3. _block_getArrayCopy()                  -> done and tested

4. Реализация итераторов       -> done and tested

5. insert()/erase() (включая итераторы)   -- start
6. begin()/end()                          -> done and tested
7. rbegin()/rend()                        -> done and tested

*/

const size_t DEFAULT_CAPACITY = size_t(32);

namespace flame_ide
{namespace templates
{

typedef enum
{
	FROM_NULL  = char(0),
	FROM_FRONT = char(1),
	FROM_BACK  = char(2)
} FromBlock;

template<typename T>
struct BlockIndex
{
	ArrayBlocks<T> *p_block;
	size_t index;
	
	BlockIndex() : p_block(nullptr), index(0) {}
};

template<typename T>
class ArrayBlocks : protected SimpleArray<T>
{
	inline void __block_setCopy(const ArrayBlocks<T> &block);
	inline void __block_setMove(ArrayBlocks<T> &block);
	
protected:
	bool is_front_adding;
	
	size_t block_number; // start/end index in block list
	
	SharedPointer<ArrayBlocks<T>> prev_block;
	SharedPointer<ArrayBlocks<T>> next_block;
	
	inline void _block_init_spNextBlock();
	inline void _block_init_spPrevBlock();
	
	size_t _block_getSize(FromBlock from_block) const;
	size_t _block_getCapacity(FromBlock from_block) const;
	
	void _block_popFront(size_t count);
	void _block_popBack(size_t count);
	
	SharedPointer<ArrayBlocks<T>>& _block_getNext();
	SharedPointer<ArrayBlocks<T>>& _block_getPrev();
	
	template<typename TSize_Type> T& _block_at(TSize_Type index,
	                                           FromBlock from_back);
	
	inline T* _block_simple_getArrayCopy() const;
	
	inline size_t _block_simple_getSize() const;
    inline size_t _block_simple_getCapacity() const;
    
	inline bool _block_simple_isEmpty() const;
	
	SimpleArrayIterator<T> _block_simple_begin();
	SimpleArrayIterator<T> _block_simple_end();
	
	SimpleArrayReverseIterator<T> _block_simple_rbegin();
	SimpleArrayReverseIterator<T> _block_simple_rend();
	
	BlockIndex<T> _block_findBlockByIndex(size_t index) const;
	BlockIndex<T> _block_findBlockByElement(const T *&element_address) const;
	
public:
	friend class ArrayBlocksIterator<T>;
	friend class ArrayBlocksReverseIterator<T>;
	
	friend class Array<T>;
	
	typedef ArrayBlocksIterator<T>        iterator;
	typedef ArrayBlocksReverseIterator<T> reverse_iterator;
	
	typedef const ArrayBlocksIterator<T>        const_iterator;
	typedef const ArrayBlocksReverseIterator<T> const_reverse_iterator;
	
	ArrayBlocks();
	ArrayBlocks(size_t init_size);
	
	template<typename TSize_Type>
	ArrayBlocks(TSize_Type init_size);
	
	ArrayBlocks(bool is_front_adding);
	ArrayBlocks(bool is_front_adding, size_t init_size);
	
	template<typename TSize_Type>
	ArrayBlocks(bool is_front_adding,
				TSize_Type init_size);
	
	ArrayBlocks(const ArrayBlocks<T> &block);
	ArrayBlocks(ArrayBlocks<T> &&block);
	
	virtual ~ArrayBlocks();
	
	size_t getSize() const; // new - not in plan
	size_t getCapacity() const; // new - not in plan
	
//	void resize(size_t count); // new - not in plan
//	void reserve(size_t count); // new - not in plan
	
	int pushFront(const T &obj);
	int pushFront(T &&obj);
	
	int pushBack(const T &obj);
	int pushBack(T &&obj);
	
	int insert(size_t pos_index, const T &obj);
	int insert(size_t pos_index, T &&obj);
	
	template<typename TArrayBlockIterator>
	int insert(TArrayBlockIterator pos_index, T &&obj);
	
	template<typename TArrayBlockIterator>
	int insert(TArrayBlockIterator pos_index, const T &obj);
	
	template<typename TArrayBlockIterator, typename TInputIterator>
	int insert(TArrayBlockIterator position,
	           TInputIterator start,
	           TInputIterator end);
	
	void popFront(size_t count = 1);
	void popBack(size_t count = 1);
	
	int erase(size_t pos_index, size_t count = 1);
	
	template<typename TArrayBlockIterator>
	int erase(TArrayBlockIterator pos_index, size_t count = 1);
	
	template<typename TArrayBlockIterator>
	int erase(TArrayBlockIterator start,
	          TArrayBlockIterator end);
	
	void clear();
	
	template<typename TSize_Type> const T& at(TSize_Type index) const;
	template<typename TSize_Type>       T& at(TSize_Type index);
	
	const ArrayBlocks<T>& operator =(const ArrayBlocks<T> &block);
    const ArrayBlocks<T>& operator =(ArrayBlocks<T> &&block);
	
	template<typename TSize_Type> 
	const T& operator [](TSize_Type index) const noexcept;
	template<typename TSize_Type> 
	      T& operator [](TSize_Type index)       noexcept;
	
	const T& operator [](size_t index) const noexcept;
	      T& operator [](size_t index)       noexcept;
	
	iterator begin();
	iterator end();
	reverse_iterator rbegin(); // tested
	reverse_iterator rend(); // tested

//	const_iterator& begin() const;
//	const_iterator& end() const;
//	const_reverse_iterator& rbegin() const;
//	const_reverse_iterator& rend() const;
	
protected:
	using SimpleArray<T>::_simple_getArrayCopy;
	
	using SimpleArray<T>::getSize;
	using SimpleArray<T>::getCapacity;
	
	using SimpleArray<T>::at;
	
	using SimpleArray<T>::pushBack;
	using SimpleArray<T>::popBack;

	using SimpleArray<T>::insert;
	using SimpleArray<T>::erase;
	
	using SimpleArray<T>::isEmpty;
	using SimpleArray<T>::rewrite;
	using SimpleArray<T>::clear;
	
	using SimpleArray<T>::operator = ;
	using SimpleArray<T>::operator [];
	
	using SimpleArray<T>::begin;
	using SimpleArray<T>::end;
	using SimpleArray<T>::rbegin;
	using SimpleArray<T>::rend;
};

}}

using flame_ide::templates::SimpleArray;
using flame_ide::templates::SimpleArrayIterator;
using flame_ide::templates::SimpleArrayReverseIterator;

using flame_ide::templates::ArrayBlocks;
using flame_ide::templates::ArrayBlocksIterator;
using flame_ide::templates::ArrayBlocksReverseIterator;

template<typename T>
ArrayBlocks<T>::ArrayBlocks()
	: SimpleArray<T>(DEFAULT_CAPACITY)
	,is_front_adding(false)
	,block_number(0)
{}

template<typename T>
ArrayBlocks<T>::ArrayBlocks(size_t init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(false)
	,block_number(0)
{}

template<typename T>
template<typename TSize_Type>
ArrayBlocks<T>::ArrayBlocks(TSize_Type init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(false)
	,block_number(0)
{}

template<typename T>
ArrayBlocks<T>::ArrayBlocks(bool front_adding)
	: SimpleArray<T>(DEFAULT_CAPACITY)
	,is_front_adding(front_adding)
	,block_number(0)
{}

template<typename T>
ArrayBlocks<T>::ArrayBlocks(bool front_adding, size_t init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(front_adding)
	,block_number(0)
{
	this->arr_first_index = front_adding ? init_size : 0;
	this->arr_last_index = front_adding ? init_size : 0;
}

template<typename T>
template<typename TSize_Type>
ArrayBlocks<T>::ArrayBlocks(bool front_adding, TSize_Type init_size)
	: SimpleArray<T>(init_size)
	,is_front_adding(front_adding)
	,block_number(0)
{
	this->arr_first_index = front_adding ? static_cast<size_t>(init_size) : 0;
	this->arr_last_index = front_adding ? static_cast<size_t>(init_size) : 0;
}

template<typename T>
ArrayBlocks<T>::ArrayBlocks(const ArrayBlocks<T> &block)
	: SimpleArray<T>(static_cast<const SimpleArray<T>&>(block))
{
	this->__block_setCopy(block);
}

template<typename T>
ArrayBlocks<T>::ArrayBlocks(ArrayBlocks<T> &&block)
	: SimpleArray<T>(static_cast<SimpleArray<T>&&>(block))
{
	this->__block_setMove(block);
}

template<typename T>
ArrayBlocks<T>::~ArrayBlocks()
{
	this->clear();
}

// private

template<typename T>
void
ArrayBlocks<T>::__block_setCopy(const ArrayBlocks<T> &block)
{
	this->block_number = block.block_number;
	this->is_front_adding = block.is_front_adding;
	
	SharedPointer<ArrayBlocks<T>> const *sp_block = nullptr;
	SharedPointer<ArrayBlocks<T>> *my_sp_block = nullptr;
	ArrayBlocks<T> *my_p_block = nullptr,
	        *p_initing_block = nullptr;
	
	// циклы инициализации
	for(sp_block = &block.prev_block
	       ,my_p_block = this
	       ,my_sp_block = &this->prev_block
	    ;
	    sp_block->isInitialized()
	    ;
	    sp_block = &(*sp_block)->prev_block
	       ,my_p_block = my_sp_block->operator ->()
	       ,my_sp_block = &(*my_sp_block)->prev_block
	)
	{
		(*my_sp_block) = make_shared<ArrayBlocks>(true, 0);
		(*my_sp_block)->next_block = SharedPointer<ArrayBlocks>(my_p_block);
		
		p_initing_block = my_sp_block->operator ->();
		p_initing_block->arr_capacity = (*sp_block)->arr_capacity;
		p_initing_block->arr_size     = (*sp_block)->arr_size;
		p_initing_block->arr_first_index  = (*sp_block)->arr_first_index;
		p_initing_block->arr_last_index   = (*sp_block)->arr_last_index;
		p_initing_block->block_number = (*sp_block)->block_number;
		
		p_initing_block->inc_arr = (*sp_block)->_block_simple_getArrayCopy();
	}
	
	for(sp_block = &block.next_block
	       ,my_p_block = this
	       ,my_sp_block = &this->next_block
	    ;
	    sp_block->isInitialized()
	    ;
	    sp_block = &(*sp_block)->next_block
	       ,my_p_block = my_sp_block->operator ->()
	       ,my_sp_block = &(*my_sp_block)->next_block
	)
	{
		(*my_sp_block) = make_shared<ArrayBlocks>(false, 0);
		(*my_sp_block)->prev_block = SharedPointer<ArrayBlocks>(my_p_block);
		
		p_initing_block = my_sp_block->operator ->();
		p_initing_block->arr_capacity = (*sp_block)->arr_capacity;
		p_initing_block->arr_size     = (*sp_block)->arr_size;
		p_initing_block->arr_first_index  = (*sp_block)->arr_first_index;
		p_initing_block->arr_last_index   = (*sp_block)->arr_last_index;
		p_initing_block->block_number = (*sp_block)->block_number;
		
		p_initing_block->inc_arr = (*sp_block)->_block_simple_getArrayCopy();
	}
}

template<typename T>
void
ArrayBlocks<T>::__block_setMove(ArrayBlocks<T> &block)
{
	this->block_number = block.block_number;
	this->is_front_adding = block.is_front_adding;
	
	if(block.prev_block.isInitialized())
	{
		this->prev_block = move(block.prev_block);
		this->prev_block->next_block = SharedPointer<ArrayBlocks>(this);
	}
	if(block.next_block.isInitialized())
	{
		this->next_block = move(block.next_block);
		this->next_block->prev_block = SharedPointer<ArrayBlocks>(this);
	}
}

// protected

template<typename T>
void
ArrayBlocks<T>::_block_init_spNextBlock()
{
	if(!this->next_block.isInitialized())
	{
		this->next_block = make_shared<ArrayBlocks>(this->arr_capacity);
		this->next_block->prev_block = SharedPointer<ArrayBlocks>(this);
		this->next_block->block_number = this->block_number + 1;
	}	
}

template<typename T>
void
ArrayBlocks<T>::_block_init_spPrevBlock()
{
	if(!this->prev_block.isInitialized())
	{
		this->prev_block = make_shared<ArrayBlocks>(true, this->arr_capacity);
		this->prev_block->next_block = SharedPointer<ArrayBlocks>(this);
		
		SharedPointer<ArrayBlocks<T>> *p_sp_block = &(this->prev_block->next_block);
		while(p_sp_block->isInitialized())
		{
			(*p_sp_block)->block_number++;
			p_sp_block = &((*p_sp_block)->next_block);
		}
	}	
}

template<typename T>
size_t
ArrayBlocks<T>::_block_getSize(FromBlock from_block) const
{
	size_t size = this->arr_size;
	switch(from_block)
	{
	case FROM_BACK:
		if(prev_block.isInitialized())
		{
			size += prev_block->_block_getSize(FROM_BACK);
		}
		break;
	case FROM_FRONT:
		if(next_block.isInitialized())
		{
			size += next_block->_block_getSize(FROM_FRONT);
		}
		break;
	default :
		if(prev_block.isInitialized())
		{
			size += prev_block->_block_getSize(FROM_BACK);
		}
		if(next_block.isInitialized())
		{
			size += next_block->_block_getSize(FROM_FRONT);
		}
		break;
	}
	return size;
}

template<typename T>
size_t
ArrayBlocks<T>::_block_getCapacity(FromBlock from_block) const
{
	size_t capacity = this->arr_capacity;
	switch(from_block)
	{
	case FROM_BACK :
		if(prev_block.isInitialized())
		{
			capacity += prev_block->_block_getCapacity(FROM_BACK);
		}
		break;
	case FROM_FRONT :
		if(next_block.isInitialized())
		{
			capacity += next_block->_block_getCapacity(FROM_FRONT);
		}
		break;
	default :
		if(prev_block.isInitialized())
		{
			capacity += prev_block->_block_getCapacity(FROM_BACK);
		}
		if(next_block.isInitialized())
		{
			capacity += next_block->_block_getCapacity(FROM_FRONT);
		}
		break;
	}
	return capacity;
}

template<typename T>
void
ArrayBlocks<T>::_block_popFront(size_t count)
{
	if(is_front_adding)
	{
		if(this->arr_size < count)
		{
			array_call_distructors(this->arr_size,
			                       this->inc_arr + this->arr_first_index);
			if(this->next_block.isInitialized())
			{
				this->next_block->_block_popFront(count - this->arr_size);
			}
			this->arr_size = 0;
			this->arr_first_index = this->arr_last_index;
		}
		else
		{
			array_call_distructors(count, this->inc_arr + this->arr_first_index);
			this->arr_size        -= count;
			this->arr_first_index += count;
		}
	}
	else
	{
		if(!this->arr_size)
		{
			if(this->next_block.isInitialized())
			{
				this->next_block->_block_popFront(count);
			}
		}
		else if(this->arr_size < count)
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
ArrayBlocks<T>::_block_popBack(size_t count)
{
	if(is_front_adding)
	{
		if(this->arr_size < count)
		{
			array_call_distructors(this->arr_size,
			                       this->inc_arr + this->arr_first_index);
			if(this->prev_block.isInitialized())
			{
				this->prev_block->_block_popBack(count - this->arr_size);
			}
			this->arr_size = 0;
			this->arr_first_index = this->arr_last_index;
		}
		else
		{
			array_call_distructors(
				count,
				this->inc_arr + (this->arr_last_index-1) - count
			);
			this->arr_size -= count;
			
			// move elements
			for(size_t i = 0; i < this->arr_size; ++i)
			{
				array_rewrite(this->inc_arr, this->arr_capacity - 1 - i,
				              this->inc_arr[this->arr_first_index
				                            + this->arr_size - 1 - i]);
				array_call_distructors(1,
				                       this->inc_arr + this->arr_first_index
				                       + this->arr_size - 1 - i);
				
			}
			this->arr_first_index += count;
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
SharedPointer<ArrayBlocks<T>>&
ArrayBlocks<T>::_block_getNext()
{
	return next_block;
}
template<typename T>
SharedPointer<ArrayBlocks<T>>&
ArrayBlocks<T>::_block_getPrev()
{
	return prev_block;
}

template<typename T>
template<typename TSize_Type>
T&
ArrayBlocks<T>::_block_at(TSize_Type index, FromBlock from_block)
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
				return next_block->_block_at(local_index - this->arr_size,
				                             FROM_FRONT);
			}
			else
			{
				return this->SimpleArray<T>::at(size_t(0));
			}
		}
	default :
		break;
	}
	
	return this->SimpleArray<T>::at(size_t(0));
}

template<typename T>
T*
ArrayBlocks<T>::_block_simple_getArrayCopy() const
{
	return this->SimpleArray<T>::_simple_getArrayCopy();
}

template<typename T>
size_t
ArrayBlocks<T>::_block_simple_getSize() const
{
	return this->SimpleArray<T>::getSize();
}

template<typename T>
size_t
ArrayBlocks<T>::_block_simple_getCapacity() const
{
	return this->SimpleArray<T>::getCapacity();
}

template<typename T>
bool
ArrayBlocks<T>::_block_simple_isEmpty() const
{
	return this->SimpleArray<T>::isEmpty();
}

template<typename T>
SimpleArrayIterator<T>
ArrayBlocks<T>::_block_simple_begin()
{
	return this->SimpleArray<T>::begin();
}
template<typename T>
SimpleArrayIterator<T>
ArrayBlocks<T>::_block_simple_end()
{
	return this->SimpleArray<T>::end();
}

template<typename T>
SimpleArrayReverseIterator<T>
ArrayBlocks<T>::_block_simple_rbegin()
{
	return this->SimpleArray<T>::rbegin();
}
template<typename T>
SimpleArrayReverseIterator<T>
ArrayBlocks<T>::_block_simple_rend()
{
	return this->SimpleArray<T>::rend();
}

template<typename T>
BlockIndex<T>
ArrayBlocks<T>::_block_findBlockByIndex(size_t index) const
{
	BlockIndex<T> block_index;
	ArrayBlocks<T> *p_block = this;
	
	while(p_block->prev_block.isInitialized())
	{ p_block = p_block->prev_block.operator ->(); }
	
	size_t tmp_size = p_block->_block_simple_getSize();
	while(index > tmp_size)
	{
		index -= tmp_size;
		if(p_block->next_block.isInitialized())
		{
			p_block = p_block->next_block.operator ->();
		}
		else
		{
			index = 0;
			p_block = nullptr;
		}
	}
	
	block_index.p_block = p_block;
	block_index.index = index;
	
	return block_index;
}

template<typename T>
BlockIndex<T>
ArrayBlocks<T>::_block_findBlockByElement(const T *&element_address) const
{
	BlockIndex<T> block_index;
	
	for(auto iterator = this->begin(), iterator_end = this->end();
	         iterator != iterator_end; ++iterator)
	{
		if(iterator.operator ->() == element_address)
		{
			block_index.p_block = iterator.inc_block;
			block_index.index = iterator.operator ->()
			                    - iterator.inc_block->inc_arr;
			
			iterator = iterator_end;
		}
	}
	
	return block_index;
}


// public

template<typename T>
size_t
ArrayBlocks<T>::getSize() const
{
	return this->_block_getSize(FROM_NULL);
}

template<typename T>
size_t
ArrayBlocks<T>::getCapacity() const
{
	return this->_block_getCapacity(FROM_NULL);
}

template<typename T>
int
ArrayBlocks<T>::pushFront(const T &obj)
{
	if(this->is_front_adding)
	{
		if(this->arr_size < this->arr_capacity)
		{
			--this->arr_first_index;
			++this->arr_size;
			
			this->inc_arr[this->arr_first_index] = obj;
			
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
ArrayBlocks<T>::pushFront(T &&obj)
{
	if(this->is_front_adding)
	{
		if(this->arr_size < this->arr_capacity)
		{
			--this->arr_first_index;
			++this->arr_size;
			
			this->inc_arr[this->arr_first_index] = obj;
			
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
ArrayBlocks<T>::pushBack(const T &obj)
{
	if(this->is_front_adding)
	{
		// нужно сдвинуть массив на один элемент влево
		if(this->arr_size < this->arr_capacity)
		{
			std::copy(this->inc_arr + this->arr_first_index,
			          this->inc_arr + this->arr_capacity,
			          this->inc_arr + this->arr_first_index - 1);
			
			array_copying(1, &obj, this->inc_arr + this->arr_capacity - 1);
			
			--this->arr_first_index;
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
ArrayBlocks<T>::pushBack(T &&obj)
{
	if(this->is_front_adding)
	{
		if(this->arr_size < this->arr_capacity)
		{
			std::copy(this->inc_arr + this->arr_first_index,
			          this->inc_arr + this->arr_capacity,
			          this->inc_arr + this->arr_first_index - 1);
			
			this->inc_arr[this->arr_capacity - 1].~T();
			this->inc_arr[this->arr_capacity - 1] = obj;
			
			--this->arr_first_index;
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
ArrayBlocks<T>::insert(size_t pos_index, const T &obj)
{
	// 1. нужно найти блок с данным индексом
	BlockIndex<T> block_index;
	
	// 2. сдвинуть элементы
	
	// 3. копировать объект
	
	return -1;
}

template<typename T>
int
ArrayBlocks<T>::insert(size_t pos_index, T &&obj)
{
	// 1. нужно найти блок с данным индексом
	BlockIndex<T> block_index = this->_block_findBlockByIndex(pos_index);
	
	if(block_index.p_block)
	{
		// 2. сдвинуть элементы
		
		// 3. переместить объект
		
		return 1;
	}
	
	return -1;
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::insert(TArrayBlockIterator pos_index, const T &obj)
{
	BlockIndex<T> block_index =
		this->_block_findBlockByElement(pos_index.operator ->());
	if(block_index.p_block)
	{
		// 2. сдвинуть элементы
		
		// 3. копировать объект
		
		return 1;
	}
	
	return -1;
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::insert(TArrayBlockIterator pos_index, T &&obj)
{
	BlockIndex<T> block_index =
	    this->_block_findBlockByElement(pos_index.operator ->());
	if(block_index.p_block)
	{
		// 2. сдвинуть элементы
		
		// 3. переместить объект
		
		return 1;
	}
	
	return -1;
}

template<typename T>
template<typename TArrayBlockIterator, typename TInputIterator>
int
ArrayBlocks<T>::insert(TArrayBlockIterator pos,
                       TInputIterator start,
                       TInputIterator end)
{
	typedef decltype(start.operator *()) TInput;
	BlockIndex<T> block_index =
	    this->_block_findBlockByElement(pos.operator ->());
	if(block_index.p_block)
	{
		// 2. сдвинуть элементы
		
		// ...
		
		if(is_same_types<TInput, T>()
		   || is_same_types<TInput, T&>() )
		{
			// 3. переместить объекты
			for(; start != end; ++start)
			{}
			
			return 1;
		}
		if(is_same_types<TInput, const T>()
		   || is_same_types<TInput, const T&>())
		{
			// 3. копировать объекты
			for(; start != end; ++start)
			{}
			
			return 1;
		}
	}
	
	return -1;
}

template<typename T>
void
ArrayBlocks<T>::popFront(size_t count)
{
	if(this->prev_block.isInitialized()
	   && this->prev_block->_block_simple_getSize())
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
ArrayBlocks<T>::popBack(size_t count)
{
	if(this->next_block.isInitialized()
	   && !(this->next_block->_block_simple_isEmpty()))
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
ArrayBlocks<T>::erase(size_t pos_index, size_t count)
{
	BlockIndex<T> block_index = _block_findBlockByIndex(pos_index);
	
	if(block_index.p_block)
	{
		for(size_t i = 0; i < count; ++i)
		{
			
		}
	}
	
	return -1;
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::erase(TArrayBlockIterator pos_index, size_t count)
{
	
	BlockIndex<T> block_index
	    = this->_block_findBlockByElement(pos_index.operator ->());
	
	return -1;
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::erase(TArrayBlockIterator start,
                      TArrayBlockIterator end)
{
	BlockIndex<T> block_index_start
	    = this->_block_findBlockByElement(start.operator ->());
	BlockIndex<T> block_index_end
	    = this->_block_findBlockByElement(end.operator ->());
	
	if(block_index_start.p_block
	   && block_index_end.p_block)
	{
		
	}
	
	return -1;
}

template<typename T>
void
ArrayBlocks<T>::clear()
{
	// don't know about pointers
	
	this->SimpleArray<T>::clear();
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
template<typename TSize_Type>
const T&
ArrayBlocks<T>::at(TSize_Type index) const
{
	return this->_block_at(index, FROM_NULL);
}
template<typename T>
template<typename TSize_Type>
T&
ArrayBlocks<T>::at(TSize_Type index)
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
const ArrayBlocks<T>&
ArrayBlocks<T>::operator =(const ArrayBlocks<T> &block)
{
	this->clear();
	this->__block_setCopy(block);
	return *this;
}

template<typename T>
const ArrayBlocks<T>&
ArrayBlocks<T>::operator =(ArrayBlocks<T> &&block)
{
	this->clear();
	this->__block_setMove(block);
	return *this;
}

template<typename T>
template<typename TSize_Type>
const T&
ArrayBlocks<T>::operator [](TSize_Type index) const noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
template<typename TSize_Type>
T&
ArrayBlocks<T>::operator [](TSize_Type index) noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
const T&
ArrayBlocks<T>::operator [](size_t index) const noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
T&
ArrayBlocks<T>::operator [](size_t index) noexcept
{
	return this->_block_at(index, FROM_NULL);
}

template<typename T>
ArrayBlocksIterator<T>
ArrayBlocks<T>::begin()
{
	if(prev_block.isInitialized()
	   && !(prev_block->_block_simple_isEmpty()) )
	{
		return prev_block->begin();
	}
	else
	{
		iterator it;
		it.inc_block = this;
		it.inc_data_iterator = it.inc_block->_block_simple_begin();
		return it;
	}
}

template<typename T>
ArrayBlocksIterator<T>
ArrayBlocks<T>::end()
{
	if(next_block.isInitialized()
	   && !(next_block->_block_simple_isEmpty()) )
	{
		return next_block->end();
	}
	else
	{
		iterator it;
		it.inc_block = this;
		it.inc_data_iterator = it.inc_block->_block_simple_end();
		return it;
	}
}

template<typename T>
ArrayBlocksReverseIterator<T>
ArrayBlocks<T>::rbegin()
{
	if(next_block.isInitialized()
	   && !(next_block->_block_simple_isEmpty()) )
	{
		return next_block->rbegin();
	}
	else
	{
		reverse_iterator it;
		it.inc_block = this;
		it.inc_data_iterator = it.inc_block->_block_simple_rbegin();
		return it;
	}
}

template<typename T>
ArrayBlocksReverseIterator<T>
ArrayBlocks<T>::rend()
{
	if(prev_block.isInitialized()
	   && !(prev_block->_block_simple_isEmpty()) )
	{
		return prev_block->rend();
	}
	else
	{
		reverse_iterator it;
		it.inc_block = this;
		it.inc_data_iterator = it.inc_block->_block_simple_rend();
		return it;
	}
}
#endif // TEMPLATES_ArrayBlocks
