#ifndef TEMPLATES_POINTERS_BASICPOINTER
#define TEMPLATES_POINTERS_BASICPOINTER

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
	
	virtual ~BasicPointer();
	
	template<class ... Ts>
	void make(Ts ... args);
	template<class ... Ts>
	void make(Ts ... args) const;
	
	void clear();
	
	bool isInitialized() const;
	
	T& operator *();
	T* operator ->();
	
	const T& operator *() const;
	const T* operator ->() const;
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
{}

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
bool
BasicPointer<T>::isInitialized() const
{
	return (inc_pointer != nullptr);
}

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

#endif // BASICPOINTER

