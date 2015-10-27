#ifndef TEMPLATES_ARRAY_STRUCTURES
#define TEMPLATES_ARRAY_STRUCTURES

#include <Templates/Pointers.h>
#include <Templates/SimpleArray.h>

namespace flame_ide
{namespace templates
{

template<class T>
class MemoryBlock : public SimpleArray<T>
{
	UniquePointer<MemoryBlock<T>> next;
	SharedPointer<MemoryBlock<T>> prev;
	
public:
	MemoryBlock();
	MemoryBlock(size_t real_size);
	MemoryBlock(int real_size);
	MemoryBlock(const MemoryBlock<T> &array);
	MemoryBlock(MemoryBlock<T> &&array);
	
	~MemoryBlock();
	
	const T& operator [](size_t index) const noexcept;
    const T& operator [](int index)    const noexcept;
	      T& operator [](size_t index)       noexcept;
	      T& operator [](int index)          noexcept;
	
	SharedPointer<MemoryBlock<T>> getNext();
	SharedPointer<MemoryBlock<T>> getPrev();
};

}}

using namespace flame_ide::templates;

template<class T>
MemoryBlock<T>::MemoryBlock()
	: SimpleArray<T>(true)
{}
template<class T>
MemoryBlock<T>::MemoryBlock(size_t real_size)
	: SimpleArray<T>(real_size)
{}

#endif // TEMPLATES_ARRAY_STRUCTURES
