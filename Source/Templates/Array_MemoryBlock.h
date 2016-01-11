#ifndef TEMPLATES_ARRAY_STRUCTURES
#define TEMPLATES_ARRAY_STRUCTURES

#include <Templates/Pointers.h>
#include <Templates/SimpleArray.h>

/*
Что сделано:
1. Реализованы все конструкторы и деструктор

Что нужно сделать и поодумать, как сделать:
1. Вставка/удаление вперёд/назад
   1.1. Может даже стоит это делегировать Array
   1.1.1. Вставка и удаление присходят локально
   1.1.2. Если нужно будет удалить диапозон - надо думать
2. Вставка/удаление в произвольном месте произвольное количество объектов
   2.1. Может даже стоит это делегировать Array
3. Индексация - делегирование на Array или здесь внутри.
   3.1 Или вообще использовать только для внутреннего пользования
*/

namespace flame_ide
{namespace templates
{

template<class T>
class MemoryBlock : public SimpleArray<T>
{
	inline void _block_setInit(size_t init_size);
	inline void _block_setCopy(const MemoryBlock<T> &block);
	inline void _block_setMove(MemoryBlock<T> &block);
	
protected:
	typedef MemoryBlock<T> my_type;
	
	bool is_main;
	bool is_end;
	bool is_front_adding;
	
	size_t first_index, last_index;
	size_t block_start_index; // start/end index in block list
	
	SharedPointer<my_type> prev_block;
	SharedPointer<my_type> next_block;
	
public:
	
	MemoryBlock();
	MemoryBlock(size_t init_size);
	template<typename TSize_Type>
	MemoryBlock(TSize_Type init_size);
	
	MemoryBlock(bool is_front_adding);
	MemoryBlock(bool is_front_adding, size_t init_size);
	template<typename TSize_Type>
	MemoryBlock(bool is_front_adding, TSize_Type init_size);
	
	
	MemoryBlock(const MemoryBlock<T> &array);
	MemoryBlock(MemoryBlock<T> &&array);
	
	virtual ~MemoryBlock();
	
	SharedPointer<my_type> getNext();
	SharedPointer<my_type> getPrev();
	
	bool isEndBlock() const noexcept;
	
	int pushFront(const T &obj);
	int pushFront(T &&obj);
	
	int pushBack(const T &obj);
	int pushBack(T &&obj);
	
	int popFront(size_t count = 1);
	int popBack(size_t count = 1);
	
	int erase(size_t pos_index, size_t count = 1); // tested
	
	void clear();
	
	const T& at(size_t index) const;
	      T& at(size_t index);
	
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
	: SimpleArray<T>()
	, is_main(true)
	, is_end(false)
	, is_front_adding(false)
	, first_index(0)
	, last_index(0)
	, block_start_index(0)
	, prev_block(make_shared<my_type>(true))
//	, next_block(make_shared<my_type>(true))
{
	prev_block->is_front_adding = true;
}

template<typename T>
MemoryBlock<T>::MemoryBlock(size_t init_size)
	: SimpleArray<T>(init_size)
	, is_main(true)
	, is_end(false)
	, is_front_adding(false)
	, first_index(0)
	, last_index(0)
	, block_start_index(0)
	, prev_block(make_shared<my_type>(true))
//	, next_block(make_shared<my_type>(true))
{
	
}

template<typename T>
template<typename TSize_Type>
MemoryBlock<T>::MemoryBlock(TSize_Type init_size)
	: SimpleArray<T>(init_size)
	, is_main(true)
	, is_end(false)
	, is_front_adding(false)
	, first_index(0)
	, last_index(0)
	, block_start_index(0)
	, prev_block(make_shared<my_type>(true, init_size))
//	, next_block(make_shared<my_type>(true))
{
	
}

template<typename T>
MemoryBlock<T>::MemoryBlock(bool is_front_adding)
	: SimpleArray<T>()
	, is_main(false)
	, is_end(true)
	, is_front_adding(is_front_adding)
	, first_index(0)
	, last_index(0)
	, block_start_index(0)
{}

template<typename T>
MemoryBlock<T>::MemoryBlock(bool is_front_adding, size_t init_size)
	: SimpleArray<T>(init_size)
	, is_main(false)
	, is_end(true)
	, is_front_adding(is_front_adding)
	, first_index(is_front_adding ? init_size : 0)
	, last_index(is_front_adding ? init_size : 0)
	, block_start_index(0)
{}

template<typename T>
template<typename TSize_Type>
MemoryBlock<T>::MemoryBlock(bool is_front_adding, TSize_Type init_size)
	: SimpleArray<T>(init_size)
	, is_main(false)
	, is_end(true)
	, is_front_adding(is_front_adding)
	, first_index(is_front_adding ? init_size : 0)
	, last_index(is_front_adding ? init_size : 0)
	, block_start_index(0)
{}

template<typename T>
MemoryBlock<T>::~MemoryBlock()
{
	if(this->arr_capaity && this->arr_size)
	{
		array_call_distructors(this->arr_size,
		                       this->inc_arr + first_index);
		array_delete(this->inc_arr);
	}
	this->arr_capaity = 0;
}

template<typename T>
SharedPointer<MemoryBlock<T>>
MemoryBlock<T>::getNext()
{
	return next_block;
}
template<typename T>
SharedPointer<MemoryBlock<T>>
MemoryBlock<T>::getPrev()
{
	return prev_block;
}

template<typename T>
bool
MemoryBlock<T>::isEndBlock() const noexcept
{
	return is_end;
}

template<typename T>
int
MemoryBlock<T>::pushFront(const T &obj)
{
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
int
MemoryBlock<T>::pushFront(T &&obj)
{
	if(this->is_front_adding)
	{
		return 1;
	}
	else
	{
		// нужно сдвинуть массив на один элемент вправо
		return 1;
	}
}

template<typename T>
int
MemoryBlock<T>::pushBack(const T &obj)
{
	if(this->is_front_adding)
	{
		// нужно сдвинуть массив на один элемент влево
		return 1;
	}
	else
	{
		return this->SimpleArray.pushBack(obj);
	}
}

template<typename T>
int
MemoryBlock<T>::pushBack(T &&obj)
{
	if(this->is_front_adding)
	{
		return 1;
	}
	else
	{
		this->SimpleArray.pushBack(obj);
	}
}

template<typename T>
int
MemoryBlock<T>::popFront(size_t count)
{
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
int
MemoryBlock<T>::popBack(size_t count)
{
	if(this->is_front_adding)
	{
		return 1;
	}
	else
	{
		return this->SimpleArray.popBack(count);
	}
}

template<typename T>
int
MemoryBlock<T>::erase(size_t pos_index, size_t count)
{
	if(!this->is_front_adding)
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
	if(is_main)
	{
		if(prev_block.isInitialized() && !prev_block->isEmpty())
		{
			prev_block->clear();
		}
		
		if(next_block.isInitialized() && !next_block->isEmpty())
		{
			next_block->clear();
		}
	}
	else
	{
		if(is_front_adding)
		{
			if(prev_block.isInitialized() && !prev_block->isEmpty())
			{
				prev_block->clear();
			}
		}
		else
		{
			if(next_block.isInitialized() && !next_block->isEmpty())
			{
				next_block->clear();
			}
		}
	}
	
	if(this->arr_size != 0)
	{
		array_call_distructors(this->arr_size,
		                       this->inc_arr + this->first_index);
	}
}

template<typename T>
const T&
MemoryBlock<T>::operator [](size_t index) const noexcept
{
	return this->inc_arr
	       + this->first_index
	       + index;
}

template<typename T>
T&
MemoryBlock<T>::operator [](size_t index) noexcept
{
	return this->inc_arr
	       + this->first_index
	       + index;
}

template<typename T>
template<typename TSize_Type>
const T&
MemoryBlock<T>::operator [](TSize_Type index) const noexcept
{
	return this->inc_arr
	       + this->first_index
	       + static_cast<size_t>(index);
}

template<typename T>
template<typename TSize_Type>
T&
MemoryBlock<T>::operator [](TSize_Type index) noexcept
{
	return this->inc_arr
	       + this->first_index
	       + static_cast<size_t>(index);
}

template<typename T>
const MemoryBlock<T>&
MemoryBlock<T>::operator =(const MemoryBlock<T> &block)
{
	return this;
}

template<typename T>
const MemoryBlock<T>&
MemoryBlock<T>::operator =(MemoryBlock<T> &&block)
{
	return this;
}

#endif // TEMPLATES_ARRAY_STRUCTURES
