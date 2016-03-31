#ifndef POINTERS_FUNCTIONS
#define POINTERS_FUNCTIONS

#include <Templates/Pointers.h>
#include <Templates/ForAll.h>

namespace flame_ide
{namespace templates
{

template<class T, class U>
BasicPointer<T>
static_pointer_cast(const BasicPointer<U>& pointer) noexcept
{
	BasicPointer<T> ret_pointer;
	if(pointer.isInitialized())
	{
		ret_pointer.inc_pointer = static_cast<T*>(pointer.inc_pointer);
	}
	
	return ret_pointer;
}
template<class T, class U>
SharedPointer<T>
static_pointer_cast(const SharedPointer<U>& pointer) noexcept
{
	SharedPointer<T> ret_pointer;
	if(pointer.isInitialized())
	{
		ret_pointer.inc_pointer = static_cast<T*>(pointer.inc_pointer);
		if(ret_pointer.inc_pointer != nullptr)
		{
			ret_pointer.is_shared = true;
		}
	}
	
	return ret_pointer;
}
template<class T, class U>
UniquePointer<T>
static_pointer_cast(UniquePointer<U>& pointer) noexcept
{
	UniquePointer<T> ret_pointer;
	if(pointer.isInitialized())
	{
		ret_pointer.inc_pointer	= static_cast<T*>(pointer.inc_pointer);
		if(ret_pointer.inc_pointer != nullptr)
		{
			pointer.inc_pointer	= nullptr;
		}
	}
	
	return ret_pointer;
}

template<class T, class U>
BasicPointer<T>
dynamic_pointer_cast(const BasicPointer<U>& pointer) noexcept
{
	BasicPointer<T> ret_pointer;
	if(pointer.isInitialized())
	{
		ret_pointer.inc_pointer = dynamic_cast<T*>(pointer.inc_pointer);
	}
	
	return ret_pointer;
}
template<class T, class U>
SharedPointer<T>
dynamic_pointer_cast(const SharedPointer<U>& pointer) noexcept
{
	SharedPointer<T> ret_pointer;
	if(pointer.isInitialized())
	{
		ret_pointer.inc_pointer = dynamic_cast<T*>(pointer.inc_pointer);
		if(ret_pointer.inc_pointer != nullptr)
		{
			ret_pointer.is_shared = true;
		}
	}
	
	return ret_pointer;
}
template<class T, class U>
UniquePointer<T>
dynamic_pointer_cast(UniquePointer<U>& pointer) noexcept
{
	UniquePointer<T> ret_pointer;
	if(pointer.isInitialized())
	{
		ret_pointer.inc_pointer = dynamic_cast<T*>(pointer.inc_pointer);
		if(ret_pointer.inc_pointer != nullptr)
		{
			pointer.inc_pointer = nullptr;
		}
	}
	
	return ret_pointer;
}

}}

#endif // POINTERS_FUNCTIONS
