#ifndef TEMPLATES_SIMPLEARRAY
#define TEMPLATES_SIMPLEARRAY

#ifndef OBJ_BLOCK_SIZE
#define OBJ_BLOCK_SIZE 64
#endif

#include <Templates/Array_Functions.h>
#include <Templates/SimpleArray_Iterators.h>

namespace flame_ide
{namespace templates
{

template<class T>
class SimpleArray
{
	inline void _simple_setInit(size_t init_size);
	inline void _simple_setCopy(const SimpleArray<T> &array);
	inline void _simple_setMove(SimpleArray<T> &array);
	
protected:
	static const unsigned long _OBJ_BLOCK_SIZE = OBJ_BLOCK_SIZE;
	size_t arr_capaity;
	size_t arr_size;
	
	T* inc_arr;
	
	inline T* _getSimpleArrayCopy() const;
	
public:
	typedef SimpleArrayIterator<T>        iterator;
	typedef SimpleArrayReverseIterator<T> reverse_iterator;
	
	typedef const SimpleArrayIterator<T>        const_iterator;
	typedef const SimpleArrayReverseIterator<T> const_reverse_iterator;
	
	SimpleArray();
	SimpleArray(bool set_default_size);
	SimpleArray(size_t init_size);
	
	template<typename TSize_Type> SimpleArray(TSize_Type init_size);
	
	SimpleArray(const SimpleArray<T> &array);
	SimpleArray(SimpleArray<T> &&array);
	
	virtual ~SimpleArray();
	
	virtual size_t getSize() const noexcept;
	virtual size_t getMaxSize() const noexcept;
	
	virtual const T& at(size_t index) const;
	virtual       T& at(size_t index);
	
	virtual int pushBack(const T &obj);
	virtual int pushBack(T &&obj);
	
	virtual int insert(size_t pos_index, T &&obj);
	virtual int insert(size_t pos_index, const T &obj);
	
	virtual int popBack(size_t count = 1);
	
	virtual int erase(size_t pos_index, size_t count = 1);
	
	iterator begin();
	iterator end();
	
	reverse_iterator rbegin();
	reverse_iterator rend();
	
	virtual void rewrite(size_t pos, const T &object);
	virtual void clear();
	
	bool isInitialized() const noexcept;
	
	const SimpleArray<T>& operator =(const SimpleArray<T> &array);
	const SimpleArray<T>& operator =(SimpleArray<T> &&array);
	
	template<typename TSize_Type> 
	const T& operator [](TSize_Type index) const noexcept;
	template<typename TSize_Type> 
	      T& operator [](TSize_Type index)		 noexcept;
	
	virtual const T& operator [](size_t index) const noexcept;
	virtual       T& operator [](size_t index)		 noexcept;
	
};

}}


using flame_ide::templates::SimpleArray;

template<class T>
SimpleArray<T>::SimpleArray()
	: inc_arr(nullptr)
{
	arr_size = 0;
	arr_capaity = 0;
}
template<class T>
SimpleArray<T>::SimpleArray(bool set_default_size)
    : SimpleArray()
{}
template<class T>
SimpleArray<T>::SimpleArray(size_t init_size)
    : arr_size(0)
{
	this->_simple_setInit(init_size);
}
template<class T>
template<typename TSize_Type>
SimpleArray<T>::SimpleArray(TSize_Type init_size)
	: arr_size(0)
{
	size_t casted_init_size = static_cast<size_t>(init_size);
	this->_simple_setInit(casted_init_size);
}
template<class T>
SimpleArray<T>::SimpleArray(const SimpleArray &array)
{
	this->_simple_setCopy(array);
}
template<class T>
SimpleArray<T>::SimpleArray(SimpleArray &&array)
{
	this->_simple_setMove(array);
}

template<class T>
SimpleArray<T>::~SimpleArray()
{
	if(arr_capaity)
	{
		array_call_distructors(arr_size, inc_arr);
		array_delete(inc_arr);
	}
}

// protected

template<class T>
T*
SimpleArray<T>::_getSimpleArrayCopy() const
{
	return array_get_copy(arr_capaity, inc_arr);
}

template<class T>
void
SimpleArray<T>::_simple_setInit(size_t init_size)
{
	this->arr_capaity = init_size;
	this->inc_arr = array_get_new<T>(init_size);
}
template<class T>
void
SimpleArray<T>::_simple_setCopy(const SimpleArray<T> &array)
{
	this->arr_capaity = array.arr_capaity;
	this->arr_size = array.arr_size;
	this->inc_arr = array._getSimpleArrayCopy();
}
template<class T>
void
SimpleArray<T>::_simple_setMove(SimpleArray<T> &array)
{
	this->arr_capaity = array.arr_capaity;
	this->arr_size = array.arr_size;
	this->inc_arr = array.inc_arr;
	
	array.arr_capaity = 0;
}

