#ifndef POINTERS_SHAREDPOINTER
#define POINTERS_SHAREDPOINTER

#include <Templates/Pointers.h>

namespace flame_ide
{namespace templates
{

template<class T>
class SharedPointer : public BasicPointer<T>
{
	unsigned long counter;
	
protected:
	inline void set(SharedPointer<T> &pointer);
	
public:
	SharedPointer();
	SharedPointer(const T &object);
	SharedPointer(SharedPointer<T> &&pointer);
	explicit SharedPointer(const SharedPointer<T> &pointer);
	
	~SharedPointer();
	
	inline void clear();
	
	inline T& operator *();
	inline T* operator ->();
	
	inline const T& operator *() const;
	inline const T* operator ->() const;
	
	inline const SharedPointer& operator =(const SharedPointer<T> &arg);
	inline const SharedPointer& operator =(SharedPointer<T> &&arg);
	inline const SharedPointer& operator =(const T &arg);
	
	inline const SharedPointer& operator =(const BasicPointer<T> &arg);
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
	, counter(0)
{
}
template<class T>
SharedPointer<T>::SharedPointer(const T &object)
	: BasicPointer<T>(object)
	, counter(0)
{
}
template<class T>
SharedPointer<T>::SharedPointer(SharedPointer<T> &&pointer)
	: counter(0)
{
	set(pointer);
}
template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &pointer)
	: SharedPointer<T>()
{
	this->inc_pointer = pointer.inc_pointer;
	this->counter = pointer.counter + 1;
}

template<class T>
SharedPointer<T>::~SharedPointer()
{
	if(!counter && this->inc_pointer != nullptr)
	{
		delete this->inc_pointer;
	}
}

template<class T>
void
SharedPointer<T>::set(SharedPointer<T> &pointer)
{
	this->inc_pointer = pointer.inc_pointer;
	pointer.inc_pointer = nullptr;
}

template<class T>
void
SharedPointer<T>::clear()
{
	if(!counter && this->inc_pointer != nullptr)
	{
		delete this->inc_pointer;
	}
	else
	{
		counter = 0;
	}
	this->inc_pointer = nullptr;
}

// operators

template<class T>
T&
SharedPointer<T>::operator *()
{
	return this->get_reference();
}
template<class T>
T*
SharedPointer<T>::operator ->()
{
	return this->get_pointer();
}

template<class T>
const T&
SharedPointer<T>::operator *() const
{
	return this->get_reference();
}
template<class T>
const T*
SharedPointer<T>::operator ->() const
{
	return this->get_pointer();
}

template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(const SharedPointer<T> &pointer)
{
	clear();
	
	if(pointer.isInitialized())
	{
		this->inc_pointer = pointer.inc_pointer;
		counter = pointer.counter + 1;
	}
	
	return *this;
}
template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(SharedPointer<T> &&pointer)
{
	clear();
	
	if(pointer.isInitialized())
	{
		this->inc_pointer = pointer.inc_pointer;
		pointer.inc_pointer = nullptr;
	}
	
	return *this;
}
template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(const T &arg)
{
	clear();
	this->make(arg);
	
	return *this;
}

template<class T>
const SharedPointer<T>&
SharedPointer<T>::operator =(const BasicPointer<T> &arg)
{
	this->inc_pointer = arg.inc_pointer;
	this->counter = 1;
	
	return *this;
}

#endif // POINTERS_SHAREDPOINTER
