#ifndef POINTERS_UNIQUEPOINTER
#define POINTERS_UNIQUEPOINTER

#include <Templates/Pointers.hpp>

namespace flame_ide
{namespace templates
{

template<class T>
class UniquePointer : public BasicPointer<T>
{
	UniquePointer(const UniquePointer &pointer);

protected:
	inline void set(UniquePointer &pointer);
	using BasicPointer<T>::inc_pointer;

public:
	UniquePointer();
	UniquePointer(const T &object);
	UniquePointer(UniquePointer &&pointer);

	virtual ~UniquePointer();

	inline const UniquePointer& operator =(UniquePointer<T> &arg);
	inline const UniquePointer& operator =(UniquePointer<T> &&arg);
	inline const UniquePointer& operator =(const T &arg);

	inline const UniquePointer& operator =(BasicPointer<T> &arg);

	template<class Tt, class Uu> friend
	UniquePointer<Tt> static_pointer_cast(UniquePointer<Uu>& pointer) noexcept;
	template<class Tt, class Uu> friend
	UniquePointer<Tt> dynamic_pointer_cast(UniquePointer<Uu>& pointer) noexcept;

	template<class Uu>
	operator UniquePointer<Uu> () {return static_pointer_cast<Uu>(*this);}
};

template<class T, class ... Ts>
UniquePointer<T> make_unique(Ts&& ... args)
{
	UniquePointer<T> pointer;
	pointer.make(args ...);

	return pointer;
}

}}

using namespace flame_ide::template;

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
	if(this->isInitialized())
	{
		delete this->inc_pointer;
		this->inc_pointer = nullptr;
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

template<class T>
const UniquePointer<T>&
UniquePointer<T>::operator =(BasicPointer<T> &arg)
{
	this->clear();

	this->inc_pointer = arg.inc_pointer;
	arg.inc_pointer = nullptr;

	return *this;
}

#endif // POINTERS_UNIQUEPOINTER
