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
	inline void _simple_setInit(size_t init_size); // tested
	inline void _simple_setCopy(const SimpleArray<T> &array); // tested
	inline void _simple_setMove(SimpleArray<T> &array); // tested
	
protected:
	size_t arr_capaity;
	size_t arr_size;
	
	T* inc_arr;
	
	inline T* _getSimpleArrayCopy() const; // tested
	
public:
	typedef SimpleArrayIterator<T>        iterator; // tested
	typedef SimpleArrayReverseIterator<T> reverse_iterator;
	
	typedef const SimpleArrayIterator<T>        const_iterator;
	typedef const SimpleArrayReverseIterator<T> const_reverse_iterator;
	
	SimpleArray(); // tested
	SimpleArray(size_t init_size); // tested
	
	template<typename TSize_Type>
	SimpleArray(TSize_Type init_size); // tested
	
	SimpleArray(const SimpleArray<T> &array); // tested
	SimpleArray(SimpleArray<T> &&array); // tested
	
	virtual ~SimpleArray(); // tested
	
	size_t getSize() const noexcept; // tested
	size_t getCapacity() const noexcept; // tested
	
	const T& at(size_t index) const;
	      T& at(size_t index);
	
	int pushBack(const T &obj); // tested
	int pushBack(T &&obj); // tested
	
	// insertion after
	int insert(size_t pos_index, T &&obj); // tested
	int insert(size_t pos_index, const T &obj);
	
	int insert(iterator it, T &&obj);
	int insert(iterator it, const T &obj);
	
	int insert(reverse_iterator it, T &&obj);
	int insert(reverse_iterator it, const T &obj);
	
	template<typename TIterator>
	int insert(const size_t pos_index,
			   const TIterator &start, const TIterator &end);  // tested
	template<typename TIterator>
	int insert(const iterator pos_index,
			   const TIterator &start, const TIterator &end);
	template<typename TIterator>
	int insert(const reverse_iterator pos_index,
			   const TIterator &start, const TIterator &end);
	
	int popBack(size_t count = 1); // tested
	
	int erase(size_t pos_index, size_t count = 1); // tested
	
	void rewrite(size_t pos, const T &object); // tested
	void clear(); // tested
	
	bool isEmpty() const noexcept;
	
	const SimpleArray<T>& operator =(const SimpleArray<T> &array); // tested
	const SimpleArray<T>& operator =(SimpleArray<T> &&array); // tested
	
	template<typename TSize_Type>
	const T& operator [](TSize_Type index) const noexcept; // tested
	template<typename TSize_Type>
	      T& operator [](TSize_Type index)		 noexcept; // tested
	
	const T& operator [](size_t index) const noexcept; // tested
	      T& operator [](size_t index)		 noexcept; // tested
	
	iterator begin(); //tested
	iterator end(); // tested
	reverse_iterator rbegin();
	reverse_iterator rend();

	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	
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
SimpleArray<T>::getSize() const noexcept // tested
{
	return arr_size;
}

