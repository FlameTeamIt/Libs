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
private:
	bool is_actual_hash;
	
protected:
//	constexpr static T null_string[] = "";
	unsigned long hash;
	
	void computeHash();
	
	// присваивание
	void assign(const T* c_str);
	void assign(const TString<T> &str);
	
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
	
	TString<T> getSubstr(size_t pos, size_t length);
	
	const T*& getCString();
	
	~TString();
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

#endif // STRING_TSTRING

