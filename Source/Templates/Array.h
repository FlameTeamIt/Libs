#ifndef TEMPLATES_ARRAY
#define TEMPLATES_ARRAY

#include <Templates/SimpleArray.h>

namespace flame_ide
{ namespace templates
{

template<class T>
class Array : public SimpleArray<T>
{
protected:
	size_t arr_size;
	
public:
	Array();
	Array(size_t length, const T* array);
	Array(const Array<T> &array);
	Array(Array<T> &&array);
	Array(size_t arr_size);
	
	~Array();
	
	void pushBack(const T &data);
	void pushFront(const T &data);
	
	void insert(size_t index, const T &data);
	void insert(size_t index, size_t count, const T *data);
	
	void popBack();
	void popFront();
	
	void popBack(size_t count);
	void popFront(size_t count);
	
	void erase(size_t index); // удаляет элемент, находящийся под этим интексом
	void erase(size_t index, size_t count); // удаляет заданное количество элементов, находящийся за этим интексом, включая текущий
	
	void clear();
	
	void   setSize(size_t new_length);
	size_t getSize() const noexcept;
	
	inline const T& at(size_t index) const;
	inline T& at(size_t index);
	
	inline const T& operator[](size_t index) const;
	inline T& operator[](size_t index);
	
	const Array<T>& operator =(const Array<T> &);
	const Array<T>& operator =(Array<T> &&);
};

}}


using namespace flame_ide::templates;

#endif // TEMPLATES_ARRAY
