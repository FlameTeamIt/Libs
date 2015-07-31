#ifndef STRING
#define STRING

#include "String_TString.h"

namespace flame_ide
{namespace templates
{

class String : public TString<char>
{
public:
	String();
	String(const char *c_str);
	String(const String &string);
	
	friend String& operator +(const String& string, const char *c_str);
	friend String& operator +(const char *c_str, const String& string);
	
	String& operator +=(const String& string);
	String& operator +=(const char *c_str);
	
	friend bool operator ==(const char *c_str, const String& string);
	friend bool operator ==(const String& string, const char *c_str);
	friend bool operator ==(const String& string1, const String& string2);
	
	friend bool operator !=(const char *c_str, const String& string);
	friend bool operator !=(const String& string, const char *c_str);
	friend bool operator !=(const String& string1, const String& string2);
	
	char& operator [](size_t index);
	
	void pushBack(char ch);
	void pushBack(const char* &c_str);
	void pushBack(const String &string);
	
	void pushFront(char ch);
	void pushFront(const char* &c_str);
	void pushFront(const String &string);
	
	void insert(size_t pos, char ch);
	void insert(size_t pos, char* &c_str);
	void insert(size_t pos, const String &string);
	
	void popBack(size_t count = 1);
	
	void popFront(size_t count = 1);
	
	void erase(size_t pos, size_t count = 1);
	
	~String();
	
	unsigned long getHash();
	
};

String& operator +(const String& string, const char *c_str);
String& operator +(const char *c_str, const String& string);

bool operator ==(const char *c_str, const String& string);
bool operator ==(const String& string, const char *c_str);
bool operator ==(const String& string1, const String& string2);

bool operator !=(const char *c_str, const String& string);
bool operator !=(const String& string, const char *c_str);
bool operator !=(const String& string1, const String& string2);

}}

using namespace flame_ide::templates;

String::String()
	: TString<char>()
{}

String::String(const String &string)
	: TString<char>(static_cast<const TString<char>&>(string))
{}

String::~String()
{}

unsigned long
String::getHash()
{
	if(!is_actual_hash)
	{
		computeHash();
	}
	
	return hash;
}

#endif // STRING
