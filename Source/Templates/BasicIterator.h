#ifndef ITERATOR_H
#define ITERATOR_H

namespace flame_ide
{namespace templates
{

// T - простой итератор
// TData - данные
template<class TIterator, class TData>
class InterfaceIterator
{
protected:
	mutable TIterator* inc_data_iterator;
	
public:
	InterfaceIterator();
	~InterfaceIterator();
	
	virtual       TData& operator *() const noexcept = 0;
	virtual       TData*& operator ->() const noexcept = 0;
};


template<class TIterator, class TData>
class BasicIterator : public InterfaceIterator<TIterator, TData>
{
public:
	BasicIterator();
	BasicIterator(BasicIterator<TIterator, TData> &&iterator);
	BasicIterator(const BasicIterator<TIterator, TData> &iterator);
	
	~BasicIterator();
	
	inline const BasicIterator<TIterator, TData>& operator ++();
	inline const BasicIterator<TIterator, TData>& operator --();
	inline const BasicIterator<TIterator, TData>& operator ++() const;
	inline const BasicIterator<TIterator, TData>& operator --() const;
};

template<class TIterator, class TData>
class BasicReverseIterator : public InterfaceIterator<TIterator, TData>
{
protected:
	using InterfaceIterator<TIterator, TData>::inc_data_iterator;
public:
	BasicReverseIterator();
	BasicReverseIterator(BasicReverseIterator<TIterator, TData> &&iterator);
	BasicReverseIterator(const BasicReverseIterator<TIterator, TData> &iterator);
	
	~BasicReverseIterator();
	
	inline const BasicReverseIterator<TIterator, TData>& operator ++();
	inline const BasicReverseIterator<TIterator, TData>& operator --();
};

}}

using flame_ide::templates::InterfaceIterator;
using flame_ide::templates::BasicIterator;
using flame_ide::templates::BasicReverseIterator;

template<class TIterator, class TData>
InterfaceIterator<TIterator, TData>::InterfaceIterator()
	: inc_data_iterator(nullptr)
{}

template<class TIterator, class TData>
InterfaceIterator<TIterator, TData>::~InterfaceIterator() {}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::BasicIterator()
	: InterfaceIterator<TIterator, TData>()
{}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::BasicIterator(BasicIterator<TIterator, TData> &&iterator)
	: BasicIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::BasicIterator(const BasicIterator<TIterator, TData> &iterator)
	: BasicIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::~BasicIterator() {}

template<class TIterator, class TData>
const BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator ++()
{
	++(this->inc_data_iterator);
	return *this;
}

template<class TIterator, class TData>
const BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator --()
{
	--(this->inc_data_iterator);
	return *this;
}

template<class TIterator, class TData>
const BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator ++() const
{
	++(this->inc_data_iterator);
	return *this;
}

template<class TIterator, class TData>
const BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator --() const
{
	--(this->inc_data_iterator);
	return *this;
}


template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::BasicReverseIterator()
	: InterfaceIterator<TIterator, TData>()
{}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::BasicReverseIterator(BasicReverseIterator<TIterator, TData> &&iterator)
	: BasicReverseIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::BasicReverseIterator(const BasicReverseIterator<TIterator, TData> &iterator)
	: BasicReverseIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::~BasicReverseIterator() {}

template<class TIterator, class TData>
const BasicReverseIterator<TIterator, TData>&
BasicReverseIterator<TIterator, TData>::operator ++()
{
	--(this->inc_data_iterator);
	return *this;
}

template<class TIterator, class TData>
const BasicReverseIterator<TIterator, TData>&
BasicReverseIterator<TIterator, TData>::operator --()
{
	++(this->inc_data_iterator);
	return *this;
}

#endif // ITERATOR_H