// public

template<class T>
size_t
SimpleArray<T>::getSize() const noexcept
{
	return arr_size;
}

template<class T>
size_t
SimpleArray<T>::getMaxSize() const noexcept
{
	return arr_capaity;
}

template<class T>
const T&
SimpleArray<T>::at(size_t index) const
{
	return inc_arr[index % arr_capaity];
}
template<class T>
T&
SimpleArray<T>::at(size_t index)
{
	return inc_arr[index % arr_capaity];
}

template<class T>
int
SimpleArray<T>::pushBack(const T &obj)
{
	if(arr_size >= arr_capaity)
	{
		return -1;
	}
	else
	{
		array_copying(1, &obj, this->inc_arr+this->arr_size);
		arr_size++;
	}
	return 1;
}
template<class T>
int
SimpleArray<T>::pushBack(T &&obj)
{
	if(arr_size < arr_capaity)
	{
		inc_arr[arr_size] = T(obj);
		arr_size++;
	}
	else
	{
		return -1;
	}
	
	return 1;
}

template<class T>
int
SimpleArray<T>::insert(size_t pos_index, const T &obj)
{
	if(pos_index < this->arr_size)
	{
		array_rewrite(this->inc_arr, pos_index, obj);
	}
	else
	if(pos_index == this->arr_size)
	{
		array_copying(1, &obj, this->inc_arr+this->arr_size);
		arr_size++;
	}
	else // >
	{
		return -1;
	}
	
	return 1;
}
template<class T>
int
SimpleArray<T>::insert(size_t pos_index, T &&obj)
{
	if(pos_index < this->arr_size)
	{
		array_rewrite(this->inc_arr, pos_index, obj);
	}
	else
	if(pos_index == this->arr_size)
	{
		this->inc_arr[pos_index] = T(obj);
		arr_size++;
	}
	else // >
	{
		return -1;
	}
	
	return 1;
}

template<typename T>
int
SimpleArray<T>::popBack(size_t count)
{
	if(count <= this->arr_size)
	{
		auto tmp_index = this->arr_size - 1;
		for(size_t i = 0; i < count; ++i)
		{
			this->inc_arr[tmp_index - i].~T();
		}
		this->arr_size -= count;
	}
	else
	{
		return -1;
	}
	
	return 1;
}

template<typename T>
int
SimpleArray<T>::erase(size_t pos_index, size_t count)
{
	if(this->arr_size - pos_index - count >= 0)
	{
		for(size_t i = 0; i < count; ++i)
		{
			this->inc_arr[pos_index+i].~T();
		}
		//нужно сдвинуть по необходимости
		
		
		this->arr_size -= count;
	}
	else
	{
		return -1;
	}
	
	return 1;
}

template<class T>
void
SimpleArray<T>::rewrite(size_t pos, const T &object)
{
	if(pos <= arr_size)
	{
		array_rewrite(this->inc_arr, pos, object);
		if(pos == arr_size)
		{
			++arr_size;
		}
	}
}

template<class T>
void
SimpleArray<T>::clear()
{
	if(arr_size)
	{
		array_call_distructors(arr_size, inc_arr);
		arr_size = 0;
 	}
}

template<class T>
bool
SimpleArray<T>::isInitialized() const noexcept
{
	return (arr_capaity != 0);
}

template<class T>
const SimpleArray<T>&
SimpleArray<T>::operator =(const SimpleArray<T> &array)
{
	clear();
	_simple_setCopy(array);
	return *this;
}
template<class T>
const SimpleArray<T>&
SimpleArray<T>::operator =(SimpleArray<T> &&array)
{
	clear();
	_simple_setMove(array);
	return *this;
}

template<class T>
template<typename TSize_Type> 
const T&
SimpleArray<T>::operator [](TSize_Type index) const noexcept
{
	return inc_arr[index];
}

template<class T>
template<typename TSize_Type> 
T&
SimpleArray<T>::operator [](TSize_Type index) noexcept
{
	return inc_arr[index];
}

template<class T>
const T&
SimpleArray<T>::operator [](size_t index) const noexcept
{
	return inc_arr[index];
}

template<class T>
T&
SimpleArray<T>::operator [](size_t index) noexcept
{
	return inc_arr[index];
}

#undef OBJ_BLOCK_SIZE
#endif // TEMPLATES_SIMPLEARRAY

