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

class String : public TString<char>
{
public:
	String();
	String(const char *c_str);
	String(const String &string);
	
	~String();
	
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
	
	~WString();
	
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

// TString

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

// String

String::String()
	: TString<char>()
{}

String::String(const String &string)
	: TString<char>(static_cast<const TString<char>&>(string))
{}

String::~String()
{}

// WString

WString::WString()
	: TString<wchar_t>()
{}

WString::WString(const WString &wstring)
	: TString<wchar_t>(static_cast<const TString<wchar_t>&>(wstring))
{}

WString::~WString()
{}

#endif // STRING
