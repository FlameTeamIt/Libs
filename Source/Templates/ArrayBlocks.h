#ifndef TEMPLATES_ARRAYBLOCKS
#define TEMPLATES_ARRAYBLOCKS

#include <Others/Bits.h>

#include <Templates/Pointers.h>
#include <Templates/SimpleArray.h>
#include <Templates/ArrayBlocks_Iterators.h>


/*


Что нужно реализовать:
1. Конструкторы копирования/перемещения   -> done and tested
2. _block_at()                            -> done and tested
3. _block_getArrayCopy()                  -> done and tested

4. Реализация итераторов       -> done and tested

5. insert()/erase() (включая итераторы)   -- not done
      5.1. insert()                          -- not done
         5.1.1. insert(index)                   -- not done
         5.1.2. insert(iterator)                -- not done
         5.1.3. insert(range)                   -- not done
      5.2 erase()                            -- not done
         5.2.1. erase(index)                    -- not done
         5.2.2. insert(iterator)                -- not done
         5.2.3. insert(range)                   -- not done

6. begin()/end()                          -> done and tested
7. rbegin()/rend()                        -> done and tested

*/


namespace flame_ide
{namespace templates
{

using namespace flame_ide::types::primitive;

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
	size_t global_index;
	
	size_t current_size;
	size_t current_capacity;
	
	typename ArrayBlocks<T>::iterator         it_front;
	typename ArrayBlocks<T>::reverse_iterator it_back;
	
	BlockIndex() : global_index(0) {p_block = nullptr;}
	BlockIndex(const BlockIndex<T> & block_index)
	{
		assign(block_index);
	}
	BlockIndex(BlockIndex<T> && block_index)
	{
		assign(block_index);
	}
	inline BlockIndex<T> const & operator =(BlockIndex<T> const & block_index)
	{
		assign(block_index);
		return *this;
	}
	
private:
	inline void assign(const BlockIndex<T> & block_index)
	{
		this->p_block          = block_index.p_block;
		this->global_index     = block_index.global_index;
		this->it_front         = block_index.it_front;
		this->it_back          = block_index.it_back;
		this->current_size     = block_index.current_size;
		this->current_capacity = block_index.current_capacity;
	}
};

template<typename T>
class ArrayBlocks : protected SimpleArray<T>
{
	static size_t const DEFAULT_CAPACITY = size_t(32);
	
public:
	using         iterator = ArrayBlocksIterator<T>;
	using reverse_iterator = ArrayBlocksReverseIterator<T>;
	
	using         const_iterator = ArrayBlocksIterator<T>        const;
	using const_reverse_iterator = ArrayBlocksReverseIterator<T> const;
	
private:
	inline void __block_setCopy(const ArrayBlocks<T> &block);
	inline void __block_setMove(ArrayBlocks<T> &block);
	
	inline static uchar_t __block_generateBitMask(const BlockIndex<T> &block_index);
	inline bool __block_isSituation1(const uchar_t bit_mask);
	inline bool __block_isSituation2(const uchar_t bit_mask);
	inline bool __block_isSituation3(const uchar_t bit_mask);
	inline bool __block_isSituation4(const uchar_t bit_mask);
	inline bool __block_isSituation5(const uchar_t bit_mask);
	inline bool __block_isSituation6(const uchar_t bit_mask);
	inline bool __block_isSituation7(const uchar_t bit_mask);
	inline bool __block_isSituation8(const uchar_t bit_mask);
	
private:
	using parent = SimpleArray<T>;
	
	using parent::_simple_getArrayCopy;
	
	using parent::getSize;
	using parent::getCapacity;
	
	using parent::at;
	
	using parent::pushBack;
	using parent::popBack;

	using parent::insert;
	using parent::erase;
	
	using parent::isEmpty;
	using parent::rewrite;
	using parent::clear;
	
	using parent::operator = ;
	using parent::operator [];
	
	using parent::begin;
	using parent::end;
	using parent::rbegin;
	using parent::rend;

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
	
	typename parent::iterator _block_simple_begin();
	typename parent::iterator _block_simple_end();
	
	typename parent::reverse_iterator _block_simple_rbegin();
	typename parent::reverse_iterator _block_simple_rend();
	
