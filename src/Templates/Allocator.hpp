#ifndef TEMPLATES_ALLOCATOR
#define TEMPLATES_ALLOCATOR

#include <Templates/ForAll.h>

namespace flame_ide
{namespace templates
{

template<typename T>
class InterfaceAllocator
{
	virtual void* __allocate();
	virtual void  __deallocate(void* pointer, unsigned long size);
	
	virtual T*   __construct();
	virtual void __destroy(T* t_pointer);
public:
	void* allocate();
	void  deallocate(void* pointer, unsigned long size);
	
	T* construct();
	template<class ... TArgs>
	T* construct();
	
	void destroy(T* t_pointer);
}

template<typename T>
class Allocator : public InterfaceAllocator<T>
{};

template<typename T>
class StackAllocator : public InterfaceAllocator
{};

}}

#endif // TEMPLATES_ALLOCATOR
