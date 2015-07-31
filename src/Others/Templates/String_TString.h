#ifndef STRING_TSTRING
#define STRING_TSTRING

#include "Array.h"
#include "String_Functions.h"

namespace flame_ide
{namespace templates
{

template<typename T>
class TString : public Array<T>
{
protected:
	bool is_actual_hash;
	
//	constexpr static T null_string[] = "";
	unsigned long hash;
	
	void computeHash();
	
	// присваивание
	void assign(const T* c_str);
	void assign(const TString<T> &tstring);
	
	// сложение строк
	void concatenation(const T* c_str);
	void concatenation(const TString<T> &str);
	
	// сравнение
	bool is_equal(const T* c_str) const;
	bool is_equal(const TString<T> &str) const;
	
	bool is_not_qual(const T* c_str) const;
	bool is_not_qual(const TString<T> &str) const;
	
public:
	TString();
	TString(const TString<T> &tstring);
	
	~TString();
	
	TString<T> getSubstr(size_t pos, size_t length);
	
	const T* getCString() const;
	
	T& operator [](size_t index) const;
};

}}

using namespace flame_ide::templates;

template<typename T>
TString<T>::TString()
	: Array<T>()
{}

template<typename T>
TString<T>::TString(const TString<T> &tstring)
	: Array<T>(static_cast<const Array<T>&>(tstring))
{}

template<typename T>
TString<T>::~TString() {}

// protected

template<typename T>
void
TString<T>::computeHash()
{}

template<typename T>
void
TString<T>::assign(const T *c_str)
{}
template<typename T>
void
TString<T>::assign(const TString<T> &tstring)
{}

template<typename T>
void
TString<T>::concatenation(const T* c_str)
{}
template<typename T>
void
TString<T>::concatenation(const TString<T> &str)
{}

template<typename T>
bool
TString<T>::is_equal(const T *c_str) const
{}
template<typename T>
bool
TString<T>::is_equal(const TString<T> &str) const
{}

template<typename T>
bool
TString<T>::is_not_qual(const T *c_str) const
{}
template<typename T>
bool
TString<T>::is_not_qual(const TString<T> &str) const
{}

// public

template<typename T>
TString<T>
TString<T>::getSubstr(size_t pos, size_t length)
{}

template<typename T>
const T*
TString<T>::getCString() const
{}

template<typename T>
T&
TString<T>::operator [](size_t index) const
{}


#endif // STRING_TSTRING