	inline ArrayBlocks<T> * _block_getFirstBlock();
	inline ArrayBlocks<T> * _block_getLastBlock();
	
	BlockIndex<T> _block_findBlock(size_t index);
	
	template<typename TArrayBlockIterator>
	BlockIndex<T> _block_findBlock(const TArrayBlockIterator &element_iterator);
	
	template<typename TInputIt, typename TOutIt>
	inline void _block_move_elements(size_t new_cells,
	                                 TInputIt & source_start,
	                                 TInputIt & source_end,
	                                 TOutIt & target);
	
	template<bool is_insert,
	         typename TIndexType, typename TConcrete>
	inline int _block_generic_change_size(TIndexType &index_type,
	                                      TConcrete *obj = nullptr);
	
	template<bool is_insert, typename TConcrete>
	inline int _block_generic_change_size_option(BlockIndex<T> &block_index,
	                                             TConcrete *obj);
public:
	friend class ArrayBlocksIterator<T>;
	friend class ArrayBlocksReverseIterator<T>;
	
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
	
	
	// in plan, but not implemented
	int insert(size_t pos_index, const T &obj);
	int insert(size_t pos_index, T &&obj);
	template<typename TArrayBlockIterator>
	int insert(TArrayBlockIterator pos_it, T &&obj);
	template<typename TArrayBlockIterator>
	int insert(TArrayBlockIterator pos_it, const T &obj);
	template<typename TArrayBlockIterator, typename TInputIt>
	int insert(TArrayBlockIterator position,
	           TInputIt start,
	           TInputIt end);
	
	void popFront(size_t count = 1);
	void popBack(size_t count = 1);
	
	// in plan, but not implemented
	int erase(size_t pos_index);
	template<typename TArrayBlockIterator>
	int erase(TArrayBlockIterator &pos_it);
	template<typename TArrayBlockIterator>
	int erase(TArrayBlockIterator &start,
	          TArrayBlockIterator &end);
	
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
};

}}

using flame_ide::templates::SimpleArray;

using flame_ide::templates::ArrayBlocks;

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

