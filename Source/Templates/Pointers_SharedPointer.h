#ifndef POINTERS_SHAREDPOINTER
#define POINTERS_SHAREDPOINTER

#include <Templates/Pointers.h>

namespace flame_ide
{namespace templates
{

template<class T>
class SharedPointer : public BasicPointer<T>
{
	bool is_shared;
	
protected:
	inline void set(SharedPointer<T> &pointer);
	
	virtual inline void _clear();
	
public:
	SharedPointer();
	SharedPointer(const T &object);
	SharedPointer(SharedPointer<T> &&pointer);
	SharedPointer(T* obj);
	explicit SharedPointer(const SharedPointer<T> &pointer);
	
	virtual ~SharedPointer();
	
	inline const SharedPointer& operator =(const SharedPointer<T> &arg);
	inline const SharedPointer& operator =(SharedPointer<T> &&arg);
	inline const SharedPointer& operator =(const T &arg);
	
	inline const SharedPointer& operator =(const BasicPointer<T> &arg);
	
	friend class BasicPointer<T>;

	template<class Tt, class Uu> friend
	SharedPointer<Tt>
	static_pointer_cast(const SharedPointer<Uu>& pointer) noexcept;
	template<class Tt, class Uu> friend
	SharedPointer<Tt>
	dynamic_pointer_cast(const SharedPointer<Uu>& pointer) noexcept;
};

template<class T, class ... Ts>
SharedPointer<T> make_shared(Ts&& ... args)
{
	SharedPointer<T> pointer;
	pointer.make(args ...);
	
	return pointer;
}

}}

using namespace flame_ide::templates;

template<class T>
SharedPointer<T>::SharedPointer()
	: BasicPointer<T>()
	, is_shared(false)
{}
template<class T>
SharedPointer<T>::SharedPointer(const T &object)
	: BasicPointer<T>(object)
	, is_shared(false)
{}
template<class T>
SharedPointer<T>::SharedPointer(SharedPointer<T> &&pointer)
	: is_shared(false)
{
	set(pointer);
}
template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &pointer)
	: SharedPointer<T>()
{
	this->inc_pointer = pointer.inc_pointer;
	this->is_shared = true;
}
template<class T>
SharedPointer<T>::SharedPointer(T *obj)
	: BasicPointer<T>()
	, is_shared(true)
{
	this->inc_pointer = obj;
}

template<class T>
SharedPointer<T>::~SharedPointer()
{
	if(!is_shared && this->inc_pointer != nullptr)
	{
		delete this->inc_pointer;
	}
	this->inc_pointer = nullptr;
}

template<class T>
void
SharedPointer<T>::_clear()
{
	if(!is_shared && this->inc_pointer != nullptr)
	{
		delete this->inc_pointer;
	}
	else
	{
		is_shared = false;
	}
	this->inc_pointer = nullptr;
}

template<class T>
void
SharedPointer<T>::set(SharedPointer<T> &pointer)
{
	this->inc_pointer = pointer.inc_pointer;
	pointer.inc_pointer = nullptr;
}

template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(const SharedPointer<T> &pointer)
{
	if(pointer.isInitialized())
	{
		this->clear();
		this->inc_pointer = pointer.inc_pointer;
		is_shared = true;
	}
	
	return *this;
}
template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(SharedPointer<T> &&pointer)
{
	if(pointer.isInitialized())
	{
		this->clear();
		this->inc_pointer = pointer.inc_pointer;
		if(pointer.is_shared)
		{
			this->is_shared = true;
		}
		pointer.inc_pointer = nullptr;
	}
	
	return *this;
}
template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(const T &arg)
{
	this->clear();
	this->make(arg);
	
	return *this;
}

template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(const BasicPointer<T> &arg)
{
	this->inc_pointer = arg.inc_pointer;
	this->is_shared = true;
	
	return *this;
}

#endif // POINTERS_SHAREDPOINTER
