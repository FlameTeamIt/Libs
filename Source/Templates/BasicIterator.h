#ifndef ITERATOR_H
#define ITERATOR_H

namespace flame_ide
{namespace templates
{

// T - простой итератор
// TData - данные
template<class T, class TData>
class InterfaceIterator
{
protected:
	mutable T* inc_data_iterator;
	
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
	BasicIterator(BasicIterator<T, TData> &&iterator);
	BasicIterator(const BasicIterator<T, TData> &iterator);
	
	~BasicIterator();
	
	inline const BasicIterator<T, TData>& operator ++();
	inline const BasicIterator<T, TData>& operator --();
};

template<class T, class TData>
class BasicReverseIterator : public InterfaceIterator<T, TData>
{
protected:
	using InterfaceIterator<T, TData>::inc_data_iterator;
public:
	BasicReverseIterator();
	BasicReverseIterator(BasicReverseIterator<T, TData> &&iterator);
	BasicReverseIterator(const BasicReverseIterator<T, TData> &iterator);
	
	~BasicReverseIterator();
	
	inline const BasicReverseIterator<T, TData>& operator ++();
	inline const BasicReverseIterator<T, TData>& operator --();
};

}}

using flame_ide::templates::InterfaceIterator;
using flame_ide::templates::BasicIterator;
using flame_ide::templates::BasicReverseIterator;

template<class T, class TData>
InterfaceIterator<T, TData>::InterfaceIterator()
	: inc_data_iterator(nullptr)
{}

template<class T, class TData>
InterfaceIterator<T, TData>::~InterfaceIterator() {}

template<class T, class TData>
BasicIterator<T, TData>::BasicIterator()
	: InterfaceIterator<T, TData>()
{}

template<class T, class TData>
BasicIterator<T, TData>::BasicIterator(BasicIterator<T, TData> &&iterator)
	: BasicIterator<T, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class T, class TData>
BasicIterator<T, TData>::BasicIterator(const BasicIterator<T, TData> &iterator)
	: BasicIterator<T, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class T, class TData>
BasicIterator<T, TData>::~BasicIterator() {}

template<class T, class TData>
const BasicIterator<T, TData>&
BasicIterator<T, TData>::operator ++()
{
	++(this->inc_data_iterator);
	return *this;
}

template<class T, class TData>
const BasicIterator<T, TData>&
BasicIterator<T, TData>::operator --()
{
	--(this->inc_data_iterator);
	return *this;
}


template<class T, class TData>
BasicReverseIterator<T, TData>::BasicReverseIterator()
	: InterfaceIterator<T, TData>()
{}

template<class T, class TData>
BasicReverseIterator<T, TData>::BasicReverseIterator(BasicReverseIterator<T, TData> &&iterator)
	: BasicReverseIterator<T, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class T, class TData>
BasicReverseIterator<T, TData>::BasicReverseIterator(const BasicReverseIterator<T, TData> &iterator)
	: BasicReverseIterator<T, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class T, class TData>
BasicReverseIterator<T, TData>::~BasicReverseIterator() {}

template<class T, class TData>
const BasicReverseIterator<T, TData>&
BasicReverseIterator<T, TData>::operator ++()
{
	--(this->inc_data_iterator);
	return *this;
}

template<class T, class TData>
const BasicReverseIterator<T, TData>&
BasicReverseIterator<T, TData>::operator --()
{
	++(this->inc_data_iterator);
	return *this;
}

#endif // ITERATOR_H