/*
 situations:
        _      _    _     _
       |1|    |2|  |3|   |4|
  |____+x++| |+x++++x+| |+x++____|
        _         _            _     _
       |1|       |2|          |3|   |4|
  |____+x++| |++++x+++| |++++++x+| |+x++____|
        _                 _               _                _
       |1|               |2|             |3|              |4|
  |____+x++| |++++++++| |+x++++++| |++++++x+| |++++++++| |+x++____|
               _               _
              |2|             |3|             
  |++++++++| |+x++++++| |++++++x+| |++++++++|
        _      _
       |1|    |4|
  |____+x++| |+x++____|

  1 -- mark & (bits::BIT8_1 | bits::BIT8_5)
  2 -- mark & (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_4)
  3 -- mark & (bits::BIT8_2 | bits::BIT8_5)
  4 -- mark & (bits::BIT8_4)
        _
       |5|
  |____+x++|
  
  5 -- mark & (bits::BIT8_1 | bits::BIT8_3)
    _    _
   |6|  |7| 
  |+x++++x+|
  
  6 -- mark & (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_3)
  7 -- mark & (bits::BIT8_2 | bits::BIT8_3)
	_
   |8|
  |+x++____|
  
  8 -- mark & (bits::BIT8_3)
*/
template<typename T> uchar_t
ArrayBlocks<T>::__block_generateBitMask(const BlockIndex<T> &block_index)
{
	typedef ArrayBlocks<T> * ArrayBlocksPointer;
	const ArrayBlocksPointer &refp_block = block_index.p_block;
	const flame_ide::types::primitive::size_t &
			ref_current_size = block_index.current_size;
	const flame_ide::types::primitive::size_t &
			ref_current_capacity = block_index.current_capacity;
	
#ifdef DEBUG
	uchar_t mark = uchar_t(0);
	if(block_index.global_index + 1 < ref_current_size/2)
	{
		mark = static_cast<uchar_t>(mark + bits::BIT8_0);
	}
	
	if(refp_block->is_front_adding)
	{
		mark = static_cast<uchar_t>(mark + bits::BIT8_1);
	}
	
	if(refp_block->arr_capacity == refp_block->arr_size)
	{
		mark = static_cast<uchar_t>(mark + bits::BIT8_2);
	}
	
	if(refp_block->arr_capacity == ref_current_capacity)
	{
		mark = static_cast<uchar_t>(mark + bits::BIT8_3);
	}
	
	if(refp_block->prev_block.isInitialized())
	{
		mark = static_cast<uchar_t>(mark + bits::BIT8_4);
	}
	
	if(refp_block->next_block.isInitialized())
	{
		mark = static_cast<uchar_t>(mark + bits::BIT8_5);
	}
	
#else
	uchar_t mark = uchar_t(0)
	    + bits::BIT8_0
	       * (block_index.global_index + 1 < ref_current_size/2) ? uchar_t(1) : uchar_t(0)
	    + bits::BIT8_1
	       * (refp_block->is_front_adding) ? uchar_t(1) : uchar_t(0)
		+ bits::BIT8_2
	       * (refp_block->arr_capacity == refp_block->arr_size) ? uchar_t(1) : uchar_t(0)
	    + bits::BIT8_3
	       * (refp_block->arr_capacity == ref_current_capacity) ? uchar_t(1) : uchar_t(0)
	    + bits::BIT8_4
	       * (refp_block->prev_block.isInitialized()) ? uchar_t(1) : uchar_t(0)
	    + bits::BIT8_5
	       * (refp_block->next_block.isInitialized()) ? uchar_t(1) : uchar_t(0)
	;
#endif
	return mark;
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation1(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result = bit_mask == (bits::BIT8_1 | bits::BIT8_5);
	return result;
#else
	return bit_mask & (bits::BIT8_1 | bits::BIT8_5);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation2(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result
	= ( bit_mask == (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_4)
	    || bit_mask == (bits::BIT8_0 | bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_4)
	    || bit_mask == (bits::BIT8_0 | bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_4
	                    | bits::BIT8_5) );
	return result;
#else
	return bit_mask & (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_4);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation3(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result
	= (bit_mask == (bits::BIT8_2 | bits::BIT8_5)
	   || bit_mask == (bits::BIT8_2 | bits::BIT8_4 | bits::BIT8_5)
	   || bit_mask == (bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_4 | bits::BIT8_5));
	return result;
#else
	return bit_mask & (bits::BIT8_2 | bits::BIT8_5);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation4(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result = bit_mask == (bits::BIT8_4);
	return result;
#else
	return bit_mask & (bits::BIT8_4);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation5(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result = (bit_mask == (bits::BIT8_1 | bits::BIT8_3));
	return result;
#else
	return bit_mask & (bits::BIT8_1 | bits::BIT8_3);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation6(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result
	= (bit_mask == (bits::BIT8_0 | bits::BIT8_2)
	|| bit_mask == (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_3)
	|| bit_mask == (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_5)
	|| bit_mask == (bits::BIT8_0 | bits::BIT8_1 | bits::BIT8_2)
	|| bit_mask == (bits::BIT8_0 | bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_3)
	|| bit_mask == (bits::BIT8_0 | bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_5));
	return result;
#else
	return bit_mask & (bits::BIT8_0 | bits::BIT8_2 | bits::BIT8_3);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation7(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result = (bit_mask == (bits::BIT8_2)
	            || bit_mask == (bits::BIT8_2 | bits::BIT8_3)
	            || bit_mask == (bits::BIT8_2 | bits::BIT8_4)
	            || bit_mask == (bits::BIT8_1 | bits::BIT8_2)
	            || bit_mask == (bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_3)
	            || bit_mask == (bits::BIT8_1 | bits::BIT8_2 | bits::BIT8_4));
	return result;
#else
	return bit_mask & (bits::BIT8_2 | bits::BIT8_3);
#endif
}

template<typename T> bool
ArrayBlocks<T>::__block_isSituation8(const uchar_t bit_mask)
{
#ifdef DEBUG
	bool result = bit_mask == (bits::BIT8_3);
	return result;
#else
	return bit_mask & (bits::BIT8_3);
#endif
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
	case FROM_NULL :
		if(prev_block.isInitialized())
		{
			size += prev_block->_block_getSize(FROM_BACK);
		}
		if(next_block.isInitialized())
		{
			size += next_block->_block_getSize(FROM_FRONT);
		}
		break;
	default : break;
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
	case FROM_NULL :
		if(prev_block.isInitialized())
		{
			capacity += prev_block->_block_getCapacity(FROM_BACK);
		}
		if(next_block.isInitialized())
		{
			capacity += next_block->_block_getCapacity(FROM_FRONT);
		}
		break;
	default : break;
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
			array_call_distructors(
			    this->arr_size,
			    this->inc_arr + this->arr_first_index
			);
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
			array_call_distructors(
			    this->arr_size,
			    this->inc_arr + this->arr_first_index
			);
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
				array_rewrite(
				    this->inc_arr, this->arr_capacity - 1 - i,
				    this->inc_arr[this->arr_first_index + this->arr_size - 1 - i]
				);
				array_call_distructors(1,
				    this->inc_arr + this->arr_first_index + this->arr_size - 1 - i
				);
				
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
					return next_block->_block_at(
					           local_index - this->arr_size,
					           FROM_FRONT
					       );
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
	default : break;
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
	return parent::isEmpty();
}

template<typename T>
typename ArrayBlocks<T>::parent::iterator
ArrayBlocks<T>::_block_simple_begin()
{
	return parent::begin();
}
template<typename T>
typename ArrayBlocks<T>::parent::iterator
ArrayBlocks<T>::_block_simple_end()
{
	return parent::end();
}

template<typename T>
typename ArrayBlocks<T>::parent::reverse_iterator
ArrayBlocks<T>::_block_simple_rbegin()
{
	return parent::rbegin();
}
template<typename T>
typename ArrayBlocks<T>::parent::reverse_iterator
ArrayBlocks<T>::_block_simple_rend()
{
	return parent::rend();
}

template<typename T>
ArrayBlocks<T> *
ArrayBlocks<T>::_block_getFirstBlock()
{
	ArrayBlocks<T> *p_block = this;
	
	while(p_block->prev_block.isInitialized())
	{ p_block = p_block->prev_block.operator ->(); }
	
	return p_block;
}

template<typename T>
ArrayBlocks<T> *
ArrayBlocks<T>::_block_getLastBlock()
{
	ArrayBlocks<T> *p_block = this;
	
	while(p_block->next_block.isInitialized())
	{ p_block = p_block->next_block.operator ->(); }
	
	return p_block;
}

template<typename T>
BlockIndex<T>
ArrayBlocks<T>::_block_findBlock(size_t index)
{
	BlockIndex<T> block_index;
	
	iterator it = this->begin();
	reverse_iterator rev_it = this->rbegin();
	
	block_index.current_size = this->getSize();
	block_index.current_capacity = this->getCapacity();
	auto last_index = block_index.current_size - 1;
	
	size_t i = 0, j = last_index;
	
	block_index.global_index = index;
	for(; i <= last_index; ++i, --j, ++it, ++rev_it)
	{
		if(i == index)
		{
			block_index.p_block
			  = block_index.it_back.inc_block
			    = it.inc_block;
			
			block_index.it_front = it;
			block_index.it_back.inc_data_iterator = it.inc_data_iterator;
			
			i = last_index + 1;
			
		} else if(j == index)
		{
			block_index.p_block
			  = block_index.it_back.inc_block
			    = rev_it.inc_block;
			
			block_index.it_front.inc_data_iterator = rev_it.inc_data_iterator;
			block_index.it_back = rev_it;
			
			i = last_index + 1;
		}
	}
	
	return block_index;
}

template<typename T>
template<typename TArrayBlockIterator>
BlockIndex<T>
ArrayBlocks<T>::_block_findBlock(const TArrayBlockIterator &element_iterator)
{
	T *element_address = &(*element_iterator);
	BlockIndex<T> block_index;
	
	block_index.current_size = this->getSize();
	block_index.current_capacity = this->getCapacity();
	
	size_t global_index_front(0), global_index_back(block_index.current_size - 1);
	
	iterator         & ref_it_front = block_index.it_front;
	reverse_iterator & ref_it_back  = block_index.it_back;
	
	auto it     = this->begin(); auto it_back     = this->rbegin();
	auto it_end = this->end();   auto it_back_end = this->rend();
	
	for(; (it != it_end) && (it_back != it_back_end);
	    ++it, ++it_back, ++global_index_front, --global_index_back)
	{
		if(it.operator ->() == element_address)
		{
			block_index.p_block = it.inc_block;
			
			ref_it_front.inc_block         = it.inc_block;
			ref_it_front.inc_data_iterator = it.inc_data_iterator;
			
			ref_it_back.inc_block = it.inc_block;
			ref_it_back.inc_data_iterator = it.inc_data_iterator;
			
			block_index.global_index = global_index_front;
			
			it = it_end;
		}
		else if(it_back.operator ->() == element_address)
		{
			block_index.p_block = it_back.inc_block;
			
			ref_it_front.inc_block         = it_back.inc_block;
			ref_it_front.inc_data_iterator = it_back.inc_data_iterator;
			
			ref_it_back.inc_block         = it_back.inc_block;
			ref_it_back.inc_data_iterator = it_back.inc_data_iterator;
			
			block_index.global_index = global_index_back;
			
			it = it_end;
		}
	}
	
	return block_index;
}

template<typename T>
template<typename TInputIt, typename TOutIt>
inline void 
ArrayBlocks<T>::_block_move_elements(size_t new_cells,
                                     TInputIt & source_first,
                                     TInputIt & source_last,
                                     TOutIt & target_it)
{
	auto source_it = source_first;
	for(auto i = new_cells;
	    i != 0 && &(*source_it) != &(*source_last);
	    --i, ++source_it, ++target_it)
	{
		placement_new(&(*target_it), move(*source_it));
	}
	for(; &(*source_it) != &(*source_last);
	    ++source_it, ++target_it)
	{
		*target_it = move(*source_it);
	}
}

template<typename T>
template<bool is_insert,
         typename TIndexType, typename TConcrete>
inline int
ArrayBlocks<T>::_block_generic_change_size(TIndexType &index_type,
                                           TConcrete *obj)
{
	BlockIndex<T> block_index = _block_findBlock(index_type);
	
	if(block_index.global_index == 0)
	{
		if(is_insert)
		{
			this->pushFront(
			    is_same_types<TConcrete, T>()
			    ?
			        move(*obj)
			    :
			        *(obj)
			);
		}
		else
		{
			this->popFront();
		}
		return 1;
	}
	
	if(block_index.global_index == block_index.current_size - is_insert)
	{
		if(is_insert)
		{
			this->pushBack(
			    is_same_types<TConcrete, T>()
			    ?
			        move(*obj)
			    :
			        *(obj)
			);
		}
		else
		{
			this->popBack();
		}
		return 1;
	}
	
	return _block_generic_change_size_option<is_insert, TConcrete>
	           (block_index, obj);
}


template<typename T>
template<bool is_insert,
         typename TConcrete>
inline int
ArrayBlocks<T>::_block_generic_change_size_option(BlockIndex<T> &block_index,
                                                  TConcrete *obj)
{
	using namespace flame_ide;
	using namespace flame_ide::types::primitive;
	
	typedef ArrayBlocks<T> * ArrayBlocksPointer;
	ArrayBlocksPointer &p_block = block_index.p_block;
	
	// Тут описаны нюансы
	// при добавлении в конец неправильно срабатывает
	uchar_t b_mask = this->__block_generateBitMask(block_index);
	if( (is_insert
	     && (__block_isSituation1(b_mask) || __block_isSituation2(b_mask)
	         || __block_isSituation5(b_mask) || __block_isSituation6(b_mask)))
	    || (!is_insert
	        && (__block_isSituation3(b_mask) || __block_isSituation4(b_mask)
	            || __block_isSituation7(b_mask) || __block_isSituation8(b_mask))) )
	{
		iterator it_source;
		iterator it_target;
		
		if(is_insert)
		{
			it_source = p_block->begin();
			if(__block_isSituation6(b_mask))
			{
				p_block->_block_init_spPrevBlock();
				p_block = p_block->prev_block.operator ->();
			}
			else
			{
				p_block = p_block->_block_getFirstBlock();
				if(p_block->arr_size == p_block->arr_capacity)
				{
					p_block->_block_init_spPrevBlock();
					p_block = p_block->prev_block.operator ->();
				}
			}
			p_block->arr_first_index--;
			p_block->arr_size++;
			
			it_target = p_block->begin();
			
			// всё готово для перемещения и вставки
			_block_move_elements(1, it_source, block_index.it_front, it_target);
			--block_index.it_front;
			(is_same_types<T, TConcrete>())
				? *block_index.it_front = move(*obj)
				: *block_index.it_front = *obj;
		}
		else // erase
		{
			
		}
	}
	else
	if( (!is_insert
	     && (__block_isSituation1(b_mask) || __block_isSituation2(b_mask)
	         || __block_isSituation5(b_mask) || __block_isSituation6(b_mask)))
	    || (is_insert
	        && (__block_isSituation3(b_mask) || __block_isSituation4(b_mask)
	            || __block_isSituation7(b_mask) || __block_isSituation8(b_mask))) )
	{
		reverse_iterator it_source;
		reverse_iterator it_target;
		
		if(is_insert)
		{
			it_source = p_block->rbegin();
			if(__block_isSituation7(b_mask))
			{
				p_block->_block_init_spNextBlock();
				p_block = p_block->next_block.operator ->();
			}
			else
			{
				p_block = p_block->_block_getLastBlock();
				if(p_block->arr_size == p_block->arr_capacity)
				{
					p_block->_block_init_spNextBlock();
					p_block = p_block->next_block.operator ->();
				}
			}
			p_block->arr_last_index++;
			p_block->arr_size++;
			
			it_target = p_block->rbegin();
			
			// всё готово для перемещения и вставки
			_block_move_elements(1, it_source, block_index.it_back, it_target);
			--block_index.it_back;
			(is_same_types<T, TConcrete>())
				? *block_index.it_back = move(*obj)
				: *block_index.it_back = *obj;
		}
		else //erase
		{
			
		}
	}
	
	
	return 1;
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
//	auto p_block = _block_getFirstBlock();
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
//	auto p_block = _block_getLastBlock();
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
	return _block_generic_change_size
	    <true, size_t, const T>(pos_index, &obj);
}

template<typename T>
int
ArrayBlocks<T>::insert(size_t pos_index, T &&obj)
{
	return _block_generic_change_size
	    <true, size_t, T>(pos_index, &obj);
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::insert(TArrayBlockIterator pos_it, const T &obj)
{
	return _block_generic_change_size
	    <true, TArrayBlockIterator, const T>(pos_it, &obj);
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::insert(TArrayBlockIterator pos_it, T &&obj)
{
	return _block_generic_change_size
	    <true, TArrayBlockIterator, T> (pos_it, &obj);
}

template<typename T>
template<typename TArrayBlockIterator, typename TInputIt>
int
ArrayBlocks<T>::insert(TArrayBlockIterator position,
					   TInputIt start,
			           TInputIt end)
{
	return 1;
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
ArrayBlocks<T>::erase(size_t pos_index)
{
	return _block_generic_change_size
			<false, size_t, void>(pos_index);
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::erase(TArrayBlockIterator &pos_it)
{
	return _block_generic_change_size
			<false, TArrayBlockIterator, void>(pos_it);
}

template<typename T>
template<typename TArrayBlockIterator>
int
ArrayBlocks<T>::erase(TArrayBlockIterator &start, TArrayBlockIterator &end)
{
	return 1;
}

template<typename T>
void
ArrayBlocks<T>::clear()
{
	ObjectBytes<T> _t_bytes;
	T *& ref_object = _t_bytes.bytes.r_obj;
	
	auto it = begin();
	auto it_end = end();
	for(; it != it_end; ++it)
	{
		(*it).~T();
		ref_object = &(*it);
		_t_bytes.nulling();
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
typename ArrayBlocks<T>::iterator
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
typename ArrayBlocks<T>::iterator
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
typename ArrayBlocks<T>::reverse_iterator
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
typename ArrayBlocks<T>::reverse_iterator
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
#endif // TEMPLATES_ARRAYBLOCKS
