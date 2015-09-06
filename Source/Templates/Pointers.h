#ifndef POINTERS
#define POINTERS

namespace flame_ide
{namespace templates
{

template<class T>
class BasicPointer;

template<class T>
class SharedPointer;

template<class T>
class UniquePointer;

}}

// BasicPointer

namespace flame_ide
{namespace templates
{

template<class T>
class BasicPointer
{
	BasicPointer(const BasicPointer<T> &pointer);
	BasicPointer(BasicPointer<T> &&pointer);
	
protected:
	mutable T *inc_pointer;
		
	inline       T* get_pointer();
	inline       T& get_reference();
	
	inline const T* get_pointer() const;
	inline const T& get_reference() const;
	
public:
	BasicPointer();
	BasicPointer(const T &object);
	
	~BasicPointer();
	
	template<class ... Ts>
	inline void make(Ts ... args);
	template<class ... Ts>
	inline void make(Ts ... args) const;
	
	virtual void clear();
	T* get() const;
	
	inline bool isInitialized() const;
	
	inline operator bool() const;
	
	inline       T& operator *();
	inline       T* operator ->();
	
	inline const T& operator *() const;
	inline const T* operator ->() const;
	
	inline const BasicPointer<T>&
	operator =(BasicPointer<T> &&pointer);
	
//	template<class Tt>
	friend class SharedPointer<T>;
//	template<class Tt>
	friend class UniquePointer<T>;
	
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
T* BasicPointer<T>::get_pointer()
{
	return inc_pointer;
}

template<class T>
T& BasicPointer<T>::get_reference()
{
	return *inc_pointer;
}

template<class T>
const T* BasicPointer<T>::get_pointer() const
{
	return inc_pointer;
}

template<class T>
const T& BasicPointer<T>::get_reference() const
{
	return *inc_pointer;
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
	if(inc_pointer != nullptr)
	{
		delete inc_pointer;
		inc_pointer = nullptr;
	}
}

template<class T>
T*
BasicPointer<T>::get() const
{
	return get_pointer();
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
	return get_pointer();
}

template<class T>
T&
BasicPointer<T>::operator *()
{
	return get_reference();
}

template<class T>
const T* BasicPointer<T>::operator ->() const
{
	return get_pointer();
}

template<class T>
const T& BasicPointer<T>::operator *() const
{
	return get_reference();
}

template<class T>
const BasicPointer<T>&
BasicPointer<T>::operator =(BasicPointer<T> &&pointer)
{
	this->inc_pointer = pointer.inc_pointer;
	pointer.inc_pointer = nullptr;
	
	return *this;
}


// SharedPointer

namespace flame_ide
{namespace templates
{

template<class T>
class SharedPointer : public BasicPointer<T>
{
	unsigned long counter;
	
protected:
	void set(SharedPointer<T> &pointer);
	
public:
	SharedPointer();
	SharedPointer(const T &object);
	SharedPointer(SharedPointer<T> &&pointer);
	explicit SharedPointer(const SharedPointer<T> &pointer);
	
	~SharedPointer();
	
	void clear();
	
	T& operator *();
	T* operator ->();
	
	const T& operator *() const;
	const T* operator ->() const;
	
	const SharedPointer& operator =(const SharedPointer<T> &arg);
	const SharedPointer& operator =(SharedPointer<T> &&arg);
	const SharedPointer& operator =(const T &arg);
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


// UniquePointer

namespace flame_ide
{namespace templates
{

template<class T>
class UniquePointer : public BasicPointer<T>
{
	UniquePointer(const UniquePointer &pointer);
	
protected:
	void set(UniquePointer &pointer);
	
public:
	UniquePointer();
	UniquePointer(const T &object);
	UniquePointer(UniquePointer &&pointer);
	
	~UniquePointer();
	
	inline T& operator *();
	inline T* operator ->();
	
	inline const T& operator *() const;
	inline const T* operator ->() const;
	
	inline const UniquePointer& operator =(UniquePointer<T> &arg);
	inline const UniquePointer& operator =(UniquePointer<T> &&arg);
	inline const UniquePointer& operator =(const T &arg);
};

template<class T, class ... Ts>
UniquePointer<T> make_unique(Ts&& ... args)
{
	UniquePointer<T> pointer;
	pointer.make(args ...);
	
	return pointer;
}

}}

using namespace flame_ide::templates;

template<class T>
UniquePointer<T>::UniquePointer()
	: BasicPointer<T>()
{}

template<class T>
UniquePointer<T>::UniquePointer(const T &object)
	: BasicPointer<T>(object)
{}

template<class T>
UniquePointer<T>::UniquePointer(UniquePointer &&pointer)
	: UniquePointer<T>()
{
	set(pointer);
}

template<class T>
UniquePointer<T>::~UniquePointer()
{
	if(this->inc_pointer != nullptr)
	{
		delete this->inc_pointer;
	}
}

// protected

template<class T>
void
UniquePointer<T>::set(UniquePointer &pointer)
{
	if(pointer.isInitialized())
	{
		this->inc_pointer = pointer.inc_pointer;
		pointer.inc_pointer = nullptr;
	}
}

// operators

template<class T>
T& 
UniquePointer<T>::operator *()
{
	return this->get_reference();
}
template<class T>
T* 
UniquePointer<T>::operator ->()
{
	return this->get_pointer();
}

template<class T>
const T& 
UniquePointer<T>::operator *() const
{
	return this->get_reference();
}
template<class T>
const T* 
UniquePointer<T>::operator ->() const
{
	return this->get_pointer();
}

template<class T>
const UniquePointer<T>& 
UniquePointer<T>::operator =(UniquePointer<T> &arg)
{
	this->clear();
	this->set(arg);
	
	return *this;
}
template<class T>
const UniquePointer<T>& 
UniquePointer<T>::operator =(UniquePointer<T> &&arg)
{
	this->clear();
	this->set(arg);
	
	return *this;
}
template<class T>
const UniquePointer<T>& 
UniquePointer<T>::operator =(const T &arg)
{
	this->clear();
	this->make(arg);
	
	return *this;
}


#endif // POINTERS
