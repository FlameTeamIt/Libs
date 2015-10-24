#ifndef ITERATOR_H
#define ITERATOR_H

namespace flame_ide
{namespace templates
{

template<class T, class TData>
class InterfaceIterator
{
protected:
	mutable T* inc_data;
	
public:
	InterfaceIterator();
	~InterfaceIterator();
	
	virtual const TData& operator *() const noexcept = 0;
	virtual       TData& operator *()       noexcept = 0;
		  
	virtual const TData* operator ->() const noexcept = 0;
	virtual       TData* operator ->()       noexcept = 0;
};


template<class T, class TData>
class BasicIterator : public InterfaceIterator<T, TData>
{
public:
	BasicIterator();
	BasicIterator(BasicIterator<T> &&iterator);
	BasicIterator(const BasicIterator<T> &iterator);
	
	~BasicIterator();
	
	inline const BasicIterator<T>& operator ++();
	inline const BasicIterator<T>& operator --();
	
	inline const BasicIterator<T>& operator ++(int);
	inline const BasicIterator<T>& operator --(int);
};

template<class T, class TData>
class BasicReverseIterator : public InterfaceIterator<TData>

{
protected:
	mutable T* inc_data;
	
public:
	BasicReverseIterator();
	BasicReverseIterator(BasicReverseIterator<T> &&iterator);
	BasicReverseIterator(const BasicReverseIterator<T> &iterator);
	
	~BaseIterator();
	
	inline const BasicReverseIterator<T>& operator ++();
	inline const BasicReverseIterator<T>& operator --();
	
	inline const BasicReverseIterator<T>& operator ++(int);
	inline const BasicReverseIterator<T>& operator --(int);
};

}}

using flame_ide::templates::InterfaceIterator;
using flame_ide::templates::BasicIterator;
using flame_ide::templates::BasicReverseIterator;

template<class T, class TData>
InterfaceIterator<T, TData>::InterfaceIterator()
	: inc_data(nullptr)
{}

template<class T, class TData>
InterfaceIterator<T, TData>::~InterfaceIterator() {}

template<class T, class TData>
BasicIterator<T, TData>::BasicIterator()
	: InterfaceIterator<T, TData>()
{}

template<class T, class TData>
BasicIterator<T, TData>::BasicIterator(BasicIterator<T> &&iterator)
	: BasicIterator<T, TData>()
{
	this->inc_data = iterator.inc_data;
}

template<class T, class TData>
BasicIterator<T, TData>::BasicIterator(const BasicIterator<T> &iterator)
	: BasicIterator<T, TData>()
{
	this->inc_data = iterator.inc_data;
}

template<class T, class TData>
BasicIterator<T, TData>::~BasicIterator() {}

template<class T, class TData>
const BasicIterator<T>&
BasicIterator<T, TData>::operator ++()
{
	this->inc_data++;
	return *this;
}

template<class T, class TData>
const BasicIterator<T>&
BasicIterator<T, TData>::operator --()
{
	this->inc_data--;
	return *this;
}

template<class T, class TData>
const BasicIterator<T>&
BasicIterator<T, TData>::operator ++(int)
{
	this->inc_data++;
	return *this;
}

template<class T, class TData>
const BasicIterator<T>&
BasicIterator<T, TData>::operator --(int)
{
	this->inc_data--;
	return *this;
}


template<class T, class TData>
BasicReverseIterator<T, TData>::BasicReverseIterator()
	: inc_data(nullptr)
{}

template<class T, class TData>
BasicReverseIterator<T, TData>::BasicReverseIterator(BasicReverseIterator<T> &&iterator)
	: BasicReverseIterator<T, TData>()
{
	this->inc_data = iterator.inc_data;
}

template<class T, class TData>
BasicReverseIterator<T, TData>::BasicReverseIterator(const BasicReverseIterator<T> &iterator)
	: BasicReverseIterator<T, TData>()
{
	this->inc_data = iterator.inc_data;
}

template<class T, class TData>
BasicReverseIterator<T, TData>::~BasicReverseIterator()
{}

template<class T, class TData>
const BasicReverseIterator<T>&
BasicReverseIterator<T, TData>::operator ++()
{
	this->inc_data--;
	return *this;
}

template<class T, class TData>
const BasicReverseIterator<T>&
BasicReverseIterator<T, TData>::operator --()
{
	this->inc_data++;
	return *this;
}

template<class T, class TData>
const BasicReverseIterator<T>&
BasicReverseIterator<T, TData>::operator ++(int)
{
	this->inc_data--;
	return *this;
}

template<class T, class TData>
const BasicReverseIterator<T>&
BasicReverseIterator<T, TData>::operator --(int)
{
	this->inc_data++;
	return *this;
}

#endif // ITERATOR_H

