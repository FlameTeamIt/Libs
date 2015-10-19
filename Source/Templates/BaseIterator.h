#ifndef ITERATOR_H
#define ITERATOR_H

namespace flame_ide
{namespace templates
{

template<class T>
class BaseIterator
{
protected:
	mutable T* _data;
	
public:
	BaseIterator();
	BaseIterator(const BaseIterator<T> &interator);
	BaseIterator(BaseIterator<T> &&interator);
	
	virtual ~BaseIterator();
	
	virtual const BaseIterator<T>& operator ++() = 0;
	virtual const BaseIterator<T>& operator --() = 0;
	
	const T& operator *() const noexcept;
	      T& operator *()       noexcept;
		  
	virtual const T* operator ->() const noexcept = 0;
	virtual       T* operator ->() noexcept = 0;
};

}}


#endif // ITERATOR_H