template<class T>
size_t
SimpleArray<T>::getCapacity() const noexcept // tested
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
	if(this->arr_size < this->arr_capaity)
	{
		if(pos_index < this->arr_size)
		{
			if(pos_index < this->arr_size)
			{
				// сдвиг
				std::copy(this->inc_arr + pos_index,
						  this->inc_arr + this->arr_size,
						  this->inc_arr + (pos_index + 1));
			}
			array_rewrite(this->inc_arr, pos_index, obj);
		}
		else
		if(pos_index == this->arr_size)
		{
			new ((void*)this->inc_arr+pos_index) T(obj);
		}
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
	if(this->arr_size < this->arr_capaity)
	{
		if(pos_index < this->arr_size)
		{
			if(pos_index < this->arr_size)
			{
				// сдвиг
				std::copy(this->inc_arr + pos_index,
						  this->inc_arr + this->arr_size,
						  this->inc_arr + (pos_index + 1));
			}
			array_rewrite(this->inc_arr, pos_index, obj);
		}
		else
		if(pos_index == this->arr_size)
		{
			new (this->inc_arr+pos_index) T(obj);
		}
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
SimpleArray<T>::insert(iterator it, const T &obj)
{
	size_t index = this->inc_arr - it.inc_data_iterator;
	return this->insert(index, obj);
}
template<class T>
int
SimpleArray<T>::insert(iterator it, T &&obj)
{
	size_t index = this->inc_arr - it.inc_data_iterator;
	return this->insert(index, obj);
}

template<class T>
int
SimpleArray<T>::insert(reverse_iterator it, const T &obj)
{
	size_t index = this->inc_arr - it.inc_data_iterator;
	return this->insert(index, obj);
}
template<class T>
int
SimpleArray<T>::insert(reverse_iterator it, T &&obj)
{
	size_t index = this->inc_arr - it.inc_data_iterator;
	return this->insert(index, obj);
}

template<class T>
template<typename TIterator>
int
SimpleArray<T>::insert(const size_t pos_index,
					   const TIterator &start, const TIterator &end) // tested
{
	TIterator it;
	size_t count_insertion = 0;
	for(it = start; it != end; ++it)
	{
		++count_insertion;
	}
	
	if(this->arr_size + count_insertion > this->arr_capaity
		|| this->arr_size < pos_index)
	{
		return -1;
	}
	
	// далее нужно понять, на сколько нужно сдвинуть элементы, чтобы вместить
	// диапозон.
	
	// сдвигаем
	if(pos_index < this->arr_size)
	{
		std::copy(this->inc_arr + pos_index,
				  this->inc_arr + this->arr_size,
				  this->inc_arr + (pos_index + count_insertion));
	}
	
	std::copy(start, end, this->inc_arr+pos_index);
	this->arr_size = this->arr_size + count_insertion;
	
	return 1;
}
template<class T>
template<typename TIterator>
int
SimpleArray<T>::insert(const iterator it,
					   const TIterator &start, const TIterator &end) // tested
{
	size_t index = this->inc_arr - it.inc_data_iterator;
	return this->insert(index, start, end);
	return 1;
}
template<class T>
template<typename TIterator>
int
SimpleArray<T>::insert(const reverse_iterator it,
					   const TIterator &start, const TIterator &end) // tested
{
	size_t index = this->inc_arr - it.inc_data_iterator;
	return this->insert(index, start, end);
	return 1;
}

template<typename T>
int
SimpleArray<T>::popBack(size_t count) //tested
{
	if(count <= this->arr_size)
	{
		array_call_distructors(count, this->inc_arr + (arr_size-1 - count));
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
	auto tmp_size = pos_index + count;
	if(this->arr_size >= tmp_size)
	{
		for(size_t i = 0; i < count; ++i)
		{
			this->inc_arr[pos_index+i].~T();
		}
		
		//нужно сдвинуть по необходимости
		if(this->arr_size > tmp_size)
		{
			// сдвиг
			for(auto i = tmp_size; i < this->arr_size; ++i)
			{
				std::copy(this->inc_arr+tmp_size,
						  this->inc_arr+this->arr_size,
						  this->inc_arr+pos_index);
			}
		}
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
SimpleArray<T>::rewrite(size_t pos, const T &object) // tested
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
SimpleArray<T>::clear() // tested
{
	if(arr_size)
	{
		array_call_distructors(arr_size, inc_arr);
		arr_size = 0;
 	}
}

template<class T>
bool
SimpleArray<T>::isEmpty() const noexcept
{
	return (arr_size == 0);
}

template<class T>
const SimpleArray<T>&
SimpleArray<T>::operator =(const SimpleArray<T> &array) // tested
{
	clear();
	_simple_setCopy(array);
	return *this;
}
template<class T>
const SimpleArray<T>&
SimpleArray<T>::operator =(SimpleArray<T> &&array) // tested
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

template<typename T>
SimpleArrayIterator<T>
SimpleArray<T>::begin() // tested
{
	iterator it;
	it.inc_data_iterator = this->inc_arr;
	
	return it;
}

template<class T>
SimpleArrayIterator<T>
SimpleArray<T>::end() // tested
{
	iterator it;
	it.inc_data_iterator = this->inc_arr + this->arr_size;
	
	return it;
}

template<class T>
SimpleArrayReverseIterator<T>
SimpleArray<T>::rbegin()
{
	reverse_iterator it;
	it.inc_data_iterator = this->inc_arr + this->arr_size - 1;
	
	return it;
}

template<class T>
SimpleArrayReverseIterator<T>
SimpleArray<T>::rend()
{
	reverse_iterator it;
	it.inc_data_iterator = this->inc_arr - 1;
	
	return it;
}

template<class T>
const SimpleArrayIterator<T>
SimpleArray<T>::begin() const
{
	const_iterator it;
	it.inc_data_iterator = this->inc_arr;
	
	return it;
}

template<class T>
const SimpleArrayIterator<T>
SimpleArray<T>::end() const
{
	const_iterator it;
	it.inc_data_iterator = this->inc_arr + this->arr_size;
	
	return it;
}

template<class T>
const SimpleArrayReverseIterator<T>
SimpleArray<T>::rbegin() const
{
	const_reverse_iterator it;
	it.inc_data_iterator = this->inc_arr + this->arr_size - 1;
	
	return it;
}

template<class T>
const SimpleArrayReverseIterator<T>
SimpleArray<T>::rend() const
{
	const_reverse_iterator it;
	it.inc_data_iterator = this->inc_arr - 1;
	
	return it;
}

#undef OBJ_BLOCK_SIZE
#endif // TEMPLATES_SIMPLEARRAY

