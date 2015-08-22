#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

namespace flame_ide
{namespace templates
{

template<class T>
class SmartPointer
{
	mutable T *inc_pointer;
	mutable bool is_temporary;
	mutable bool is_initilized;
	
protected:
	void set(const SmartPointer& pointer);
	
public:
	SmartPointer();
	SmartPointer(T *new_pointer);
	SmartPointer(const T &object);
	SmartPointer(const SmartPointer& pointer);
	
	~SmartPointer();
	
	template<class ... Ts>
	void make(Ts ... args);
	
	void clear();
	
	const T* getPointer() const;
	
	T& operator *() noexcept;
	T* operator ->() noexcept;
	
	const T& operator *() const noexcept;
	const T* operator ->() const noexcept;
	
	SmartPointer& operator =(const SmartPointer<T> &arg);
	SmartPointer& operator =(const T &arg);
	
};

}}

using namespace flame_ide::templates;

template<class T>
SmartPointer<T>::SmartPointer()
{
	inc_pointer = nullptr;
	is_temporary = false;
}

template<class T>
SmartPointer<T>::SmartPointer(T *new_pointer)
	: SmartPointer<T>()
{
	if(new_pointer != nullptr)
	{
		this->inc_pointer = new_pointer;
		this->is_initilized = true;
	}
}

template<class T>
SmartPointer<T>::SmartPointer(const T &object)
{
	make(object);
}

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer &pointer)
	: SmartPointer<T>()
{
	set(pointer);
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
	if(is_initilized)
	{
		delete inc_pointer;
	}
}

// protected

template<class T>
void
SmartPointer<T>::set(const SmartPointer &pointer)
{
	this->inc_pointer = pointer.inc_pointer;
	this->is_initilized = true;
	
	pointer.inc_pointer = nullptr;
	pointer.is_initilized = false;
}

// public

template<class T>
template<class ... Ts>
void
SmartPointer<T>::make(Ts ... args)
{
	inc_pointer = new T(args ...);
	is_initilized = true;
}

template<class T>
void
SmartPointer<T>::clear()
{
	if(is_initilized)
	{
		delete inc_pointer;
		inc_pointer = nullptr;
		
		is_initilized = false;
	}
}

template<class T>
const T*
SmartPointer<T>::getPointer() const
{
	return inc_pointer;
}

// operators

template<class T>
T& 
SmartPointer<T>::operator *() noexcept
{
	return *inc_pointer;
}
template<class T>
T* 
SmartPointer<T>::operator ->() noexcept
{
	return inc_pointer;
}

template<class T>
const T& 
SmartPointer<T>::operator *() const noexcept
{
	return *inc_pointer;
}
template<class T>
const T* 
SmartPointer<T>::operator ->() const noexcept
{
	return inc_pointer;
}

template<class T>
SmartPointer<T>& 
SmartPointer<T>::operator =(const SmartPointer<T> &arg)
{
	this->clear();
	this->set(arg);
	
	return *this;
}
template<class T>
SmartPointer<T>& 
SmartPointer<T>::operator =(const T &arg)
{
	this->clear();
	this->make(arg);
	
	return *this;
}

#endif // SMARTPOINTER_H

