#ifndef TEMPLATES_ARRAY
#define TEMPLATES_ARRAY

#include <Templates/Array_Iterators.h>
#include <Templates/MemoryBlock.h>

namespace flame_ide
{namespace templates
{

template<class T>
class Array
{
	void __array_init(size_t);
	void __array_setCopy(const Array<T> &array);
	void __array_setMove(Array<T> &array);
	
public:
	size_t arr_size;
	size_t arr_capacity;
	
	Array();
	Array(size_t arr_size);
	Array(const Array<T> &array);
	Array(Array<T> &&array);
	
	~Array();
	
	int pushBack(const T &data);
	int pushFront(const T &data);
	
	int insert(size_t index, const T &data);

	int popBack(size_t count = 1);
	int popFront(size_t count = 1);
	
	void erase(size_t index);

	void clear();
	
	size_t getSize() const noexcept;
	size_t getCapacity() const noexcept;
	
	const T& at(size_t index) const;
	      T& at(size_t index);
	
	const T& operator[](size_t index) const noexcept;
	      T& operator[](size_t index)		noexcept;
	
	const Array<T>& operator =(const Array<T> &array);
	const Array<T>& operator =(Array<T> &&array);
};

}}

using namespace flame_ide::templates;

template<class T>
Array<T>::Array()
{}

template<class T>
Array<T>::Array(size_t array_size)
{}

template<class T>
Array<T>::Array(const Array<T> &array)
{
}

template<class T>
Array<T>::Array(Array<T> &&array)
{
}

template<class T>
Array<T>::~Array()
{}

template<class T>
void
Array<T>::__array_setCopy(const Array<T> &array)
{}

template<class T>
void
Array<T>::__array_init(size_t size)
{}

template<class T>
void
Array<T>::__array_setMove(Array<T> &array)
{}

#endif // TEMPLATES_ARRAY
