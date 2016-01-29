#ifndef POINTERS_BASICPOINTER
#define POINTERS_BASICPOINTER

#include <Templates/Pointers.h>

namespace flame_ide
{namespace templates
{

template<class T>
class BasicPointer
{
	BasicPointer(const BasicPointer<T> &pointer);
	BasicPointer(BasicPointer<T> &&pointer);
	
	const BasicPointer<T>& operator =(const BasicPointer<T> &pointer);
	const BasicPointer<T>& operator =(BasicPointer<T> &&pointer);
	
	
protected:
	mutable T *inc_pointer;
	
	inline       T* _get_pointer();
	inline       T& _get_reference();
	
	inline const T* _get_pointer() const;
	inline const T& _get_reference() const;
	
	inline virtual void _clear();
	
public:
	BasicPointer();
	BasicPointer(const T &object);
	
	virtual ~BasicPointer();
	
	template<class ... Ts>
	inline void make(Ts ... args);
	template<class ... Ts>
	inline void make(Ts ... args) const;
	
	inline void clear();
	inline const T* get() const;
	inline SharedPointer<T> getShared() const;
	
	inline bool isInitialized() const;
	
	inline operator bool() const;
	
	virtual inline       T& operator *();
	virtual inline       T* operator ->();
	
	virtual inline const T& operator *() const;
	virtual inline const T* operator ->() const;
	
	friend class SharedPointer<T>;
	friend class UniquePointer<T>;
	
	template<class Tt, class Uu> friend
	BasicPointer<Tt> static_pointer_cast(const BasicPointer<Uu>& pointer) noexcept;
	template<class Tt, class Uu> friend
	BasicPointer<Tt> dynamic_pointer_cast(const BasicPointer<Uu>& pointer) noexcept;
};

}}

using namespace flame_ide::templates;

template<class T>
BasicPointer<T>::BasicPointer()
{
	inc_pointer = nullptr;
}
template<class T>
BasicPointer<T>::BasicPointer(const T &object)
{
	make(object);
}

template<class T>
BasicPointer<T>::~BasicPointer()
{
	if(isInitialized())
	{
		delete inc_pointer;
	}
}

template<class T>
T*
BasicPointer<T>::_get_pointer()
{
	return inc_pointer;
}

template<class T>
T&
BasicPointer<T>::_get_reference()
{
	return *inc_pointer;
}

template<class T>
const T*
BasicPointer<T>::_get_pointer() const
{
	return inc_pointer;
}

template<class T>
const T&
BasicPointer<T>::_get_reference() const
{
	return *inc_pointer;
}

template<class T>
const T&
BasicPointer<T>::_clear()
{
	if(inc_pointer != nullptr)
	{
		delete inc_pointer;
		inc_pointer = nullptr;
	}
}

template<class T>
template<class ... Ts>
void
BasicPointer<T>::make(Ts ... args)
{
	inc_pointer = new T(args ...);
}
template<class T>
template<class ... Ts>
void
BasicPointer<T>::make(Ts ... args) const
{
	inc_pointer = new T(args ...);
}

template<class T>
void
BasicPointer<T>::clear()
{
	this->_clear();
}

template<class T>
const T*
BasicPointer<T>::get() const
{
	return inc_pointer;
}

template<class T>
SharedPointer<T>
BasicPointer<T>::getShared() const
{
	SharedPointer<T> pointer;
	pointer.inc_pointer = this->inc_pointer;
	pointer.is_shared = true;
	
	return pointer;
}

template<class T>
bool
BasicPointer<T>::isInitialized() const
{
	return (inc_pointer != nullptr);
}

template<class T>
BasicPointer<T>::operator bool() const
{
	return (inc_pointer != nullptr);
}

// operators

template<class T>
T*
BasicPointer<T>::operator ->()
{
	return _get_pointer();
}

template<class T>
T&
BasicPointer<T>::operator *()
{
	return _get_reference();
}

template<class T>
const T*
BasicPointer<T>::operator ->() const
{
	return _get_pointer();
}

template<class T>
const T&
BasicPointer<T>::operator *() const
{
	return _get_reference();
}

/* ----- private ----- */
//template<class T>
//const BasicPointer<T>&
//BasicPointer<T>::operator =(const BasicPointer<T> &pointer)
//{
//	this->inc_pointer = pointer.inc_pointer;
//	
//	return *this;
//}

#endif // POINTERS_BASICPOINTER
