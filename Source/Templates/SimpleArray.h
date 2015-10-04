#ifndef SIMPLEARRAY
#define SIMPLEARRAY

#ifndef OBJ_BLOCK_SIZE
#define OBJ_BLOCK_SIZE 64
#endif

#include <Templates/Array_Functions.h>

namespace flame_ide
{ namespace templates
{

template<class T>
class SimpleArray
{
	void _simple_setInit(size_t init_size);
	void _simple_setCopy(const SimpleArray<T> &array);
	void _simple_setMove(SimpleArray<T> &array);
	
protected:
	static const unsigned long _OBJ_BLOCK_SIZE = OBJ_BLOCK_SIZE;
	size_t real_arr_size;
	T* inc_arr;
	
	T* _getSimpleArrayCopy() const;
	
public:
	SimpleArray();
	SimpleArray(bool set_default_size);
	SimpleArray(const size_t &init_size);
	SimpleArray(const SimpleArray<T> &array);
	SimpleArray(SimpleArray<T> &&array);
	
	virtual ~SimpleArray();
	
	virtual void   setSize(size_t size);
	virtual size_t getSize() const noexcept;
	
	virtual const T& at(size_t index) const;
	virtual       T& at(size_t index);
	
	void rewrite(size_t pos, const T &object);
	virtual void clear();
	
	bool isInitialized() const noexcept;
	
	const SimpleArray<T>& operator =(const SimpleArray<T> &array);
	const SimpleArray<T>& operator =(SimpleArray<T> &&array);
	
	virtual const T& operator [](size_t index) const;
	virtual       T& operator [](size_t index);
};

}}


using namespace flame_ide::templates;

template<class T>
SimpleArray<T>::SimpleArray()
	: real_arr_size(0), inc_arr(nullptr)
{}
template<class T>
SimpleArray<T>::SimpleArray(bool set_default_size)
    : SimpleArray()
{
	if(set_default_size)
	{
		this->_simple_setInit(_OBJ_BLOCK_SIZE);
	}
}
template<class T>
SimpleArray<T>::SimpleArray(const size_t &init_size)
{
	this->_simple_setInit(init_size);
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
	if(real_arr_size)
	{
		array_delete(inc_arr);
	}
}

// protected

template<class T>
T*
SimpleArray<T>::_getSimpleArrayCopy() const
{
	return array_get_copy(real_arr_size, inc_arr);
}

template<class T>
void
SimpleArray<T>::_simple_setInit(size_t init_size)
{
	this->real_arr_size = init_size;
	this->inc_arr = array_get_new<T>(init_size);
}
template<class T>
void
SimpleArray<T>::_simple_setCopy(const SimpleArray<T> &array)
{
	this->real_arr_size = array.real_arr_size;
	this->inc_arr = array._getSimpleArrayCopy();
}
template<class T>
void
SimpleArray<T>::_simple_setMove(SimpleArray<T> &array)
{
	this->real_arr_size = array.real_arr_size;
	this->inc_arr = array.inc_arr;
	
	array.real_arr_size = 0;
}

// public

template<class T>
void 
SimpleArray<T>::setSize(size_t new_size)
{
	if(this->inc_arr)
	{
		if(new_size > this->real_arr_size)
		{
			this->real_arr_size = new_size;
			
			T* new_inc_arr = array_get_new<T>(new_size);
			array_copying(this->real_arr_size, this->inc_arr,
						  new_inc_arr);
			array_delete(inc_arr);
			
			this->inc_arr = new_inc_arr;
		}
	}
	else
	{
		this->real_arr_size = new_size;
		inc_arr = array_get_new<T>(new_size);
	}
}


template<class T>
size_t
SimpleArray<T>::getSize() const noexcept
{
	return real_arr_size;
}

template<class T>
const T&
SimpleArray<T>::at(size_t index) const
{
	return inc_arr[index % real_arr_size];
}
template<class T>
T&
SimpleArray<T>::at(size_t index)
{
	return inc_arr[index % real_arr_size];
}

template<class T>
void
SimpleArray<T>::rewrite(size_t pos, const T &object)
{
	if(pos < real_arr_size)
	{
		array_rewrite(this->inc_arr, pos, object);
	}
}

template<class T>
void
SimpleArray<T>::clear()
{
	if(real_arr_size)
	{
		real_arr_size = 0;
		array_delete(this->inc_arr);
	}
}

template<class T>
bool
SimpleArray<T>::isInitialized() const noexcept
{
	return (real_arr_size != 0);
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
const T&
SimpleArray<T>::operator [](size_t index) const
{
	return inc_arr[index];
}
template<class T>
T&
SimpleArray<T>::operator [](size_t index)
{
	return inc_arr[index];
}

#undef OBJ_BLOCK_SIZE
#endif // SIMPLEARRAY

