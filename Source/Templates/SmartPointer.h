#ifndef TEMPLATES_SMARTPOINTER
#define TEMPLATES_SMARTPOINTER

namespace flame_ide
{namespace templates
{

template<class T>
class SmartPointer
{
	T *inc_pointer;
	bool is_initilized;
	
	SmartPointer(const SmartPointer &pointer);
	
protected:
	void set(SmartPointer& pointer);
	
public:
	SmartPointer();
	SmartPointer(const T &object);
	SmartPointer(SmartPointer &&pointer);
	
	~SmartPointer();
	
	template<class ... Ts>
	void make(Ts ... args);
	
	void clear();
	
	const T* getPointer() const;
	
	T& operator *() noexcept;
	T* operator ->() noexcept;
	
	const T& operator *() const noexcept;
	const T* operator ->() const noexcept;
	
	const SmartPointer& operator =(SmartPointer<T> &arg);
	const SmartPointer& operator =(const T &arg);
};

template<class T, class ... Ts>
SmartPointer<T> make(Ts ... args);

}}

using namespace flame_ide::templates;

template<class T>
SmartPointer<T>::SmartPointer()
{
	inc_pointer = nullptr;
}

template<class T>
SmartPointer<T>::SmartPointer(const T &object)
{
	make(object);
}

template<class T>
SmartPointer<T>::SmartPointer(SmartPointer &&pointer)
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
SmartPointer<T>::set(SmartPointer &pointer)
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
const SmartPointer<T>& 
SmartPointer<T>::operator =(SmartPointer<T> &arg)
{
	this->clear();
	this->set(arg);
	
	return *this;
}
template<class T>
const SmartPointer<T>& 
SmartPointer<T>::operator =(const T &arg)
{
	this->clear();
	this->make(arg);
	
	return *this;
}

template<class T, class ... Ts>
SmartPointer<T> make(Ts ... args)
{
	SmartPointer<T> pointer;
	pointer.make(args ...);
	
	return pointer;
}

#endif // SMARTPOINTER_H

