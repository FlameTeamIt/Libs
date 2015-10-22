#ifndef TEMPLATES_ARRAY
#define TEMPLATES_ARRAY

#include <Templates/SimpleArray.h>
#include <Templates/Array_MemoryBlock.h>

namespace flame_ide
{ namespace templates
{

template<class T>
class Array : public SimpleArray<T>
{
	void _array_setCopy(const Array<T> &array);
	void _array_setMove(Array<T> &array);
	
protected:
	size_t head, tail, size;
	SharedPointer<MemoryBlock<T>> next, prev;
	
public:
	Array();
	Array(size_t arr_size);
	Array(const Array<T> &array);
	Array(Array<T> &&array);
	
	~Array();
	
	virtual void pushBack(const T &data);
	virtual void pushFront(const T &data);
	
	void insert(size_t index, const T &data);
#ifdef FUTURE
	void insert(size_t index, size_t count, const T *data);
#endif
	virtual void popBack();
	virtual void popFront();
	
	virtual void popBack(size_t count);
	virtual void popFront(size_t count);
	
	void erase(size_t index); // удаляет элемент, находящийся под этим интексом
#ifdef FUTURE
	void erase(size_t index, size_t count); // удаляет заданное количество элементов, находящийся за этим интексом, включая текущий
#endif	
	
	void clear();
	
	void   setSize(size_t new_size);
	size_t getSize() const noexcept;
//	size_t getCapacity() const noexcept
	
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
	: SimpleArray<T>()
{}

template<class T>
Array<T>::Array(size_t arr_size)
	: SimpleArray<T>(arr_size)
{}

// копируем. Вместо блоков сразу аллоцирую "нарощенный" размер
template<class T>
Array<T>::Array(const Array<T> &array)
	: SimpleArray<T>(array.getSize())
{
	size = getSize();
	for(size_t i = 0; i < size; i++)
	{
		// std::copy
		
		// или по блокам копировать?
	}
}

template<class T>
Array<T>::Array(Array<T> &&array)
{
	// нужно понять, как SharedPointer присвоить оператором перемещения
	// без костылей, велосипедов и std::move()
	
	// как вариант - попробовать отдебажить, что выберет компилятор
	// при присваивании
}

template<class T>
Array<T>::~Array()
{}

template<class T>
void
Array<T>::_array_setCopy(const Array<T> &array)
{}

template<class T>
void
Array<T>::_array_setMove(Array<T> &array)
{
	
}

#endif // TEMPLATES_ARRAY
