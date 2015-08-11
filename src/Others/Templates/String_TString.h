#ifndef STRING_TSTRING
#define STRING_TSTRING

#include <string.h>
#include <wchar.h>

#include "For_All.h"
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
	
	
	
	
	
	virtual inline size_t getCStrLength(const T* c_tstr) const = 0;
	
public:
	TString();
	TString(const size_t &length, const T* &c_tstr);
	TString(const TString<T> &tstring);
	
	~TString();
	
	virtual TString<T>& getSubstr(size_t pos, size_t length);
	
	const T* getCString() const;
	
	inline T& operator [](size_t index) const;
	
	static inline unsigned long getHash(const T* c_tstr);
	
	// присваивание
	void assign(const T* c_tstr);
	void assign(const TString<T> &tstring);
	inline TString<T>& operator =(const TString<T>& tstring);
	inline TString<T>& operator =(const char *c_tstr);
	
	inline TString<T>& operator +=(const TString<T>& tstring);
	inline TString<T>& operator +=(const char *c_tstr);
	
	// сложение строк
	void concatenation(const T* c_tstr);
	void concatenation(const TString<T> &str);
	friend TString<T>& operator +(const TString<T>& string, const T *c_tstr);
	friend TString<T>& operator +(const T *c_tstr, const TString<T>& string);
	friend TString<T>& operator +(const TString<T>& string1, const TString<T>& string2);
	
	// сравнение
	bool is_equal(const T* c_tstr) const;
	bool is_equal(const TString<T> &str) const;
	friend bool operator ==(const T *c_tstr, const TString<T>& string);
	friend bool operator ==(const TString<T>& string, const T *c_tstr);
	friend bool operator ==(const TString<T>& string1, const TString<T>& string2);
	
	bool is_not_qual(const T* c_tstr) const;
	bool is_not_qual(const TString<T> &str) const;
	friend bool operator !=(const T *c_tstr, const TString<T>& string);
	friend bool operator !=(const TString<T>& string, const T *c_tstr);
	friend bool operator !=(const TString<T>& string1, const TString<T>& string2);
};

template<typename T> inline
TString<T>& operator +(const TString<T> &string, const T *c_tstr);
template<typename T> inline
TString<T>& operator +(const T *c_tstr, const TString<T> &string);
template<typename T> inline
TString<T>& operator +(const TString<T> &string1, const TString<T> &string2);

template<typename T> inline
bool operator ==(const T *c_tstr, const TString<T> &string);
template<typename T> inline
bool operator ==(const TString<T> &string, const T *c_tstr);
template<typename T> inline
bool operator ==(const TString<T> &string1, const TString<T> &string2);

template<typename T> inline
bool operator !=(const T *c_tstr, const TString<T> &string);
template<typename T> inline
bool operator !=(const TString<T> &string, const T *c_tstr);
template<typename T> inline
bool operator !=(const TString<T> &string1, const TString<T> &string2);


}}

using namespace flame_ide::templates;

template<typename T>
TString<T>::TString()
	: Array<T>()
{
	this->is_actual_hash = false;
	this->hash = 0;
}

template<typename T>
TString<T>::TString(const size_t& length, const T *&c_tstr)
	: Array<T>(length, c_tstr)
{
	this->is_actual_hash = false;
	this->hash = 0;
}

template<typename T>
TString<T>::TString(const TString<T> &tstring)
	: Array<T>(static_cast<const Array<T>&>(tstring))
{
	if(tstring.is_actual_hash)
	{
		this->is_actual_hash = true;
		this->hash = tstring.hash;
	}
	else
	{
		this->is_actual_hash = false;
		this->hash = 0;
	}
}

template<typename T>
TString<T>::~TString() {}

// а нужно ли оно мне?
// protected

template<typename T>
void
TString<T>::computeHash()
{}

template<typename T>
void
TString<T>::assign(const T *c_tstr)
{}
template<typename T>
void
TString<T>::assign(const TString<T> &tstring)
{}

template<typename T>
void
TString<T>::concatenation(const T* c_tstr)
{}
template<typename T>
void
TString<T>::concatenation(const TString<T> &str)
{}

template<typename T>
bool
TString<T>::is_equal(const T *c_tstr) const
{}
template<typename T>
bool
TString<T>::is_equal(const TString<T> &str) const
{}

template<typename T>
bool
TString<T>::is_not_qual(const T *c_tstr) const
{}
template<typename T>
bool
TString<T>::is_not_qual(const TString<T> &str) const
{}

// public

template<typename T>
TString<T>&
TString<T>::getSubstr(size_t pos, size_t length)
{
	
}

template<typename T>
const T*
TString<T>::getCString() const
{}

template<typename T>
T&
TString<T>::operator [](size_t index) const
{
	return this->inc_arr[index];
}

// static

template<typename T>
unsigned long
TString<T>::getHash(const T *c_tstr)
{
	// тут сложно из-за незнания размера массива
	// нужно как-то узнавать его
//	size_t c_tstr_len = getCStrLength(c_tstr);
}

// operators



// friend operators

#endif // STRING_TSTRING
