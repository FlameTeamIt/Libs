#ifndef STRING
#define STRING

#include "Array.h"
#include "String_Functions.h"

namespace flame_ide
{namespace templates
{

template<typename T>
class TString : public Array<T>
{
protected:
	const T* null_string = "";
	unsigned long hash;
	
	void computeHash();
	
	TString<T> getSubstr();
	
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
};

class String : public TString<char>
{
public:
	String();
	String(const char *c_str);
	String(const String &string);
	
	unsigned long getHash();
	
	String& operator+(const char *c_str);
	String& operator+(const String& string);
	
	String& operator+=(const char *c_str);
	String& operator+=(const String& string);
	
	String& operator=(const char *c_str);
	String& operator=(const String& string);
	
	bool operator==(const char *c_str);
	bool operator==(const String& string);
	
	bool operator!=(const char *c_str);
	bool operator!=(const String& string);
};

class WString : public TString<wchar_t>
{
public:
	WString();
	WString(const wchar_t *);
	
	WString& operator+(const wchar_t *c_str);
	WString& operator+(const WString& string);
	
	WString& operator+=(const wchar_t *c_str);
	WString& operator+=(const WString& string);
	
	bool operator==(const wchar_t *c_str);
	bool operator==(const WString& string);
	
	bool operator!=(const wchar_t *c_str);
	bool operator!=(const WString& string);
};

}}

using namespace flame_ide::templates;

String::String()
	: Array()
{
	inc_arr = (char*)null_string;
}


#endif // STRING
