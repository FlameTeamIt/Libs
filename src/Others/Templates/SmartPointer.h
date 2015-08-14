#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

namespace flame_ide
{namespace templates
{

template<class T>
class SmartPointer
{
	T *inc_pointer;
	
public:
	SmartPointer();
	SmartPointer(T *new_pointer);
	
	~SmartPointer();
	
	template<Args ... args>
	void make(Args ... args);
	
	inline T& operator *() noexcept;
	
	inline T* getPointer();
	inline T* operator ->() noexcept;
	
	const T& operator *() const noexcept;
	const T& operator ->() const noexcept;
	
	T& operator =(const SmartPointer<T> &arg);
	T& operator =(T* arg);
};

}}


#endif // SMARTPOINTER_H

