#ifndef ARRAY_ITERATORS
#define ARRAY_ITERATORS

#include <Templates/BasicIterator.h>

namespace flame_ide
{namespace templates
{

template<class T> class Array;
template<class T, class TData> class ArrayIterator;
template<class T, class TData> class ArrayReverseIterator;

template<class T, class TData>
class ArrayIterator : public BasicIterator<T, TData>
{
public:
	virtual const TData& operator *() const noexcept;
	virtual       TData& operator *()       noexcept;
		  
	virtual const TData* operator ->() const noexcept;
	virtual       TData* operator ->()       noexcept;
};

template<class T, class TData = T>
class ArrayReverseIterator : public BasicReverseIterator<T, T>
{
public:
	virtual const TData& operator *() const noexcept;
	virtual       TData& operator *()       noexcept;
		  
	virtual const TData* operator ->() const noexcept;
	virtual       TData* operator ->()       noexcept;
};

}}

#endif // ARRAY_ITERATORS
