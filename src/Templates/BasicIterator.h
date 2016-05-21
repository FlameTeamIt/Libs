#ifndef ITERATOR_H
#define ITERATOR_H

namespace flame_ide
{namespace templates
{

// TIterator - простой итератор
// TData - данные

template<class TIterator, class TData>
class IteratorInterface
{
protected:
	mutable TIterator inc_data_iterator;
	
	virtual void operator_inc() = 0; // ++
	virtual void operator_dec() = 0; // --
	virtual void operator_inc() const = 0; // ++
	virtual void operator_dec() const = 0; // --
	
public:
	IteratorInterface();
	~IteratorInterface();
	
	typedef IteratorInterface<TIterator, TData> my_type;
	
	virtual TData& operator *() noexcept = 0;
	virtual TData* operator ->() noexcept = 0;
	virtual const TData& operator *() const noexcept = 0;
	virtual const TData* operator ->() const noexcept = 0;
};


template<class TIterator, class TData>
class BasicIterator : public IteratorInterface<TIterator, TData>
{
protected:
	using IteratorInterface<TIterator, TData>::inc_data_iterator;
	
	virtual void operator_inc(); // ++
	virtual void operator_dec(); // --
	virtual void operator_inc() const; // ++
	virtual void operator_dec() const; // --
	
public:
	BasicIterator();
	BasicIterator(BasicIterator<TIterator, TData> &&iterator);
	BasicIterator(const BasicIterator<TIterator, TData> &iterator);
	
	~BasicIterator();
	
	inline BasicIterator<TIterator, TData>& operator ++();
	inline BasicIterator<TIterator, TData>& operator --();
	inline const BasicIterator<TIterator, TData>& operator ++() const;
	inline const BasicIterator<TIterator, TData>& operator --() const;
};

template<class TIterator, class TData>
class BasicReverseIterator : public IteratorInterface<TIterator, TData>
{
protected:
	using IteratorInterface<TIterator, TData>::inc_data_iterator;
	
	virtual void operator_inc(); // ++
	virtual void operator_dec(); // --
	virtual void operator_inc() const; // ++
	virtual void operator_dec() const; // --
	
public:
	BasicReverseIterator();
	BasicReverseIterator(BasicReverseIterator<TIterator, TData> &&iterator);
	BasicReverseIterator(const BasicReverseIterator<TIterator, TData> &iterator);
	
	~BasicReverseIterator();
	
	inline BasicReverseIterator<TIterator, TData>& operator ++();
	inline BasicReverseIterator<TIterator, TData>& operator --();
	inline const BasicReverseIterator<TIterator, TData>& operator ++() const;
	inline const BasicReverseIterator<TIterator, TData>& operator --() const;
};


}}

using flame_ide::templates::IteratorInterface;
using flame_ide::templates::BasicIterator;
using flame_ide::templates::BasicReverseIterator;

template<class TIterator, class TData>
IteratorInterface<TIterator, TData>::IteratorInterface()
{}

template<class TIterator, class TData>
IteratorInterface<TIterator, TData>::~IteratorInterface() {}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::BasicIterator()
	: IteratorInterface<TIterator, TData>()
{}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::BasicIterator(
		BasicIterator<TIterator, TData> &&iterator)
	: BasicIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::BasicIterator(
		const BasicIterator<TIterator, TData> &iterator)
	: BasicIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>::~BasicIterator() {}

template<class TIterator, class TData>
void
BasicIterator<TIterator, TData>::operator_inc() // ++
{
	++(this->inc_data_iterator);
}

template<class TIterator, class TData>
void
BasicIterator<TIterator, TData>::operator_dec() // --
{
	--(this->inc_data_iterator);
}

template<class TIterator, class TData>
void
BasicIterator<TIterator, TData>::operator_inc() const // ++
{
	++(this->inc_data_iterator);
}

template<class TIterator, class TData>
void
BasicIterator<TIterator, TData>::operator_dec() const // --
{
	--(this->inc_data_iterator);
}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator ++()
{
	operator_inc();
	return *this;
}

template<class TIterator, class TData>
BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator --()
{
	operator_dec();
	return *this;
}

template<class TIterator, class TData>
const BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator ++() const
{
	operator_inc();
	return *this;
}

template<class TIterator, class TData>
const BasicIterator<TIterator, TData>&
BasicIterator<TIterator, TData>::operator --() const
{
	operator_dec();
	return *this;
}


template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::BasicReverseIterator()
	: IteratorInterface<TIterator, TData>()
{}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::BasicReverseIterator(
	BasicReverseIterator<TIterator, TData> &&iterator)
	: BasicReverseIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::BasicReverseIterator(
	const BasicReverseIterator<TIterator, TData> &iterator)
	: BasicReverseIterator<TIterator, TData>()
{
	this->inc_data_iterator = iterator.inc_data_iterator;
}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>::~BasicReverseIterator() {}

template<class TIterator, class TData>
void
BasicReverseIterator<TIterator, TData>::operator_inc() // ++
{
	--(this->inc_data_iterator);
}

template<class TIterator, class TData>
void
BasicReverseIterator<TIterator, TData>::operator_dec() // --
{
	++(this->inc_data_iterator);
}

template<class TIterator, class TData>
void
BasicReverseIterator<TIterator, TData>::operator_inc() const // ++
{
	--(this->inc_data_iterator);
}

template<class TIterator, class TData>
void
BasicReverseIterator<TIterator, TData>::operator_dec() const // --
{
	++(this->inc_data_iterator);
}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>&
BasicReverseIterator<TIterator, TData>::operator ++()
{
	operator_inc();
	return *this;
}

template<class TIterator, class TData>
BasicReverseIterator<TIterator, TData>&
BasicReverseIterator<TIterator, TData>::operator --()
{
	operator_dec();
	return *this;
}

template<class TIterator, class TData>
const BasicReverseIterator<TIterator, TData>&
BasicReverseIterator<TIterator, TData>::operator ++() const
{
	operator_inc();
	return *this;
}

template<class TIterator, class TData>
const BasicReverseIterator<TIterator, TData>&
BasicReverseIterator<TIterator, TData>::operator --() const
{
	operator_dec();
	return *this;
}

#endif // ITERATOR_H
