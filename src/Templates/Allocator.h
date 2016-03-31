#ifndef TEMPLATES_ALLOCATOR
#define TEMPLATES_ALLOCATOR

#include <Templates/ForAll.h>

namespace flame_ide
{namespace templates
{


template<typename T>
struct Allocator
{
	static void* allocate();
	static void  deallocate(void* pointer, unsigned long size);
	
	static T* construct();
	template<class ... TArgs>
	static T* construct();
	
	static void destroy(T* t_pointer);
};

template<typename T>
struct StackAllocator
{
	static void* allocate();
	static void  deallocate(void* pointer, unsigned long size);
	
	static T construct();
	template<class ... TArgs>
	static T construct(TArgs && ... args);
	
	static void destroy(T* t_pointer);
};

}}

#endif // TEMPLATES_ALLOCATOR
